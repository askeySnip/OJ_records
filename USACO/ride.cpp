/*
ID: leezhen1
TASK: ride
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;
int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string s1, s2;
	fin >> s1 >> s2;
	int ans1 = 1, ans2 = 1;
	for(int i=0; i<s1.length(); i++){
		ans1 *= s1[i]-'A'+1;
	}
	ans1 %= 47;
	for(int i=0; i<s2.length(); i++){
		ans2 *= s2[i]-'A'+1;
	}
	ans2%=47;
	if(ans1 == ans2){
		fout << "GO" << endl;
	}else{
		fout << "STAY" << endl;
	}
	return 0;
}