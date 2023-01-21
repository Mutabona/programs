#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    FILE *f, *f1;
    size_t size;
    f1 = fopen("output.txt", "wt");
    if (!argv[1]) {
        fprintf(f1, "Usage: stat filename\n");
        return 1;
    }
    f = fopen(argv[1], "rt");
    if (!f) {
        fprintf(f1, "Can't open file %s\n", argv[1]);
        return 2;
    }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fprintf(f1, "%lu\n", size);
    return 0;
}