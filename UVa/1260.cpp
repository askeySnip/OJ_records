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
int main() {
	int t, n;
	int a[1024];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 0;
		for(int i=1; i<n; i++) {
			for(int j=i-1; j>=0; j--) {
				if(a[i] >= a[j]) {
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}