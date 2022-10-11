#include <stdio.h>
#include <string.h>

int main(){

    char nome[50], sobrenome[50], nomecompleto[50], cpf[50], nascimento[50], 
    nacionalidade[50], email[50];


    printf("---------------------------------------\n");
    printf("\tInformacoes Pessoais:\n");
    printf("---------------------------------------\n");

    //nome
    printf("Nome: ");
    scanf(" %s", nome);
    printf("Sobrenome: ");
    scanf(" %s", sobrenome);
    strcpy(nomecompleto, " ");
    strcat(nome, " ");
    strcat(nome, sobrenome);
    strcat(nomecompleto, nome);

    //dados pessoais
    printf("CPF: ");
    scanf(" %s", cpf);
    printf("Data de nascimento ex(28/01/199): ");
    scanf(" %s", nascimento);
    printf("Nacionalidade: ");
    scanf(" %s", nacionalidade);
    printf("Email: ");
    scanf(" %s", email);

    printf("\n\n\n\n%s\n", nomecompleto);
    printf("%s\n", cpf);
    printf("%s\n", nascimento);
    printf("%s\n", nacionalidade);
    printf("%s", email);

}