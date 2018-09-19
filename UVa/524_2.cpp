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
int check_prime = 0, n;
int vist[20];
vi chain;
void dfs(int p) {
	if(p == n-1) {
		for(int i=2; i<=n; i++) {
			if(vist[i]) continue;
			if(check_prime&(1<<(i+1)) && check_prime&(1<<(i+chain[p-1]))) {
				for(int i=0; i<p; i++) printf("%d ", chain[i]);
				printf("%d\n", i);
			}
			break;
		}
		return;
	}
	for(int i=2; i<=n; i++) {
		if(vist[i]) continue;
		if(check_prime & (1 << (i + chain[p-1]))) {
			vist[i] = 1;
			chain[p] = i;
			dfs(p+1);
			vist[i] = 0;
		}
	}
}
int main() {
	int primes[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	check_prime = 0;
	for(int i=0; i<12; i++) {
		check_prime += (1 << primes[i]);
	}
//	cout << check_prime << endl;
	int kase = 0;
	chain.resize(20);
	chain[0] = 1;
	while(scanf("%d", &n) == 1) {
		if(kase) printf("\n");
		memset(vist, 0, sizeof vist);
		printf("Case %d:\n", ++kase);
		if(n == 1) continue;
		vist[1] = 1;
		dfs(1);
	}
	return 0;
}