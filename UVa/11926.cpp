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
const int mx = 2000005;
bitset<mx> bs;
bool solve(){
	int s, e, itv;
	bool ret = true;
	for(int i=0; i<n; i++) {
		scanf("%d %d", &s, &e);
		if(!ret) continue;
		for (int j = 2 * s + 1; j <= 2 * e; j++) {
			if (bs.test(j)) {
				ret = false;
				break;
			}
			bs.set(j);
		}
	}
	for(int k=0; k<m; k++) {
		scanf("%d %d %d", &s, &e, &itv);
		if(!ret) continue;
		while (true) {
			for (int j = 2 * s + 1; j <= 2 * e; j++) {
				if (bs.test(j)) {
					ret = false;
					break;
				}
				bs.set(j);
			}
			s += itv;
			e += itv;
			if (s > 1000000 && e > 1000000)
				break;
			else if (e > 1000000)
				e = 1000000;
		}
	}
	return ret;
}
int main() {
	while(scanf("%d %d", &n, &m) == 2 && (m || n)) {
		bs.reset();
		if(solve()) {
			printf("NO CONFLICT\n");
		} else {
			printf("CONFLICT\n");
		}
	}
	return 0;
}