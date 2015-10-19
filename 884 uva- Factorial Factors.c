#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX 1000010
int ara[MAX];
using namespace std;
int factor (int num) {
   int i, j, k;
   int fact = 0;
   for (i = 2; i*i <= num; i++) {
      if (num %i == 0) {
         fact++;
         num /= i;
         while (num %i == 0 && num > 1) {
            fact++;
            num /= i;
         }
      }
   }
   if (num != 1) fact++;
   return fact;
}
int main ()
{
   int n;
   int i, j, count;
   ara[1] = 0;
   for (i = 2; i <= MAX; i++ ) {
      ara[i] = ara[i-1] + factor (i);
   }
   while (scanf (" %d", &n) != EOF) {
      printf ("%d\n", ara[n]);
   }
   return 0;
}
