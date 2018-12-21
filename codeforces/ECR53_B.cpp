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
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

int n;
int a[200024];
int b;

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", &a[i]);
	bitset<200024> vist;
	int cur = 0, last = -1;
	REP(i, 0, n) {
		if(i) printf(" ");
		scanf("%d", &b);
		if(vist[b]) {
			printf("0");
			continue;
		}
		for(;cur<n; cur++) {
			if(a[cur] == b) {
				vist[b] = true;
				printf("%d", cur - last);
				last = cur++;
				break;
			}
			vist[a[cur]] = true;
		}
	}	
	return 0;
}