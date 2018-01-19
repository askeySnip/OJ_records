#include <iostream>

using namespace std;
double cards[300];
int bs(double l, int low, int high){
	while(low < high){
		int mid = (low + high) / 2;
		if(cards[mid] == l){
			return mid;
		}else if(cards[mid] > l){
			high = mid;
		}else{
			low = mid+1;
		}
//		cout << mid << endl;
	}
	return low;
}
int main() {
	double d;
//	double cards[300];
	cards[0] = 0;
//	cout << 1.0/2*1.0;
	for(int i=1; i<300; i++){
		cards[i] = cards[i-1] + 1.0/(i+1);
	}
	while(cin >> d){
		if(d == 0){
			break;
		}
		cout << bs(d, 0, 300) << " card(s)" << endl;
	}
	return 0;
}