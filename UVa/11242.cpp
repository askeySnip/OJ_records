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
	int f, r;
	int ft[13], rt[13];
	double d[130];
	while(scanf("%d", &f), f) {
		scanf("%d", &r);
		for(int i=0; i<f; i++) {
			scanf("%d", ft+i);
		}
		for(int i=0; i<r; i++) {
			scanf("%d", rt+i);
		}
		int c = 0;
		for(int i=0; i<f; i++) {
			for(int j=0; j<r; j++) {
				d[c++] = rt[j]*1.0/ft[i];
			}
		}
		sort(d, d+c);
		double ans = 0.0;
		for(int i=1; i<c; i++) {
			ans = max(ans, d[i]*1.0/d[i-1]);
		}
		printf("%.2f\n", ans);
	}
	return 0;
}