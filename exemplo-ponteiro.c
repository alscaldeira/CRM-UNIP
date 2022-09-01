#include <stdio.h>

void test(int* number) {
    *number = 6;
}

int main() {
    int number = 5;
    test(&number);
    printf("Testing this number: %d\n", number);
    return 0;
}
