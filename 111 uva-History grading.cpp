#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
   int n, c[20], r[20], lcs[21][21],x;
   scanf(" %d\n", &n);
   for(int i = 0; i < n; i++){
      scanf(" %d", &x);
      c[x] = i;
   }
   while(scanf(" %d", &x) == 1){
      r[x] = 0;
      for(int i = 1; i < n; i++){
         scanf(" %d", &x);
         r[x] = i;
      }
      for(int i = 0; i <= n; i++)
         for(int j = 0; j <= n; j++){
            if(i==0 || j==0){
               lcs[i][j] = 0;
               continue;
            }

            if(c[i] == r[j]) lcs[i][j] = 1 + lcs[i-1][j-1];
            else lcs[i][j] = max (lcs[i][j-1], lcs[i-1][j]);
      }
      printf("%d\n",lcs[n][n]);
   }
   return 0;
}
