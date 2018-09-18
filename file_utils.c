#include <stdio.h>
#include <sys/stat.h>

/*******************************************
 * Function that reads a file
 * Allocates memory for file (free'd in reverse.c main)
 ******************************************/
int read_file(char* filename, char **buffer){
	FILE* in = fopen(filename, "r");
	
	struct stat st;
	int fileExists = stat(filename,&st);
	int size = st.st_size;
	if(size == 0){
		fprintf(stderr, "File size error \n");
		return -1;
	}

	//Allocate memory using malloc
	*buffer = malloc(size * sizeof(char));
	fread(*buffer,sizeof(char),size,in);	
	fclose(in);

	return 1;	
}

/***********************************************
 * function that writes file in reverse
 * Use library function fputc to write
***********************************************/
int write_file(char* filename, char *buffer, int size){
	FILE* out = fopen(filename, "w");
	int i = size-1;
	while(i >= 0){
		fputc(buffer[i], out);
		i--;
	}
	fclose(out);
	return 1;
}
