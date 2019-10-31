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

int n, s;
int a[100024];
int events[100024];
ii seg[400048];

void build(int v, int tl, int tr) {
    if(tl == tr) {
        seg[v].first = seg[v].second = events[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        //seg[v] = seg[v * 2] + seg[v * 2 + 1];
        seg[v].first = seg[v * 2].first + seg[v * 2 + 1].first;
        seg[v].second = max(seg[v * 2].second, seg[v * 2].first + seg[v * 2 + 1].second);
    }
}

void update(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) {
        seg[v].first = seg[v].second = val;
    } else {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        seg[v].first = seg[v * 2].first + seg[v * 2 + 1].first;
        seg[v].second = max(seg[v * 2].second, seg[v * 2].first + seg[v * 2 + 1].second);
    }
}

int solve() {
    map<int, vi> mp;
    REP(i, 0, n) {
        if(mp[a[i]].size() < s) events[i] = 1;
        else if(mp[a[i]].size() == s) events[i] = -s;
        else events[i] = 0;
        mp[a[i]].push_back(i);
    }
    build(1, 0, n-1);
    int ans = seg[1].second;
    //cout << seg[1] << endl;
    REP(i, 1, n) {
        update(1, 0, n-1, i-1, 0);
        int idx = lower_bound(mp[a[i-1]].begin(), mp[a[i-1]].end(), i-1) - mp[a[i-1]].begin();
        if(idx + s >= mp[a[i-1]].size()) continue;
        int pos = mp[a[i-1]][idx+s];
        update(1, 0, n-1, pos, 1);
        if(idx + s + 1 < mp[a[i-1]].size()) {
            pos = mp[a[i-1]][idx+s+1];
            update(1, 0, n-1, pos, -s);
        }
        ans = max(ans, seg[1].second);
        //cout << seg[1] << endl;
    }
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &s);
        for(int i=0; i<n; i++) scanf("%d", &a[i]);
        printf("Case #%d: %d\n", ++kase, solve());
    }
	return 0;
}

