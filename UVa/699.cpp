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
map<int, int> mp;
void build(int p){
	int v;
	cin >> v;
	if(v == -1) return;
	mp[p] += v;
	build(p-1);
	build(p+1);	
}
bool init(){
	int v; cin >> v;
	if(v == -1) return false;
	mp.clear();
	mp[0] += v;
	build(-1);
	build(1);
	return true;
}
int main() {
	int kase = 0;
	while(init()){
//		if(kase != 0) cout << endl;
		cout << "Case " << ++kase << ":" << endl;
		int t = mp.size();
		int i=0;
		for(auto it = mp.begin(); it!=mp.end(); it++){
			cout << it->second;
			i++;
			if(i != t) cout << " ";
		}
		cout << endl << endl;
	}
	return 0;
}