#include <stdio.h>
#include <string.h>

int main(){

    char estado[20], cidade[20], cep[20], rua[20];
    int numerocasa;
    printf("---------------------------------------\n");
    printf("\n\n\t\tEndereco\n");
    printf("---------------------------------------\n");

    printf("Estado: ");
    scanf(" %s", estado);
    printf("Cidade: ");
    scanf(" %s", cidade);
    printf("CEP: ");
    scanf(" %s", cep);
    printf("Rua: ");
    scanf("%s", rua);
    printf("Numero: ");
    scanf(" %d", &numerocasa);
    
    
    printf("\n\n\n%s\n", estado);
    printf("%s\n", cidade);
    printf("%s\n", cep);
    printf("%s\n", rua);
    printf("%d\n", numerocasa);
}