#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;
double exe(){
	char s[30];
	cin >> s;
	switch (s[0]) {
		case '+': return exe() + exe();
		case '-': return exe() - exe();
		case '*': return exe() * exe();
		case '/': return exe() / exe();
		default : return atof(s);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	printf("%lf\n", exe());
	return 0;
}