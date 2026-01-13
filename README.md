*This project has been created as part of the 42 curriculum by mmohamm2*

##NAME
	get_next_line – read line from a give file descriptor. 

##SYNOPSIS

	#include “get_next_line.h”
	OR
	#include “get_next_line_bonus.h”
	
	char	*get_next_line(int fd);

##Description

	The get_next_line() function reads given file until it finds a new line
	character, create a array for the line and returns pointer to the array.
	If the fd 0 or Negative value get_next_line returns NULL. 
	
	The pointer get_next_line() return can be freed using free(). 
	
	The get_next_line() only allocates memory for the array it returns
	and the buffer read additionally from the file.

##Instructions

	The get_next_line() requires file descriptor to read the file. The file
	file descriptor can be created using the open(“filepath”, “MODE”).
	
	The OPEN() will return a int which can be passed to the get_next_line to
	read a line.

##RETURN VALUE
	The get_next_line() returns pointer to array if valid file descriptor 
	provide which has data to read. 

	The get_next_line() returns NULL pointer if there nothing to read or any 
	error occurred during the file reading. 

##compile instruction
	Import the get_next_line header file into the main program.
	#import "get_next_line.h"

	Char *x;
	X = get_next_line(fd);

	Compliation
	cc -Wall -Werror -Wextra -D BUFFER_SIZE <main> get_next_line.c get_next_line_utils.c

	Modify the standard name with a bonus to compile it with a bonus.


##Detailed Explaination of the Programm

The get_next_line function takes in a file discripter as input, (FYI, in order to access a file in c
Program, we can use the open() function, which makes the system call and returns a file descriptor, which refers
To the entry in the file descriptor table).

The get_next_line function utilized the read() function to read the data from the file descriptor.
The read command needs three inputs to work, such as file descriptor, buffer, and reading buffer size.
The read function will read data from the file descriptor to each end of the file.
If it is a valid file descriptor.

The get_next_line function should only print line by line. As mentioned. There is no guarantee
That it read exactly one line, it could read more that, in that case, it should return only the
Line and store excess to store that get_next_line utilizes the static variable.

This implementation uses an array as a data structure which is easier to traverse through and there is no
Need insert to delete in the middle of the struct. The array seems to be a simple and effective data structure to
Solve this issue. It's possible to implement this function using a link list, but as the design of the log,
There are a few places in the logic that functions to access the elements of the array using index. Array are
Much more effective compared to the linked list. 

The get_next_line has around 10 helper functions, each handling a specific task.

Get_next_line → main function that calls the other helper functions.

Ft_filereader → this function is responsible for the reading of the file and joining the buffer if it has one.

Ft_strjoin → This works as part of ft_filereader to join the read buffer and existing buffer.

Ft_hasline → this function takes a buffer, char, as input to check if that char is present in the buffer.

Ft_strlen → This function works as a helper for a few functions, such as the ft_strjoin and  ft_buffer functions.

Ft_calloc → this function works as standard ft_call (memory allocation and initiation).

Ft_memmove → this simple function copies the data pointed by the src pointer to the destination pointer.

Ft_line → this function is another import function which extracts the line and separates the exact data returned from 
the ft_filereader function.

Ft_buff → This function works in polar opposite to the ft_line. It extracts the excess data stored in the buffer 
and frees the input pointer.

The Get_next_line bonus works almost the same, but it can work with multiple files at the same time, when reading multiple files.
The function should be able to keep track of each file exces buffer. An array of pointer techniques is used to solve that.
In the bonus part.


Resources
<a name="GeekforGeeks">https://www.geeksforgeeks.org/c/static-variables-in-c/</a>
<a name="C Programming Book">https://colorcomputerarchive.com/repo/Documents/Books/The%20C%20Programming%20Language%20%28Kernighan%20Ritchie%29.pdf</a>
	
