/* localtime example */
#include <stdio.h>
#include <time.h>
#include <libc.h>
#include <math.h>
#include <stdbool.h>

// type declaration
typedef struct {
    int64_t hours[60];
    int64_t minutes[60];
    int64_t seconds[60];
} WatchTimes;

struct tm *timeInfo;
time_t my_time;


// function declaration
int calculateHour(int hour, int minute);

void printAll3Digits(WatchTimes *watchTimes);

void clearData(int64_t *array);

void calculateTime(WatchTimes *watchTimes, const struct tm *timeinfo);

void test(int n);
void decToBinary(long n);

int main() {

    decToBinary(1152921504606846976);
    decToBinary(44);
    return 0;
    WatchTimes watchTimes;
    clearData(watchTimes.hours);
    clearData(watchTimes.minutes);
    clearData(watchTimes.seconds);

    printAll3Digits(&watchTimes);

    while (true) {
        time(&my_time);
        timeInfo = localtime(&my_time);

        printf("%d:%d:%d\n", timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

        calculateTime(&watchTimes, timeInfo);

        sleep(1);
    }
}

// function to convert decimal to binary
void decToBinary(long n) {
    // array to store binary number
    long binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%ld", binaryNum[j]);
}


void calculateTime(WatchTimes *watchTimes, const struct tm *timeinfo) {
    int hour = calculateHour(timeinfo->tm_hour, timeinfo->tm_min);


    // Hours
    if (timeinfo->tm_hour == 0) {
        clearData(watchTimes->hours);
    }

    for (int i = 0; i <= hour; i++) {
        watchTimes->hours[i] = 1;
    }

    //Minutes
    if (timeinfo->tm_min == 0) {
        clearData(watchTimes->minutes);
    }
    for (int i = 0; i <= timeinfo->tm_min; i++) {
        watchTimes->minutes[i] = 1;
    }

    //Seconds
    if (timeinfo->tm_sec == 0) {
        clearData(watchTimes->seconds);
    }
    for (int i = 0; i <= timeinfo->tm_sec; i++) {
        watchTimes->seconds[i] = 1;
    }

    printAll3Digits(watchTimes);
}

void clearData(int64_t *array) {
    for (int i = 0; i < 60; i++) {
        array[i] = 0;
    }
}

int calculateHour(int hour, int minute) {

    if (hour > 12) {
        hour = hour - 12;
    }

    float castHour = (float) hour;
    float castMinute = (float) minute;

    float hoursMinutes = castHour + (castMinute / 60);
    int mappedHour = (int) roundf(hoursMinutes * 5);

    return mappedHour;
}

void printAll3Digits(WatchTimes *watchTimes) {

    // Hours
    for (int i = 0; i < 60; i++) {
        printf("%lld", watchTimes->hours[i]);
    }
    printf("\n");


    // Minutes
    for (int i = 0; i < 60; i++) {
        printf("%lld", watchTimes->minutes[i]);
    }
    printf("\n");


    // Seconds
    for (int i = 0; i < 60; i++) {
        printf("%lld", watchTimes->seconds[i]);
    }
    printf("\n");
    printf("\n");
}

