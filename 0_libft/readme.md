# libft
[Subject](https://cdn.intra.42.fr/pdf/pdf/51637/en.subject.pdf)

***125/100 SUCCESS***

---

## Goal of a project

`C` programming can be very tedious when one doesn’t have access to the highly useful
standard functions. We will create our own library.

## Why is *libft* important?

This project is about understanding the way these functions work,
implementing and learning to use them. It will be helpful since you will use it in your next `C` assignments.

## Mandatory:

- We must write our own function implementing the following original ones. They do not require any external functions:

 1 | 2 | 3 | 4
--- | --- | --- | ---
isalpha | isdigit | isalnum | isascii
isprint | strlen | memset | bzero
memcpy | memmove | strlcpy | strlcat
toupper | tolower | strchr | strrchr
strncmp | memchr | memcmp | strnstr
atoi | calloc | strdup

- Create additional functions

Func | Desctiption
--- | ---
ft_substr | Allocates and returns a substring from the string ’s’.
ft_strjoin | Allocates and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
ft_strtrim | Allocates and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
ft_split | Allocates and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.
ft_itoa | Allocates and returns a string representing the integer received as an argument.
ft_strmapi | Applies the function ’f’ to each character of the string ’s’, and passing its index as first argument to create a new string resulting from successive applications of ’f’.
ft_striteri | Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument.
ft_putchar_fd | Outputs the character ’c’ to the given file descriptor.
ft_putstr_fd | Outputs the string ’s’ to the given file descriptor.
ft_putendl_fd | Outputs the string ’s’ to the given file descriptor followed by a newline.
ft_putnbr_fd | Outputs the integer ’n’ to the given file descriptor.


## Bonus:

- Implement the following functions in order to easily use your lists:

Func | Desctiption
--- | ---
ft_lstnew | Allocates and returns a new node. The member variable ’content’ is initialized with the value of the parameter ’content’.
ft_lstadd_front | Adds the node ’new’ at the beginning of the list.
ft_lstadd_back | Adds the node ’new’ at the end of the list.
ft_lstsize | Counts the number of nodes in a list.
ft_lstlast | Returns the last node of the list.
ft_lstdelone | Takes as a parameter a node and frees the memory of the node’s content using the function ’del’ given as a parameter and free the node. The memory of ’next’ must not be freed.
ft_lstclear | Deletes and frees the given node and every successor of that node, using the function ’del’ and free. Finally, the pointer to the list must be set to NULL.
ft_lstiter | Iterates the list ’lst’ and applies the function ’f’ on the content of each node.
ft_lstmap | Iterates the list ’lst’ and applies the function ’f’ on the content of each node. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed.


---
# ru:libft

[Задание](https://cdn.intra.42.fr/pdf/pdf/51637/en.subject.pdf)

Проверено на ***125/100 SUCCESS***

---

## Цель проекта

Создать свою библиотеку необходимых функций для использования в дальнейшем.

## Почему *libft* важен?

Данный проект позволяет нам понять и реализовать базовые библиотечные функции, а также научиться использвать их. Наша библиотека с такими функциями будет использоваться нами в дальнейших проектах. 

## Обязательная часть

- Мы должны написать свои функции, которые должны имплементировать работу оригинальных. Они не должны содержать сторонних функций: 

 1 | 2 | 3 | 4
--- | --- | --- | ---
isalpha | isdigit | isalnum | isascii
isprint | strlen | memset | bzero
memcpy | memmove | strlcpy | strlcat
toupper | tolower | strchr | strrchr
strncmp | memchr | memcmp | strnstr
atoi | calloc | strdup

- Создать дополнительные функции:

Функция | Описание
--- | ---
ft_substr | Выделяет память и возвращает подстроку из строки ’s’.
ft_strjoin | Выделяет память и воозвращает новую строку, полученная при конкатенации строк ’s1’ и ’s2’.
ft_strtrim | Выделяет память и возвращает копию строки ’s1’  с удаленными символами из набора ’set’ с начала и конца строки.
ft_split | Выделяет память и возвращает массив строк, полученных при делении строки ’s’, используя символ ’c’ как разделитель.
ft_itoa | Выделяет память и возвращает строковое представление переданного целого числа.
ft_strmapi | Применяет функцию ’f’ к каждому символу строки string ’s’,и создает новую строку после успешного применения функции ’f’.
ft_striteri | Применяет функцию ’f’ к каждому символу переданной строки.
ft_putchar_fd | Выводит символ ’c’ в переданный файловый дескрипто.
ft_putstr_fd | Выводит строку ’s’ в переданный файловый дескриптор.
ft_putendl_fd | Выводит строку ’s’ в переданный файловый дескриптор со последующим '\n'.
ft_putnbr_fd | Выводит целое число ’n’ в переданный файловый дескрипто.

## Бонусная часть

- Реализовать следующие функции:

Функция | Описание
--- | ---
ft_lstnew | Выделяет память и возвращает новый элемент списка.
ft_lstadd_front | Добавляет новый элемент ’new’ в начало списка.
ft_lstadd_back | Добавляет новый элемент ’new’ в конец списка.
ft_lstsize | Считает кол-во элементов в списке.
ft_lstlast | Возвращает последний элемент списка.
ft_lstdelone | Очищает содержимое элемента, применяя функцию ’del’.
ft_lstclear | Очищает переданный элемент списка используя функции ’del’ и free(3). В конце, указатель на список должен быть NULL.
ft_lstiter | Применяет функцию ’f’ к содержимому всех элементов списка ’lst’.
ft_lstmap | Создает новый список, как результат успешного выполнения функции ’f’ к содержимому всех элементов списка ’lst’. Фунция ’del’ удаляет содержимое элемента, если необходимо.

--- 

### Misc

- [C Library - <stdlib.h>](https://www.tutorialspoint.com/c_standard_library/stdlib_h.htm)
- [C Library - <string.h>](https://www.tutorialspoint.com/c_standard_library/string_h.htm)