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
	vector<int> v;
	int t, c = 0;
	while(scanf("%d", &t) == 1){
		v.push_back(t);
		c++;
		sort(v.begin(), v.end());
		if(c%2) printf("%d\n", v[c/2]);
		else printf("%d\n", (v[c/2-1]+v[c/2])/2);
	}
	return 0;
}