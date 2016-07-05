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
 problem:  UVA-941
 Category: Pattern Technique
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL fact[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,
        1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000};
string s; LL n;
void func () {
    int len = s.length();
    if (len == 0) return;
    //sort (s.begin(), s.end());
    //if (n <= 1) {cout << s; return;}
    LL temp = n /fact[len-1];
    if (n %fact[len-1] == 0) temp--;
    cout << s[temp];
    s.erase (s.begin()+temp);
    n = n - temp * fact[len-1];
    func ();
}
int main ()
{
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> s >> n;
        n++;
        sort (s.begin(), s.end());
        func ();
        cout << endl;
    }
    return 0;
}
