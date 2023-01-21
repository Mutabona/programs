#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	size_t size;
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s arg1 arg2...\n", argv[0]);
		return 1;
	}
	FILE *f;
	f = fopen(argv[1], "rt");
	if(!f)
	{
		fprintf(stderr, "Cant' open file %s\n", argv[1]);
		return 2;
	}
	fseek(f, 0, SEEK_END);
	size = ftell(f);
	printf("SIZE = %u\n", size);
	rewind(f);
	char *m = (char*)malloc(size+1);
	if(!m)
	{
		fprintf(stderr, "Cant' allocate %d bytes\n", size);
		return 3;
	}
	fread(m, size, 1, f);
	m[size]=0;
	printf(m);
	FILE *fout;
	fout = fopen(getenv("COPY_NAME"), "wt");
	fwrite(m, size, 1, fout);
	free(m);
	fclose(f);
	fclose(fout);
	return 0;
}