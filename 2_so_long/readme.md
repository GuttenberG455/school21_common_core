# so_long
[Subject](https://cdn.intra.42.fr/pdf/pdf/47280/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_2_so_long.pdf)

***100/100 SUCCESS***. No bonus

---

## Goal of a project

We must create a basic 2D game in which a hero
escapes the map after collecting all collectibles. We are going to use MiniLibX functions.

## Why is *so_long* important?

This project will help you improve your skills in the following areas: window management,
event handling, colors, textures, file parsing and so forth.

## Mandatory:

- The player’s goal is to collect every collectible present on the map, then escape.
- The *W*, *A*, *S*, and *D* keys must be used to move the main character.
- The player should be able to move in these 4 directions: up, down, left, right and should not be able to move into walls.
- The map has to be constructed with components: walls, collectibles, exits, player's position and freespace. 
- The map must be rectangular and contain at least 1 exit, 1 collectible, and 1 starting position.

## Bonus

- Some sprite animation (mlx_loop_hook)
- Display the movement count directly on screen (mlx_string_put)
- Enemy patrols


---
# ru:so_long

[Задание](https://cdn.intra.42.fr/pdf/pdf/47280/en.subject.pdf)

[Лист проверки](https://github.com/mharriso/school21-checklists/blob/master/ng_2_so_long.pdf)

Проверено на ***100/100 SUCCESS***. Без бонуса

---

## Цель проекта

Мы должны написать простенькую 2d игру, в которой главный герой должен выйти с карты, при этом собрать все объекты сбора. Будем использовать простую MiniLibX библиотеку.

## Почему *so_long* важен?

Данный проект помогает поднять уровень знаний в следущих областях: операции с окнами, обработчик событий, цвета, текстуры и т.д.

## Обязательная часть

- Задача игрока: собрать все объекты и выйти с карты через выход
- Клавиши *W*, *A*, *S*, и *D* должны использоваться для перемещения персонажа вверх, влево, вниз, вправо и герой не должен проходить сквозь стены.
- Карта состоит из элементов: стена, собираемый предмет, выход, стартовая позиция игрока и пустое пространство.
- Карта должна быть прямоугольной и содержать одну стартовую позицию, и как минимум один собираемый предмет и выход. 

## Бонусная часть

- Добавить спрайтовую анимацию.
- Вражеские патрули, убивающего главного героя.
- Вывод кол-во шагов на окно, а не в консоль.

--- 

### Misc

- [MiniLibx - 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx)
- [ft_libgfx AKA b_gfx overload](https://github.com/qst0/ft_libgfx)