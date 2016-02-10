//http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include <bits/stdc++.h>
using namespace std;
void LIS (int ara[], int n) {
   vector <int > v[10000];
   int j = -1;
   for (int i = 0; i < n; i++) {
      if (i == 0) v[++j].push_back (ara[i]);
      else if (ara[i] > v[j][j]) {
         v[j+1] = v[j];
         v[++j].push_back (ara[i]);
      }
      else {
         int k = j;
         while (k != -1 && ara[i] < v[k][k]) k--;
         if(k == -1) {v[0][0] = ara[i]; continue;}
         v[k+1] = v[k];
         v[++k].push_back (ara[i]);
      }
   }
   cout << "Max hits: " << v[j].size() << endl;
   for (int i = 0; i < v[j].size(); i++) cout << v[j][i] << endl;
}
int main ()
{
   int vc[10000], as = 0; int tc, n = 0, x = 0;
   cin >> tc;
   //int ara[] = {10, 22, 2, 9, 33, 21, 50, 41, 60, 80};
   //int ara[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
   string s;
   getline (cin, s);
   getline (cin, s);
   bool temp = false;
   while (tc--) {
   	if (temp == true) cout << endl; temp = true;
   while (getline (cin, s) ) {
      if (s[0] >= '0' && s[0] <= '9') {
         for (int i = 0; s[i]; i++)
            x = (10*x) + (s[i] - 48);
         vc[as++] = x;
         x = 0;
         n++;
      }
      else break;
   }
   		LIS (vc, n);
      	n = 0;	x = 0; as = 0;
   }
   return 0;
}
