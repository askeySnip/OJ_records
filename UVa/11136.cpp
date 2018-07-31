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
	multiset<int> ms;
	int k, n, t;
	long long ans;
	while(scanf("%d", &k), k) {
		ans = 0L;
		ms.clear();
		for(int i=0; i<k; i++) {
			scanf("%d", &n);
			for(int j=0; j<n; j++) {
				scanf("%d", &t);
				ms.insert(t);
			}
			ans += *ms.rbegin() - *ms.begin();
			ms.erase(ms.begin());
			n = *ms.rbegin();
			t = ms.erase(n);
			if(t > 1) {
				for(int i=1; i<t; i++) {
					ms.insert(n);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}