void mensagem1(){
    printf("\n\nCom quais produtos abaixo você tem familiaridade e/ou costuma investir com frequência?\n");
    printf("(1) Nenhum.\n");
    printf("(2) Renda Fixa(CDBs, Tesouro, Fundos de RF, etc).\n");
    printf("(3) Renda Variável(Ações, Fiis, etc).\n");
    printf("(4) Derivativos(Fundos, termos,etc).\n");
    printf("Escolha: ");
}

void mensagem2() {
    printf("\nQual percentual dos seus recursos você espera resgatar nos próximos 12 meses?\n");
    printf("(1) Mais de 25%%.\n");
    printf("(2) Entre 5%% e 25%%.\n");
    printf("(3) Até 5%%.\n");
    printf("(4) Não tenho expectivas de resgatar meus recursos nos próximos 12 meses.\n");
    printf("Escolha: ");
}

void mensagem3() {
    printf("\nPor quanto tempo você pretende manter seus recursos investidos?\n");
    printf("(1) Até 1 ano.\n");
    printf("(2) De 1 a 3 anos.\n");
    printf("(3) De 3 a 5 anos\n");
    printf("(4) Por mais de 5 anos.\n");
    printf("Escolha: ");
}

void mensagem4() {
    printf("Quais são os produtos que você investe e/ou investiu mais de 10%% de sua renda nos últimos 12 meses?\n");
    printf("(1) Nenhum.\n");
    printf("(2) Renda Fixa(CDBs, Teseuro, Fundos de RF, etc).\n");
    printf("(3) Renda Variável(Acoes, Fiis, etc).\n");
    printf("(4) Derivativos(Fundos, termos,etc).\n");
    printf("Escolha: ");
}

void investidorNivel() {
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o teste de perfil de investidor.\n");
    fclose(logFile);

    system("cls");
    logo();

    int qualnivel = 0, resultado = 0, cont;

    for(cont = 1; cont <=4; cont++){
        if(cont == 1) mensagem1();
        if(cont == 2) mensagem2();
        if(cont == 3) mensagem3();
        if(cont == 4) mensagem3();
        scanf("%d", &qualnivel);
        system("cls");
        logo();
        switch (qualnivel) {

            case 1:
                resultado += 5;
                break;

             case 2:
                resultado += 10;
                break;

             case 3:
                resultado += 15;
                break;

             case 4:
                resultado += 20;
                break;


        }



    }


    if(resultado <= 40){
        printf("Você é conservador %d", resultado);
        //Carlos- acrescentei o log e fiz o retorno para o menu.
        fprintf(logFile,"Perfil do cliente testado com sucesso, sendo agora classificado como conservador.\n");
        fclose(logFile);
        getch();
        menuPrincipal();

    } else if(resultado <= 60){
        printf("Você é moderado %d", resultado);
        //Carlos- acrescentei o log e fiz o retorno para o menu.
        fprintf(logFile,"Perfil do cliente testado com sucesso, sendo agora classificado como moderado.\n");
        fclose(logFile);
        getch();
        menuPrincipal();

    } else {
        printf("Você é agressivo %d", resultado);
        //Carlos- acrescentei o log e fiz o retorno para o menu.
        fprintf(logFile,"Perfil do cliente testado com sucesso, sendo agora classificado como agressivo.\n");
        fclose(logFile);
        getch();

        menuPrincipal();

    }



}
