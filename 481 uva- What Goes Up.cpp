#include <iostream>
using namespace std;
int a[10000000];
int bsearch (int arr[], int l, int r, int d) {
   int m;
   while (l < r) {
      m = (l+r) /2;
      if (d == arr[m]) return m;
      else if (d < arr[m]) r = m;
      else l = m;
      if (l == r-1) break;
   }
   return r;
}
int main ()
{
   int x;
   int n;
   for (int i = 0; cin >> x; i++) {
      a[i] = x;
      n = i;
   }
   n++;
   int T[n+1], L[n];
   T[0] = -1 * 1e9;
   for (int i = 1; i <= n; i++) T[i] = 1e9;
   for (int i = 0; i <= n; i++) L[i] = 1;
   int j = 1; T[1] = a[0];
   for (int i = 0; i < n; i++) {
      if (a[i] <= T[j]) {
         int k = j;
//         while (a[i] <= T[--k]) ;
         k = bsearch (T, 0, k+1, a[i]); //complexity nlog(K) :)
         T[k] = a[i];
         L[i] = k;
      }
      else {
         T[++j] = a[i];
         L[i] = j;
      }
   }
//   for (int i = 0; i < n; i++) cout << L[i] << " ";
//   cout << endl;
//   for (int i = 1; i < n; i++) cout << T[i] << " ";
//   cout << endl;
   cout << j << endl << "-" << endl;
   int seq[j+1] = {0};
   for (int i = n-1, k = j; i >= 0; i--) {
      if (L[i] == k) {
         seq[k] = a[i];
         k--;
      }
   }
   for (int i = 1; i <= j; i++) cout << seq[i] << endl;
   return 0;
}
