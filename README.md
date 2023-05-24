# simple_shell
This project is a program that implements a simple command-line shell. Here is an overview of how it works:

The shell.h header file includes necessary libraries and declares function prototypes for the shell.

The main.c file contains the main function, which serves as the entry point of the program. It calls the lsh_loop function to start the command loop.

The lsh_loop function is responsible for running the command loop. It prompts the user for input, reads the input line using lsh_read_line, splits the line into tokens using lsh_split_line, and executes the command using lsh_execute. The loop continues until the lsh_execute function returns a status indicating that the shell should exit.

The lsh_execute function checks if the entered command is a built-in command (cd, help, or exit). If it is a built-in command, the corresponding function (lsh_cd, lsh_help, or lsh_exit) is executed. Otherwise, it calls the lsh_launch function to execute external commands.

The lsh_launch function forks a child process and executes the command in the child process. The parent process waits for the child process to complete.

The lsh_cd function handles the built-in cd command to change the current directory.

The lsh_help function displays information about the shell and the built-in commands.

The lsh_exit function terminates the shell program.

The lsh_read_line function reads input from the user. It uses getline if LSH_USE_STD_GETLINE is defined or falls back to reading character by character using getchar if LSH_USE_STD_GETLINE is not defined.

The lsh_split_line function splits the input line into tokens based on whitespace delimiters. It dynamically allocates memory for the token array and returns a NULL-terminated array of tokens.




