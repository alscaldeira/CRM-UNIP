void menuAnalista() {

    int saida;

    int errorsCount = 0;
    bool sair = false;

    while(errorsCount < 3 && !sair) {
        system("cls");

        logo();

        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Menu analista aberto.\n");
        fclose(logFile);

        printf("Qual opcao deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 - Incluir analista\n");
        printf("2 - Alterar analista\n");
        printf("3 - Consultar analista\n");
        printf("4 - Excluir analista\n");
        printf("5 - Retornar ao menu\n");
        printf("Digite uma opção: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        switch (saida) {
            case 1:
                cadastroAnalista();
                break;
           case 2:
                alteracaoAnalistas();
                break;
            case 3:
                consultaAnalistas();
                break;
            case 4:
                exclusaoAnalistas();
                break;
            case 5:
                sair = true;
                break;
            default:
                errorsCount++;
                opcaoInvalida(errorsCount);
                break;
        }
    }
}
