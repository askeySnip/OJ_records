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
bool check(int i, int j, int n) {
	int t = (i^j);
	int c = 0;
	for(int i=0; i<n; i++) {
		if(t&(1<<i)) c++;
	}
	return c == 1;
}
int main() {
	int n;
	vi nodes, weights;
	vector<vi> links;
	while(scanf("%d", &n) == 1) {
		nodes.assign((1 << n), 0);
		links.resize((1<<n));
		for(int i=0; i<(1<<n); i++) {
			scanf("%d", &nodes[i]);
		}
		weights.assign((1 << n), 0);
		for(int i=0; i<(1<<n); i++){
			for(int j=i+1; j<(1<<n); j++){
				if(check(i, j, n)) {
					links[i].push_back(j);
					links[j].push_back(i);
					weights[i] += nodes[j];
					weights[j] += nodes[i];
				}
			}
		}
		int sums = 0, t = 0;
		for(int i=0; i<(1<<n); i++) {
			for(int j=0; j<n; j++){
				t = weights[i] + weights[links[i][j]];
//				cout << t << " " << i << " " << j << endl;
				sums = max(sums, t);
			}
		}
		printf("%d\n", sums);
	}
	return 0;
}