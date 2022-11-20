#define TAM 100


char arquivo[] = "analista.bin";
analistas max[TAM];
FILE *arq;

void cadastroAnalista()
{
    struct Analista analistas;
    int retorno;
    arq = fopen(arquivo, "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o cadastro do analista.\n");

    printf("Digite o c�digo do analista: ");
    scanf("%d", &analistas.codigo);
    printf("Digite o nome do analista: ");
    fflush(stdin);
    gets(analistas.nome);
    printf("Digite a senha do analista: ");
    fflush(stdin);
    gets(analistas.senha);
    printf("Digite o cpf do analista: ");
    fflush(stdin);
    gets(analistas.cpf);
    retorno = fwrite (&analistas, sizeof(analistas), 1, arq);
    if (retorno == 1)
    {
        fclose (arq);
        fprintf(logFile,"Cadastro de analista realizado.\n");
        fclose(logFile);
        printf("\n Dados do produto inclu�dos com sucesso!");
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
    printf ("\nDigite o codigo que procura: ");
    scanf ("%d", &cod);

    while (fread (&analistas, sizeof(analistas), 1, arq))
    {
        if ((cod == analistas.codigo) && (analistas.deletado != '*'))
        {
            fprintf(logFile,"Analista consultado.\n");
            fclose(logFile);

            printf("C�digo: %d; Nome: %s; CPF: R$ %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"Falha ao consultar analista.\n");
        fclose(logFile);

        printf("\nCodigo nao cadastrado!!\n");
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
    printf ("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf ("%d", &cod);

    while (fread (&analistas, sizeof(analistas), 1, arq))
    {
        if (cod == analistas.codigo)
        {
            printf("C�digo: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
            encontrado = 1;

            printf("\nTem certeza que quer excluir este analista? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's' || certeza == 'S')
            {
                analistas.deletado = '*';
                fseek(arq,sizeof(struct Analista)*-1, SEEK_CUR);
                fwrite(&analistas, sizeof(analistas), 1, arq);
                fseek(arq, sizeof(analistas)* 0, SEEK_END);
                printf("\nAnalista excluido com sucesso! \n");
                system("pause>nul");
                system("cls || clear");

                fprintf(logFile,"Ocorreu a exclud�o de um cliente.\n");
                fclose(logFile);
            }
            else if (certeza == 'n')
            {
                fprintf(logFile,"Cancelaram a exclus�o do analista.\n");
                fclose(logFile);
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"Falha na exclus�o do analista.\n");
        fclose(logFile);
        printf ("\nCodigo nao cadastrado!!\n");
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

    struct Analista analistas;
    int cod, encontrado = 0;
    printf ("\nDigite o codigo que deseja alterar: ");
    scanf ("%d", &cod);

    while (fread (&analistas, sizeof(analistas), 1, arq))
    {
        if (cod == analistas.codigo)
        {
            printf("C�digo: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
            encontrado = 1;

            fseek(arq,sizeof(struct Analista)*-1, SEEK_CUR);
            printf("\nDigite um novo nome: ");
            fflush(stdin);
            gets(analistas.nome);
            printf("\nDigite o novo cpf: ");
            scanf("%s", &analistas.cpf);

            fwrite(&analistas, sizeof(analistas), 1, arq);
            fseek(arq, sizeof(analistas)* 0, SEEK_END);

            fprintf(logFile,"Altera��o do analista realizado.\n");
            fclose(logFile);

            printf("\n Dados do analista alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"Altera��o do analista falhou.\n");
        fclose(logFile);

        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(arq);
}
