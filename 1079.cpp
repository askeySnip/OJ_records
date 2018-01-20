#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;
double absolute(double d){
	if(d > 0) return d;
	else return -d;
}
int main() {
	int a, b;
	while (cin >> a >> b) {
		double bias = 1000;
		int u = 1;
		double ex = a*1.0/b;
//		cout << ex << endl;
		for(int i=1; i<=a+b; i++){
			double w = absolute(ex - u*1.0/i);
			while(w > absolute(ex - (u+1)*1.0/i)){
				w = absolute(ex - (u+1)*1.0/i);
				u++;
//				cout << w << endl;
			}
			if(w < bias){
				bias = w;
//				cout << bias << endl;
				cout << u << "/" << i << endl;
			}
			if(ex == u*1.0/i){
				break;
			}
		}
		cout << endl;
	}
	return 0;
}