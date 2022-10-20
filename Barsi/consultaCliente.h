
void consultaCliente() {
    setlocale(LC_ALL, "Portuguese");

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o consulta do cliente.\n");

    FILE *cadastroCLIENTES;

    if((cadastroCLIENTES = fopen("clientes.txt", "r")) == NULL){
        printf("Falha na abertura do arquivo!");
        fprintf(logFile,"Falha ao consultar cliente.\n");
        fclose(logFile);
        getch();
    }

    char nome[100], endereco[100], sexo[15], email[100], nacionalidade[20],
    uf[2], nascimento[30], cidade[30], estCivil[15], cpf[30];

    if(cadastroCLIENTES != NULL){
        while(fscanf(cadastroCLIENTES, "%[^\n]s, %[^\n]s", nome, cpf) != EOF) {
            printf("%s\n, %s\n", nome, cpf);
        }

    }
    fclose(cadastroCLIENTES);

    menuClientes();
}
