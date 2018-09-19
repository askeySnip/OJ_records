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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int main() {
	int n;
	int prices[10024];
	int m;
	while(scanf("%d", &n) == 1) {
		for(int i=0; i<n; i++) {
			scanf("%d", &prices[i]);
		}
		scanf("%d", &m);
		sort(prices, prices+n);
		int a, b;
		for(int i=0; i<n-1 && prices[i]*2 <= m; i++) {
			auto it = lower_bound(prices+i+1, prices+n, m-prices[i]);
			if(*it == m-prices[i]) {
				a = prices[i];
				b = m-a;
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}
	
	return 0;
}