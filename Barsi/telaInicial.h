#ifndef TELAINICIAL_H_INCLUDED
#define TELAINICIAL_H_INCLUDED

void telaInicial() {
    int saida, cont;
    for(cont = 1; cont <= 3; cont++) {
        system("cls");

        logo();

        printf("------------------------------------------------------\n");
        printf("1 --- Login\n");
        printf("0 --- Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida == 1 || saida == 0) {
            break;
        } else {
            printf("Opcao invalida, por favor digite uma opcao valida!\n\n\n");
            printf("Digite uma tecla para continuar.....");
            getch();
        }

    }

    switch (saida) {
        case 1:
            //Enviar para a tela de login
            printf("Bem vindo a sua conta\n");
            login();
            break;

        default:
            //encerra o programa
            sair();
            break;
    }

}

#endif // TELAINICIAL_H_INCLUDED
