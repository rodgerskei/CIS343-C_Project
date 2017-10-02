/*
*Program Name: C_Project reverse.c
*Name: Keith Rodgers
*Date: 9/20/17
*Description: User interface with code/main function
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "file_utils.h"

int main(int argc, char** argy)
{
	//declare files and buffer
	char* file_ip = argy[1];
	char* file_op = argy[2];
	char* buffer;

	//read file and return size of file
	int size = read_file(file_ip, &buffer);
	
	//reverse order and write to output file
	write_file(file_op, buffer, size);

	//free memory from malloc statement in file_utils.c
	free(buffer);

	return 0;
}