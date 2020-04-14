#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "convert.h"


int main(int argc, char const *argv[]){
	
	if(argc != 2){
		printf("ERROR: USAGE: ./convert <filename.fasta> <output.fasta>\n");
		return 0;
	}
	int fd1 = open(fd, argv[1], O_RDWR);
	if(fd1 == -1){
		perror("FILE ERROR :");
		return errno;
	}


	char newname[60];
	newname = strcat(newname, "AminoAcid_");
	newname = strcat(newname, argv[1]);


	int fd2 = open(fd, newname, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if(fd2 == -1){
		perror("FILE ERROR :");
		return errno;
	}


	FASTA *strand;
	strand = (strand *)malloc(sizeof(FASTA));


	readfile(fd1, strand);
	DNAtoRNA(strand);
	BtoAA(strand);

	writefile(fd2, strand);

	return 0;
}