
void menuClientes() {
    setlocale(LC_ALL, "Portuguese");

    int saida;

    for(int cont = 1; cont <= 3; cont++){
        system("cls");

        logo();

        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Menu cliente aberto.\n");
        fclose(logFile);


        printf("Qual opcao deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 --- Incluir cliente\n");
        printf("2 --- Alterar cliente\n");
        printf("3 --- Consultar cliente\n");
        printf("4 --- Excluir cliente\n");
        printf("5 --- Investidor nivel\n");
        printf("6 --- Retornar ao menu\n")

        printf("Digite uma opção: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida < 1 || saida <= 6){
            break;
        } else {
            printf("Opção invalida, por favor digite uma opção válida!\n\n\n");
            //Carlos - Acrescentei o registro do log caso o usuário tenha digitado uma opção invalida.
            FILE *logFile;
            logFile=fopen("log.txt", "a");
            fprintf(logFile,"Usuário digitou uma opção invalida.\n");
            fclose(logFile);
            system("pause");
        }
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

        default:
            menuPrincipal();
            break;

    }

}
