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
	int n, a, c;
	while(scanf("%d", &n), n) {
		c = 0;
		for(int i=0; i<n; i++) {
			scanf("%d", &a);
			if(a > 0) {
				if(c) printf(" ");
				printf("%d", a);
				c++;
			}
		}
		if(c == 0) printf("0");
		printf("\n");
	}
	return 0;
}