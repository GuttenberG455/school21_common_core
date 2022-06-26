# Module 00
[Subject]([https://cdn.intra.42.fr/pdf/pdf/52147/en.subject.pdf])

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_00.pdf)

***100/100 SUCCESS***

---
## Project topics:
Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff

## List of exercises:
* ### ex00: Megaphone
Program converts input parameter to uppercase.

* ### ex01: My Awesome PhoneBook
You have to implement two classes:
- PhoneBook
  - It has an array of contacts.
  - It can store a maximum of 8 contacts. If the user tries to add a 9th contact, replace the oldest one by the new one.
- Contact
  - Stands for a phonebook contact. </br>

On program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT.
- ADD: save a new contact
  - If the user enters this command, they are prompted to input the information of the new contact one field at a time. Once all the fields have been completed, add the contact to the phonebook.
  - The contact fields are: first name, last name, nickname, phone number, and darkest secret. A saved contact can’t have empty fields.
- SEARCH: display a specific contact
  - Display the saved contacts as a list of 4 columns: index, first name, last name and nickname.
  - Each column must be 10 characters wide. A pipe character (’|’) separates them. The text must be right-aligned. If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot (’.’).
  - Then, prompt the user again for the index of the entry to display. If the index is out of range or wrong, define a relevant behavior. Otherwise, display the contact information, one field per line.
- EXIT
  - The program quits and the contacts are lost forever!
Any other input is discarded. Once a command has been correctly executed, the program waits for another one. It stops when the user inputs EXIT.

* ### ex02: The Job Of Your Dreams
We to recreate the Account.cpp file. Our program should pass the tests. Its output should match the one saved in the log file (except for the
timestamps).
