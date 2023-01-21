#include <stdio.h>
#include <math.h>

int main() {
    long long int n, temp = 0;
    long long int otv;
    scanf("%lld", &n);
    otv = pow(2, n);
    for (long long int i = otv; i > 0; i--) {
        temp = 0;
        for (long long int j = i; j > 0; ) {
            if (temp && (j % 2)) {
                otv--;
                break;
            }
            temp = j % 2;
            j /= 2;
        }
    }
    printf("%lld", otv);
}