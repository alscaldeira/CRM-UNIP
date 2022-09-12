#include "stdio.h"

// Entidade do usuário
#include "./entity/usuario.c"

// Leitor de arquivo
#include "./../../lib/leitor_txt.c"

void consulta() {
    Usuario usuario = { "Anderson", 12 };
    printf("%s\n\n", usuario.nome);
    lerArquivo();
    // textoParaUsuario();
}