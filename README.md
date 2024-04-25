# Simple Shell
This project is a shell program developed in C language, providing a simple user interface for executing system commands.
## Description
This program implements an interactive shell allowing the user to execute system commands from a command-line interface. It supports several basic features such as executing simple commands, managing environment variables, and running system commands like ls -l.
## Requirements
### General 
 - Allowed editors: vi, vim, emacs
 - All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
 - All your files should end with a new line
 - A README.md file, at the root of the folder of the project is mandatory
 - Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
 - Your shell should not have any memory leaks
 - No more than 5 functions per file
 - All your header files should be include guarded
 - Use system calls only when you need to (why?)
### List of allowed funtions and system calls +
 - all functions from string.h
 - access (man 2 access)
 - chdir (man 2 chdir)
 - close (man 2 close)
 - closedir (man 3 closedir)
 - execve (man 2 execve)
 - exit (man 3 exit)
 - _exit (man 2 _exit)
 - fflush (man 3 fflush)
 - fork (man 2 fork)
 - free (man 3 free)
 - getcwd (man 3 getcwd)
 - getline (man 3 getline)
 - getpid (man 2 getpid)
 - isatty (man 3 isatty)
 - kill (man 2 kill)
 - malloc (man 3 malloc)
 - open (man 2 open)
 - opendir (man 3 opendir)
 - perror (man 3 perror)
 - printf (man 3 printf)
 - fprintf (man 3 fprintf)
 - vfprintf (man 3 vfprintf)
 - sprintf (man 3 sprintf)
 - putchar (man 3 putchar)
 - read (man 2 read)
 - readdir (man 3 readdir)
 - signal (man 2 signal)
 - stat (__xstat) (man 2 stat)
 - lstat (__lxstat) (man 2 lstat)
 - fstat (__fxstat) (man 2 fstat)
 - strtok (man 3 strtok)
 - wait (man 2 wait)
 - waitpid (man 2 waitpid)
 - wait3 (man 2 wait3)
 - wait4 (man 2 wait4)
 - write (man 2 write)
## Resources
 A list of exit status codes as applicable/situational.
 - [Exit Codes and Their Meanings](https://hpc-discourse.usc.edu/t/exit-codes-and-their-meanings/414)
 - [What are Exit Codes in Linux?](https://itsfoss.com/linux-exit-codes/)
 # files 
 - Shell.h : header.
 - simple_shell.C: main.
 - exec_commd.c: file Execute  command.
 - get_check.c: check if a specified enviromment variable.
 - get_execlp.c: execute a file with variable 
 - get_execvp.c: Search for an executable file in PATH and execute it
 - get_exit.c: exit
 - get_handle.c: ctrl + d.
 - get_recup.c: Construct a string with status, filename, and command.
 - get_run_ls-l.c: command ls -l
 - get_which.c: value of an enviromment variable.
 # Compilation du programme:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
# Execute
./hsh
# Result
![alt tag](https://github.com/Farelito/holbertonschool-simple_shell/blob/main/hsh.png)
# Contributors
- Antonin Paillasse(https://github.com/Antonin-crypto)
- Farel Jumelaisbakoumé(https://github.com/Farelito)
