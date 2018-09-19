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
char dig[10];
int nums[13];
int broken;
int digits[10] = {126, 48, 109, 121, 51, 91, 95, 112, 127, 123};
bool flag = false;

void dfs(int u, int c) {
	if(flag || c>n) return;
	if(c == n) {
		flag = true;
		return;
	}
	if(broken&nums[c]) return;
	if((nums[c]&digits[u]) == nums[c]) {
		int t = digits[u]^nums[c];
		for(int i=0; i<7; i++) {
			if(t&(1<<i)) broken|=(1<<i);
		}
		dfs(u-1, c+1);
		for(int i=0; i<7; i++) {
			if(t&(1<<i)) broken&=~(1<<i);
		}
	}
}

int main() {
//	for(int i=0; i<10; i++){
//		for(int j=0; j<7; j++) {
//			if(digits[i]&(1<<j))printf("1");
//			else printf("0");
//		}
//		printf("\n");
//	}
	while(scanf("%d", &n), n) {
		if(n == 1) {
			scanf("%s", dig);
			printf("MATCH\n");
			continue;
		}
		// inital data
		broken = 0;
		flag = false;
		
		for(int i=0; i<n; i++) {
			scanf("%s", dig);
			int s = 0;
			for(int j=6; j>=0; j--) {
				if(dig[j] == 'Y') s|=(1<<(6-j));
			}
			nums[i] = s;
		}
		for(int i=9; i-n+1>=0; i--) {
			if(flag) break;
//			cout << digits[i] << " " << nums[0] << " " << (digits[i]&nums[0]) << endl;
			if((digits[i]&nums[0]) == nums[0]) {
//				cout << i << endl;
				int t = digits[i]^nums[0];
				for(int j=0; j<7; j++) {
					if(t&(1<<j)) broken|=(1<<j);
				}
				dfs(i-1, 1);
				for(int j=0; j<7; j++) {
					if(t&(1<<j)) broken&=~(1<<j);
				}
			}
		}
		if(flag) printf("MATCH\n");
		else printf("MISMATCH\n");
	}
	return 0;
}