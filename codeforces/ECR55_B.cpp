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
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
	int n;
	char line[100005];
	scanf("%d", &n);
	scanf("%s", line);
	vii seg;
	int len = strlen(line);
	int start = 0;
	int ans = 0;
	for(int i=0; i<len; i++) {
		if(line[i] == 'S') {
			if(start != i) {
				seg.push_back(ii(start, i-1));
				ans = max(ans, i - start);
			}
			start = i+1;
		}
	}
	if(start <= len-1) {seg.push_back(ii(start, len-1)); ans = max(ans, len-start);}
	if(seg.size() == 0) printf("0\n");
	else if(seg.size() == 1) printf("%d\n", ans);
	else {
		ans += 1;
		bool f = false;
		for(int i=1; i<(int)seg.size(); i++) {
			if(seg[i].first - seg[i-1].second == 2) {
				ans = max(ans, seg[i].second - seg[i-1].first + 1);
				f = true;
			}
		}
		if(seg.size() < 3 && f) ans--;
		printf("%d\n", ans);
	}
	return 0;
}