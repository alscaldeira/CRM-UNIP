void menuPrincipal() {
    int saida;

    int errorsCount = 0;
    bool finalizar = false;

    while(errorsCount < 3 && !finalizar) {
        system("cls");

        logo();

        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Menu principal aberto.\n");
        fclose(logFile);

        printf("Qual op��o deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 - Gerenciamento do cliente\n");
        printf("2 - Gest�o do analista\n");
        printf("0 - Sair\n");
        printf("Digite uma op��o: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        switch(saida) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuAnalista();
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

void opcaoInvalida(int errorsCount) {
    printf("Voc� ser� direcionado ao menu!\n\n");

    FILE *logFile;
    logFile=fopen("log.txt", "a");

    fprintf(logFile,"O usu�rio digitou uma op��o inv�lida pela %d� vez.\n", errorsCount);

    if(errorsCount == 2) {
        printf("Voc� digitou um total de duas respostas inv�lidas.\n");
        printf("O software ir� finalizar caso a pr�xima entrada digitada for inv�lida.\n\n");
    } else if (errorsCount == 3) {
        printf("O software ser� fechado devido � quantidade excessiva de entradas inv�lidas.\n");
        fprintf(logFile,"Software ser� fechado devido � quantidade de erros excessivos de entrada.", errorsCount);
    }

    fclose(logFile);
    system("pause");
}
