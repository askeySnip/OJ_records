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
int a[10024];
int num[1000024];
int main() {
	int kase = 0;
	while(scanf("%d", &n), n) {
		if(kase) printf("\n");
		int k = 0;
		memset(num, 0, sizeof num);
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
			num[a[i]]++;
			k = max(k, num[a[i]]);
		}
		sort(a, a+n);
		printf("%d\n", k);
		for(int i=0; i<k; i++) {
			for(int j=i; j<n; j+=k) {
				printf("%d", a[j]);
				if(j+k>=n) printf("\n");
				else printf(" ");
			}
		}
		kase++;
	}
	return 0;
}