
void telaInicial() {
    setlocale(LC_ALL, "Portuguese");

    int saida, cont;
    for(cont = 1; cont <= 3; cont++) {
        system("cls");

        logo();

        printf("------------------------------------------------------\n");
        printf("1 - Login Analista\n");
        printf("2 - Login Gerente\n");
        printf("0 - Sair\n");
        printf("Digite uma op��o: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida >= 0 || saida <= 2) {
            break;
        } else {
            printf("Op��o inv�lida, por favor digite uma op��o v�lida!\n\n\n");
            system("pause");
        }

    }

    switch (saida) {
        case 1:
            loginAnalista();
            break;

        case 2:
            login();
            break;

        default:
            sair();
            break;
    }

}
