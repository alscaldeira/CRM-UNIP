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

        printf("Qual opcao deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 - Gerenciamento do cliente\n");
        printf("2 - Gest�o do analista\n");
        printf("9 - Logout\n");
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
            case 9:
                telaInicial();
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
    printf("Op��o inv�lida, por favor digite uma op��o v�lida!\n\n");

    FILE *logFile;
    logFile=fopen("log.txt", "a");

    fprintf(logFile,"Usu�rio digitou uma op��o inv�lida pela %d� vez.\n", errorsCount);

    if(errorsCount == 2) {
        printf("Voc� teve um total de duas respostas inv�lidas.\n");
        printf("O software ir� finalizar caso a pr�xima entrada for inv�lida.\n\n");
    } else if (errorsCount == 3) {
        printf("O software ser� fechado devido � quantidade excessiva de entrada inv�lida.\n");
        fprintf(logFile,"Software ser� fechado devido � quantidade de erros excessivos de entrada.", errorsCount);
    }

    fclose(logFile);
    system("pause");
}
