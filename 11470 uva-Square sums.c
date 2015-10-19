#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{
   int cas, tc = 0, i, j, k, ara[15][15], n;
   int p, q, sum[15], visited[15][15];
   //freopen ("in.txt", "r", stdin);
   while (scanf (" %d", &n) == 1) {
      if (n == 0) break;
      for (i = 0; i < n; i++)
         for (j = 0; j < n; j++)  scanf (" %d", &ara[i][j]);
      memset (visited, 0, sizeof (visited));
      memset (sum, 0, sizeof (sum));
      for (i = 0, j = 0; visited[i][j] == 0 && i < n; i++, j++) {
         for (p = i, q = j; p < n && !visited[p][q]; p++) {sum[i] += ara[p][q]; visited[p][q] = 1;}
         for (p = i, q = j+1; q < n && !visited[p][q]; q++) {sum[i] += ara[p][q]; visited[p][q] = 1;}
         for (p = n-1, q = n-1; p > 0 && !visited[p][q]; p--) {sum[i] += ara[p][q]; visited[p][q] = 1;}
         for (p = n-1, q = n-2; q > 0 && !visited[p][q]; q--) {sum[i] += ara[p][q]; visited[p][q] = 1;}
         n--;
      }
      printf ("Case %d:", ++tc);
      for (j = 0; j < i; j++) printf (" %d", sum[j]);
      printf ("\n");
   }
}
