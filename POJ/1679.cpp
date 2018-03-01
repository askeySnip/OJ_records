#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	cin >> n;
	int mtr[103][103];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> mtr[i][j];
		}
	}
	int a = 0, c = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(mtr[i][j] <= 50){
				a++;
				if(i == 1 || j == 1 || i == n || j == n || mtr[i-1][j] > 50 || mtr[i+1][j] > 50 || mtr[i][j-1] > 50 || mtr[i][j+1] > 50) c++;
			}
		}
	}
	cout << a << " " << c << endl;
	return 0;
}