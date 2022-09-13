#include "stdio.h"

int main (void) {

    FILE * testfile;
    testfile = fopen("testfile.txt","w");
    
    fprintf(testfile,"ACEITA PELO AMOR DE DEUS.");
    fclose(testfile);

    return 0;
}