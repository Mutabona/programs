#include <stdio.h>

int d[100][100];

int dec(int n, int k) {

    if ( n >= 0 && k >= 0 && d[n][k] > 0 ) return d[n][k];

    if ( n < 0 ) return 0;

    if ( n <= 1 || k == 1 ) return 1;

    d[n][k] =  dec(n, k-1) + dec(n-k, k);  

    return d[n][k];
}

int main() {

    int m, i, j;

    scanf("%d", &m);

    for (i = 0; i < m; i++) {

        for (j = 0; j < m; j++) {

        d[i][j] = -1;
   }
 }

 printf("%d", dec(m, m));

 return 0;

}