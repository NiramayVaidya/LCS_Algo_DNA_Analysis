#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1
#define NW 2
#define W 3
int charcount(char file[]);
int charsep(char file1[], char file2[]);
void mylcs(char *x, char *y);
void printlcs(int **dir, char *x, int i, int j);

int noc1, noc2;

int main(int argc, char *argv[]) {
	char *file[2];
	file[0] = argv[1];
	file[1] = argv[2];

	noc1 = charcount(file[0]);
	noc2 = charcount(file[1]);
	charsep(file[0], file[1]);
}

int charsep(char file1[], char file2[]) {
	FILE *fp1;
	FILE *fp2;
	char *x, *y;
	int i = 0;
	int j = 0;

	fp1 = fopen(file1, "r");		
	fp2 = fopen(file2, "r");

	x = (char *)malloc(noc1 * sizeof(char));
	y = (char *)malloc(noc2 * sizeof(char));

	while(i <= noc1) {
		x[i] = fgetc(fp1);
		i++;
	}
	
	while(j <= noc2) {
		y[j] = fgetc(fp2);
		j++;
	}

	mylcs(x,y);

	return 0;
}


int charcount(char file[]) {
	FILE *fp = NULL;
	char ch;
	int count = 0;
	fp = fopen(file, "r");
	while ((ch = fgetc(fp)) != '\n')
		count++;

	fclose(fp);
	return count;
}


void mylcs(char *x, char *y) {
	int m, n;
	int i = 0;
	int j = 0;
	m = noc1;
	n = noc2;

	int **num, **dir;

	num = (int **)malloc(sizeof(int *) * (noc1 + 1));
	dir = (int **)malloc(sizeof(int *) * (noc1 + 1));

	for (i = 0; i <= m ; i++) {
		num[i] = (int *)malloc(sizeof(int) * (noc2 + 1));
		dir[i] = (int *)malloc(sizeof(int) * (noc2 + 1));
	} 
	for (j = 0; j <= n; j++) {
		num[0][j] = 0;
	}
	for (i = 0; i <= m; i++) {
		num[i][0] = 0;
	}

	for (i = 1; i <= m; i++) {				//LCS table being created here.
		for(j = 1; j <= n; j++) {
			if(x[i-1] == y[j-1]) {
				num[i][j] = num[i - 1][j - 1] + 1;
				dir[i][j] = NW;
			}
			else if(num[i - 1][j] >= num[i][j - 1]) {
				num[i][j] = num[i-1][j];
				dir[i][j] = N;
			}
			else {
				num[i][j] = num[i][j - 1];
				dir[i][j] = W;
			}
		}
	}
	i--;
	j--;
	printf("Sequence 1: %s\n", x);
	printf("Sequence 2: %s\n", y);
	printf("Length of the longest common subsequence: %d\n\n", num[i][j]);
	printf("Position in sequence 1 | Position in sequence 2 | LCS\n");
	printf("-----------------------------------------------------\n");
	printlcs(dir, x, i, j);
	printf("-----------------------------------------------------\n");
	printf("\n\n");

	for(i = 0; i < noc1; i++) {
		free(num[i]);
		free(dir[i]);
	}
	free(num);
	free(dir);	
}

void printlcs(int **dir, char *x, int i, int j) {
		char *s = x;
		int **di = dir;
		int a = i;
		int b = j; 
		if(a == 0 || b == 0)
			return;
		if(di[a][b] == NW) {
			printlcs(di, s, a - 1, b - 1);
			printf("%10d             | %11d            |", a, b);
			printf("%3c\n", s[a - 1]); 
		}
		else if(di[i][j] == N)
			printlcs(di, s, a - 1, b);

		else printlcs(di, s, a, b - 1);
}