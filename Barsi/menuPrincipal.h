#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menuPrincipal() {

    int saida;

    for(int cont = 1; cont <= 3; cont++){
        system("cls");

        logo();

        //Carlos - Registro de abertura de menu no LOG.
        FILE *logFile;
        logFile=fopen("log.txt", "a");
        fprintf(logFile,"Menu principal aberto.\n");


        printf("Qual opcao deseja:\n");
        printf("------------------------------------------------------\n");
        printf("1 --- Renda fixa\n");
        printf("2 --- Renda variavel\n");
        printf("3 --- Cadastro de cliente\n");
        printf("4 --- Perfil do investidor\n");
        printf("5 --- Cadastrar novo colaborador\n");
        printf("9 --- Logout\n");
        printf("0 --- Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida < 0 || saida <= 4 || saida == 9){
            break;
        } else {
            printf("Opcao invalida, por favor digite uma opcao valida!\n\n\n");
            printf("Digite uma tecla para continuar.....");
            //Carlos - Acrescentei o registro do log caso o usuário tenha digitado uma opção invalida.
            FILE *logFile;
            logFile=fopen("log.txt", "a");
            fprintf(logFile,"Usuario digitou uma opção invalida.\n");
            fclose(logFile);
            getch();
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
            printf("Bem vindo ao cadastro");
            cadastroClientes();
            break;

        case 4:
            printf("Realizar o perfil do investidor");
            investidorNivel();
            break;

        case 5:
            printf("Cadastrar novo colaborador");
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

#endif // MENUPRINCIPAL_H_INCLUDED
