
char *good;
char *bad;
size_t length;
int retg, retb;
do
{
retg = scanf("%m[a-zA-Z]%n", &good, &length);
if(strncmp(good, "bomb", length) == 0).....
free(good);

retb = scanf("%m[^a-zA-Z]%n", &bad, &length);
free(bad);
} while ((1 == retg) || (1 == retb))
