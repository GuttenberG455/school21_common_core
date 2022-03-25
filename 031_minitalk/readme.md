# minitalk
[Subject](https://cdn.intra.42.fr/pdf/pdf/49236/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_2_minitalk.pdf)

***120/100 SUCCESS***

---

## Goal of a project

Create a communication program in the form of a *client* and a *server*. The *client* must send the string, to the *server*. The *server* must print it.

## Why is *minitalk* important?

This project introduce us to the signals and handlers. Event-driven programming is used here. 

## Mandatory:

- The client takes two parameters: server PID and string to send.
- The server has to display the string pretty quickly.
- You can only use these two signals: *SIGUSR1* and *SIGUSR2*.

## Bonus

- The server acknowledges every message received by sending back a signal to the client.
- Unicode characters support.

### Mistakes

- Disputes between subject and checklist: insufficient explanation of server acknowledgement.

---
# ru:minitalk

[Задание](https://cdn.intra.42.fr/pdf/pdf/49236/en.subject.pdf)

[Лист проверки](https://github.com/mharriso/school21-checklists/blob/master/ng_2_minitalk.pdf)

Проверено на ***120/100 SUCCESS***

---

## Цель проекта

Написать программу, состоящую из сервера и клиента. Клиент посылает сообщение с текстом по номеру процесса сервера, сервер должен вывести его на экран.

## Почему *minitalk* важен?

Данный проект знакомит нас с событийно-ориентированным программированием, сигналами и их обработчиками.

## Обязательная часть

- Клиент на вход получает два аргумента: ID процесса сервера и сообщение.
- Сервер должен достаточно быстро напечатать полученное сообщение
- Мы можем использовать только сигналы *SIGUSR1* и *SIGUSR2*

## Бонусная часть

- Поддержка символов Юникода
- Сервер должен обратно отправлять сигнал клиенту о получении сообщения.

### Ошибки

- Разногласия между заданием и листом проверки по существу обратной связи между сервером и клиентом.

--- 

### Misc

