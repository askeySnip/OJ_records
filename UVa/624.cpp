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

int tapeLen, n;
int trackLen[23];
int ans = 0, nearestTotal = 0;
void backtrack(int total, int mask, int p) {
	if(total > tapeLen) return;
	if(total > nearestTotal) {
		nearestTotal = total;
		ans = mask;
	}
	if(p >= n) return;
	backtrack(total + trackLen[p], mask | (1<<p), p+1);
	backtrack(total, mask, p+1);
}
int main() {
	
	while(scanf("%d %d", &tapeLen, &n) != EOF) {
		for(int i=0; i<n; i++) {
			scanf("%d", &trackLen[i]);
		}
		ans = -1, nearestTotal = -1;
		backtrack(0,0,0);
		for(int i=0; i<n; i++) {
			if((ans>>i)&1) printf("%d ", trackLen[i]);
		}
		printf("sum:%d\n",nearestTotal);
	}
	return 0;
}