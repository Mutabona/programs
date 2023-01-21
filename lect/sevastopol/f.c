char * b[6]; //Тут живут char*. 6 штук
char ** p;

// Send begin
p = (char*) malloc(6 * sizeof(char*))  ;
p[0] = b[0];
p[1] = b[1];
....

   // alloc memory for 6 char *
???         // copy b[] into p
// Send end
//Какую строчку пояснить?
