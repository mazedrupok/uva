/*UVA-10236 The Fibonacci Primes
   22000th prime is 249439.. so we have
   to calculate 249439's Fibonacci..
   22000 primes are less than 249440.. :)
   we will show output as Fibonacci[prime[n] ] .. :)
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll LIMIT = 300000 + 11; //22000th prime is 249439 ..
ll primes[LIMIT];        //so we have to calculate 249439's Fibonacci..
ll p[LIMIT];
double fib[LIMIT];

ll solve(ll n) {
  return fib[p[n]];
}

int main() {
  fill(primes, primes + LIMIT, 1);
  primes[0] = primes[1] = 0;
  for (ll i = 2; i * i < LIMIT; ++ i) {
    // if (!primes[i]) continue;
    for (ll j = i * i; j < LIMIT; j += i) {
      primes[j] = 0;
    }
  }
  primes[1] = true;

  ll cnt = 0;
  for (ll i = 0; i < LIMIT; ++i) {
    if (primes[i]) {
      p[cnt] = i;
      ++cnt;
    }
  }
  p[1] = 3;
  p[2] = 4;
  fib[1] = 1;
  fib[2] = 1;
  bool flag = false;
  for (ll i = 3; i < LIMIT; ++i) {
    fib[i] = fib[i-1] + (flag ? fib[i-2] / 10LL : fib[i-2]);
    flag = false;
    while (fib[i] >= 1000000000LL) {
      fib[i] /= 10LL;
      flag = true;
    }
  }

  ll n;
  while (cin >> n) {
    cout << solve(n) << endl;
  }

  return 0;
}
