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
#include <climits>

using namespace std;
typedef vector<double> vi;
typedef pair<double, double> ii;
typedef vector<pair<double, double> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

class UnionFind {
private:
    vi p, rank;
public:
    UnionFind(int n) {
        p.assign(n, 0); rank.assign(n, 0);
        REP(i, 0, n) p[i] = i;
    }
    int findSet(int i) {
        return (i == p[i] ? i : (p[i] = findSet(p[i])));
    }
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

ll L, R;
ll sz = 1e7+1;

vi primes;
bitset<10000010> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=2; i<= sz; i++) {
        if(bs[i]) {
            for(ll j = i* i; j<= sz; j+=i) bs[j] = 0;
            primes.push_back((int)i);
        }
    }
}

int solve() {
    int ans = 0;
    if(L == 1) ans++, L++;
    for(ll i=L; i<=R; i++) {
        if(i <= sz && bs[(int)i]) {
            ans++;
            //cout << "Y:" << i << endl;
            continue;
        }
        ll pf_indx = 0, pf = primes[pf_indx];
        ll ti = i;
        ll x2 = 0, n2 = 1;
        while(ti % 2 == 0) ti/=2, x2++;
        while(pf * pf <= ti) {
            ll power = 0;
            while(ti  % pf == 0) {
                ti /= pf, power++;
            }
            n2 *= (power+1);
            pf = primes[++pf_indx];
        }
        if(ti != 1) n2 *= 2;
        if(abs(x2*n2 - n2) <= 2) {
            ans++;
            //cout << "Y:" << i << " x2, n2 " << x2 << " " << n2 << endl;
        }
    }
    return ans;
}

int main() {
	int t, kase = 0;
	cin >> t;
	sieve();
	while(t--) {
	    cin >> L >> R;
        printf("Case #%d: %d\n", ++kase, solve());
	}
	return 0;
}

