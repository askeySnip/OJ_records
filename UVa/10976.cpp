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
	int k;
	while(scanf("%d", &k) == 1){
		vector<pair<int, int> > v;
		for(int y=k+1; y<=2*k; y++){
			if((k*y)%(y-k) == 0){
				v.push_back(make_pair((k*y)/(y-k), y));
			}
		}
		printf("%d\n", (int)v.size());
		for(int i=0; i<v.size(); i++){
			printf("1/%d = 1/%d + 1/%d\n", k, v[i].first, v[i].second);
		}
	}
	return 0;
}