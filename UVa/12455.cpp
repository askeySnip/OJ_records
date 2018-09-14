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

int t, n, p;
int bars[23];

bool check(int i) {
	int c = 0, s = 0;
	while(i) {
		if(i&1) s+=bars[c];
		c++;
		i = i>>1;
	}
	return s==n;
}
int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &p);
		for(int i=0; i<p; i++) {
			scanf("%d", &bars[i]);
		}
		bool flag = false;
		for(int i=0; i<(1<<p); i++) {
			if(check(i)) {flag = true; break;}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}