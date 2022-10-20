
void telaInicial() {
    setlocale(LC_ALL, "Portuguese");

    int saida, cont;
    for(cont = 1; cont <= 3; cont++) {
        system("cls");

        logo();

        printf("------------------------------------------------------\n");
        printf("1 --- Login\n");
        printf("0 --- Sair\n");
        printf("Digite uma opção: ");
        scanf("%d", &saida);
        printf("------------------------------------------------------\n");

        if(saida == 1 || saida == 0) {
            break;
        } else {
            printf("Opção inválida, por favor digite uma opção válida!\n\n\n");
            system("pause");
        }

    }

    switch (saida) {
        case 1:
            login();
            break;

        default:
            sair();
            break;
    }

}
