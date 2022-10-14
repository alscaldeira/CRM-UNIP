#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#define ENTER 13    // CÓDIGO ASCII DA TECLA ENTER
#define BACKSPACE 8 // CÓDIGO ASCII DA TECLA BACKSPACE
#define SPACE 32    // CÓDIGO ASCII DA TECLA BARRA DE ESPACO
#define TAB 9       // CÓDIGO ASCII DA TECLA BACKSPACE
#define ESC 27      // CÓDIGO ASCII DA TECLA ESC

void login() {

    //Essa página suscedará a página de bem-vindo do usuario

    char ch = '\0';
    char user[15] = "Emerson";
    char loginUser[15];
    char senha[15] = "12345";
    char loginSenha[15];
    int permissao = 0;
    int ctecla = 0;

    memset(loginUser, '\0', sizeof(loginUser));
    memset(loginSenha, '\0', sizeof(loginSenha));

    for(int cont = 1; cont <= 3; cont++){
        system("cls");

        logo();

        printf("\nTentativa %d de 3\n\n", cont);

        printf("Usuario: ");
        scanf("%s", loginUser);

        printf("Senha: ");
        while(ctecla < 5){

            ch = getch();

            switch(ch){

                case BACKSPACE:
                    if(ctecla > 0){
                        fflush(stdin);
                        putch(BACKSPACE);
                        ch = '\0';
                        loginSenha[ctecla] = ch;
                        ctecla --;
                        putch(SPACE);
                        putch(BACKSPACE);
                    }
                    break;

                case TAB:
                    putch(TAB);
                    ctecla = 5;
                    break;

                case ENTER:
                    putch(ENTER);
                    ctecla = 5;
                    break;

                default:
                    loginSenha[ctecla] = ch;
                    putch('*');
                    ctecla ++;
                    break;
            }
        }

        ctecla = 0;

        if(strcmp(user, loginUser) == 0 && strcmp(senha, loginSenha) == 0) {
            permissao = 1;
            break;

        } else if(strcmp(user, loginUser) != 0 && strcmp(senha, loginSenha) == 0){
            printf("\nUsuario nao existe!!!!!\n");
            getch();

        } else if(strcmp(user, loginUser) == 0 && strcmp(senha, loginSenha) != 0){
            printf("\nSenha incorreta!!!!!\n");
            getch();

        } else if(strcmp(user, loginUser) != 0 && strcmp(senha, loginSenha) != 0){
            printf("\nDados incorretos!!!!!\n");
            getch();

        }

    }

    if(permissao == 1){
        menuPrincipal();

    } else {
        sair();
    }

}


#endif // LOGIN_H_INCLUDED
