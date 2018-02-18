#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int k;
	cin >> k;
	if(k > 36){
		cout << "-1" << endl;
	}else{
		int i;
		for(i=0; i<k/2; i++){
			cout << "8";
		}
		if(i*2 == k){
			cout << endl;
		}else{
			cout << "6" << endl;
		}
	}
	return 0;
}