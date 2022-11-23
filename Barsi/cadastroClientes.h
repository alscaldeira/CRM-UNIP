#define ENTER 13    // C�DIGO ASCII DA TECLA ENTER
#define BACKSPACE 8 // C�DIGO ASCII DA TECLA BACKSPACE
#define SPACE 32    // C�DIGO ASCII DA TECLA BARRA DE ESPACO
#define TAB 9       // C�DIGO ASCII DA TECLA TAB
#define ESC 27      // C�DIGO ASCII DA TECLA ESC
#define TAM 100

typedef struct Clientes{
    int  codigo,numeroDependentes;
    char profissao[35], nome[100], endereco[100], sexo[15], email[100], nacionalidade[20],
    uf[2], nascimento[30], cidade[30], estCivil[15], cpf[30],deletado;
}clientes;

char arquivoc[] = "clientes.bin";
//clientes max [TAM];
FILE *clientef;

void cadastroClientes(){
    int ctecla = 0;
    char ch = '\0';
    setlocale(LC_ALL, "Portuguese");
    struct Clientes clientes;
    int dependentes,retorno;
    clientef = fopen(arquivoc, "ab");
    if (clientef == NULL)
    {
        printf("Erro ao abrir arquivo");
        return;
    }
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o cadastro do cliente.\n");

    int op, op2; //op um est� ligado ao sexo do cliente, j� a op��o dois o estado civil.


    system("cls");
    logo();

    //Dados pessoais
    fflush(stdin);
    printf("Digite o c�digo do cliente:");
    scanf("%d",&clientes.codigo);
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]", clientes.nome);
    fflush(stdin);
    printf("CPF: ");
    while(ctecla < 11){

        ch = getch();

        switch(ch){

            case BACKSPACE:
                if(ctecla > 0){
                    fflush(stdin);
                    putch(BACKSPACE);
                    ch = '\0';
                    clientes.cpf[ctecla] = ch;
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
                clientes.cpf[ctecla] = ch;
                putch(ch);
                ctecla ++;
                break;
            }
        }

    ctecla = 0;

    fflush(stdin);
    printf("\nData de nascimento ex(24/09/2022): ");
    scanf("%[^\n]", clientes.nascimento);

    //sexualidade
    printf("\nSexo\n");
    printf("1 -- Masculino\n");
    printf("2 -- Feminino\n");
    printf("3 -- N�o definir\n");
    printf("Digite uma op��o v�lida: ");
    scanf("%d", &op);

    switch (op){

    case 1:
        strcpy(clientes.sexo, "Masculino");
        break;

    case 2:
        strcpy(clientes.sexo, "Feminino");
        break;

    case 3:
        strcpy(clientes.sexo, "N�o definir");
        break;
    }

    fflush(stdin);
    printf("\nNacionalidade: ");
    scanf("%[^\n]", clientes.nacionalidade);
    printf("\nEstado(ex:SP,RJ): ");
    scanf("%s", clientes.uf);
    fflush(stdin);
    printf("\nCidade: ");
    scanf("%[^\n]", clientes.cidade);
    fflush(stdin);
    printf("\nEndereco: ");
    scanf("%[^\n]", clientes.endereco);
    printf("\nEmail: ");
    scanf("%s", clientes.email);

    //estado c�vil
    printf("\nEstado civil: \n");
    printf("1 -- Casado/a\n");
    printf("2 -- Solteiro/a\n");
    printf("3 -- Uniao est�vel\n");
    printf("4 -- Vi�vo/a\n");
    printf("Digite uma op��o v�lida: ");
    scanf("%d", &op2);

    switch (op2){
    case 1:
        strcpy(clientes.estCivil, "Casado/a");
        break;

    case 2:
        strcpy(clientes.estCivil, "Solteiro/a");
        break;

    case 3:
        strcpy(clientes.estCivil, "Uni�o est�vel");
        break;

    case 4:
        strcpy(clientes.estCivil, "Vi�vo/a");
        ;
        break;
    }


    printf("\nTem dependentes?\n");
    printf("1 -- Sim\n");
    printf("2 -- N�o\n");
    printf("Digite uma op��o v�lida: ");
    scanf("%d", &dependentes);

    if (dependentes == 1){
        printf("N�meros de dependentes: ");
        scanf("%d", &clientes.numeroDependentes);
    } else {
        clientes.numeroDependentes = 0;
    }


    retorno = fwrite (&clientes, sizeof(clientes), 1, clientef);

    if (retorno == 1)
    {
        fclose (clientef);
        fprintf(logFile,"Cadastro de cliente realizado.\n");
        fclose(logFile);
        printf("\n Dados do cliente inclu�dos com sucesso!");
        system("pause>nul");
        system("cls || clear");
    }
    else
    {
        fprintf(logFile,"Erro com o cadastro do cliente.\n");
        fclose(logFile);
        fclose (clientef);
        printf("\n Falha ao gravar dados do cliente.");
        system("pause>nul");
        system("cls || clear");
    }


}
void alterarClientes()
{
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    clientef = fopen(arquivoc, "r+b");
    if (clientef == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }

    struct Clientes clientes;
    int cod, encontrado = 0;
    printf("\nDigite o c�digo que deseja alterar: \n");
    scanf("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if (cod == clientes.codigo)
        {
            printf("Cod %d - Nome: %-s - CPF %-14s\n", clientes.codigo, clientes.nome, clientes.cpf);
            printf("Estado civil: %s - N�mero de dependentes: %d\n\n",clientes.estCivil, clientes.numeroDependentes );
            encontrado = 1;

            fseek(clientef, sizeof(struct Clientes) * -1, SEEK_CUR);
            printf("\nDigite um novo estado civil: \n");
            fflush(stdin);
            gets(clientes.estCivil);
            printf("\nDigite o novo n�mero de dependentes: \n");
            scanf("%d", &clientes.numeroDependentes);

            fwrite(&clientes, sizeof(clientes), 1, clientef);
            fseek(clientef, sizeof(clientes) * 0, SEEK_END);

            fprintf(logFile,"Altera��o do cliente realizada.\n");
            fclose(logFile);

            printf("\n Dados do produto alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"Altera��o do cliente falhou.\n");
        fclose(logFile);

        printf("\nC�digo n�o cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}

void excluirClientes()
{
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    clientef = fopen(arquivoc, "r+b");
    if (clientef == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }
    struct Clientes clientes;
    int cod, encontrado = 0;
    char certeza;
    printf("\nDigite o c�digo que deseja EXCLUIR: \n");
    scanf("%d", &cod);

    while(fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if (cod == clientes.codigo)
        {
            printf("Cod %d - Nome: %-15s - CPF %.3s.***.***-**\n", clientes.codigo, clientes.nome, clientes.cpf);
            printf("Estado civil: %s - N�mero de dependentes: %d\n\n", clientes.estCivil, clientes.numeroDependentes );
            encontrado = 1;

            printf("\nTem certeza que quer excluir este cliente? s/n \n");
            fflush(stdin);
            scanf("%c", &certeza);
            if (certeza == 's')
            {
                clientes.deletado = '*';
                fseek(clientef, sizeof(struct Clientes) * -1, SEEK_CUR);
                fwrite(&clientes, sizeof(clientes), 1, clientef);
                fseek(clientef, sizeof(clientes) * 0, SEEK_END);
                printf("\nCliente exclu�do com sucesso! \n");
                system("pause>nul");
                system("cls || clear");

                fprintf(logFile,"Ocorreu a exclus�o de um cliente.\n");
                fclose(logFile);
            }
            else if (certeza == 'n')
            {
                fprintf(logFile,"Exclus�o de cliente cancelada.\n");
                fclose(logFile);
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"A exclus�o do cliente falhou.\n");
        fclose(logFile);
        printf("\nC�digo n�o cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}

void consultarClientes()
{
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    clientef = fopen(arquivoc, "rb");
    if (clientef == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }
    struct Clientes clientes;
    int cod, encontrado = 0;
    printf("\nDigite o c�digo que procura: \n");
    scanf("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if ((cod == clientes.codigo) && (clientes.deletado != '*'))
        {
            printf("Cod %d - Nome: %-15s - CPF %.3s.***.***-**\n", clientes.codigo, clientes.nome, clientes.cpf);
            printf("Estado civil: %s - N�mero de dependentes: %d\n\n",clientes.estCivil, clientes.numeroDependentes );
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
            fprintf(logFile,"Cliente consultado.\n");
            fclose(logFile);
        }
    }
    if (!encontrado)
    {   fprintf(logFile,"N�o foi poss�vel consultar o cliente.\n");
        fclose(logFile);
        printf("\nC�digo n�o cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}
