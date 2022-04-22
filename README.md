# printf
Alternate printf function by Feyitimi Victor and Ekaette Augustina Essien.
# Introduction
This project is a rebuild of the standard printf function in C capable of printing to standard output using the format specificiers %d, %c, %s, and %%. Using the function returns the number of characters printed (excluding the null byte at the end of strings). Flag characters, field width, precision, or length are not handled nor taken into account.
The format specificiers we added are %x ,%X, %b, %o, %u, %r, %R, and %p.
# Format Types (Types and Output)
TYPE - OUTPUT

c - char

s - String

r - reverse String

R - rot13 String 

d - Integer (decimal)

i - integer

% - Percent

Xl - Lowercase hex

X - Uppercase hex

b - binary

o - octal

u - unsigned

p - pointer

F - expletive
# Examples
Character: printf("%c", Z); Output:: Z

Integer: printf("%i", 34); Output: 34

String: printf("%s", Ooops, we printed a string to stdout!.); Output: Ooops, we printed a string to stdout!.




# Requirements
Allowed editors: vi, vim, emacs All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89 All your files should end with a new line A README.md file, at the root of the folder of the project is mandatory Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl You are not allowed to use global variables No more than 5 functions per file In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples The prototypes of all your functions should be included in your header file called main.h Don’t forget to push your header file All your header files should be include guarded Note that we will not provide the _putchar function for this project GitHub There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.
# Functions and Macros used include:
write (man 2 write) malloc (man 3 malloc) free (man 3 free) va_start (man 3 va_start) va_end (man 3 va_end) va_copy (man 3 va_copy) va_arg (man 3 va_arg)
# Collaborators
Feyitimi Victor
<br/>
Essien Ekaette
