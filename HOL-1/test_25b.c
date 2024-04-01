#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("%d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("%s ", argv[i]);  // Added a space after each argument
    }
    printf("\n");
    return 0;
}
