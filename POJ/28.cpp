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
	string s;
	vector<string> v;
	while(cin >> s){
		v.push_back(s);
	}
	int n = v.size();
	for(int i=n-1; i>0; i--){
		cout << v[i] << " ";
	}
	cout << v[0] << endl;
	return 0;
}