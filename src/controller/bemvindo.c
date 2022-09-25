#include <stdio.h>
#include <stdlib.h>

int main() {
     printf("\t\tBem-vindo a\n");

    printf("\t ____                 _ \n");
    printf("\t| __ )  __ _ _ __ ___(_)\n");
    printf("\t|  _ \\ / _` | '__/ __| |\n");
    printf("\t| |_) | (_| | |  \\__ \\ |\n");
    printf("\t|____/ \\__,_|_|  |___/_|\n\n\n");

    int saida;
    int cont = 0;
    while(saida < 1 || saida > 2){
        printf("------------------------------------------------------\n");
        printf("Voce ja e nosso cliente? Para realiza o login\n");
        printf("1 --- Login\n");
        printf("Para fazer parte da Barsi crie sua conta\n");
        printf("2 --- Cadastro\n");
        printf("Para sair do programa\n");
        printf("3 --- Sair\n");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida == 3){
            printf("Volte sempre!!!");
            return 0;
        }

        if(cont >= 3) {
            printf("Limite de tentativas excedidas!");
            return 0;
        } else {
            printf("Opcao invalida, por favor digite uma opcao valida!\n");
            cont++;
        } 

    }

    if(saida == 1) {
        //Enviar para a tela de inicial
        printf("bem vindo a sua conta");
        //login();
    } else {
        //enviar para a tela de cadastro
        printf("vamos realizar o seu cadastro\n");
        //cadastro();
    }

}