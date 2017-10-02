/*
*Program Name: C_Project file_utils.h
*Name: Keith Rodgers
*Date: 9/20/17
*Description: Function signatures & gaurds included here
*/
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

//Function to read from input file
int read_file( char* filename, char **buffer );

//Function to write to output file
int write_file( char* filename, char *buffer, int size);

#endif