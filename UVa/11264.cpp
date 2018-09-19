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
	int c[1024];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &c[i]);
		if(n < 3) printf("%d\n", n);
		else {
			int sum = c[0], count = 2;
			for(int i=1; i<n-1; i++) {
				if(sum < c[i] && sum+c[i] < c[i+1]) {
					sum += c[i];
					count++;
				}
			}
			printf("%d\n", count);
		}
	}
	return 0;
}