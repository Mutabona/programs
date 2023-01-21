#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    FILE *f, *f1;
    size_t size;
    f = fopen(argv[1], "rt");
    f1 = fopen(argv[2], "wt");
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    char *m = (char*)malloc(size+1);
    rewind(f);
    fread(m, size, 1, f);
    m[size]=0;
    fwrite(m, size, 1, f1);
    free(m);
	fclose(f);
	fclose(f1);
	return 0;
}