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
int n, m;
int c[1024];
bool can(int t) {
	int ct = 1, cap = t;
	for(int i=0; i<n; i++) {
		if(t < c[i]) return false;
		if(cap < c[i]) {
			ct++;
			cap = t;
		}
		cap -= c[i];
	}
	return ct <= m;
}
int main() {
	while(scanf("%d %d", &n, &m) != EOF) {
		for(int i=0; i<n; i++) {
			scanf("%d", &c[i]);
		}
		int l = 0, h = 1e9, mid;
		while(l<h) {
			mid = (l+h) / 2;
			if(can(mid)) h = mid;
			else l = mid+1;
		}
		printf("%d\n", l);
	}
	return 0;
}