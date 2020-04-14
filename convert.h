/*
 * FASTA file processing
 * FASTA = FAST alignment
 * we need following functions:
 * 1. read fasta file - save comment and dna into diff realloc-able arrays 
 * 2. DnatoRna - complement the bases in the file
 * 3. base to amino acid - replace every 3 bases with their respective amino acid
 * 4. write to another fasta file (write with comments )
 * 5. Main function
 *
*/

#define COLOR_RED     \x1b[31m
#define COLOR_GREEN   \x1b[32m
#define COLOR_YELLOW  \x1b[33m
#define COLOR_BLUE    \x1b[34m
#define COLOR_MAGENTA \x1b[35m
#define COLOR_CYAN    \x1b[36m
#define COLOR_RESET   \x1b[0m

/*
 * printf("COLOR_RED Hello, FASTA!\n COLOR_RESET"); 
 * prints "Hello, FASTA!" in red color
*/

typedef struct FASTA{
	char *data;
	char *comments;
        char *protein;
        char *non-protein;
}FASTA;

/*read the file and load into FASTA data struct, make sure that every string is 120 chars long*/
void readfile(int fd, FASTA *strand);

/*Complement each base in the same string*/
void DNAtoRNA(FASTA *strand);

/*base to amino acid ( where is the comparison chart ? )*/
void BtoAA(FASTA *strand);

/*writes comment followed by a newline and then the amino acid Abbrv.*/
void writefile(int fd, FASTA *strand);

/*main is supposed to call these functions*/

/*
 * We need progress bars
 * colors !
 *
*/
