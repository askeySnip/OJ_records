#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
int main() {
	unsigned int a, m, n, sum;
	while (cin >> a) {
		for(m = a; ;m++){
			if((a * a + 1) % m == 0)
				break;
				
		}
		n = (a * a + 1) / m;
		sum = 2 * a + m + n;
		cout << sum << endl;
	}
	return 0;
	
}