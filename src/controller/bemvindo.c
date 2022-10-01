#include <stdio.h>
#include <stdlib.h>
#include ".\logo.c"

int main() {
    int saida, cont;
    for(cont = 1; cont <= 3; cont++) {
        system("cls");
        printf("\t\tBem-vindo a\n");
        logo();
        printf("------------------------------------------------------\n");
        printf("Voce ja e nosso cliente? Para realiza o login\n");
        printf("1 --- Login\n");
        printf("Para fazer parte da Barsi crie sua conta\n");
        printf("2 --- Cadastro\n");
        printf("Para sair do programa\n");
        printf("3 --- Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");
        
        if(saida == 1 || saida == 2 || saida == 3) {
            break;
        } else {
            printf("Opcao invalida, por favor digite uma opcao valida!\n");
        } 

    }

    switch (saida) {
        case 1:
            //Enviar para a tela de inicial
            printf("bem vindo a sua conta");
            //login();
            break;

        case 2:
            //enviar para a tela de cadastro
            printf("vamos realizar o seu cadastro\n");
            //cadastro();
            break;

        case 3:
            printf("Obrigado volte sempre!");
            return 0;

    }

}