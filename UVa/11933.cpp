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
	int n;
	int a, b, c;
	while(scanf("%d", &n), n) {
		a = 0; b = 0; c = 0;
		for(int i=0; i<32; i++) {
			if(n & (1 << i)) {
				c++;
				if(c%2) a += (1<<i);
				else b += (1<<i);
			}
		}
		printf("%d %d\n", a, b);
	}
	return 0;
}