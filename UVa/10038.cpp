/*
ID: leezhen1
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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int main() {
	int n;
	while(scanf("%d", &n) == 1){
		int c[3100] = {};
		int l[3100] = {};
		for(int i=0; i<n; i++){
			scanf("%d", &l[i]);
		}
		for(int i=1; i<n; i++){
			int j = abs(l[i]-l[i-1]);
			c[j]++;
		}
		bool flag = true;
		for(int i=1; i<n; i++){
			if(c[i] == 0){
				flag = false;
				break;
			}
		}
		if(flag) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}