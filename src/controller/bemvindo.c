#include <stdio.h>

int main() {
     printf("\t\tBem-vindo a\n");

    printf("\t ____                 _ \n");
    printf("\t| __ )  __ _ _ __ ___(_)\n");
    printf("\t|  _ \\ / _` | '__/ __| |\n");
    printf("\t| |_) | (_| | |  \\__ \\ |\n");
    printf("\t|____/ \\__,_|_|  |___/_|\n\n\n");

    int saida;
    int valido = 0;
    while(valido == 0){
        printf("------------------------------------------------------\n");
        printf("Voce ja e nosso cliente? Para realiza o login\n");
        printf("1 --- Login\n");
        printf("Para fazer parte da Barsi crie sua conta\n");
        printf("2 --- Cadastro\n");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida == 1 || saida ==2){
            valido++;
            break;
        } else{
            printf("Opcao invalida, por favor digite uma opcao valida!\n");
        }
    }

        if(saida == 1) {
            printf("bem vindo a sua conta");
        } else {
            printf("vamos realizar o seu cadastro");
        }

}