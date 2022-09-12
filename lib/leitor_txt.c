#include "stdio.h"
#include "string.h"

char* lerArquivo() {
    
    FILE* ptr;
    char ch;
 
    // Opening file in reading mode
    ptr = fopen("/home/alscaldeira/Workspace/Uni/CRM-UNIP/src/repository/data/usuario.txt", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    do {
        ch = fgetc(ptr);
        printf("%c", ch);

        printf("%zu", strlen(2));
 
    } while (ch != EOF);
 
    // Closing the file
    fclose(ptr);
}