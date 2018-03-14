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
#include <cmath>

using namespace std;
int main() {
	map<int, int> p;
	int n, t;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &t);
		p[t]++;
	}
	for(auto i = p.begin(); i != p.end(); i++){
		printf("%d %d\n", i->first, i->second);
	}
	return 0;
}