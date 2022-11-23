void consultaAnalista(){
    setlocale(LC_ALL, "Portuguese");

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o consulta do analista.\n");

    FILE *CadastroAnalistas;

    if((CadastroAnalistas = fopen("analistas.txt", "r")) == NULL){
        printf("Falha na abertura do arquivo!");
        fprintf(logFile,"Falha ao consultar analista.\n");
        fclose(logFile);
        getch();
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
