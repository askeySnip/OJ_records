#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	long long n, k;
	cin >> n >> k;
	if(k >= 70){
		cout << "No" << endl;
	}else{
		bool flag = true;
		for(long long i = 2l; i <= k; i++){
			if(n % i != i - 1){
				flag = false;
			} 
		}
		if(!flag) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}