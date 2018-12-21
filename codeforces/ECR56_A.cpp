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
	int q, x;
	scanf("%d", &q);
	REP(i, 0, q) {
		scanf("%d", &x);
		int ans = 0;
		if(x%2 == 1) {
			ans ++;
			x -= 3;
		}
		ans += x/2;
		printf("%d\n", ans);
	} 
	return 0;
}