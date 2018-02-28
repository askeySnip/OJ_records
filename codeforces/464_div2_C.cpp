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
	long long a[200000+6];
	for(int i=1; i<=n; i++){ 
		cin >> a[i];
		a[n+i] = a[i];
	}
	for(int i=2; i<=2*n; i++){
		a[i] += a[i-1]; 
	}
	int s, f; 
	cin >> s >> f; 
	long long ans = 0L;
	int id = 1;
	int j = 1;
	for(int i=n+f-1; j<=n; i--){
		int t;
		t = a[i] - a[i-f+s];
		if(t > ans){
			ans = t;
			id = j;
		}
		j++;
	}
	cout << id << endl;
	return 0;
}