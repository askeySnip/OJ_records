#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int v, p;
	int mi[303][303], f[303][303];
	cin >> v >> p;
	int a[300+3];
	for(int i=1; i<=v; i++){
		cin >> a[i];
	}
	if(v <= p){
		cout << "0" << endl;
		return 0;
	}
	memset(mi, 0, sizeof(mi));
	for(int i=1; i<=v; i++){
		for(int j=1; j<=p; j++){
			f[i][j] = 99999999;
		}
	}
	for(int i=1; i<=v; i++){
		for(int j=i+1; j<=v; j++){
			mi[i][j] = mi[i][j-1] + a[j] - a[(i+j)/2];
		}
		f[i][1] = mi[1][i];
	}
	for(int i=2; i<=v; i++){
		for(int j=2; j<=p; j++){
			for(int k=j-1; k<i; k++){
				f[i][j] = min(f[i][j], f[k][j-1] + mi[k+1][i]);
			}
		}
	}
	cout << f[v][p] << endl;
	return 0;
}