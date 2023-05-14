#include "time.h"

struct time setTime() {
    struct time time;
    printf("Hours: "); scanf("%d", &time.hours);
    printf("Minutes: "); scanf("%d", &time.minutes);
    return time;
}