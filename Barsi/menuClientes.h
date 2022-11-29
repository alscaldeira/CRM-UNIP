
void menuClientes() {
    int errorsCount = 0;
    bool sair = false;
    int saida = 0;

    while(errorsCount < 3 && !sair){
        system("cls");

        logo();

        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Menu cliente aberto.\n");
        fclose(logFile);


        printf("Qual opcao deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 - Incluir cliente\n");
        printf("2 - Alterar cliente\n");
        printf("3 - Consultar cliente\n");
        printf("4 - Excluir cliente\n");
        printf("5 - Investidor nível\n");
        printf("6 - Retornar ao menu\n");
        printf("Digite uma opção: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida < 1 || saida > 6){
            printf("Usuário digitou uma opção inválida!\n\n\n");
            //Carlos - Acrescentei o registro do log caso o usuario tenha digitado uma opcao invalida.
            FILE *logFile;
            logFile=fopen("log.txt", "a");
            fprintf(logFile,"Usuário digitou .\n");
            fclose(logFile);
            system("pause");
        }

            switch (saida) {
            case 1:
                cadastroClientes();
                break;

            case 2:
                alterarClientes();
                break;

            case 3:
                consultarClientes();
                break;

            case 4:
                excluirClientes();
                break;

            case 5:
                investidorNivel();
                break;

            case 6:
                sair = true;
                break;

            default:
                errorsCount++;
                break;

        }

    }

}
