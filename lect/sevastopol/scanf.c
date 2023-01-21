char *good_string;
char *bad_string;
int length, retcode_good, retcode_bad;

do
{
retcode_good = scanf("%m[a-z]%n", &good_string,  &length);
if(1 == retcode_good) 
	if(strcmp(good_string....

			printf("YES");
			free(good_string);
	                return 0;

retcode_bad = scanf("%m[^a-z]%n", &bad_string,  &length);
free(bad_string);
}
while((1 == recode_bad) || (1 == retcode_good))


