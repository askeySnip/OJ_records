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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
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

int n, g, m;
vi guest_c;
vi guest_a;
map<int, vector<int>> mp_c;
map<int, vector<int>> mp_a;
map<int, int> m_c;
map<int, int> m_a;
int ans[100024];

void solve() {
    sort(guest_a.begin(), guest_a.end());
    sort(guest_c.begin(), guest_c.end());
    REP(i, 0, n) {
        int p1 = (i+n-(m%n))%n, p2 = (i+(m%n))%n;
        int idx1 = lower_bound(guest_c.begin(), guest_c.end(), p1) - guest_c.begin();
        int idx2 = upper_bound(guest_a.begin(), guest_a.end(), p2) - guest_a.begin();
        int d1, d2;
        int g1, g2;
        if(idx1 == guest_c.size()) {
            if(guest_c.empty()) d1 = inf;
            else {
                d1 = guest_c[0] + n - p1;
                g1 = guest_c[0];
            }
        } else {
            d1 = guest_c[idx1] - p1;
            g1 = guest_c[idx1];
        }
        if(idx2 == 0) {
            if(guest_a.empty()) d2 = inf;
            else {
                d2 = n - guest_a.back() + p2;
                g2 = guest_a.back();
            }
        } else {
            d2 = p2 - guest_a[idx2-1];
            g2 = guest_a[idx2-1];
        }
        if(d1 == d2 && d1 <= m) {
            m_c[g1]++;
            m_a[g2]++;
        }
        if(d1 < d2 && d1 <= m) {
            m_c[g1]++;
        }
        if(d1 > d2 && d2 <= m) {
            m_a[g2]++;
        }
    }
    for(auto it=m_a.begin(); it!= m_a.end(); it++) {
        int p = it->first;
        for(int k=0; k<mp_a[p].size(); k++) {
            ans[mp_a[p][k]] = it->second;
        }
    }
    for(auto it=m_c.begin(); it!= m_c.end(); it++) {
        int p = it->first;
        for(int k=0; k<mp_c[p].size(); k++) {
            ans[mp_c[p][k]] = it->second;
        }
    }
    REP(i, 0, g) {
        printf(" %d", ans[i]);
    }
    printf("\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t, kase = 0;
	cin >> t;
	while(t--) {
	    guest_a.clear();
	    guest_c.clear();
	    mp_a.clear();
	    mp_c.clear();
	    m_a.clear();
	    m_c.clear();
	    cin >> n >> g >> m;
	    int h;
	    char c;
	    REP(i, 0, g) {
            cin >> h >> c;
            h--;
            if(c == 'A') {
                guest_a.push_back(h);
                if(mp_a.find(h) == mp_a.end()) {
                    mp_a[h] = vector<int>(0);
                }
                mp_a[h].push_back(i);
            }else {
                guest_c.push_back(h);
                if(mp_c.find(h) == mp_c.end()) {
                    mp_c[h] = vector<int>(0);
                }
                mp_c[h].push_back(i);
            }
	    }
        printf("Case #%d:", ++kase);
        solve();
	}
	return 0;
}

