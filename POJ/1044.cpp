#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
int main() {
	int case_id = 0;
	int n;
	int y[20], a[20], b[20];
	while(cin >> n){
		if(n == 0) break;
		for(int i=0; i<n; i++){
			cin >> y[i] >> a[i] >> b[i];
			b[i] -= a[i];
		}
		a[0] = y[0];
		while(a[0] < 10000){
			bool flag = true;
			for(int i=1; i<n; i++){
				int p = a[0] - y[i];
				if(p < 0 || p % b[i] != 0){
					flag = false;
					break;
				}
			}
			if(flag){
				cout << "Case #" << ++case_id <<  ":" <<endl;
				cout << "The actual year is " << a[0] << "." << endl << endl;
				break;
			}
			a[0] = a[0] + b[0];
		}
		if(a[0] >= 10000){
			cout << "Case #" << ++ case_id << ":" << endl;
			cout << "Unknown bugs detected." << endl << endl;
		}
	}
	return 0;
}