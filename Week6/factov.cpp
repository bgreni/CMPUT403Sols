#include <bits/stdc++.h>

using namespace std;
/*
  Brian Grenier
  1545276
  bgrenier

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://github.com/UAPSPC/Code-Archive/blob/master/num_theory/factinfact.c

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
using ll = long long;
const ll MAXP =  100000;
const ll MAXPS = MAXP + 1000;
ll primes[MAXPS];

ll pfif(ll k, ll n) {
  ll pow, sum = 0;

  for (pow = k; pow <= n; pow *= k)
    sum += n / pow;
  return sum;
}

void getPrimes(){
  ll i, j, isprime, psize = 1;

  primes[0] = 2;
  for(i = 3; i <= MAXP; i+= 2){
    for(isprime = j = 1; j < psize; j++){
      if(i % primes[j] == 0){
       isprime = 0;
        break;
      }
      if(1.0*primes[j]*primes[j] > i) break;
    }
    if(isprime) primes[psize++] = i;
  }
}

ll fif(ll k, ll n) {
  ll i, p, m, tmp, min = 2000000000;
  
  for (i = 0; k > 1; i++) {
    p = primes[i];
    if (p*p > k) p = k;
    for (m = 0; k % p == 0; m++) k /= p;
    if (!m) continue;
    tmp = pfif(p,n)/m;
    if (tmp < min) min = tmp;
  }
  return min;
}


int32_t main() {
    ll n, m;
    getPrimes();
    while (cin >> n >> m) {

        if (m == 0) {
            cout << m << " does not divide " << n << "!" << endl;
        }
        else if (m <= n) {
            cout << m << " divides " << n << "!" << endl;
        } 
        else if (m == 1) {
            cout << m << " divides " << n << "!" << endl;
        } else {
            if (fif(m, n) != 0) {
            cout << m << " divides " << n << "!" << endl;
        } else {
            cout << m << " does not divide " << n << "!" << endl;
        }
        }
    }
}