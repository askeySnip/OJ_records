/*
ID: leezhen
TASK: practice
LANG: C++11                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

vi primes;
bitset<1000010> bs;
ll sum;
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i=2; i<1000010; i++) {
		if(bs[i]) {
			primes.push_back(i);
			for(ll j=i*i; j<1000010; j+=i) bs[j] = 0;
		}
	}
}

ll gen(ll n, ll step) {
	return (n+1-step+1)*(n/step)/2L;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, nn;
	cin >> n;
	nn = n;
	sieve();
	vector<ll> ans;
	vi divs;
	divs.push_back(1);
	REP(i, 0, primes.size()) {
		if(primes[i] > n) break;
		int base = primes[i];
		int sz = divs.size();
		while(n%primes[i] == 0) {
			REP(i, 0, sz) divs.push_back(base*divs[i]);
			n/=primes[i];
			base *= primes[i];
		}
	}
	int sz = divs.size();
	if(n!=1) {
		REP(i, 0, sz) divs.push_back(n * divs[i]);
	}
	sum = (ll)(1+nn)*(ll)n/2L;
	REP(i, 0, divs.size()) {
		ll t = gen(nn, divs[i]);
		ans.push_back(t);
	}
	sort(ans.begin(), ans.end());
	REP(i, 0, ans.size()) {
		if(i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}