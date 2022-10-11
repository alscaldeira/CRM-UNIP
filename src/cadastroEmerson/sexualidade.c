#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int opcao;
    char sexo[20];

    do{
        system("cls");
        printf("---------------------\n");
        printf("\tSexo:\n");
        printf("---------------------\n");
        printf("1 -- Masculino\n");
        printf("2 -- Feminino\n");
        printf("3 -- Nao definir\n");
        printf("Digite uma opcao valida: ");
        scanf(" %d", &opcao);
    } while(opcao <1 || opcao >3);

    switch(opcao){
    case 1:
    strcpy(sexo, "Masculino");
        break;
    
    case 2:
    strcpy(sexo, "Feminino");
        break;

    case 3:
    strcpy(sexo, "Indefinido");
        break;   
    }

    printf("%s", sexo);
}