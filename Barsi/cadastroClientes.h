void cadastroClientes()

{
        // variaveis
    char nome[100], endereco[100], sexo[15], email[100], nacionalidade[20], uf[2], cidade[30], estCivil[15];
    int cpf, ano, op, op2; //op um está ligado ao sexo do cliente, já a opção dois o estado civil.
    float nas;

    int dependentes, numeroDependentes, empregado;
    char profissao[35], nomeEmprego[30];
    float renda, bens;
        // Tentativa de salvar o cadastro em TXT
  FILE *cadastroCLIENTES;
  //abertura do arquivo. Caso ocorra falha, finaliza o programa.
  if((cadastroCLIENTES=fopen("clientes.txt", "a"))==NULL)
  {
    printf("Falha na abertura do arquivo!");
    getch();
    //menu();
  }

    system("cls");
    logo();
    // escopo do cadastro
    fflush(stdin);
    printf("\n\nNome: ");
    scanf("%[^\n]", nome);
    printf("\nCPF(sem espacos e caracteres especiais): ");
    scanf("%d", &cpf);
    printf("\nData de nascimento ex(24.09): ");
    scanf("%f", &nas);
    printf("\nAno de nascimento: ");
    scanf("%d", &ano);
    printf("\n Sexo: ");
    printf("\n 1- Masculino");
    printf("\n 2- Feminino");
    printf("\n 3- Nao definir\n");
    scanf("%d", &op);

    switch (op)
    {
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
    printf("\nEmail:");
    scanf("%s", email);
    printf("\nEstado civil: 1 - Casado/a");
    printf("\n2-Solteiro/a");
    printf("\n3-Uniao estavel");
    printf("\n4-Vilvo/a\n");
    scanf("%d", &op2);

    switch (op2)
    {
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


    printf("\nTem dependestes?\n");
    printf("\n1 - sim");
    printf("\nOutra tecla - nao\n");
    scanf("%d", &dependentes);

    if (dependentes == 1)
    {
        printf("Quantos dependestes?");
        scanf("%d", &numeroDependentes);
    }
    else
    {
        numeroDependentes = 0;
    }

    fflush(stdin);
    printf("\nQuanto em bens voce possui? \n");
    scanf("%f", &bens);
    fflush(stdin);
    printf("\nQual a sua profissao?\n");
    scanf("%[^\n]", profissao);
    printf("\nEsta empregado no momento?");
    printf("\n1 - sim");
    printf("\nOutra tecla - nao\n");
    scanf("%d", &empregado);

    if (empregado == 1)
    {
        fflush(stdin);
        printf("\nQual o nome da empresa em que esta empregado?\n");
        scanf("%[^\n]", nomeEmprego);
    }
    else
    {
        strcpy(nomeEmprego, "Desempregado/a");
    }
    if (empregado != 1)
    {
        renda=0.00;
    }
    else
    {
        printf("\nQual a sua renda mensal\n");
        scanf("%f", &renda);
    }



    fprintf(cadastroCLIENTES,"Nome:%s\nCPF:%d\nNascimento:%2.f.%d\nSexo:%s\nNacionalidade:%s\nUF:%s\nCidaded:%s",nome,cpf,nas,ano,sexo,nacionalidade,uf,cidade);
    fprintf(cadastroCLIENTES,"\nEndereco:%s\nEmail:%s\nEstado civil:%s\nNumero de dependetes:%d\nProfissão:%s\n",endereco,email,estCivil,numeroDependentes,profissao);
    fprintf(cadastroCLIENTES,"Nome da empresa atual:%s\nRenda Mensal:%2.f\nValor em bens:%2.f\n\n",nomeEmprego,renda,bens);

    fclose(cadastroCLIENTES);
    printf ("\n\nCadastro realizado com sucesso");

    getch();


    menuPrincipal();
}

