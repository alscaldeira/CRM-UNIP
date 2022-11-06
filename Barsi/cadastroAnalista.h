struct analista{
    char nomeAnalista[30];
    int senha,cpf;
}analista;

void cadastroAnalista(){
    setlocale(LC_ALL, "Portuguese");

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o cadastro do cliente.\n");
    fclose (logFile);


    FILE *auxAnal;
    FILE *CadastroAnalistasp;
    CadastroAnalistasp = fopen("analistas.txt", "a+b");
    auxAnal=fopen("auxiliarAnal.txt", "wb");
    if (CadastroAnalistasp == NULL || auxAnal==NULL){
        printf("Erro ao abrir o arquivo!\n");
        system("pause");
        menuPrincipal();
    }
  char continua[]={'S'};
  while(strcmp(continua,"N")!=0)
  {
    system("cls");
    fflush(stdin);
    printf("Digite o CPF do colaborador sem traços e pontos: ");
    scanf("%d",&analista.cpf);
    fflush(stdin);
    printf("Digite o nome(login)..........: ");
    gets(analista.nomeAnalista);
    printf("Digite a senha..........: ");
    scanf("%d", &analista.senha);
    fflush(stdin);

    fprintf(CadastroAnalistasp, "%s %d\n",analista.nomeAnalista,analista.senha);


    fseek(CadastroAnalistasp,SEEK_END,1);
    fwrite(&analista,sizeof(analista),1,CadastroAnalistasp);;
    printf("Deseja continuar?(S/N): ");
    scanf("%s", continua);
  }
  fclose(CadastroAnalistasp);
  fclose(auxAnal);
  logFile=fopen("log.txt", "a");
  fprintf(logFile, "Foi realizado o cadastro de novos integrantes no sistema.\n");
  fclose(logFile);
  printf("Cadastro/s realizado/s com sucesso.");
  system("pause");
  menuPrincipal();

}

void consultaAnalistas(){

    setlocale(LC_ALL, "Portuguese");

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o consulta do analista.\n");

    FILE *auxAnal;
    FILE *CadastroAnalistasp;
    CadastroAnalistasp = fopen("analistas.txt", "a+b");
    auxAnal=fopen("auxiliarAnal.txt", "wb");
    if (CadastroAnalistasp == NULL || auxAnal==NULL){
        printf("Erro ao abrir o arquivo!\n");
        system("pause");
        menuPrincipal();
    }
    char nome[100], senha[100];

    if(CadastroAnalistas != NULL){
        while(fscanf(CadastroAnalistas, "%[^\n]s, %[^\n]s", nome, senha) != EOF) {
            printf("%s , %s", nome, senha);
        }

    }
    fclose(CadastroAnalistas);

    system("pause");

    menuAnalista();
}

}
