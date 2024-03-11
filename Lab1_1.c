#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char* argv[])
{
    clock_t start, end;
    start = clock();
    int mod = 10007;
    long long n = 800000000;
    long long square, cube, sum, sum_square, sum_cube;
    sum_square = 0;
    sum_cube = 0;
    square = 0;
    cube = 0;
    sum = 0;
    int i;
    #pragma omp parallel for num_threads(4) private(square, cube) reduction(+:sum_square, sum_cube)
    for (i = 1; i <= n; ++i) {
        square = ((i % mod) * (i % mod)) % mod;
        cube = ((square % mod) * (i % mod)) % mod;
        sum_square += square;
        sum_cube += cube;
    }
    sum = (sum_square + sum_cube) % mod;
    end = clock();
    printf("sum = %d\n", sum);
    printf("time ticks are %d\n", (int)((end-start)));
    return 0;
}