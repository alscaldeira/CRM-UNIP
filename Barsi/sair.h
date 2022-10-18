
void sair(){

    system("cls");
    printf("Obrigado volte sempre!\n\n\n\n");
    //Carlos - Log registra saidas.
    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Sistema encerrado.\n");
    fclose(logFile);
    system("pause");
    return 0;
}

