#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
#if defined(PI)
    printf("pid: %d\n", getpid());
    sleep(10);
    compute_pi_baseline(50000000);
#elif defined(MATRIX)
    static int array[10000][10000] = {0};
    matrix(10000,10000,array);
#elif defined(BRANCH)
    static int arr1[10000000];
    static int arr2[10000000];
    for(int i=0; i<10000000; i++) {
        arr1[i] = i*2;   //even
        arr2[i] = i*2+1;  //odd
    }
    static int arr3[20000000];
    merge(arr1, arr2, arr3, 10000000);

#endif
    return 0;

}


