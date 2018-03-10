#include <iostream>
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
	int p, e, j, d;
	cin >> p >> e >> j >> d;
	int i;
	for(i=d+1; i<=21252;i++){
		if((i-p)%23 == 0) break;
	}
	for(; i<=21525; i+=23){
		if((i-e)%28==0) break;
	}
	for(;i<=21525; i+=644){
		if((i-j)%33 == 0) break;
	}
	cout << i-d << endl;
	return 0;
}