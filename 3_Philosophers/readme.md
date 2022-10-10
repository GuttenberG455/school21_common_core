# Philosophers
[Subject](https://cdn.intra.42.fr/pdf/pdf/47291/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_philosophers.pdf)

***125/100 SUCCESS***

---

## Goal of a project

Simulate a lifecycle of philosphers, their eating, sleeping and waiting states, using limited resources (forks).
They should avoid dying. Simulation ends, when all philosophers ate certain times, or one of philosopher died.

## Why is *Philosophers* important?

*Philosophers* is simple project which allows you to learn about multithreading, multiprocessing, mutexes and threads.  

## Mandatory:

-  Each philosopher should be a thread.
-  There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, there should be only one fork on the table.
-  To prevent philosophers from duplicating forks, you should protect the forks state
with a mutex for each of them

## Bonus

-  Each philosopher should be a process. But the main process should not be a
philosopher.
-  All the forks are put in the middle of the table.
-  They have no states in memory but the number of available forks is represented by
a semaphore.


---
# ru:Philosophers

[Задание](https://cdn.intra.42.fr/pdf/pdf/47291/en.subject.pdf)

[Лист проверки](https://github.com/mharriso/school21-checklists/blob/master/ng_4_philosophers.pdf)

Проверено на ***125/100 SUCCESS***

---

## Цель проекта

Симулировать жизненный цикл философов, их приемы пищи, сон и процесс ожидания, используя ограниченные ресурсы (вилки),
таким образом, чтобы они максимально долго старались жить. Симуляция заканчивается, когда поели достаточное кол-во раз или
один из философов умер. 

## Почему *Philosophers* важен?

Данный проект дает возможность познакомиться с многопоточностью, паралелльным программированием, средствами синхронизации
доступа к ресурсам.

## Обязательная часть

- Каждый философ должен быть потоком. 
- Одна вилка на каждого философа, каждая вилка лежит между двумя философами.
- В качестве средства синхронизации доступа к ресурсу используются мьютексы.

## Бонусная часть

- Каждый философ являются процессом. Но главный процесс не является философом.
- Все вилки лежат в центре стола.
- В качестве средства синхронизации доступа к ресурсу используются семафоры

--- 

### Misc

- [Unix2019b/Библиотека pthreads](https://acm.bsu.by/wiki/Unix2019b/%D0%91%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA%D0%B0_pthreads)
- [В чем разница между мьютексом, монитором и семафором](https://javarush.ru/groups/posts/2174-v-chem-raznica-mezhdu-mjhjuteksom-monitorom-i-semaforom)
- [Philosophers visualizer](https://nafuka11.github.io/philosophers-visualizer/)
- [Dining Philosopher Problem Using Semaphores](https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/)