/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct
struct gar {
  int t, f, h;
};

// data
int d, g;
gar gb[110];
int dp[110][150];

int main() {
  scanf("%d%d", &d, &g);
  REP(i, 1, g + 1) scanf("%d%d%d", &gb[i].t, &gb[i].f, &gb[i].h);
  sort(gb + 1, gb + g + 1, [](gar a, gar b) { return a.t < b.t; });
  REP(i, 0, g + 1) {
    REP(j, 0, d + 1) { dp[i][j] = -inf; }
  }
  dp[0][0] = 10;
  REP(i, 1, g + 1) {
    REP(j, 0, d + 1) {
      if (dp[i - 1][j] - gb[i].t + gb[i - 1].t >= 0) {
        dp[i][j] =
            max(dp[i][j], dp[i - 1][j] - gb[i].t + gb[i - 1].t + gb[i].f);
      }
      if (j - gb[i].h >= 0 &&
          dp[i - 1][j - gb[i].h] - gb[i].t + gb[i - 1].t >= 0) {
        dp[i][j] =
            max(dp[i][j], dp[i - 1][j - gb[i].h] - gb[i].t + gb[i - 1].t);
        if (j == d) {
          printf("%d\n", gb[i].t);
          return 0;
        }
      }
    }
  }
  int ans = 10;
  REP(i, 1, g + 1) {
    if (gb[i].t <= ans)
      ans += gb[i].f;
    else
      break;
  }
  printf("%d\n", ans);
  return 0;
}

// int f[110];
//     //把井高度当成背包空间，生命当成价值，则f[i]表示到达i高度的时候最长能活多久
// struct cow {
//   int t, l, h;
// } a[110];
// int cmp(const cow &a, const cow &b) { return a.t < b.t; }
// int main(void) {
//   int d, g;
//   cin >> d >> g;
//   for (int i = 0; i < g; i++) cin >> a[i].t >> a[i].l >> a[i].h;
//   sort(a, a + g, cmp);              //按时间排序
//   f[0] = 10;                        //初始生命为10小时，高度为0
//   for (int i = 0; i < g; i++) {     //枚举垃圾
//     for (int j = d; j >= 0; j--) {  //把井当成01背包那样枚举空间
//       if (f[j] >= a[i].t) {         //如果来垃圾的时候还活着
//         if (j + a[i].h >= d) {      //如果能出去了输出时间并结束
//           cout << a[i].t;
//           return 0;
//         }
//         f[j + a[i].h] =
//             max(f[j], f[j + a[i].h]);  //这样的转移很罕见吧！这一行是堆高度的
//         f[j] += a[i].l;  //这一行是吃掉的。注意和上面那个转移不能换位置
//       }
//     }
//   }
//   cout
//       << f[0];
//       //如果最后没出去，那么f[0]表示的一定是把所有垃圾都吃掉之后获得的生命
//   return 0;
// }
