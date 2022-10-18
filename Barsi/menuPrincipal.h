
void menuPrincipal() {

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
        printf("1 --- Renda fixa\n");
        printf("2 --- Renda variavel\n");
        printf("3 --- Cadastro de cliente\n");
        printf("4 --- Perfil do investidor\n");
        printf("5 --- Cadastrar novo analista\n");
        printf("9 --- Logout\n");
        printf("0 --- Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida < 0 || saida <= 5 || saida == 9){
            break;
        } else {
            printf("Opcao invalida, por favor digite uma opcao valida!\n\n\n");
            //Carlos - Acrescentei o registro do log caso o usuário tenha digitado uma opção invalida.
            FILE *logFile;
            logFile=fopen("log.txt", "a");
            fprintf(logFile,"Usuario digitou uma opção invalida.\n");
            fclose(logFile);
            system("pause");
        }
    }

    switch (saida) {
        case 1:
            printf("Bem vindo a opcao de renda fixa");
            //rendaFixa();
            break;

        case 2:
            printf("Bem vindo a opcao de renda variavel");
            //rendaVariavel();
            break;

        case 3:
            cadastroClientes();
            break;

        case 4:
            investidorNivel();
            break;

        case 5:
            cadastroAnalista();
            break;

        case 9:
            telaInicial();
            break;

        default:
            sair();
            break;

    }

}
