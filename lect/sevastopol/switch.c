int length;
char *p;

scanf("%m[^0-9]", &p);
switch(p[0])
{
	case 'N': scanf("%d", &length);
		/*> */	y = 2;  	
		/*	 |*/
		/*	 V*/

			y  = 3; /* =>*/ break;	

	case 2:	 	y = 4;  /* =>*/ break;
	default:	y = 5;	

}

