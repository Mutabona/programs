#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hasWord(char* str, char* word);

int main() {
    FILE* file = fopen("artemchurka.txt", "r+");
    char* slovo = (char*)malloc(7*sizeof(char));    
    printf("Vvedi slovo chertila: "); scanf("%s", slovo);
    if (!file)
        return -1;
    char *stroka = (char*)malloc(100*sizeof(char));
    while (fgets(stroka, 100, file)) {
        printf("%s %d\n", stroka, hasWord(stroka, slovo));
    }
    return 0;
}

int hasWord(char* str, char* word) {
    int count = 0;
    char *p = str;
  do {
    p = strstr(p, word);
	if (p != NULL){
	  count++;  
	  p = &p[strlen(word)];
	}
  } while (p != NULL);
    return count;
}