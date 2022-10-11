#include <stdio.h>
#include <stddef.h>
#include <string.h>

int profissao(){

    int emprego;
    char profissao[35], nomeEmpresa[30];
    float renda, bens;

    printf("Qual é a sua profissão?");
    scanf("%s", profissao);

    printf("Está empregado no momento?\n");
    printf("1 -- Sim\n");
    printf("2 -- Nao");
    scanf("%d", &emprego);

    if (emprego == 1){
        printf("Qual o nome da empresa em que está empregado? ");
        scanf("%s", nomeEmpresa);
    }
    else{
        strcpy(nomeEmpresa, " ");
    }
    if(emprego == 1){
        printf("Qual a sua renda mensal? ");
        scanf("%f", &renda);
    }
    printf("Quanto em bens você possui: ");
    scanf("%f", &bens);
}


