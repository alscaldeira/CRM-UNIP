#define ENTER 13    // C�DIGO ASCII DA TECLA ENTER
#define BACKSPACE 8 // C�DIGO ASCII DA TECLA BACKSPACE
#define SPACE 32    // C�DIGO ASCII DA TECLA BARRA DE ESPACO
#define TAB 9       // C�DIGO ASCII DA TECLA TAB
#define ESC 27      // C�DIGO ASCII DA TECLA ESC
#define TAM 100

typedef struct Clientes{
    int codigo,numeroDependentes;
    char nome[100], endereco[100], sexo[15], email[100], nacionalidade[20],
    uf[2], nascimento[30], cidade[30], estCivil[15], cpf[30],deletado, nivelInvest[20];
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
    printf("Digite o c�digo do cliente: ");
    scanf("%d",&clientes.codigo);
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]", clientes.nome);
    fflush(stdin);
    printf("CPF (sem caracteres especiais): ");
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
void alterarClientes(){
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
    printf("\nDigite o c�digo que deseja alterar: ");
    scanf("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if (cod == clientes.codigo)
        {
            printf("\nCod %d - Nome: %-s - CPF %.3s.***.***-**\n", clientes.codigo, clientes.nome, clientes.cpf);
            printf("Email: %s \nCidade: %s \nUF: %s \nEndere�o: %s\n\n",clientes.email, clientes.cidade, clientes.uf, clientes.endereco);
            encontrado = 1;

            fseek(clientef, sizeof(struct Clientes) * -1, SEEK_CUR);
            printf("\nDigite um novo Email: ");
            fflush(stdin);
            gets(clientes.email);
            printf("\nDigite uma nova cidade: ");
            fflush(stdin);
            gets(clientes.cidade);
            printf("\nDigite uma nova UF: ");
            fflush(stdin);
            gets(clientes.uf);
            printf("\nDigite um novo endere�o: ");
            fflush(stdin);
            gets(clientes.endereco);


            fwrite(&clientes, sizeof(clientes), 1, clientef);
            fseek(clientef, sizeof(clientes) * 0, SEEK_END);

            fprintf(logFile,"Altera��o do cliente realizada.\n");
            fclose(logFile);

            printf("\n Dados do cliente alterados com sucesso!");
            system("pause>nul");
            system("cls || clear");
        }
    }
    if (!encontrado)
    {
        fprintf(logFile,"\nAltera��o do cliente falhou.\n");
        fclose(logFile);

        printf("\nC�digo n�o cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}

void excluirClientes(){
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
    printf("\nDigite o c�digo que deseja EXCLUIR: ");
    scanf("%d", &cod);

    while(fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if (cod == clientes.codigo)
        {
            printf("\nCod %d - Nome: %-15s - CPF %.3s.***.***-**\n", clientes.codigo, clientes.nome, clientes.cpf);
            printf("Email: %s \nCidade: %s \nUF: %s \nEndere�o: %s\n\n",clientes.email, clientes.cidade, clientes.uf, clientes.endereco);
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

void consultarClientes(){
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
    printf("\nDigite o c�digo que procura: ");
    scanf("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if ((cod == clientes.codigo) && (clientes.deletado != '*'))
        {
            printf("\nCod %d - Nome: %-15s - CPF %.3s.***.***-**\n", clientes.codigo, clientes.nome, clientes.cpf);
            //printf("N�vel do investidor: %s\n", clientes.nivelInvest);
            printf("Email: %s \nCidade: %s \nUF: %s \nEndere�o: %s\n\n",clientes.email, clientes.cidade, clientes.uf, clientes.endereco);
            encontrado = 1;
            system("pause>nul");
            system("cls || clear");
            fprintf(logFile,"Cliente consultado.\n");
            fclose(logFile);
        }
    }
    if (!encontrado){
        fprintf(logFile,"\nN�o foi poss�vel consultar o cliente.\n");
        fclose(logFile);
        printf("\nC�digo n�o cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);
}

void pergunta1() {
    printf("\n\nCom quais produtos abaixo voc� tem familiaridade e/ou costuma investir com frequ�ncia?\n");
    printf("(1) Nenhum.\n");
    printf("(2) Renda Fixa(CDBs, Tesouro, Fundos de RF, etc).\n");
    printf("(3) Renda Vari�vel(A��es, Fiis, etc).\n");
    printf("(4) Derivativos(Fundos, termos,etc).\n");
    printf("Escolha: ");
}

void pergunta2() {
    printf("\nQual percentual dos seus recursos voc� espera resgatar nos pr�ximos 12 meses?\n");
    printf("(1) Mais de 25%%.\n");
    printf("(2) Entre 5%% e 25%%.\n");
    printf("(3) At� 5%%.\n");
    printf("(4) N�o tenho expectivas de resgatar meus recursos nos pr�ximos 12 meses.\n");
    printf("Escolha: ");
}

void pergunta3() {
    printf("\nPor quanto tempo voc� pretende manter seus recursos investidos?\n");
    printf("(1) At� 1 ano.\n");
    printf("(2) De 1 a 3 anos.\n");
    printf("(3) De 3 a 5 anos\n");
    printf("(4) Por mais de 5 anos.\n");
    printf("Escolha: ");
}

void pergunta4() {
    printf("Quais s�o os produtos que voc� investe e/ou investiu mais de 10%% de sua renda nos �ltimos 12 meses?\n");
    printf("(1) Nenhum.\n");
    printf("(2) Renda Fixa(CDBs, Teseuro, Fundos de RF, etc).\n");
    printf("(3) Renda Vari�vel(Acoes, Fiis, etc).\n");
    printf("(4) Derivativos(Fundos, termos,etc).\n");
    printf("Escolha: ");
}

void investidorNivel() {

    struct Clientes clientes;

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    clientef = fopen(arquivoc, "r+b");
    if (clientef == NULL)
    {
        printf("Arquivo inexistente!");
        system("pause>nul");
        system("cls || clear");
    }

    int cod, encontrado = 0;
    printf("\nDigite o codigo que deseja alterar: ");
    scanf("%d", &cod);

    while (fread(&clientes, sizeof(clientes), 1, clientef))
    {
        if ((cod == clientes.codigo) && (clientes.deletado != '*'))
        {
            printf("\nCod %d - Nome: %-s - CPF %.3s.***.***-**\n", clientes.codigo, clientes.nome, clientes.cpf);
            encontrado = 1;

            fseek(clientef, sizeof(struct Clientes) * -1, SEEK_CUR);

            fflush(stdin);
            int qualnivel = 0, resultado = 0, cont;

            for(cont = 1; cont <=4; cont++){
                if(cont == 1) pergunta1();
                if(cont == 2) pergunta2();
                if(cont == 3) pergunta3();
                if(cont == 4) pergunta4();
                scanf("%d", &qualnivel);
                system("cls");
                logo();
                switch (qualnivel) {

                    case 1:
                        resultado += 5;
                        break;

                     case 2:
                        resultado += 10;
                        break;

                     case 3:
                        resultado += 15;
                        break;

                     case 4:
                        resultado += 20;
                        break;
                }
            }

            if(resultado <= 40){
                printf("O n�vel de investimento do cliente � conservador ");
                strcpy(clientes.nivelInvest, "Conservador");
                //printf("\nNivel investidor: %s \n", clientes.nivelInvest);
                fprintf(logFile,"Perfil do cliente testado com sucesso, o mesmo sendo conservador.\n");
                fclose(logFile);
                getch();
                menuClientes();

            } else if(resultado <= 60){
                printf("O n�vel de investimento do cliente � moderado ");
                strcpy(clientes.nivelInvest, "Moderado");
                //printf("\nNivel investidor: %s \n", clientes.nivelInvest);
                fprintf(logFile,"Perfil do cliente testado com sucesso, o mesmo sendo moderado.\n");
                fclose(logFile);
                getch();
                menuClientes();

            } else {
                printf("O n�vel de investimento do cliente � agressivo ");
                strcpy(clientes.nivelInvest, "Agressivo");
                //printf("\nNivel investidor: %s \n", clientes.nivelInvest);
                fprintf(logFile,"Perfil do cliente testado com sucesso, o mesmo sendo agressivo.\n");
                fclose(logFile);
                getch();
                menuClientes();

            }

            fprintf(logFile,"Nivel de investimento do cliente realizado.\n");
            fclose(logFile);

            system("pause>nul");
            system("cls || clear");
        }

            fwrite(&clientes, sizeof(clientes), 1, clientef);
            fseek(clientef, sizeof(clientes) * 0, SEEK_END);
    }
    if (!encontrado){
        fprintf(logFile,"Nivel de investimento do cliente falhou.\n");
        fclose(logFile);

        printf("\nCodigo nao cadastrado!!\n");
        system("pause>nul");
        system("cls || clear");
    }
    fclose(clientef);




}

