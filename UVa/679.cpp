/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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

using namespace std;
int main() {
	int n;
	while(scanf("%d", &n) && n != -1){
		for(int i=0; i<n; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			int start = 1;
			while(start <= (1 << (a-1))-1){
				if(b%2) {start *= 2; b = b/2 + 1;}
				else {start = start * 2 + 1; b/=2;}
			}
			printf("%d\n", start);
		}
	}
	return 0;
}