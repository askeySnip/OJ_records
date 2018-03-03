#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int count_one(int n){
	int ones = 0;
	while(n){
		if(n%2 == 1) ones++;
		n = n >> 1;
	}
	return ones;
}
int main() {
	int n;
	while(cin >> n){
		if(!n) break;
		int c = count_one(n);
		int b = n+1;
		while(c!=count_one(b)) b++;
		cout << b << endl;
	}
	return 0;
}