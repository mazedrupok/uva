#include <stdio.h>
#include <stdlib.h>
int cmpfunc1 (const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}
int cmpfunc2 (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}
int main ()
{
    int n, d, r, i, overtime, pay;
    int m[110], e[110], sum;
    int sumM, sumE;
    while (scanf (" %d %d %d", &n, &d, &r) == 3) {
        if (n == 0 && d == 0 && r == 0) break;
        overtime = 0;
        pay = 0;
        for (i = 0; i < n; i++) scanf (" %d", &m[i]);
        qsort(m, n, sizeof (int), cmpfunc1);
        for (i = 0; i < n; i++) scanf (" %d", &e[i]);
        qsort(e, n, sizeof (int), cmpfunc2);
        for (i = 0; i < n; i++) {
            sum = m[i] + e[i];
            if (sum > d) {
                overtime = (sum - d) * r;
                pay = pay + overtime;
            }
        }
        printf ("%d\n", pay);
    }
    return 0;
}
