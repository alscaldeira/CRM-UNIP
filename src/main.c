#include <stdio.h>

int main() {
    printf("Bem-vindo a\n");

    printf(" ____                 _ \n");
    printf("| __ )  __ _ _ __ ___(_)\n");
    printf("|  _ \\ / _` | '__/ __| |\n");
    printf("| |_) | (_| | |  \\__ \\ |\n");
    printf("|____/ \\__,_|_|  |___/_|\n");

    char resposta;
    printf("voce ja e nosso cliente digite [S/N]: \n");
    scanf("%s", &resposta);

    if(resposta == 'S') {
        teladelogin();
    } else {
        cadastro();
    }

}
