/*
ID: leezhen
TASK: practice
LANG: C++11                
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
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

char s[100];
typedef struct {
	int id, c, join, tottime;
	int solved[10];
	int pen[10];
} contestant;
vector<contestant> vc;
void init(){
	vc.resize(102);
	for(int i=0; i<102; i++){
		vc[i].id = i;
		vc[i].c  = 0;
		vc[i].join = 0;
		vc[i].tottime = 0;
		memset(vc[i].solved, 0, sizeof(vc[i].solved));
		memset(vc[i].pen, 0, sizeof(vc[i].pen));
	}
}
bool cmp(const contestant& c1, const contestant& c2) {
	if(c1.c != c2.c) return c1.c > c2.c;
	if(c1.tottime != c2.tottime) return c1.tottime < c2.tottime;
	return c1.id < c2.id;
}
void solve() {
	sort(vc.begin(), vc.end(), cmp);
	for(int i=0; i<vc.size(); i++){
		if(vc[i].join == 0) continue;
		printf("%d %d %d\n", vc[i].id, vc[i].c, vc[i].tottime);
	}
}
int main() {
	int n;
	gets(s);
	sscanf(s, "%d", &n);
	init();
	int id, pid, t;
	char status;
	gets(s);
	while(gets(s)){
		if(s[0] == '\0') {
			solve();
			n--;
			printf("\n");
			init();
			continue;
		}
		sscanf(s, "%d %d %d %c", &id, &pid, &t, &status);
		vc[id].join = 1;
		if(vc[id].solved[pid] == 0) {
			if (status == 'I') {
				vc[id].pen[pid] += 20;
			} else if(status == 'C') {
				vc[id].solved[pid] = 1;
				vc[id].c++;
				vc[id].tottime += vc[id].pen[pid] + t;
			}
		}
	}
	solve();
	return 0;
}