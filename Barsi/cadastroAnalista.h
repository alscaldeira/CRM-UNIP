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
    printf("Digite o código do analista: ");
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
        printf("\n Dados do analista incluídos com sucesso!");
        system("pause>nul");
        system("cls || clear");
    }
    else
    {
        fclose (arq);
        printf("\n Falha ao gravar dados do analista.");
        system("pause>nul");
        system("cls || clear");
    }
}

void consultaAnalistas(){
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
            printf("Código: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
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
    fclose(arq);
}

void exclusaoAnalistas() {
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
            printf("Código: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
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
            }
            else if (certeza == 'n')
            {
                system("cls || clear");
            }
        }
    }
    if (!encontrado)
    {
        printf ("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(arq);
}
void alteracaoAnalistas() {
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
            printf("Código: %d; Nome: %s; CPF: %.3s.***.***-**", analistas.codigo, analistas.nome, analistas.cpf);
            encontrado = 1;

            fseek(arq,sizeof(struct Analista)*-1, SEEK_CUR);
            printf("\nDigite um novo nome: ");
            fflush(stdin);
            gets(analistas.nome);
            printf("\nDigite o novo cpf: ");
            scanf("%s", &analistas.cpf);

            fwrite(&analistas, sizeof(analistas), 1, arq);
            fseek(arq, sizeof(analistas)* 0, SEEK_END);

            printf("\n Dados do analista alterados com sucesso!");
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
    fclose(arq);
}
