#define ENTER 13    // CÓDIGO ASCII DA TECLA ENTER
#define BACKSPACE 8 // CÓDIGO ASCII DA TECLA BACKSPACE
#define SPACE 32    // CÓDIGO ASCII DA TECLA BARRA DE ESPACO
#define TAB 9       // CÓDIGO ASCII DA TECLA TAB
#define ESC 27      // CÓDIGO ASCII DA TECLA ESC
#define TAM 100

typedef struct Analista{
    int codigo;
    char nome[30],senha[30],cpf[11];
    char deletado;
} analistas;

void loginAnalista() {
    char arquivo[] = "analista.bin";
    analistas max[TAM];
    FILE *arq;


    char ch = '\0';
    char user[15] = "esc";
    char loginUser[15];
    //char senha[15] = "123";
    char loginSenha[15];
    int permissao = 0;
    int ctecla = 0;

    memset(loginUser, '\0', sizeof(loginUser));
    memset(loginSenha, '\0', sizeof(loginSenha));

    for(int cont = 1; cont <= 3; cont++){

        system("cls");

        logo();
        printf("\nTentativa %d de 3\n\n", cont);

        arq = fopen(arquivo, "rb");
        if (arq == NULL)
        {
            printf("Arquivo inexistente!");
            system("pause>nul");
            system("cls || clear");
        }
        struct Analista analistas;
        int cod, encontrado = 0;
        printf ("\nCódigo do Analista: ");
        scanf ("%d", &cod);

        while (fread (&analistas, sizeof(analistas), 1, arq))
        {
            if ((cod == analistas.codigo) && (analistas.deletado != '*'))
            {
                encontrado = 1;
            }
        }
        if (!encontrado)
        {
            printf("\nCodigo nao cadastrado!!\n");
            system("pause>nul");
            system("cls || clear");
        }



        fclose(arq);

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

        if(strcmp(analistas.senha, loginSenha) == 0) {
            permissao = 1;
            break;

        } else {
            printf("\nSenha incorreta!!!!!\n");
            getch();
        }
    }

    if(permissao == 1){
        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Login realizado com sucesso por %s.\n", loginUser);
        fclose(logFile);
        menuPrincipalAnalista();

    } else {
        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Login recusado, limite de tentativas excedidas.\n");
        fclose(logFile);
        sair();
    }

}

