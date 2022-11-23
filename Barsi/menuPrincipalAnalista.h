void menuPrincipalAnalista() {
    int saida;

    int errorsCount = 0;
    bool finalizar = false;

    while(errorsCount < 3 && !finalizar) {
        system("cls");

        logo();

        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Menu principal do analista aberto.\n");
        fclose(logFile);

        printf("Qual opção deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 - Gerenciamento do cliente\n");
        printf("0 - Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        switch(saida) {
            case 1:
                menuClientes();
                break;
            case 0:
                finalizar = true;
                sair();
                break;
            default:
                errorsCount++;
                opcaoInvalida(errorsCount);
                break;
        }
    }
}
