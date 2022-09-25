#include <stdio.h>
#include <string.h>

int main() {

    //Essa página suscedará a página de bem-vindo do usuario

    char user[15] = "esc";
    char loginuser[15];
    char senha[15] = "1234";
    char loginsenha[15];


    for(int cont = 1; cont <= 3; cont++){
        printf("Usuario: ");
        scanf("%s", &loginuser);

        printf("Senha: ");
        scanf("%s", &loginsenha);

        if(strcmp(user, loginuser) == 0 && strcmp(senha, loginsenha) == 0) {
            //será direcionado para a tela inicial chamando a função
            printf("acesso autorizado\n Bem Vindo a Barsi");
            //telainicial();
            break;
        } else {
            printf("acesso negado\n");
        }
    }

}