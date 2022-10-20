
void menuPrincipal() {
    setlocale(LC_ALL, "Portuguese");

    int saida;

    for(int cont = 1; cont <= 3; cont++){
        system("cls");

        logo();

        //Carlos - Registro de abertura de menu no LOG.
        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Menu principal aberto.\n");
        fclose(logFile);


        printf("Qual opcao deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 --- Gerenciamento do cliente\n");
        printf("2 --- Gest�o do analista\n");
        printf("9 --- Logout\n");
        printf("0 --- Sair\n");
        printf("Digite uma op��o: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida < 0 || saida <= 2 || saida == 9){
            break;
        } else {
            printf("Op��o inv�lida, por favor digite uma op��o v�lida!\n\n\n");
            //Carlos - Acrescentei o registro do log caso o usu�rio tenha digitado uma op��o invalida.
            FILE *logFile;
            logFile=fopen("log.txt", "a");
            fprintf(logFile,"Usu�rio digitou uma op��o inv�lida.\n");
            fclose(logFile);
            system("pause");
        }
    }

    switch (saida) {
        case 1:
            menuClientes();
            break;

        case 2:
            menuAnalista();
            break;

        case 9:
            telaInicial();
            break;

        default:
            sair();
            break;

    }

}
