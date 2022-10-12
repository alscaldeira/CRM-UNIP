#include <stdio.h>
#include <stdlib.h>
//#include ".\logo.c"
void retornasex (const char *sex)
{
    printf(sex);
    return;
}

void cadastro ()

{
    //variaveis
    char nome[100], end[100],sex[12],em[100],nac[20],uf[2],cid[30],civ[15];
    int doc,num,year,op,op2;
    float nas;

    //escopo do cadastro
    
    printf("Nome: ");
    scanf("%s",nome);
    printf("\nCPF: ");
    scanf("%d",&doc);
    printf("\nData de nascimento ex((24.09)): ");
    scanf("%f",&nas);
    printf("\nAno de nascimento: ");
    scanf("%f", &year);
    printf ("\n Sexo: ");
    printf("\n 1- Masculino");
    printf("\n 2- Feminino");
    printf ("\n 3- Nao definir");
    scanf("%d",op);

    switch (op)
    {
    case 1:
    sex = "Masculino";
        break;
    
    case 2:
    sex = "Feminino";
        break;

    case 3:
    sex =  "Nao definir";
        break;   
    }
    printf("\nNacionalidade: ");
    scanf("%s",nac);
    printf("\nEstado((ex:SP,RJ)): ");
    scanf("%s",uf);
    printf("\nCidade: ");
    scanf("%s",cid);
    printf("\n Endereço: ");
    scanf("%s",end);
    printf("\n Email:");
    scanf("%s",em);
    printf("\nEstado civil: 1 - Casado/a");
    printf("\n2-Solteiro/a");
    printf("\n3-União estavel");
    printf("\n4-Vilvo/a");
    scanf("%d",&op2);

    switch (op2)
    {
    case 1:
    civ="Casado/a";
        break;
    
    case 2:
    civ="Solteiro/a";
        break;

    case 3:
    civ="União estavel";
        break;

    case 4:
    civ="Vilvo/a";
        break;        
    }

    int dep, ndep,empre;
    char prof[35],nempre[30];
    float rend,bens;

    printf("\nTem dependestes?");
    printf("\n1 - sim");
    printf("\nOutra tecla - nao");
    scanf("%d",&dep);

    if (dep ==  1){
        printf("Quantos dependestes?");
        scanf("%d",&ndep);
    }
    else{
        ndep=null;
    }
    printf("\nQual é a sua profissão?");
    scanf("%s",prof);
    printf("\nEstá empregado no momento?");
    printf("\n1 - sim");
    printf("\nOutra tecla - nao");
    scanf("%d",&empre);

    if (empre == 1){
        printf("\nQual o nome da empresa em que está empregado?");
        scanf("%s",nempre);
    }
    else{
        nempre=null;
    }
    if(nempre!=null){
        printf("\nQual a sua renda mensal?");
        scanf("%f",&rend);
    }
    printf("\nQuanto em bens você possui: ");
    scanf("%f", &bens);
}