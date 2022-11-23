#define ENTER 13    // CÓDIGO ASCII DA TECLA ENTER
#define BACKSPACE 8 // CÓDIGO ASCII DA TECLA BACKSPACE
#define SPACE 32    // CÓDIGO ASCII DA TECLA BARRA DE ESPACO
#define TAB 9       // CÓDIGO ASCII DA TECLA TAB
#define ESC 27      // CÓDIGO ASCII DA TECLA ESC
#define TAM 100


char arquivo[] = "analista.bin";
analistas max[TAM];
FILE *arq;

void cadastroAnalista()
{
    int ctecla = 0;
    char ch = '\0';
    struct Analista analistas;
    int retorno;
    arq = fopen(arquivo, "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return;
    }
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o cadastro do analista.\n");

    printf("Digite o código do analista: ");
    scanf("%d", &analistas.codigo);
    printf("Digite o nome do analista: ");
    fflush(stdin);
    gets(analistas.nome);
    printf("Digite a senha do analista de 5 dígitos numéricos: ");
    fflush(stdin);
    while(ctecla < 5){

            ch = getch();

            switch(ch){

                case BACKSPACE:
                    if(ctecla > 0){
                        fflush(stdin);
                        putch(BACKSPACE);
                        ch = '\0';
                        analistas.senha[ctecla] = ch;
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
                    analistas.senha[ctecla] = ch;
                    putch(ch);
                    ctecla ++;
                    break;
            }
        }

    ctecla = 0;

    printf("\nDigite o CPF do analista sem pontos ou caracteres especiais: ");
    fflush(stdin);
    while(ctecla < 11){

            ch = getch();

            switch(ch){

                case BACKSPACE:
                    if(ctecla > 0){
                        fflush(stdin);
                        putch(BACKSPACE);
                        ch = '\0';
                        analistas.cpf[ctecla] = ch;
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
                    analistas.cpf[ctecla] = ch;
                    putch(ch);
                    ctecla ++;
                    break;
            }
        }

    ctecla = 0;

    retorno = fwrite (&analistas, sizeof(analistas), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        fprintf(logFile,"O cadastro de analista foi realizado.\n");
        fclose(logFile);
        printf("\n Os dados do produto foram incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
    }
    else
    {
        fclose (arq);
        fprintf(logFile,"Cadastro de analista falhou.\n");
        fclose(logFile);
        printf("\n Falha ao gravar dados do produto.");
        system("pause>nul");
        system("cls || clear");
    }
}

void consultaAnalistas(){

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    arq = fopen(arquivo, "rb");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }
    struct Analista analistas;
    int cod, encontrado = 0;
    printf ("\nDigite o código que procura: ");
    scanf ("%d", &cod);

    while (fread (&analistas, sizeof(analistas), 1, arq))
    {
        if ((cod == analistas.codigo) && (analistas.deletado != '*'))
        {
            fprintf(logFile,"Analista consultado.\n");
            fclose(logFile);

            printf("Código: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"Falha ao consultar analista.\n");
        fclose(logFile);

        printf("\nCódigo não cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(arq);
}

void exclusaoAnalistas() {

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    arq = fopen(arquivo, "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }
    struct Analista analistas;
    int cod, encontrado = 0;
    char certeza;
    printf ("\nDigite o código que deseja EXCLUIR: ");
    scanf ("%d", &cod);

    while (fread (&analistas, sizeof(analistas), 1, arq))
    {
        if (cod == analistas.codigo)
        {
            printf("Código: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
            encontrado = 1;

            printf("\nTem certeza que deseja excluir este analista? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's' || certeza == 'S')
            {
                analistas.deletado = '*';
                fseek(arq,sizeof(struct Analista)*-1, SEEK_CUR);
                fwrite(&analistas, sizeof(analistas), 1, arq);
                fseek(arq, sizeof(analistas)* 0, SEEK_END);
                printf("\nAnalista excluído com sucesso! \n");
                system("pause>nul");
                system("cls || clear");

                fprintf(logFile,"Ocorreu a exclusão de um cliente.\n");
                fclose(logFile);
            }
            else if (certeza == 'n')
            {
                fprintf(logFile,"A exclusão do analista foi cancelada.\n");
                fclose(logFile);
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"Falha na exclusão do analista!\n");
        fclose(logFile);
        printf ("\nCódigo não cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(arq);
}
void alteracaoAnalistas() {
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    arq = fopen(arquivo, "r+b");
    if (arq == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }

    int ctecla = 0;
    char ch = '\0';

    struct Analista analistas;
    int cod, encontrado = 0;
    printf ("\nDigite o código que deseja alterar: ");
    scanf ("%d", &cod);

    while (fread (&analistas, sizeof(analistas), 1, arq))
    {
        if (cod == analistas.codigo)
        {
            printf("Código: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
            encontrado = 1;

            fseek(arq,sizeof(struct Analista)*-1, SEEK_CUR);
            printf("\nDigite um novo nome: ");
            fflush(stdin);
            gets(analistas.nome);
            printf("\nDigite o novo CPF sem pontos ou caracteres especiais: ");
            while(ctecla < 11){

            ch = getch();

            switch(ch){

                case BACKSPACE:
                    if(ctecla > 0){
                        fflush(stdin);
                        putch(BACKSPACE);
                        ch = '\0';
                        analistas.cpf[ctecla] = ch;
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
                    analistas.cpf[ctecla] = ch;
                    putch(ch);
                    ctecla ++;
                    break;
                }
            }

            ctecla = 0;

            printf("\nDigite uma nova senha de 5 dígitos numéricos: ");
            fflush(stdin);
            while(ctecla < 5){

            ch = getch();

            switch(ch){

                case BACKSPACE:
                    if(ctecla > 0){
                        fflush(stdin);
                        putch(BACKSPACE);
                        ch = '\0';
                        analistas.senha[ctecla] = ch;
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
                    analistas.senha[ctecla] = ch;
                    putch(ch);
                    ctecla ++;
                    break;
            }
        }

        ctecla = 0;

            fwrite(&analistas, sizeof(analistas), 1, arq);
            fseek(arq, sizeof(analistas)* 0, SEEK_END);

            fprintf(logFile,"Alteração do analista realizada.\n");
            fclose(logFile);

            printf("\n Os dados do analista foram alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"A alteração do analista falhou.\n");
        fclose(logFile);

        printf("\nCódigo não cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(arq);
}
