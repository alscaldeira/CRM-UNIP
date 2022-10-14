#ifndef SAIR_H_INCLUDED
#define SAIR_H_INCLUDED

void sair(){

    system("cls");
    printf("Obrigado volte sempre!\n\n\n\n");
    //Carlos - Log registra saidas.
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Sistema encerrado.\n");
    fclose(logFile);
    printf("Digite uma tecla para sair..............");
    getch();
    return 0;
}

#endif // SAIR_H_INCLUDED
