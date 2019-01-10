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

int main() {
	int n;
	scanf("%d", &n);
	vii xy, ab;
	int x, y, a, b;
	REP(i, 0, n) {
		scanf("%d %d", &x, &y);
		xy.push_back(ii(x, y));
	}
	REP(i, 0, n) {
		scanf("%d %d", &a, &b);
		ab.push_back(ii(a, b));
	}
	sort(xy.begin(), xy.end());
	sort(ab.begin(), ab.end());
	printf("%d %d\n", xy[0].first+ab.back().first, xy[0].second + ab.back().second);
	return 0;
}