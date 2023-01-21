/*
char * b[6];
char ** p;
*/
// Send begin
 p = (char **) malloc(6 * sizeof(char*));  // alloc memory for 6 char *
 p[0] = b[0]; p[1] = b[1];         // copy b[] into p
//Send end
//
