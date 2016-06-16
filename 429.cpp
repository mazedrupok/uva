/**
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok
   problem: https://uva.onlinejudge.org/external/4/429.pdf
   Catagory: BFS
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 10005
#define read(f) freopen(f, "r", stdin)
#define write(f) freopen(f, "w", stdout)

struct node {
   string s; int level;
   node (string a, int b) {
      s = a; level = b;
   }
   node () {}
};
string word[205];
int word_size = 0;
bool oneCharDif (string a, string b) {
   if (a.size() != b.size()) return 0;
   int cnt = 0;
   for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) cnt++;
      if (cnt > 1) break;
   }
   if (cnt == 1) return 1;
   else return 0;
}
int bfs (string a, string b) {
   queue <node > q;
   q.push (node(a, 0));
   int visit[205] = {0};

   while (q.empty() == 0) {
      node u = q.front(); q.pop();
      if (u.s == b ) return u.level;

      for (int i = 0; i <= word_size; i++) {
        if (visit[i] == 0)
         if (oneCharDif(word[i], u.s) == 1) {
            q.push (node(word[i], u.level+1));
            visit[i] = 1;
         }
      }
   }
}
int main ()
{
   //read ("in.txt");
   string s, t;
   int tc;
   bool temp = false;
   cin >> tc;
   while (tc--) {
      word_size = 0;
      while (cin >> s) {
         if (s == "*") break;
         word[++word_size] = s;
      }
      if (temp) cout << endl; temp = true;
      int var = 1;
      s = ""; t = ""; string line = "";
      getline(cin, line);
      while (getline (cin, line)) {
         if (line.size() == 0) break;
         int j = 0; while (line[j] != ' ') j++;
         s = line.substr(0, j);
         t = line.substr(j+1, line.size()-j-1);
         cout << s << ' ' << t << ' ' << bfs (s, t) << endl;
      }
   }
   return 0;
}
