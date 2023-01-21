#include <stdio.h>

int getOpr(int st1[3], int st2[3], int st3[3]) {
    return st1[0]*st2[1]*st3[2]+st2[0]*st3[1]*st1[2]+st3[0]*st2[2]*st1[1]-st1[2]*st2[1]*st3[0]-st2[2]*st3[1]*st1[0]-st3[2]*st2[0]*st1[1];
}

int main() {
    int st1[3], st2[3], st3[3], x[3], opr[4];
    double otv[3];
    for (int i = 0; i<3; i++) {
        scanf("%d", &st1[i]);
        scanf("%d", &st2[i]);
        scanf("%d", &st3[i]);
        scanf("%d", &x[i]);
    }
    opr[0] = getOpr(st1, st2, st3);
    if (opr[0] == 0) {
        printf("NO");
        return 0;
    }
    opr[1] = getOpr(x, st2, st3);
    opr[2] = getOpr(st1, x, st3);
    opr[3] = getOpr(st1, st2, x);
    otv[0] = (double)opr[1] / opr[0];
    otv[1] = (double)opr[2] / opr[0];
    otv[2] = (double)opr[3] / opr[0];
    printf("%lg\n", otv[0]);
    printf("%lg\n", otv[1]);
    printf("%lg\n", otv[2]);
    return 0;
}