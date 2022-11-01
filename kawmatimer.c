#include <stdio.h>
#include <stdlib.h>
void pomodoro(int workTime, int breakTime, int times) {
    workTime = workTime - 1;
    int buf = workTime;
    breakTime = breakTime - 1;
    int seconds = 59;
    // work time loop
    for (times; times > 0; times--) {
        for (workTime; workTime >= 0; seconds--) {
            if (seconds >= 10) {
                system("clear");
                printf("Work mode (%i sessions left)\n", times);
                printf("%i:%i\n", workTime, seconds);
                sleep(1);
            }
            if (seconds < 10) {
                system("clear");
                printf("Work mode (%i sessions left)\n", times);
                printf("%i:0%i\n", workTime, seconds);
                sleep(1);
            }
            if (seconds == 0) {
                workTime--;
            }
        }
        workTime = buf;
        seconds = 59;
        // break time loop
        for (breakTime; breakTime >= 0; seconds--) {
            if (seconds >= 10) {
                system("clear");
                printf("Break time! (%i sessions left)\n", times);
                printf("%i:%i\n", breakTime, seconds);
                sleep(1);
            }
            if (seconds < 10) {
                system("clear");
                printf("Break time (%i sessions left)\n", times);
                printf("%i:0%i\n", breakTime, seconds);
                sleep(1);
            }
            if (seconds == 0) {
                breakTime--;
            }
        }
        breakTime = buf;
        seconds = 59;
    }
}
int main() {
    int workTime, breakTime, times;
    char decision;

    printf("Welcome to Kawmatimer!\n");
    printf("How long is your work time?\n");
    scanf(" %i", &workTime);

    printf("How long is your break time?\n");
    scanf(" %i", &breakTime);

    printf("How many pomodoro sessions do you want to take?\n");
    scanf("%i", &times);

    printf("Is it all correct? (y/n)\nWork time: %i minutes\nBreak time: %i minutes\n%i times\n", workTime, breakTime, times);
    scanf(" %c", &decision);
    if (decision == 'y' || decision == 'n') {
        pomodoro(workTime, breakTime, times);
    } else if (decision == 'n' || decision == 'N') {
        main();
    }
    return 0;
}