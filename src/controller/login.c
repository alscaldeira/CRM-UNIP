#include <stdio.h>
#include <string.h>

int main() {

    int opcao = 0;

    char user[15] = "esc";
    char loginuser[15];
    char senha[15] = "1234";
    char loginsenha[15];

    printf("User: ");
    scanf("%s", &loginuser);

    printf("Senha: ");
    scanf("%s", &loginsenha);

    if(strcmp(user, loginuser) == 0 && strcmp(senha, loginsenha) == 0) {
        printf("acesso autorizado\n Bem Vindo a Barsi");
    } else {
        printf("acesso negado");
    }

}