#include <stdio.h>
#include <string.h>

int main(){

    char estadocivil[50];
    int opcao;

    do{
        printf("---------------------------------------\n");
        printf("\t\tEstado civil\n");
        printf("---------------------------------------\n");
        printf("1 -- Casado/a\n");
        printf("2 -- Solteiro/a\n");
        printf("3 -- Uniao Estavel\n");
        printf("4 -- Viuvo/a\n");
        printf("Digite uma opcao: ");
        scanf(" %d", &opcao);
    } while(opcao <1 || opcao >4);

    switch(opcao){

        case 1:
            strcpy(estadocivil, "Casado");
            break;
        
        case 2:
            strcpy(estadocivil, "Solteiro/a");
            break;

        case 3:
            strcpy(estadocivil, "Uniao Estavel");
            break;    

        case 4:
            strcpy(estadocivil, "Viuvo/a");
            break;    
    }

    printf("\n%s", estadocivil);

}