/*
*Program Name: C_Project file_utils.c
*Name: Keith Rodgers
*Date: 9/20/17 
*Note that this(http://www.sanfoundry.com/c-program-reverse-file-contents/) code was referenced.
*Description: code implemented here
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <malloc.h>
#include "file_utils.h"

//Function to read from input file
int read_file( char* filename, char **buffer )
{
	//declare file and struct to determine size
	FILE * file_ip;
	struct stat st;

	//open file, if valid input continue
	file_ip = fopen(filename, "r");
	if(file_ip != NULL)
	{
		//determine size of file
		stat(filename, &st);
		int size = st.st_size;

		//allocate memory to buffer & read file
		*buffer = malloc(size * sizeof(char));
		fread(*buffer, size, 1, file_ip);

		//close file, return size of file
		fclose(file_ip);
		return size;
	}
	else
	{
		//invalid input
		fprintf( stderr, "Value of errno: %d\n", errno );
		return 0;
	}
}

//Function to write to output file
int write_file( char* filename, char *buffer, int size)
{
	FILE * file_op;
	file_op = fopen(filename, "w");

	//if buffer empty error out
	if(buffer == NULL)
	{
		fprintf( stderr, "Value of errno: %d\n", errno );
		return 0;
	}

	//reverse order and write to file
	int i;
	for(i = 1; i <= size; ++i)
	{
		fwrite(buffer + (size - i), 1, 1, file_op);
	}

	//if file empty, error out
	if(file_op == NULL)
	{
		fprintf( stderr, "Value of errno: %d\n", errno );
		return 0;
	}

	//close file
	fclose(file_op);
	return 0;
}