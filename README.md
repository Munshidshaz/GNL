This project has been created as part of the 42 curriculum by mmohamm2

NAME
	get_next_line – read line from a give file descriptor. 

SYNOPSIS

	#include “get_next_line.h”
	OR
	#include “get_next_line_bonus.h”
	
	char	*get_next_line(int fd);

Description

	The get_next_line() function reads given file until it finds a new line
	character, create a array for the line and returns pointer to the array.
	If the fd 0 or Negative value get_next_line returns NULL. 
	
	The pointer get_next_line() return can be freed using free(). 
	
	The get_next_line() only allocates memory for the array it returns
	and the buffer read additionally from the file.

Instructions

	The get_next_line() requires file descriptor to read the file. The file
	file descriptor can be created using the open(“filepath”, “MODE”).
	
	The OPEN() will return a int which can be passed to the get_next_line to
	read a line.

RETURN VALUE
	The get_next_line() returns pointer to array if valid file descriptor 
	provide which has data to read. 

	The get_next_line() returns NULL pointer if there nothing to read or any 
	error occurred during the file reading. 

Resources
https://www.geeksforgeeks.org/c/static-variables-in-c/
https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20%28Kernighan%20Ritchie%29.pdf
	
