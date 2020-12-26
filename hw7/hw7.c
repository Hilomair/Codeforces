#include <stdio.h>
#include <time.h>

struct timespec diff(struct timespec start, struct timespec end);
float number[205][205]; 
int main() {
    
    float ans[205];
    struct timespec time1, time2, time_diff;
 
    
    
    FILE* in_file = fopen("data.txt", "r"); // read only  
    FILE* out_file = fopen("output.txt", "w"); // write only
    

    if (! in_file ) { // equivalent to saying if ( in_file == NULL )   
        printf("oops, file can't be read\n"); 
        exit(-1); 
    } 

    // File Read
    clock_gettime(CLOCK_MONOTONIC, &time1);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 202; j++) {
            fscanf(in_file, "%f", & number[i][j] );
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &time2);
    time_diff = diff(time1, time2);
    printf("File Read: %ld:%ld \n", time_diff.tv_sec, time_diff.tv_nsec);

    // Calculate
    clock_gettime(CLOCK_MONOTONIC, &time1);
    for (int k = 0; k < 200; k++) {
        float tmp = 0;
        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 202; j++) {
                tmp += number[k][j] * number[i][j];
            }
        }
        ans[k] = tmp;
    }
    clock_gettime(CLOCK_MONOTONIC, &time2);
    time_diff = diff(time1, time2);
    printf("Calculate: %ld:%ld \n", time_diff.tv_sec, time_diff.tv_nsec);

    // File Write
    clock_gettime(CLOCK_MONOTONIC, &time1);
    for (int i = 0; i < 200; i++) {
        // printf("%f\n", ans[i]);
        fprintf(out_file, "%f\n", ans[i]);
    }
    clock_gettime(CLOCK_MONOTONIC, &time2);
    time_diff = diff(time1, time2);
    printf("File Write: %ld:%ld \n", time_diff.tv_sec, time_diff.tv_nsec);

    return 0;
}

struct timespec diff(struct timespec start, struct timespec end)
{
    struct timespec temp;
    if ( (end.tv_nsec-start.tv_nsec) < 0) {
        temp.tv_sec = end.tv_sec-start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec-start.tv_nsec;
    } 
    else {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
}