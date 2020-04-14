void BtoAA(FASTA *strand) {
    char aa[4];
    char *ch, *prot, *non-prot;
    ch = strand->data;
    prot = strand->protein;
    non-prot = strand->non-protein;
    int i, j = 0, flag = 0;
    for(i = 0; *ch != '\0'; i++) {
        if(i % 3 == 0 && i != 0) {
            aa[j] = '\0';
            j = 0;
            if(!strcmp(aa, "AUG")) {
                printf("START codon\n");
                flag = 1;
            }
            if(!strcmp(aa, "UGA") || !strcmp(aa, "UAG")) {
                printf("STOP codon\n");
                flag = 0;
            }
            else if(!strcmp(aa, "UAA")) {
                printf("STOP codon\n");
                flag = 0;
            }
            if(flag) {
                if(!strcmp(aa, "GCU") || !strcmp(aa, "GCC")) {
                    *output = 'A';
                    printf("Amino acid Alanine found...\n");
                }
                else if(!strcmp(aa, "GCA") || !strcmp(aa, "GCG")) {
                    *output = 'A';
                    printf("Amino acid Alanine found...\n");
                }
                else if(!strcmp(aa, "CGU") || !strcmp(aa, "CGC")) {
                    *output = 'R';
                    printf("Amino acid Arginine found...\n");
                }
                else if(!strcmp(aa, "CGA") || !strcmp(aa, "CGG")) {
                    *output = 'R';
                    printf("Amino acid Arginine found...\n");
                }
                else if(!strcmp(aa, "AGA") || !strcmp(aa, "AGG")) {
                    *output = 'R';
                    printf("Amino acid Arginine found...\n");
                }
                else if(!strcmp(aa, "AUU") || !strcmp(aa, "AAC")) {
                    *output = 'N';
                    printf("Amino acid Asparagine found...\n");
                }
                else if(!strcmp(aa, "GAU") || !strcmp(aa, "GAC")) {
                    *output = 'D';
                    printf("Amino Aspartic acid found...\n");
                }
                else if(!strcmp(aa, "UGU") || !strcmp(aa, "UGC")) {
                    *output = 'C';
                    printf("Amino acid Cysteine found...\n");
                }
                else if(!strcmp(aa, "GAA") || !strcmp(aa, "GAG")) {
                    *output = 'E';
                    printf("Amino Glutamic acid found...\n");
                }
                else if(!strcmp(aa, "CAA") || !strcmp(aa, "CAG")) {
                    *output = 'Q';
                    printf("Amino acid Glutamine found...\n");
                }
                else if(!strcmp(aa, "GGU") || !strcmp(aa, "GGC")) {
                    *output = 'G';
                    printf("Amino acid Glycine found...\n");
                }
                else if(!strcmp(aa, "GGA") || !strcmp(aa, "GGG")) {
                    *output = 'G';
                    printf("Amino acid Glycine found...\n");
                }
                else if(!strcmp(aa, "CAU") || !strcmp(aa, "CAC")) {
                    *output = 'H';
                    printf("Amino acid Histidine found...\n");
                }
                else if(!strcmp(aa, "AUU") || !strcmp(aa, "AUC")) {
                    *output = 'I';
                    printf("Amino acid Isoleucine found...\n");
                }
                else if(!strcmp(aa, "AUA")) {
                    *output = 'I';
                    printf("Amino acid Isoleucine found...\n");
                }
                else if(!strcmp(aa, "UUA") || !strcmp(aa, "UUG")) {
                    *output = 'L';
                    printf("Amino acid Leucine found...\n");
                }
                else if(!strcmp(aa, "CUU") || !strcmp(aa, "CUC")) {
                    *output = 'L';
                    printf("Amino acid Leucine found...\n");
                }
                else if(!strcmp(aa, "CUA") || !strcmp(aa, "CUG")) {
                    *output = 'L';
                    printf("Amino acid Leucine found...\n");
                }
                else if(!strcmp(aa, "AAA") || !strcmp(aa, "AAG")) {
                    *output = 'K';
                    printf("Amino acid Lysine found...\n");
                }
                else if(!strcmp(aa, "AUG")) {
                    *output = 'M';
                    printf("Amino acid Methionine found...\n");
                }
                else if(!strcmp(aa, "UUU") || !strcmp(aa, "UUC")) {
                    *output = 'F';
                    printf("Amino acid PhenylAlanine found...\n");
                }
                else if(!strcmp(aa, "CCU") || !strcmp(aa, "CCC")) {
                    *output = 'P';
                    printf("Amino acid Proline found...\n");
                }
                else if(!strcmp(aa, "CCA") || !strcmp(aa, "CCG")) {
                    *output = 'P';
                    printf("Amino acid Proline found...\n");
                }
                else if(!strcmp(aa, "UCU") || !strcmp(aa, "UCC")) {
                    *output = 'S';
                    printf("Amino acid Serine found...\n");
                }
                else if(!strcmp(aa, "UCA") || !strcmp(aa, "UCG")) {
                    *output = 'S';
                    printf("Amino acid Serine found...\n");
                }
                else if(!strcmp(aa, "AGU") || !strcmp(aa, "AGC")) {
                    *output = 'S';
                    printf("Amino acid Serine found...\n");
                }
                else if(!strcmp(aa, "ACU") || !strcmp(aa, "ACC")) {
                    *output = 'T';
                    printf("Amino acid Threonine found...\n");
                }
                else if(!strcmp(aa, "ACA") || !strcmp(aa, "ACG")) {
                    *output = 'T';
                    printf("Amino acid Threonine found...\n");
                }
                else if(!strcmp(aa, "UGG")) {
                    *output = 'W';
                    printf("Amino acid Tryptophan found...\n");
                }
                else if(!strcmp(aa, "UAU") || !strcmp(aa, "UAC")) {
                    *output = 'Y';
                    printf("Amino acid Tyrosine found...\n");
                }
                else if(!strcmp(aa, "GUU") || !strcmp(aa, "GUC")) {
                    *output = 'V';
                    printf("Amino acid Valine found...\n");
                }
                else if(!strcmp(aa, "GUA") || !strcmp(aa, "GUG")) {
                    *output = 'V';
                    printf("Amino acid Valine found...\n");
                }
                prot++;
            }
            else {
                
        }
        aa[j] = *ch;
        j++;
        ch++;
    }
    *output = '\0';
}
    