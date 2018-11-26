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
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	int ans = 0;
	int r = 2 * n, g = 5 * n, b = 8 * n;
	ans += r/k;
	ans += g/k;
	ans += b/k;
	if(r%k) ans++;
	if(g%k) ans++;
	if(b%k) ans++;
	printf("%d\n", ans);
	return 0;
}