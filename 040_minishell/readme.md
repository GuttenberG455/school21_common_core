# minishell
[Subject](https://cdn.intra.42.fr/pdf/pdf/43461/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_3_minishell.pdf)

***100/100 SUCCESS***

---

## Goal of a project

This project is about creating a simple shell, little bash. 

## Why is *minishell* important?

During the completing this project, we will learn how the bash works: processes, signals, file descriptors, environment, builtin functions.

## Mandatory:

Your shell should:
- Display a **prompt** when waiting for a new command.
- Have a working **history**.
- Search and launch the right executable (based on the `PATH` variable or using a relative or an absolute path).
- Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).
- Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
- Implement **redirections**:
	- < should redirect input.
	- > should redirect output.
	- << should be given a delimiter, then read the input until a line containing the delimiter is seen.
	- >> should redirect output in append mode.
- Implement **pipes** (| character). The output of each command in the pipeline is connected to the input of the next command via a pipe.
- Handle **environment variables** ($ followed by a sequence of characters) which should expand to their values.
- Handle $? which should expand to the exit status of the most recently executed foreground pipeline.
- Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
- In interactive mode:
	- ctrl-C displays a new prompt on a new line.
	- ctrl-D exits the shell.
	- ctrl-\ does nothing.
- Your shell must implement the following **builtins**:
	- `echo` with option -n
	- `cd` with only a relative or absolute path
	- `pwd` with no options
	- `export` with no options
	- `unset` with no options
	- `env` with no options or arguments
	- `exit` with no options  

## Bonus

Your program has to implement:
- && and || with parenthesis for priorities.
- Wildcards * should work for the current working directory.

### Mistakes

- Wrong output of `echo` command with many options (-n)
- Shell doesn't use limited amount of file descriptors (piping one time at the start)

---
# ru:minishell

[Задание](https://cdn.intra.42.fr/pdf/pdf/43461/en.subject.pdf)

[Лист проверки](https://github.com/mharriso/school21-checklists/blob/master/ng_3_minishell.pdf)

Проверено на ***100/100 SUCCESS***

---

## Цель проекта

Цель проекта - написать собственный bash, оболочку операциионной системы (shell). 

## Почему *minishell* важен?

Во время выполнения этого проекта, мы узнаем, как работает bash: процессы, сигналы, редиректы, файловые дескрипторы, переменные окружающей среды.

## Обязательная часть

Наш shell долежн:
- Показывать строку **prompt**, когда ожидает ввода новой команды.
- Иметь рабочую **history**.
- Искать и запускать исполняемые файлы (основаны на переменной `PATH` или используюется относительный или глобальный пути).
- Не интепретировать незакрытые кавычки или специальные символы как \ и ;
- Обработать ’ (одиночную кавычку) которая должна предотвратить shell интерпретировать метасимволы в последовательности в кавычках.
- Обработать " (двойные кавычку) которая должна предотвратить shell интерпретировать метасимволы в последовательности в кавычкая, не считая $ (знак доллара).
- Имплементировать **redirections**:
	- < должен перенаправить ввод (input).
	- > должен перенаправить вывод (output).
	- << должен быть дан разделитель, затем считывать ввод, пока не будет строки, содержащей разделитель.
	- >> должен перенаправить вывод (output) в режиме добавления.
- Имплементировать **pipes** (| символ). Вывод команды должен быть направлен в ввод следущей команды, связанных пайпом.
- Обработать **environment variables** ($), которые должны вернуть свое значение по параметру.
- Обработать $? , которое должно вернуть статус выхода последней запущенной команды.
- Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
- В интерактивном режиме:
	- ctrl-C отображает prompt на новой строке.
	- ctrl-D должен выйти из shell.
	- ctrl-\ ничего не делает.
- Имплементировать следующие **builtins**:
	- `echo` с опцией -n
	- `cd` только с относительным или глобальным путем
	- `pwd` без опций
	- `export` без опций
	- `unset` без опций
	- `env` без опций или аргументов
	- `exit` без опций

## Бонусная часть

В программе должны быть реализованы:
- && и || со скобками для приоритета.
- Wildcards * должны работать для текущей директории.

### Ошибки

- Неправильный вывод фунции `echo` с нескольким количеством опции(-n)
- Shell не использует ограниченное кол-во файловых дескрипторов (pipes прокладываются один раз, в начале)

--- 

### Misc

- []()