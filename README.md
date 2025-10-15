Academic implementation of linked lists in C language.

## 📘 Description
**ListC** is an educational project developed for the Computer Science course at UFPR(Universidade Federal do Paraná - Federal University of Paraná).  
It implements basic operations on singly linked lists in C, focusing on learning dynamic memory management and pointer manipulation.

## 🧩 Project Structure
| File | Description |
|------|--------------|
| **lista.h** | Header file defining function and structures prototypes (with documentation). |
| **lista.c** | Implementation of the functions and structures declared in `lista.h`. |
| **tp4.c** | Main file used for testing — includes cases that intentionally trigger errors. |
| **saida_esperada.txt** | File containing the expected output for the tests in `tp4.c`. |
| **testa.sh** | Bash script that compares program output with `saida_esperada.txt` and runs Valgrind to check for memory leaks. |
| **makefile** | Contains basic build and clean commands for compilation and object file management. |

---

## ⚙️ Compilation and Execution

You can build and test the project manually or using the provided **Makefile**.

## ▶️ Compile
```bash
make

## ▶️ Run the tests
```bash 
./tp4

## 🧪 Automated test script
```bash
./testa.sh 1

This script will compare the output of your program with the expected output in 'saida_esperada.txt'.

```bash
./testa.sh 2

this script will run Valgrind to detect possible memory leaks.

🧹 Clean object files
```bash
make clean

Other Uses of makefile

You can see the defined functions written in the file 'makefile' and bash:
make command

📚 Example Functions
. *lista_cria();
. lista_destroi();
. lista_insere_inicio();
. lista_insere_fim();
. lista_insere_ordenado();
. lista_remove_inicio();
. lista_remove_fim();
. lista_remove_ordenado();

🧠 Objective 
This project was developed as part of the Computer Science course assignment of UFPR.

It aims to strengthen understanding of:

. Dynamic memory allocation in C;
. Linked list manipulation;
. Testing and debugging with Valgrind and shell scripts.

✏️ Author
Hyam-M.
Academic project – for learning purposes only.
