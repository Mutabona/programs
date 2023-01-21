#include <stdio.h>

int main() {
        int h1, m1, h2, m2, h3, m3;

        scanf("%d:%d", &h1, &m1);
        scanf("%d:%d", &h2, &m2);

        h3 = (h1 + h2) % 24;

        if ((m1 + m2) >= 60) {
                h3 += (m1 + m2) / 60;
        }

        m3 = (m1 + m2) % 60;

        printf("%02d:%02d", h3, m3);

        return 0;
}
