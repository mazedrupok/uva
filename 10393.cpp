#include <bits/stdc++.h>
using namespace std;

#define FOI(i, A, B) for (i = A; i <= B; i++)
#define FOD(i, A, B) for (i = A; i >= B; i--)

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("testO.txt", "w", stdout);
	map<char, int> Map;
	Map['q'] = 1; Map['a'] = 1; Map['z'] = 1;
	Map['w'] = 2; Map['s'] = 2; Map['x'] = 2;
	Map['e'] = 3; Map['d'] = 3; Map['c'] = 3;
	Map['r'] = 4; Map['f'] = 4; Map['v'] = 4; Map['t'] = 4; Map['g'] = 4; Map['b'] = 4;
	//Special Case : ' ' -- > 5, 6
	Map['y'] = 7; Map['h'] = 7; Map['n'] = 7; Map['u'] = 7; Map['j'] = 7; Map['m'] = 7;
	Map['i'] = 8; Map['k'] = 8; Map[','] = 8;
	Map['o'] = 9; Map['l'] = 9; Map['.'] = 9;
	Map['p'] = 10; Map[';'] = 10; Map['/'] = 10;

	int F, N;
	while (cin >> F >> N) {
		int i, j;
		bool fing[11];
		memset(fing, true, sizeof fing);
		for(int i = 0; i < F; i++) {
			int u;
			cin >> u;
			fing[u] = false;
		}
		map <string, int> mps;
		vector <string> vc;
		for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            int test = true;
            for (int j = 0; s[j]; j++) {
                if (fing[Map[s[j]]] == false) {
                    test = false; break;
                }
            }
            if (test == true) {
                bool test2 = true;
                for (int j = 0; j < vc.size(); j++) {
                    bool test1 = false;
                    for (int k = 0; vc[j][k] && s[k]; k++) {
                        if (vc[j][k] != s[k]) test1 = true;
                    }
                    if (test1 == false) {
                        if (s.size() > vc[j].size()) vc[j] = s;
                        test2 = false;
                        break;
                    }
                }
                if (test2 == true) vc.push_back(s);
            }
		}
		sort (vc.begin(), vc.end());
		int len = 0;
		for (int i = 0; i < vc.size(); i++) {
            len =  max(len, (int)vc[i].size());
		}
		int cnt = 0;
        for (int i = 0; i < vc.size(); i++) {
            if (vc[i].size() == len) cnt++;
		}
		cout << cnt << endl;
		for (int i = 0; i < vc.size(); i++) {
            if (vc[i].size() == len) cout << vc[i] << endl;
		}
	}
	return 0;
}
