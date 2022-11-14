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
        printf("2 - Gestão do analista\n");
        printf("9 - Logout\n");
        printf("0 - Sair\n");
        printf("Digite uma opção: ");
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
    printf("Opção inválida, por favor digite uma opção válida!\n\n");

    FILE *logFile;
    logFile=fopen("log.txt", "a");

    fprintf(logFile,"Usuário digitou uma opção inválida pela %dº vez.\n", errorsCount);

    if(errorsCount == 2) {
        printf("Você teve um total de duas respostas inválidas.\n");
        printf("O software irá finalizar caso a próxima entrada for inválida.\n\n");
    } else if (errorsCount == 3) {
        printf("O software será fechado devido à quantidade excessiva de entrada inválida.\n");
        fprintf(logFile,"Software será fechado devido à quantidade de erros excessivos de entrada.", errorsCount);
    }

    fclose(logFile);
    system("pause");
}
