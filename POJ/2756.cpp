#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	while(x>=2*y) x = x >> 1;
	while(y>=2*x) y = y >> 1;
	while(x != y){
		if(x > y) x = x >> 1;
		else y = y >> 1;
	}
	cout << x << endl;
	return 0;
}