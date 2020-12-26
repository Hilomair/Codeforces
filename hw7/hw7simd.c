#include <stdio.h>
#include <time.h>
#include <emmintrin.h>
#include <stdlib.h>
#include <string.h>

struct timespec diff(struct timespec start, struct timespec end);

int main() {
    double number[200][202]   __attribute__ ((aligned(64))); 
    double ans[200]           __attribute__ ((aligned(64))); 
    double tmp_mul[2]         __attribute__ ((aligned(64))); 
    double tmp_sum[2]         __attribute__ ((aligned(64))); 
    struct timespec time1, time2, time_diff;
 
    
    
    FILE* in_file = freopen("data.txt", "r", stdin); // read only  
    FILE* out_file = freopen("output_simd.txt", "w", stdout); // write only
    

    if (! in_file ) { // equivalent to saying if ( in_file == NULL )   
        printf("oops, file can't be read\n"); 
        exit(-1); 
    } 

    // File Read
    clock_gettime(CLOCK_MONOTONIC, &time1);
    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 202; j++) {
            scanf("%lf", &number[i][j] );
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &time2);
    time_diff = diff(time1, time2);
    printf("File Read: %ld:%ld \n", time_diff.tv_sec, time_diff.tv_nsec);

    // Calculate
    clock_gettime(CLOCK_MONOTONIC, &time1);
    __m128d *a, *b, *mul, *sum;
    for (int k = 0; k < 200; k++) {
        memset(tmp_sum, 0, sizeof(tmp_sum));
        memset(tmp_mul, 0, sizeof(tmp_mul));
        sum = (__m128d *) tmp_sum;
        mul = (__m128d *) tmp_mul;

        for (int i = 0; i < 200; i++) {
            a = (__m128d*) number[k];
            b = (__m128d*) number[i];
            for (int j = 0; j < 202 / 2; j++) {
                *mul = _mm_mul_pd(a[j], b[j]);
                *sum = _mm_add_pd(*mul, *sum);
            }
        }

       ans[k] = tmp_sum[0] + tmp_sum[1];
    }

    clock_gettime(CLOCK_MONOTONIC, &time2);
    time_diff = diff(time1, time2);
    printf("Calculate: %ld:%ld \n", time_diff.tv_sec, time_diff.tv_nsec);

    // File Write
    clock_gettime(CLOCK_MONOTONIC, &time1);
    for (int i = 0; i < 200; i++) {
        printf("%lf\n", ans[i]);
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