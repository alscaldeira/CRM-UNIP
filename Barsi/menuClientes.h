
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
        /*printf("2 --- Alterar cliente\n");
        printf("3 --- Consultar cliente\n");
        printf("4 --- Excluir cliente\n");*/
        printf("5 --- Retornar ao menu\n");
        printf("Digite uma op��o: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida < 1 || saida <= 5){
            break;
        } else {
            printf("Op��o invalida, por favor digite uma op��o v�lida!\n\n\n");
            //Carlos - Acrescentei o registro do log caso o usu�rio tenha digitado uma op��o invalida.
            FILE *logFile;
            logFile=fopen("log.txt", "a");
            fprintf(logFile,"Usu�rio digitou uma op��o invalida.\n");
            fclose(logFile);
            system("pause");
        }
    }

    switch (saida) {
        case 1:
            cadastroClientes();
            break;

       /* case 2:
            alterarClientes();
            break;

        case 3:
            consultarClientes();
            break;

        case 4:
            excluirClientes();
            break; */

        default:
            menuPrincipal();
            break;

    }

}
