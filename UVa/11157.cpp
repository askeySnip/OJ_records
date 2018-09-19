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
int n, d;
vii stones;
int main() {
	char type;
	int t, p;
	stones.resize(112);
	scanf("%d", &t);
	int kase = 0;
	while(t--) {
		scanf("%d %d", &n, &d);
		getchar();
		stones[0] = make_pair(1, 0);
		for(int i=1; i<=n; i++) {
			scanf("%c-%d", &type, &p);
			getchar();
			if(type == 'B') stones[i] = make_pair(1, p);
			else stones[i] = make_pair(0, p);
		}
		stones[n+1] = make_pair(1, d);
		int a = 0, b = 0, ans = 0;			// 两只青蛙同时跳
		for(int i=1; i<=n+1; ) {
			if(stones[i].first) {
				ans = max(ans, stones[i].second-stones[a].second);
				ans = max(ans, stones[i].second-stones[b].second);
				a = b = i;
				i++;
			}else {
				ans = max(ans, stones[i].second-stones[a].second);
				a = i;
				i++;
				if(stones[i].first == 0) {
					ans = max(ans, stones[i].second-stones[b].second);
					b = i;
					i++;
				}
			}
		}
		printf("Case %d: %d\n", ++kase, ans);
	}
	return 0;
}