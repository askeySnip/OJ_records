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
	int n, m, t, k, v;
	while(scanf("%d %d", &n, &m) == 2) {
		vector<vi> nums(1000000+1);
		for(int i=1; i<=n; i++) {
			scanf("%d", &t);
			nums[t].push_back(i);
		}
		for(int i=0; i<m; i++) {
			scanf("%d %d", &k, &v);
			if(nums[v].size() < k) printf("0\n");
			else printf("%d\n", nums[v][k-1]);
		}
	}
	return 0;
}