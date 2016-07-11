/** UVA 10651
   MMM   MMM     A     ZZZZZZZ EEEEEEE DDDDD
   MM MMM MM    AAA    Z   ZZ  EE    E DDDDDDD
   MM  M  MM   AA AA      ZZ   EEEE    DD   DD
   MM     MM  AAAAAAA   ZZ   Z EE    E DDDDDDD
   MMM   MMM AA     AA ZZZZZZZ EEEEEEE DDDDD

 Name:     Md. Abdul Mazed (RUPOK)
           Noakhali Science & Technology University
 Email:    mazedrupok@gmail.com || mazed4g@gmail.com
 FB id:    www.facebook.com/mazedrupok
 Github:   www.github.com/mazedrupok
*/
#include <bits//stdc++.h>
using namespace std;

#define MAX 100005
#define read(f)  freopen(f,"r",stdin)
#define write(f) freopen(f,"w",stdout)
#define LL long long
#define ULL unsigned long long
#define inf        INT_MAX
#define mod        1000000007
#define PI         acos(-1.0)
#define sqr(x)     ((x)*(x))

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N=N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

/****************************** END OF TEMPLATE ******************************/
int n, dp[(1<<12) +2]; //works in n <= 15
int cnt = 0;
int call (int mask)
{
    if (dp[mask] != -1) return dp[mask];
    int temp = mask;
    for (int i = 0; i < 10; i++) {
        if (!check(mask, i) && check(mask, i+1) && check(mask, i+2)) {
            mask = Set (mask, i);
            mask = reset(mask, i+1);
            mask = reset(mask, i+2);
            dp[temp] = call (mask);
            mask = temp;
        }
        if (check(mask, i) && check(mask, i+1) && !check(mask, i+2)) {
            mask = reset (mask, i);
            mask = reset (mask, i+1);
            mask = Set (mask, i+2);
            dp[temp] = call (mask);
            mask = temp;
        }
    }
    int cn = 0;
    for (int i = 0; i < 12; i++ ) {
        if (check (temp, i) ) cn++;
    }
    cnt = min (cnt, cn);
    return dp[mask] = cnt;
}
int main ()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    //read("in.txt"); //write ("out.txt");
    int tc, cs = 0;
    string s;
    cin >> tc;
    memset (dp, -1, sizeof(dp));
    while (tc--) {
        cin >> s;
        int mask = 0;
        //memset (dp, -1, sizeof(dp));
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'o') {mask = Set(mask, i); cnt++;}
        }
        cout << call (mask) << endl;
    }
    return 0;
}
