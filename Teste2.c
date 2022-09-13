#include "stdio.h"

int main (void) {

    FILE * testfile;
    testfile = fopen("testfile.txt","r");
    
    if (testfile == NULL) {
        printf("Nao foi possivel abrir o arquivo. Por favor verifique o sistema. \n");
        getchar();
        exit(0);
    }

    char frase [100];
    
    while (fgets(frase, 100, testfile) != NULL)
    {
        printf ("%s", frase);
    }
    
    fclose(testfile);

    printf("\n");
    system("Pause");
    return 0;
}