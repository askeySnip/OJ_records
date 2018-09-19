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
int n;
int r[100024];
bool can(int t) {
	for(int i=1; i<=n; i++) {
		if(t < r[i]-r[i-1]) return false;
		if(t == r[i]-r[i-1]) t--;
	}
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	int kase = 0;
	r[0] = 0;
	while(t--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d", &r[i]);
		}
		int l = 0, h = 1e7, mid;
		while(l < h) {
			mid = (l+h)/2;
			if(can(mid)) h = mid;
			else l = mid+1;
		}
		printf("Case %d: %d\n", ++kase, l);
	}
	return 0;
}