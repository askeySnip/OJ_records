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
const ll inf = 1e9;
const int mod = 1e9+7;

int minimum, maximum, mean, median;

int get_odd() {
    int s = minimum + maximum + median;
    if(s == mean * 3) return 3;
    if(s > mean * 3) {
        if(median + minimum >= 2 * mean) return -1;
        int d = 2 * mean - median - minimum;
        int t = (s - mean * 3 + d - 1) / d;
        return 2 * t + 3;
    } else {
        if(median + maximum <= 2 * mean) return -1;
        int d = median + maximum - 2 * mean;
        int t = (mean * 3 - s + d - 1) / d;
        return 2 * t + 3;
    }
    return -1;
}

int get_even() {
    int s = minimum + maximum + median + median;
    if(s == mean * 4) return 4;
    if(s < mean * 4) {
        if(median + maximum <= 2 * mean) return -1;
        int d = median + maximum - 2 * mean;
        int t = (mean*4 - s + d - 1) / d;
        return 2 * t  + 4;
    } else {
        if(minimum + median >= 2 * mean) return -1;
        int d = 2 * mean - minimum - median;
        int t = (s - mean * 4 + d - 1) / d;
        return 2 * t + 4;
    }
    return -1;
}

int solve() {
    if(minimum > maximum || mean > maximum || median > maximum) return -1;
    if(minimum > mean || minimum > median) return -1;
    if(minimum == maximum) return 1;
    if(minimum + maximum == 2 * mean && mean == median) return 2;
    int odd = get_odd();
    int even = get_even();
    int ans = 0;
    if(odd != -1 && even != -1) return min(odd, even);
    if(odd != -1) return odd;
    if(even != -1) return even;
    return -1;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    // t = 1;
    while(t--) {
        scanf("%d%d%d%d", &minimum, &maximum, &mean, &median);
        printf("Case #%d: ", ++kase);
        int t = solve();
        if(t != -1) printf("%d\n", t);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
