/*
ID: leezhen1
TASK: gift1
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
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	int np;
	fin >> np;
	map<string, int> account;
	vector<string> name;
	string s;
	for(int i=0; i<np; i++){
		fin >> s;
		name.push_back(s);
		account[s] = 0;
	}
	int a, b;
	for(int i=0; i<np; i++){
		fin >> s >> a >> b;
		if(!b) continue;
		int t = a/b;
		account[s] += a%b-a;
		for(int i=0; i<b; i++){
			fin >> s;
			account[s] += t;
		}
	}
	for(int i=0; i<name.size(); i++){
		fout << name[i] << " " << account[name[i]] << endl;
	}
	return 0;
}