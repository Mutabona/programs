#include <stdio.h>

int main() {
        int k, count ;
        scanf("%d", &k);

        for(count = 0; k; k >> 1) {
		count += k & 1;
/*                if ((k % 2) == 1) {
                        count++;
                }*/
//                k /= 2;
//		k >> 1;
        }
        printf("%d", count);

        return 0;
}
