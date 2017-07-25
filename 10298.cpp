#include <bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ff first
#define ss second
using namespace std;
int pi[1000001], len;
string s;
void prefix_function () { //KMP
    int i = 1, j = 0;
    pi[j] = 0;
    for (i, j; i < len; ) {
        if (s[i] == s[j]) {
            pi[i] = j+1;
            i++;
            j++;
        }
        else {
            while (s[i] != s[j] && j > 0) j = pi[j-1];
            if (s[i] != s[j]) {
                pi[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
    int n, u, v, w;
    while (cin >> s && s[0] != '.') {
        len = s.size();
        prefix_function ();
        n = len - pi[len-1];
        cout << len/n << "\n";
    }
    return 0;
}
