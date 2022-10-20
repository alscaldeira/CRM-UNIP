void cadastroClientes(){
    setlocale(LC_ALL, "Portuguese");

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o cadastro do cliente.\n");
        // variaveis
    char nome[100], endereco[100], sexo[15], email[100], nacionalidade[20],
    uf[2], nascimento[30], cidade[30], estCivil[15], cpf[30];
    int op, op2; //op um está ligado ao sexo do cliente, já a opção dois o estado civil.

    int dependentes, numeroDependentes, empregado;
    char profissao[35], nomeEmprego[30];
    float renda, bens;

    FILE *cadastroCLIENTES;
    if((cadastroCLIENTES = fopen("clientes.txt", "a"))==NULL){
        printf("Falha na abertura do arquivo!");
        fprintf(logFile,"Falha ao cadastrar cliente.\n");
        fclose(logFile);
        getch();

        menuPrincipal();
}

    system("cls");
    logo();

    //Dados pessoais
    fflush(stdin);
    printf("Nome: ");
    scanf("%[^\n]", nome);
    fflush(stdin);
    printf("CPF: ");
    scanf("%[^\n]", cpf);
    fflush(stdin);
    printf("Data de nascimento ex(24/09/2022): ");
    scanf("%[^\n]", nascimento);

    //sexualidade
    printf("\nSexo\n");
    printf("1 -- Masculino\n");
    printf("2 -- Feminino\n");
    printf("3 -- Nao definir\n");
    printf("Digite uma opcao valida: ");
    scanf("%d", &op);

    switch (op){

    case 1:
        strcpy(sexo, "Masculino");
        break;

    case 2:
        strcpy(sexo, "Feminino");
        break;

    case 3:
        strcpy(sexo, "Nao definir");
        break;
    }

    fflush(stdin);
    printf("\nNacionalidade: ");
    scanf("%[^\n]", nacionalidade);
    printf("\nEstado(ex:SP,RJ): ");
    scanf("%s", uf);
    fflush(stdin);
    printf("\nCidade: ");
    scanf("%[^\n]", cidade);
    fflush(stdin);
    printf("\nEndereco: ");
    scanf("%[^\n]", endereco);
    printf("\nEmail: ");
    scanf("%s", email);

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
        strcpy(estCivil, "Casado/a");
        break;

    case 2:
        strcpy(estCivil, "Solteiro/a");
        break;

    case 3:
        strcpy(estCivil, "União estavel");
        break;

    case 4:
        strcpy(estCivil, "Viuvo/a");
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
        scanf("%d", &numeroDependentes);
    } else {
        numeroDependentes = 0;
    }

    fflush(stdin);
    printf("\nValor em bens que voce possui: ");
    scanf("%f", &bens);
    fflush(stdin);
    printf("\nQual a sua profissao? ");
    scanf("%[^\n]", profissao);
    printf("\nEsta empregado no momento?\n");
    printf("1 -- Sim\n");
    printf("2 -- Nao\n");
    printf("Digite uma opcao valida: ");
    scanf("%d", &empregado);

    if (empregado == 1){
        fflush(stdin);
        printf("\nQual o nome da empresa em que esta empregado? ");
        scanf("%[^\n]", nomeEmprego);
    } else {
        strcpy(nomeEmprego, "Desempregado/a");
    }
    if (empregado != 1){
        renda=0.00;
    } else {
        printf("\nQual a sua renda mensal: ");
        scanf("%f", &renda);
    }



    fprintf(cadastroCLIENTES,"Nome:%s\nCPF:%s\nNascimento:%s\nSexo:%s\nNacionalidade:%s\nUF:%s\nCidade:%s",nome,cpf,nascimento,sexo,nacionalidade,uf,cidade);
    fprintf(cadastroCLIENTES,"\nEndereco:%s\nEmail:%s\nEstado civil:%s\nNumero de dependetes:%d\nProfissão:%s\n",endereco,email,estCivil,numeroDependentes,profissao);
    fprintf(cadastroCLIENTES,"Nome da empresa atual:%s\nRenda Mensal:%2.f\nValor em bens:%2.f\n\n",nomeEmprego,renda,bens);

    fclose(cadastroCLIENTES);
    printf ("\n\nCadastro realizado com sucesso!!");
    //Abertura do log para registrar o cadastro realizado. Carlos
    fprintf(logFile,"Cadastro de cliente realizado.\n");
    fclose(logFile);

    getch();


    menuPrincipal();
}

