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
	priority_queue<int, vi, greater<int> > pq;
	int n, t;
	while(scanf("%d", &n), n) {
		for(int i=0; i<n; i++) {
			scanf("%d", &t);
			pq.push(t);
		}
		int ans = 0;
		int a, b;
		for(int i=1; i<n; i++) {
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			ans += a+b;
			pq.push(a+b);
		}
		printf("%d\n", ans);
		while(!pq.empty()) pq.pop();
	}
	return 0;
}