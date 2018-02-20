#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	for(int i=0; i*a<=n; i++){
		if((n-a*i)%b == 0){
			int m = (n-a*i)/b;
			int c = 1;
			for(int j=0; j<i; j++){
				for(int k=0; k<a; k++){
					cout << c + (k+1)%a << " ";
				}
				c += a;
			}
			for(int j=0; j<m; j++){
				for(int k=0; k<b; k++){
					cout << c + (k+1)%b << " ";
				}
				c += b;
			}
			cout << endl;
			return 0;
		}
	}
	
	cout << "-1" << endl;
	return 0;
}