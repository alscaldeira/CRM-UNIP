#include <stdio.h>
#include <string.h>
#include <stdlib.h>
<<<<<<< HEAD
=======
#include ".\logo.c"

void login() {

    logo();
>>>>>>> acbde99b7f9051abd7f19ab86444baa54742de9f

void login() {
    //Essa página suscedará a página de bem-vindo do usuario

    char user[15] = "esc";
    char loginuser[15];
    char senha[15] = "1234";
    char loginsenha[15];
    int permissao;

    for(int cont = 1; cont <= 3; cont++){
        //system("cls");
        
        printf("\nTentativa %d de 3\n", cont);

        printf("\nUsuario: ");
        scanf("%s", loginuser);

        printf("Senha: ");
        scanf("%s", loginsenha);

        if(strcmp(user, loginuser) == 0 && strcmp(senha, loginsenha) == 0) {
            permissao = 1;
            break;

        } else if(strcmp(user, loginuser) != 0 && strcmp(senha, loginsenha) == 0){
            printf("Usuario nao existe!!!!!\n");

        } else if(strcmp(user, loginuser) == 0 && strcmp(senha, loginsenha) != 0){
            printf("Senha incorreta!!!!!\n");

        } else if(strcmp(user, loginuser) != 0 && strcmp(senha, loginsenha) != 0){
            printf("Dados incorretos!!!!!\n");

        }  

    }

    if(permissao == 1){
        //telainicial();
        printf("Acesso autorizado\nBem Vindo a Barsi");
        
    } else {
        system("cls");
        printf("\nAcesso negado\n");
    }
<<<<<<< HEAD
=======

>>>>>>> acbde99b7f9051abd7f19ab86444baa54742de9f
}