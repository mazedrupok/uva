//UVA-374-Big Mod
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main ()
{
   long long a, b, c, sum , i;
   bool ara[1000000];
   //freopen ("in.txt", "r", stdin);
   while (scanf (" %lld %lld %lld", &a, &b, &c) != EOF) {
      if (a == 0) {printf ("0\n"); continue;}
      if (c == 0) {printf ("0\n"); continue;}
      if (a == 1) {printf ("1\n"); continue;}
      if (b == 0) {printf ("1\n"); continue;}

      for (i = 0; b != 0; i++) {
         if (b %2 == 1) {ara[i] = 1; b--;}
         else if (b %2 == 0) {ara[i] = 0; b = b / 2;}
      }
      sum = 1;
      for ( i--; i >= 0; i--) {
         if (ara[i] == 1) sum = (sum * (a % c)) %c;
         else if (ara[i] == 0) sum = (sum * sum) %c;
      }
      printf ("%lld\n", sum %c);
   }
   //ref: https://imranshabijabi.wordpress.com/2012/11/24/
   return 0;

}
/*int big_mod(int base, int power, int mod)
{
    if(power==0)    return 1;
    //কোন কিছুর power 0 হলে তার মান 1 হয়ে যায়
    else if(power%2==1) //power বেজোড় হলে
    {
        int p1 = base % mod;
        int p2 = (big_mod(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else if(power%2==0) //power জোড় হলে
    {
        int p1 = (big_mod(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}*/
