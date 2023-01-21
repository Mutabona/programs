#include <stdio.h>
#include <time.h>
int main()
{
    time_t rawtime;
    struct tm* timeinfo;
 
    // Used to store the time
    // returned by localetime() function
    char buffer[80];
 
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80,
             "Time is %I:%M%p.",
             timeinfo);
 
    // strftime() function stores the
    // current time as Hours : Minutes
    //%I %M and %p-> format specifier
    // of Hours minutes and am/pm respectively*/
 
    // prints the formatted time
    puts(buffer);
 
    return 0;
}
