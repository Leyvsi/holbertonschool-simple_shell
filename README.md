# Simple Shell

**Simple Shell** is a minimal Unix command interpreter written in C, developed as part of the  
**Holberton School – Simple Shell** project.

The goal of this project is to understand how a shell works internally by implementing
basic features such as command execution, process creation, and environment handling.

---

## 📌 Description

This project implements a simple version of a Unix shell.
It reads user input, parses commands and arguments, searches for executables in the `PATH`,
and executes them using system calls.

The shell works in both **interactive** and **non-interactive** modes.


## 🚀 Features

- Interactive mode with a prompt
- Non-interactive mode (input from pipe or file)
- Execution of external commands
- Executable path resolution using `$PATH`
- Built-in command support (`exit`)
- Basic error handling


## 📦 Project Structure

-AUTHORS # List of project authors
-shell.h # Main header (prototypes, structs, macros)

-shell.c # Main shell loop
-exec.c # Command execution (fork, execve, wait)
-builtins.c # Built-in commands (exit)

-get_env.c # Environment variable handling
-get_full_path.c # Resolve executable path using PATH

-tokenize.c # Command line tokenization
-error.c # Error handling and messages

-test.sh # Test script
-hsh # Compiled shell binary
-README.md # Project documentation


## 🛠 Compilation

Compile the project using `gcc`:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

🧑‍💻 Usage
Interactive mode
./hsh

Example 
($) /bin/ls
shell.c exec.c tokenize.c
($) exit

Non-interactive mode
echo "/bin/ls" | ./hsh

🧪 Testing

You can use the provided test script:

./test.sh

Or redirect input:

./hsh < test.sh

📋 Built-in Commands

exit — exits the shell

📚 Environment

Uses environment variables

Searches executables using the PATH variable

🧑‍💻 Authors

Leyvsi
Melissa9513
AlexLucM

<img width="509" height="764" alt="Capture d&#39;écran 2026-01-11 204752" src="https://github.com/user-attachments/assets/1a1ecd1d-e990-4023-ad13-f16c4dc83069" />

