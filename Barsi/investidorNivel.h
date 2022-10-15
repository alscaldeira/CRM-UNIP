#ifndef INVESTIDORNIVEL_H_INCLUDED
#define INVESTIDORNIVEL_H_INCLUDED


void investidorNivel() {

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o teste de perfil de investidor.\n");
    fclose(logFile);

    system("cls");
    logo();

    int qualnivel = 0, resultado = 0;
    printf("\n\nCom quais produtos abaixo voce tem familiaridade e/ou costuma investir com frequencia?\n");
    printf("(1) Nenhum.\n");
    printf("(2) Renda Fixa(CDBs, Teseuro, Fundos de RF, etc).\n");
    printf("(3) Renda Variavel(Acoes, Fiis, etc).\n");
    printf("(4) Derivativos(Fundos, termos,etc).\n");
    printf("Escolha: ");
    scanf("%d", &qualnivel);


    switch (qualnivel) {

        case 1:
            resultado = 10;
            break;

         case 2:
            resultado = 20;
            break;

         case 3:
            resultado = 30;
            break;

         case 4:
            resultado = 40;
            break;

    }

    system("cls");
    logo();
    printf("Qual percentual dos seus recursos voce espera resgatar nos proximos 12 meses?\n");
    printf("(1) Mais de 25%%.\n");
    printf("(2) Entre 5%% e 25%%.\n");
    printf("(3) Ate 5%%.\n");
    printf("(4) Nao tenho expectivas de resgatar recursos nos proximos 12 meses.\n");
    printf("Escolha: ");
    scanf("%d", &qualnivel);

    switch (qualnivel) {

        case 1:
            resultado += 10;
            break;

         case 2:
            resultado += 20;
            break;

         case 3:
            resultado += 30;
            break;

         case 4:
            resultado += 40;
            break;

    }

    system("cls");
    logo();
    printf("Por quanto tempo pretende manter seus recursos investidos?\n");
    printf("(1) Ate 1 ano.\n");
    printf("(2) De 1 a 3 anos.\n");
    printf("(3) De 3 a 5 anos\n");
    printf("(4) Por mais de 5 anos.\n");
    printf("Escolha: ");
    scanf("%d", &qualnivel);

    switch (qualnivel) {

        case 1:
            resultado += 10;
            break;

         case 2:
            resultado += 20;
            break;

         case 3:
            resultado += 30;
            break;

         case 4:
            resultado += 40;
            break;

    }

    system("cls");
    logo();
    printf("Em quais dos produtos voce investe e/ou investiu mais de 10%% de sua renda nos ultimos 12 meses?\n");
    printf("(1) Nenhum.\n");
    printf("(2) Renda Fixa(CDBs, Teseuro, Fundos de RF, etc).\n");
    printf("(3) Renda Variavel(Acoes, Fiis, etc).\n");
    printf("(4) Derivativos(Fundos, termos,etc).\n");
    printf("Escolha: ");
    scanf("%d", &qualnivel);

    switch (qualnivel) {

        case 1:
            resultado += 10;
            break;

         case 2:
            resultado += 20;
            break;

         case 3:
            resultado += 30;
            break;

         case 4:
            resultado += 40;
            break;

    }

    if(resultado <= 40){
        printf("vc e conservador %d", resultado);
        //Carlos- acrescentei o log e fiz o retorno para o menu.
        fprintf(logFile,"Perfil do cliente testado com sucesso, o mesmo sendo conservador.\n");
        fclose(logFile);
        getch();
        menuPrincipal();

    } else if(resultado <= 60) {
        printf("vc e moderado %d", resultado);
        //Carlos- acrescentei o log e fiz o retorno para o menu.
        fprintf(logFile,"Perfil do cliente testado com sucesso, o mesmo sendo moderado.\n");
        fclose(logFile);
        getch();
        menuPrincipal();

    } else {
        printf("vc e agressivo %d", resultado);
        //Carlos- acrescentei o log e fiz o retorno para o menu.
        fprintf(logFile,"Perfil do cliente testado com sucesso, o mesmo sendo agressivo.\n");
        fclose(logFile);
        getch();

        menuPrincipal();

    }



}

#endif // INVESTIDORNIVEL_H_INCLUDED
