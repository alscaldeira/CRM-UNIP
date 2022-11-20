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

    int op, op2; //op um está ligado ao sexo do cliente, já a opção dois o estado civil.


    system("cls");
    logo();

    //Dados pessoais
    fflush(stdin);
    printf("Digite o codigo do cliente.");
    scanf("%d",&clientes.codigo);
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]", clientes.nome);
    fflush(stdin);
    printf("CPF: ");
    scanf("%[^\n]", clientes.cpf);
    fflush(stdin);
    printf("Data de nascimento ex(24/09/2022): ");
    scanf("%[^\n]", clientes.nascimento);

    //sexualidade
    printf("\nSexo\n");
    printf("1 -- Masculino\n");
    printf("2 -- Feminino\n");
    printf("3 -- Nao definir\n");
    printf("Digite uma opcao valida: ");
    scanf("%d", &op);

    switch (op){

    case 1:
        strcpy(clientes.sexo, "Masculino");
        break;

    case 2:
        strcpy(clientes.sexo, "Feminino");
        break;

    case 3:
        strcpy(clientes.sexo, "Nao definir");
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

    //estado cívil
    printf("\nEstado civil: \n");
    printf("1 -- Casado/a\n");
    printf("2 -- Solteiro/a\n");
    printf("3 -- Uniao estavel\n");
    printf("4 -- Viuvo/a\n");
    printf("Digite uma opcao valida: ");
    scanf("%d", &op2);

    switch (op2){
    case 1:
        strcpy(clientes.estCivil, "Casado/a");
        break;

    case 2:
        strcpy(clientes.estCivil, "Solteiro/a");
        break;

    case 3:
        strcpy(clientes.estCivil, "União estavel");
        break;

    case 4:
        strcpy(clientes.estCivil, "Viuvo/a");
        ;
        break;
    }


    printf("\nTem dependentes?\n");
    printf("1 -- Sim\n");
    printf("2 -- Nao\n");
    printf("Digite uma opcao valida: ");
    scanf("%d", &dependentes);

    if (dependentes == 1){
        printf("Numeros de dependestes: ");
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
        printf("\n Dados do cliente incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
    }
    else
    {
        fprintf(logFile,"Cadastro de cliente com erro.\n");
        fclose(logFile);
        fclose (clientef);
        printf("\n Falha ao gravar dados do cliente.");
        system("pause>nul");
        system("cls || clear");
    }


}
void alterarClientes()
{
    clientef = fopen(arquivoc, "r+b");
    if (clientef == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }

    struct Clientes clientes;
    int cod, encontrado = 0;
    printf("\nDigite o codigo que deseja alterar: \n");
    scanf("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if (cod == clientes.codigo)
        {
            printf("Cod %d - Nome: %-15s - CPF %-14s\n\n", clientes.codigo, clientes.nome, clientes.cpf);
            encontrado = 1;

            fseek(clientef, sizeof(struct Clientes) * -1, SEEK_CUR);
            printf("\nDigite um novo estado civil: \n");
            fflush(stdin);
            gets(clientes.estCivil);
            printf("\nDigite o novo numero de dependentes: \n");
            scanf("%d", &clientes.numeroDependentes);

            fwrite(&clientes, sizeof(clientes), 1, clientef);
            fseek(clientef, sizeof(clientes) * 0, SEEK_END);

            printf("\n Dados do produto alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}

void excluirClientes()
{
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
    printf("\nDigite o codigo que deseja EXCLUIR: \n");
    scanf("%d", &cod);

    while(fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if (cod == clientes.codigo)
        {
            printf("Cod %d - Nome: %-15s - CPF %-14s\n\n", clientes.codigo, clientes.nome, clientes.cpf);
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
                printf("\nCliente excluido com Sucesso! \n");
                system("pause>nul");
                system("cls || clear");
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}

void consultarClientes()
{
    clientef = fopen(arquivoc, "rb");
    if (clientef == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }
    struct Clientes clientes;
    int cod, encontrado = 0;
    printf("\nDigite o codigo que procura: \n");
    scanf("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if ((cod == clientes.codigo) && (clientes.deletado != '*'))
        {
            printf("Cod %d - Nome: %-15s - CPF %-14s\n\n", clientes.codigo, clientes.nome, clientes.cpf);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}
