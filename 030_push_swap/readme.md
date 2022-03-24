# push_swap
[Subject](https://cdn.intra.42.fr/pdf/pdf/47284/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_2_push_swap.pdf)

***125/100 SUCCESS***

---

## Goal of a project

Sort integers in ascending order, using two stacks and some instructions.

## Why is *push_swap* important?

This project introduce us to the structure of stack - list LIFO (Last in - First out). Moreover, in this project we use dynamic programming: function that counts steps, necessary for putting number in the right place in the other stack.

## Mandatory:

- Program takes as an argument the first stack formatted as list of integers. The program must display the list of instructions possible to sort the stack.
- To do this we have several operations:
	- sa, sb: Swap the first 2 elements at the top of stack
	- ra, rb: Shift up all elements of stack a by 1.
	- rra, rrb:  Shift down all elements of stack a by 1.
	- pa, pb: Take the first element at the top of one stack and put it at the top of another

## Bonus

- Write a program named *checker* that takes as an argument the stack a formatted as a list of integers.
- It will then wait and read instructions on the standard input. Once all the instructions have been read, the program has to execute them on the stack received as an argument.
- If after executing those instructions, the stack a is actually sorted, then the program must display "OK", otherwise "KO"

---
# ru:push_swap

[Задание](https://cdn.intra.42.fr/pdf/pdf/47284/en.subject.pdf)

[Лист проверки](https://github.com/mharriso/school21-checklists/blob/master/ng_2_push_swap.pdf)

Проверено на ***125/100 SUCCESS***

---

## Цель проекта

Отсортировать стек целых чисел по возрастанию, используя второй стек и некоторые команды.

## Почему *push_swap* важен?

Данный проект дает знакомит нас со стеком - тип данных, представляющий собой список, организованный по принципу "Последним пришел - первым вышел". В данном проекте используется динамическое программирование: определяем необходимое кол-во шагов для каждого элемента стека, чтобы поставить его на нужное место в другой стек - и так каждый  раз после перемещения. 

## Обязательная часть

- На вход поступает последовательность целых чисел. Задача - отсортировать их по возрастанию.
- Изменять положение элементов в списке можем используя следующие команды:
	- sa, sb: Поменять местами два верхних элемента стека
	- ra, rb: Переместить верхний элемент стека в конец данного стека
	- rra, rrb: Переместить нижний элемент стека в начало данного стека
	- pa, pb: Переместить верхний элемент одного стека в начало другого
- Вывод программы представляет собой список команд

## Бонусная часть

- Задача - написать чекер - программу, проверяющую список команд для последовательности целых чисел, действительно ли данная комбинация команд отсортирует стек.  
- Команды поступают в стандартный ввод, после запуска программы с последовательностью чисел. Концом команд используется EOF.

--- 

### Misc
