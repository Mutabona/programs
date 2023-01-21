#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, count = 0;
    long a = 0;
    double b;
    FILE *in, *out;
    in = fopen("input.txt", "rt");
    out = fopen("output.txt", "wt");
    fscanf(in, "%d", &n);
    for (int i = 1; count <= n; i++) {
        a += i ;
        count = 2;
        for (int j = 2; j*j <= a ; j++) {
            if (a % j == 0) {
                count+=2;
            }
        }
        b = sqrt(a);
        if (b*b==a) {
            count--;
        }
    }
    fprintf(out, "%ld", a);
    fclose(in);
    fclose(out);
    return 0;
}