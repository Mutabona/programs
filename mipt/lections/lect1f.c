#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv, char **envp) {
  printf("Content-Type: text/plain;charset=us-ascii\n\n");
  printf("Hello, world!\n\n");
  printf("Hello, %s\n\n", getenv("REMOTE_ADDR"));
  int i;
  for(i=0; i<argc; i++) {
	  printf(argv[i]);
	  printf("\n\n");
  }
  for(i=0; envp[i]; i++) {
	  printf(envp[i]);
	  printf("\n\n");
  }

  return 0;
}