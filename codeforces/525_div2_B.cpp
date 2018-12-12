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
	int n, k, t;
	scanf("%d %d", &n, &k);
	priority_queue<int, vi, greater<int> > pq;
	for(int i=0; i<n; i++) {
		scanf("%d", &t);
		pq.push(t);
	}
	int base = 0;
	for(int i=0; i<k; i++) {
		if(pq.empty()) {
			printf("0\n");
		}else {
			int f = pq.top(); pq.pop();
			while(!pq.empty() && pq.top() == f) pq.pop();
			printf("%d\n", f - base);
			base = f;
		}
	}
	return 0;
}