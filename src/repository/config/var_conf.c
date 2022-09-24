#include "stdio.h"

struct TamanhoMaxStrings_s {
    int nome;
} tamanhoMaxStrings_default = { 50 };

int main() {
    printf("%d", tamanhoMaxStrings_default.nome);
    return 0;
}