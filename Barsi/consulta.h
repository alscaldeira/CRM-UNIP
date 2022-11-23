void consulta(char entidade[]) {

    char arquivo[80];
    strcpy(arquivo, entidade);
    strcat(arquivo, ".txt");

    FILE *ptr;

    ptr=fopen(arquivo, "r+");

    if(ptr == NULL) {
        arquivoNaoEncontrado(arquivo);
        fclose(ptr);

        criarNovoArquivo();

        system("pause");
        return;
    }

    char str[] = "Olá :)";

    fwrite(str, 1, sizeof(str), ptr);

    fflush(ptr);

    char txt[255];

    fread(&txt, sizeof(char), 255, ptr);

    printf("%s <<<<<<<<<<< %l <<<<<<<< \n\n", txt, sizeof(txt));
    system("pause");

    fclose(ptr);

    info("Cadastro recuperado");
    system("pause");
}

void criarNovoArquivo(char entidade[]) {
    info("Criando novo arquivo");

    char arquivo[80];
    strcpy(arquivo, entidade);
    strcat(arquivo, ".txt");

    FILE *file;
    file = fopen(entidade, "w+");
    fflush(file);
    fclose(file);
    consulta(entidade);
}
