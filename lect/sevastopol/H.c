

int x, y;

x = 0;

switch(x) {

/*вход 0==x*/	case 0: y = 1;	
		//	|
		//	v
/*вход 1==x*/	case 1: y = 2; break; // => выход
		
/*default gateway*/	default: y = 3; break; //=> выход

} 
