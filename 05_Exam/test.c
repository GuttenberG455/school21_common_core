#include <stdio.h> //delete
#include <stdlib.h> // malloc, free
#include <unistd.h> // write, close, fork, exit, chdir, execve, dup2, pipe
#include <string.h> // strcmp, strncmp
#include <signal.h> // signal, kill
#include <sys/types.h> //for linux
#include <sys/wait.h> //for linux

#define STDIN		0
#define STDOUT		1
#define STDERR		2

#define TYPE_END	3
#define TYPE_PIPE	4
#define TYPE_BREAK	5

typedef struct s_base
{
    char **argv;	// аргументы
    int size;		// кол-во аргументов
	int type;		// тип функции
	int fd[2];		// fd для dup2 и pipe
	struct s_base *prev;	// предыдущая структура
    struct s_base *next;	// следующая структура
} t_base;

/*
**====================================
**============Part utils==============
**====================================
*/

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int size = ft_strlen(str);
	char *new;

	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}

/*
**====================================
**============Part error==============
**====================================
*/

void exit_fatal(void)
{
	write(STDERR, "error: fatal\n", ft_strlen("error: fatal\n"));
	exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
	write(STDERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int exit_cd_1()
{
	write(STDERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	return (EXIT_FAILURE);
}

int exit_cd_2(char *str)
{
	write(STDERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STDERR, str, ft_strlen(str));
	write(STDERR, "\n", 1);
	return (EXIT_FAILURE);
}

/*
**====================================
**============Part parsing============
**====================================
*/

void ft_lstadd_back(t_base **ptr, t_base *new) // добавляем в конец списка
{
    t_base *temp;

	if (!(*ptr))
		*ptr = new;
	else
	{
		temp = *ptr;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

int size_argv(char **argv) // считаем длину аргумента
{
    int i = 0;
    while (argv[i] && strcmp(argv[i], "|") != 0 && strcmp(argv[i], ";") != 0) // пока есть аргумент и он не ; или |
        i++;
    return (i);
}

int check_end(char *argv)
{
    if (!argv)
        return (TYPE_END);		// обычный конец
    if (strcmp(argv, "|") == 0)
        return (TYPE_PIPE);		// пайп
    if (strcmp(argv, ";") == 0)
        return (TYPE_BREAK);	// точка запятая
    return (0);
}

int parser_argv(t_base **ptr, char **argv) // парсер команды
{
    int size = size_argv(argv); // считаем длину argv
    t_base *new; // создаем новую структуру

    if (!(new = (t_base *)malloc(sizeof(t_base)))) // выделяем ей память
        exit_fatal(); // не выделили память
    if (!(new->argv = (char **)malloc(sizeof(char *) * (size + 1)))) 
        exit_fatal(); // не выделили память
    new->size = size; // кол-во аргументов
	new->next = NULL; // след
	new->prev = NULL; // пред
    new->argv[size] = NULL; // последний + 1 аргумент, чтобы не ушел
    while (--size >= 0)
        new->argv[size] = ft_strdup(argv[size]); // переписываем аргументы  в нашу структуру
    new->type = check_end(argv[new->size]);	// записываем тип конца (ничего, пайп, точка запятая)
    ft_lstadd_back(ptr, new);	// добавляем структуру в конце списка
    return (new->size);	// возвращаем кол-во команд
}

/*
**====================================
**============Part execve=============
**====================================
*/

void exec_cmd(t_base *temp, char **env) // выполнение команды
{
	pid_t pid;		// создание дочернего процесса
	int status;		// статус сигнала
	int pipe_open;	// входной открытый пайп

	pipe_open = 0;	// изначально 0 ст. ввод
	if (temp->type == TYPE_PIPE || (temp->prev && temp->prev->type == TYPE_PIPE)) // если тип пайп, или предыдущий был пайпом
	{
		pipe_open = 1;	// флаг открытия пайпа
		if (pipe(temp->fd)) // создаем пайп[2] из двух fd
			exit_fatal();	// ошибка
	}
	pid = fork();	// создаем дочку
	if (pid < 0)	// если не создался, то ошибка
		exit_fatal();
	else if (pid == 0) // дочерний процесс
	{
		if (temp->type == TYPE_PIPE && dup2(temp->fd[STDOUT], STDOUT) < 0) // если тип - пайп, и заменяем предыдущий fd на STDOUT
			exit_fatal(); // если не получилось, то ошибка
		if (temp->prev && temp->prev->type == TYPE_PIPE && dup2(temp->prev->fd[STDIN], STDIN) < 0) // если предыдущий - пайп, то заменяем предыдущий fd на STDIN
			exit_fatal(); // если не получилось, то ошибка
		if ((execve(temp->argv[0], temp->argv, env)) < 0) // выполняем команду с аргументами 
			exit_execve(temp->argv[0]); // если не получилось, то ошибка
		exit(EXIT_SUCCESS); // завершаем процесс
	}
	else // родительский процесс
	{
		waitpid(pid, &status, 0); // ожидание дочернего процесса 
		if (pipe_open)	// если пайп открыт
		{
			close(temp->fd[STDOUT]);	// закрыть 
			if (!temp->next || temp->type == TYPE_BREAK) // если ничего нет дальше, а сейчас ;
				close(temp->fd[STDIN]); // закрываем STDIN
		}
		if (temp->prev && temp->prev->type == TYPE_PIPE) // елси предыдущий - пайп
			close(temp->prev->fd[STDIN]); //  закрываем предыдущий STDIN
	}
}

void exec_cmds(t_base *ptr, char **env) // выполнение команд
{
	t_base *temp;

	temp = ptr;	// временная структура
	while (temp) 
	{
		if (strcmp("cd", temp->argv[0]) == 0) // если наша команда cd
		{
			if (temp->size < 2) // без аргументов
				exit_cd_1(); // выходим с ошибкой
			else if (chdir(temp->argv[1])) // с аргументом и сразу переход
				exit_cd_2(temp->argv[1]); // выходим с ошибкой, если неправильный путь
		}
		else
			exec_cmd(temp, env); // если не cd выполняем команду
		temp = temp->next;
	}
}

/*
**====================================
**============Part main===============
**====================================
*/

void free_all(t_base *ptr) // очистка памяти
{
	t_base *temp;
	int i;

	while (ptr)
	{
		temp = ptr->next;
		i = 0;
		while (i < ptr->size)
			free(ptr->argv[i++]);
		free(ptr->argv);
		free(ptr);
		ptr = temp;
	}
	ptr = NULL;
}

int main(int argc, char **argv, char **env)
{
	t_base *ptr = NULL;
	int i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
    	{
            if (strcmp(argv[i], ";") == 0) // если это ; то скипаем
            {
                i++;
                continue ;
            }
    	    i += parser_argv(&ptr, &argv[i]); // создаем новый список команд, парсим, возвращаем кол-во команд
    	    if (!argv[i])
    	        break;
    	    else
    	        i++;
    	}
		if (ptr) // если что-то в списке есть
			exec_cmds(ptr, env); // выполнение команд
		free_all(ptr); // очищаем всегда, в любом случае
	}
	return (0);
}

/*

0.0 Подключаем необходимые библиотеки
0.1 Пишем константы для дефолтных fd и для типов (конец, |, ;)
0.2 Объявляем структуру под команду
0.3 Пишем свои ft_strlen и ft_strdup
1.0 Начинаем писать мейн, создаем переменные для начала структуры и итератор по аргументам
1.1 Начинаем писать парсер: пишем сначала функцию, считающую кол-во аргументов (не конец, не |, не ;)
1.2 Выделяем память под структуру и массив для аргументов char** длиной size
1.3 Создаем новую структуру cmd записываем туда важную информацию: size, обнуляем указатели, переписываем все аргументы
1.4 Записываем в новую структуру тип конца команды (конец, |, ;)
1.5 Закидывем структуру в конец списка через написанную функцию lst_add_back
2.0 В мейне пропускаем все пройденные аргументы. 
2.1 Если есть комманды, то запускаем выполнение
2.2 Проходим все структуры по списку
	2.2.1 Если команда cd то проверяем все ли ок (иначе выходим) и выполняем chdir (смена директории)
	2.2.2 Д
*/