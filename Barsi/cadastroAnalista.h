#define BUFFER 7200

typedef struct{
    char nome[30],senha[30],cpf[11];
} AnalistaStruct;

char arquivo[] = "dados-analistas.bin";

void cadastroAnalista(){

    AnalistaStruct analista;

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o cadastro do cliente.\n");
    fclose (logFile);

    FILE *auxAnal;
    FILE *CadastroAnalistasp;
    CadastroAnalistasp = fopen(arquivo, "a");
    auxAnal=fopen("auxiliarAnal.txt", "ab");
    if (CadastroAnalistasp == NULL || auxAnal==NULL){
        printf("Erro ao abrir o arquivo!\n");
        system("pause");
        menuPrincipal();
    }

    char continua='S';
    while(continua == 83 || continua == 115) // Comparando com os códigos 'S' e 's'
    {
        system("cls");
        printf("Digite o CPF do colaborador sem traços e pontos: ");
        scanf("%s", &analista.cpf);
        printf("Digite o nome(login)...........................: ");
        scanf("%s", &analista.nome);
        printf("Digite a senha.................................: ");
        scanf("%s", &analista.senha);

        fprintf(CadastroAnalistasp, "%s; %s; %s;\n",
                analista.nome, analista.senha, analista.cpf);

        printf("Deseja continuar cadastrando?.............(S/N): ");
        continua = NULL;
        scanf("%s", &continua);
    }

    fclose(CadastroAnalistasp);
    fclose(auxAnal);
    logFile=fopen("log.txt", "a");
    fprintf(logFile, "Foi realizado o cadastro de novos integrantes no sistema.\n");
    fclose(logFile);
    printf("Cadastro/s realizado/s com sucesso.");
    system("pause");

}

void consultaAnalistas(){

    FILE *logFile;
    logFile=fopen("log.txt", "a");
    fprintf(logFile,"Iniciou o consulta do analista.\n");

    FILE *auxAnal;
    FILE *CadastroAnalistasp;
    CadastroAnalistasp = fopen(arquivo, "r");
    auxAnal=fopen("auxiliarAnal.txt", "r");
    if (CadastroAnalistasp == NULL || auxAnal==NULL){
        printf("Erro ao abrir o arquivo!\n");
        system("pause");
        return;
    }

    int cpf,a=0;
    //printf("Informe o CPF a ser pesquisado:");
    //scanf("%d",&cpf);
    fflush(stdin);
    fseek(CadastroAnalistasp,SEEK_SET,1);

    char buff[BUFFER];
    fread(&buff,sizeof(buff),1,CadastroAnalistasp);

    AnalistaStruct * analistas[100];
    converterBufferParaStruct(buff, analistas);

    /*
    while(!feof(CadastroAnalistasp)){
        printf("Nome do analista: %s\n", analista.nomeAnalista);
        if(analista.cpf==cpf){
            a++;
            printf("CPF: %d\n",analista.cpf);
            printf("Login:%s\n",analista.nomeAnalista);
            printf("Senha:%d\n",analista.senha);
        }
        fread(&analista,sizeof(analista),1,CadastroAnalistasp);
    }*/
    //if(a==0){
    //    printf("Analista não encontrado.\n");
    //}

    fclose(CadastroAnalistasp);
    fclose(auxAnal);
    system("pause");
}

void exclusaoAnalistas() {}
void alteracaoAnalistas() {}

void converterBufferParaStruct(char buff[], AnalistaStruct *analista[]) {
    int maxCharsEmAnalista = 75;

    int posicaoItem = 1;
    int posicaoAnalista = 1;
    int posicaoChar = 0;

    analista = (AnalistaStruct*) malloc(sizeof(AnalistaStruct) * 100 * (sizeof(char) * 3));

    /*printf("size(Analista): %d; size(Nome): %d; size(Senha): %d; size(CPF): %d; size(char): %d\n",
           sizeof(AnalistaStruct),
           sizeof(analista[0]->nome),
           sizeof(analista[0]->senha),
           sizeof(analista[0]->cpf),
           sizeof(char));
*/

    for(int i=0; i<sizeof(buff); i++) {

        if(buff == NULL || buff == '\0') break;

        //if(posicaoItem == 1) strncat(analista[posicaoAnalista]->nome, &buff[i], 1);
        if(posicaoItem == 1) {
            analista = malloc(sizeof(analista) * sizeof(AnalistaStruct));
            analista[posicaoAnalista] = malloc(sizeof(AnalistaStruct));
            analista[posicaoAnalista]->nome[posicaoChar] = buff[i];
        }
        //if(posicaoItem == 2) strcat(analista[posicaoAnalista]->senha, buff[i]);
        //if(posicaoItem == 3) strcat(analista[posicaoAnalista]->cpf, buff[i]);

        /*
        printf(" Analista: %d { ", posicaoAnalista);
        printf("Nome: %s; ", analista[posicaoAnalista]->nome);
        printf("Senha: %s; ", analista[posicaoAnalista]->senha);
        printf("CPF: %s }\n", analista[posicaoAnalista]->cpf);
        */

        printf("%c ", buff[i]);
        printf("%s[%d] ", analista[posicaoAnalista]->nome[posicaoChar], i);
        printf("\n");

        posicaoChar++;
        if(buff[i] == ';') posicaoItem++;
        if(buff[i] == '\n') posicaoItem = 1;
    }
}
