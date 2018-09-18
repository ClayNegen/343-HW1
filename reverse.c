#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

/*********************************
 * Main method to read file, reverse it,
 * and write it to a different file.
 *
 * Free allocated memory for @param buffer
 *
 * @author Clay Negen
 ********************************/

int main (int argc, char** argv){
	char* buffer;
	char ch;
	struct stat st;
	stat(argv[1], &st);
	int size = st.st_size;	
	buffer = malloc(size);
	
	//Error handling for command line arguments
	if (argc != 3){
		fprintf(stderr, "Please provide 2 file names \n");
		exit(1);
	}

	//Read in file contents
	int read = read_file(argv[1], &buffer);
	if (read < 0)
	{
		fprintf(stderr, "File does not exist \n");
	}
	
	//Writes contents reversed into new file	
	int write = write_file(argv[2], buffer, size);

	printf("Completed write \n");
	free(buffer);
	return 1;
}

