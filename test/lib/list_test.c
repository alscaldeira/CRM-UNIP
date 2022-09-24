#include <stdio.h>
#include "./../../lib/list.c"

void testList() {
    char a[] = {"a"};
    char *aux = "foo";

    printf("%s\n", aux);

    char *c = " bar";

    char *d = *aux + *c;

    printf("%s\n <<<<", d);

    // char b[] = adicionar(a, aux);

    // int i;
    // for(i = 0; i < 10; i++)
    // printf("%c ", b[i]);
}

int main() {
    testList();
    return 0;
}