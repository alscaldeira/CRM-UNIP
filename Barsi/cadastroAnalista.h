
void cadastroAnalista(){

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o cadastro do cliente.\n");

    char nomeAnalista[30],continua[]={'S'};
    int senha;
  FILE *CadastroAnalistas;
  if((CadastroAnalistas=fopen("analistas.txt", "a"))==NULL)
  {
    printf("Falha na abertura do arquivo!");
    strcpy(continua,"N");
    getch();
    menuPrincipal();
  }
  while(strcmp(continua,"N")!=0)
  {
    system("cls");
    fflush(stdin);
    printf("Digite o nome(login)..........: ");
    scanf("%[^\n]", nomeAnalista);
    printf("Digite a senha..........: ");
    scanf("%f", &senha);

    fprintf(CadastroAnalistas, "%s %d\n",nomeAnalista,senha);

    fprintf(logFile, "Foi realizado o cadastro de novos integrantes no sistema.\n");

    printf("Deseja continuar?(S/N): ");
    scanf("%s", continua);
  }
  fclose(CadastroAnalistas);
  fclose(logFile);
  printf("Cadastro/s realizado/s com sucesso.");
  getch();
  menuPrincipal();

}
