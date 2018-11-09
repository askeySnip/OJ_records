/*
Id: leezhen
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
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

// struct


// data
char dictory[202][100];
int path[202][202];
int size;
char from[100], to[100], buf[200];

int getId(char* s) {
  for(int i=0; i<size; i++) {
    if(!strcmp(dictory[i], s)) return i;
  }
  return -1;
}
int main() {
  int t;
  scanf("%d", &t);
  getchar(); getchar();
  while(t--) {
    size = 0;
    while(gets(dictory[size]) && strcmp(dictory[size], "*")) size++;
    memset(path, 0, sizeof path);
    for(int i=0; i<size; i++) {
      for(int j=i+1; j<size; j++) {
        int count = 0;
        for(int k=0; dictory[i][k]; k++) count+=(dictory[i][k] != dictory[j][k]);
        if(count <= 1) path[i][j] = path[j][i] = 1;
        else path[i][j] = path[j][i] = 202;
      }
    }

    for(int k=0; k<size; k++) {
      for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
          if(path[i][j] > path[i][k] + path[k][j]) {
            path[i][j] = path[i][k] + path[k][j];
          }
        }
      }
    }

    while(gets(buf) && buf[0]) {
      sscanf(buf, "%s %s", from, to);
      int fid = getId(from), tid = getId(to);
      printf("%s %s %d\n", from, to, path[fid][tid]);
    }
    if(t) puts("");
  }
  return 0;
}
