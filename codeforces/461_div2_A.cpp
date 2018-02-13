#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if(y == 0 || (y == 1 && x != 0)|| y-1 > x || ((x-y+1)%2 && y!=1) ){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}
	return 0;
}