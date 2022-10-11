void cadastro ()

{
    //variaveis
    char nome[100], end[100],sex[12],em[100],nac[20],uf[2],cid[30],civ[15];
    int doc,num,year,op,op2;
    float nas;


    int dep, ndep,empre;
    char prof[35],nempre[30];
    float rend,bens;

    
    printf("\nQual é a sua profissão?");
    scanf("%s",prof);
    printf("\nEstá empregado no momento?");
    printf("\n1 - sim");
    printf("\nOutra tecla - nao");
    scanf("%d",&empre);

    if (empre == 1){
        printf("\nQual o nome da empresa em que está empregado?");
        scanf("%s",nempre);
    }
    else{
        //nempre=null;
    }
    if(nempre!=1){
        printf("\nQual a sua renda mensal?");
        scanf("%f",&rend);
    }
    printf("\nQuanto em bens você possui: ");
    scanf("%f", &bens);
}


