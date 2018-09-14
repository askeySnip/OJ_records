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
	int t, a, b, c;
	scanf("%d", &t);
	while(t--) {
		bool flag = false;
		scanf("%d %d %d", &a, &b, &c);
		for(int x=-99; x<100; x++) {
			for(int y=x+1; y<100; y++) {
				int z = a-x-y;
				if(z>-100 && z < 100 && x*y*z==b && x*x+y*y+z*z==c && x!=z && y!=z) {
					flag = true;
					printf("%d %d %d\n", x, y, z);
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) printf("No solution.\n");
	}
	return 0;
}