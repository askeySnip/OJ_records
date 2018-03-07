#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	map<int, int> mp;
	mp[1000000000] = 1;
	for(int i=0; i<n; i++){
		int id, sl;
		scanf("%d%d", &id, &sl);
		auto it = mp.lower_bound(sl);
		if(it == mp.end()) it--;
		int t = abs(it->first - sl);
		int idx = it->second;
		if(it != mp.begin()){
			it--;
			if(abs(it->first - sl) < t || (abs(it->first - sl) == t && it->second < idx)){
				idx = it->second;
			}
		}
		printf("%d %d\n", id, idx);
		it = mp.find(sl);
		if(it == mp.end() || it->second>id) mp[sl] = id;
	}
	return 0;
}