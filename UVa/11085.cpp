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
int r[10];
int vistr[10], vist_cross[20], vist_xcross[20];
vector<vi> succ;
vi sample;
void dfs(int p) {
	if(p == 9) {
		succ.push_back(sample);
		return;
	}
	for(int i=1; i<9; i++) {
		if(vistr[i] || vist_cross[i-p+8] || vist_xcross[i+p]) continue;
		vistr[i] = 1;
		vist_cross[i-p+8] = 1;
		vist_xcross[i+p] = 1;
		sample[p] = i;
		dfs(p+1);
		vistr[i] = 0;
		vist_cross[i-p+8] = 0;
		vist_xcross[i+p] = 0;
	}
}

void cacul_success() {
	sample.resize(9);
	memset(vistr, 0, sizeof vistr);
	memset(vist_cross, 0, sizeof vist_cross);
	memset(vist_xcross, 0, sizeof vist_xcross);
	for(int i=1; i<9; i++) {
		vistr[i] = 1;
		vist_cross[i-1+8] = 1;
		vist_xcross[i+1] = 1;
		sample[1] = i;
		dfs(2);
		vistr[i] = 0;
		vist_cross[i-1+8] = 0;
		vist_xcross[i+1] = 0;
	}
}

int main() {
	cacul_success();

	int kase = 0;
	while(scanf("%d", &r[1]) == 1) {
		for(int i=2; i<=8; i++) {
			scanf("%d", &r[i]);
		}
		int min_diff = 10, d;
		for(int i=0; i<succ.size(); i++) {
			d = 0;
			for(int j=1; j<9; j++) {
				if(succ[i][j] != r[j]) d++;
			}
			min_diff = min(d, min_diff);
		}
		printf("Case %d: %d\n", ++kase, min_diff);
	}
	return 0;
}