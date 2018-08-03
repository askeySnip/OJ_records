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
vi areas(26);
vector<vi> link(26);
vi parent(26);
void solve() {
	int years = 0;
	bool flag = true;
	parent.assign(26, 0);
	for(int i=0; i<26; i++) {
		if(areas[i] >= 0) parent[i] = 1;
	}
	int rem = n - 3;
	while(flag) {
		if(rem == 0) break;
		flag = false;
		for(int i=0; i<26; i++) {
			if(areas[i] < 0) {
				int c = 0;
				for(int j=0; j<link[i].size(); j++) {
					if(parent[link[i][j]] == 1) c++;
				}
				if(c > 2) {
					parent[i] = -1;
					flag = true;
//					cout << i << endl;
				}
			}
		}
		years++;
		for(int i=0; i<26; i++) {
			if(parent[i] == -1) {
				parent[i] = 1;
				areas[i] = 1;
				rem--;
			}
		}
	}
//	cout << rem << endl;
	if(rem) printf("THIS BRAIN NEVER WAKES UP\n");
	else printf("WAKE UP IN, %d, YEARS\n", years);
}
int main() {
	char s[40];
	while(scanf("%d\n", &n) == 1) {
		scanf("%d", &m);
		scanf("%s", s);
		areas.assign(26, 0);
		link.clear();
		link.resize(26);
		for(int i=0; i<3; i++) areas[s[i]-'A'] = 1;
		for(int i=0; i<m; i++) {
			scanf("%s", s);
			if(!areas[s[0]-'A']) areas[s[0]-'A'] = -1;
			if(!areas[s[1]-'A']) areas[s[1]-'A'] = -1;
			link[s[0]-'A'].push_back(s[1]-'A');
			link[s[1]-'A'].push_back(s[0]-'A');
		}
//		for(int i=0; i<26; i++) cout << areas[i] << endl;
		solve();
	}
	return 0;
}