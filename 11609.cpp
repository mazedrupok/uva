/**
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MMM   MMM AA     AA ZZZZZZZ EEEEEEE DDDDD

 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 github:   www.github.com/mazedrupok
*/
//UVA--11609
#include <bits//stdc++.h>
using namespace std;
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
/****************************** END OF TEMPLATE ******************************/
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0); //read("in.txt");
    int tc, cs = 0;
    LL n, a = 2L, mod = 1000000007, res;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %lld", &n);
        res = bigmod(a, n-1, mod);
        res = (res*n) %mod;
        printf ("Case #%d: %lld\n", ++cs, res);
    }
    return 0;
}
