/*
ID: leezhen1
TASK: practice
LANG: C++14
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
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
class SegmentTree {
 private:
  vi st, A;
  int n;
  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  void build(int p, int L, int R) {
    if (L == R)
      st[p] = L;
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
  }
  int rmq(int p, int L, int R, int i, int j) {
    if (i > R || j < L)
      return -1;  // if return the value instead of index, this will be a
                  // trouble.
    if (L >= i && R <= j) return st[p];

    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2;
  }

 public:
  SegmentTree(vi& _A) {
    A = _A;
    n = _A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }
  int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
};
int main() {
  int arr[] = {18, 17, 13, 19, 15, 11, 20};
  vi A(arr, arr + 7);
  SegmentTree st(A);
  printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));
  printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));
  return 0;
}

// better implement
const int N = 1e5;  // limit for array size
int n;              // array size
int t[2 * N];

void build() {
  for (int i = n - 1; i; i--) {
    t[i] = t[i << 1] + t[i << 1 | 1];
  }
}

void modify(int p, int value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r) {  // sum of [l, r)
  int ans = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += t[l++];
    if (r & 1) ans += t[--r];
  }
  return ans;
}

// add a value to all elements in some interval
void modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) t[l++] += value;
    if (r & 1) t[--r] += value;
  }
}
// compute an element at some position.
int query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) {
    res += t[p];
  }
  return res;
}

// If at some point after modifications we need to inspect all the elements in
// the array, we can push all the modifications to the leaves using the
// following code. After that we can just traverse elements starting with index
// n. This way we reduce the complexity from O(nlog(n)) to O(n) similarly to
// using build instead of n modifications.
void push() {
  for (int i = 1; i < n; i++) {
    t[i << 1] += t[i];
    t[i << 1 | 1] += t[i];
    t[i] = 0;
  }
}

// Non-commutative combiner functions
// However, there are cases when the combiner isn't commutative, for example, in
// the problem 380C - Sereja and Brackets, tutorial available here
// http://codeforces.com/blog/entry/10363. Fortunately, our implementation can
// easily support that. We define structure S and combine function for it. In
// method build we just change + to this function. In modify we need to ensure
// the correct ordering of children, knowing that left child has even index.
// When answering the query, we note that nodes corresponding to the left border
// are processed from left to right, while the right border moves from right to
// left. We can express it in the code in the following way:

void modify(int p, const S& value) {
  for (t[p += n] = value; p >>= 1;) t[p] = combine(t[p << 1], t[p << 1 | 1]);
}

S query(int l, int r) {
  S resl, resr;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) combine(resl, t[l++]);
    if (r & 1) combine(t[--r], resr);
  }
  return combine(resl, resr);
}

// Lazy propagation
// Next we'll describe a technique to perform both range queries and range
// modifications, which is called lazy propagation. First, we need more
// variables:

int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];

// h is a height of the tree, the highest significant bit in n. d[i] is a
// delayed operation to be propagated to the children of node i when necessary
// (this should become clearer from the examples). Array size if only N because
// we don't have to store this information for leaves — they don't have any
// children. This leads us to a total of 3 * n memory use.

// Increment modifications, queries for maximum

// This is probably the simplest case. The code below is far from universal and
// not the most efficient, but it's a good place to start.

// we have 2 variables for every internal node, it's useful to write a method to
// apply changes to both of them.
void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
}

// build is designed to update all the parents of a given node.
void build(int p) {
  while (p > 1) p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
}

// push propagates changes from all the parents of a given node down the tree
// starting from the root. This parents are exactly the prefixes of p in binary
// notation, that's why we use binary shifts to calculate them.
void push(int p) {
  for (int s = h; s > 0; s--) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i << 1, d[i]);
      apply(i << 1 | 1, d[i]);
      d[i] = 0;
    }
  }
}

void inc(int l, int r, int value) {
  l += n, r += n;
  int l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) apply(l++, value);
    if (r & 1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}

int query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  int res = -2e9;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = max(res, t[l++]);
    if (r & 1) res = max(res, t[--r]);
  }
  return res;
}

// Assignment modifications, sum queries

// We suppose there's a value we never use for modification, in our case it's 0.
// In case there's no such value — we would create additional boolean array and
// refer to it instead of checking d[p] == 0.

// Now we have additional parameter k, which stands for the lenght of the
// interval corresponding to node p. We will use this name consistently in the
// code to preserve this meaning. Obviously, it's impossible to calculate the
// sum without this parameter. We can avoid passing this parameter if we
// precalculate this value for every node in a separate array or calculate it
// from the node index on the fly, but I'll show you a way to avoid using extra
// memory or calculations.
void calc(int p, int k) {
  if (d[p] == 0)
    t[p] = t[p << 1] + t[p << 1 | 1];
  else
    t[p] = d[p] * k;
}

void apply(int p, int value, int k) {
  t[p] = value * k;
  if (p < n) d[p] = value;
}

void build(int l, int r) {
  int k = 2;
  for (l += n, r += n - 1; l > 1; k <<= 1) {
    l >>= 1, r >>= 1;
    for (int i = r; i >= l; i--) calc(i, k);
  }
}

void push(int l, int r) {
  int s = h, k = 1 << (h - 1);
  for (l += n, r += n - 1; s > 0; --s, k >>= 1) {
    for (int i = l >> 1; i <= r >> s; ++i) {
      apply(i << 1, d[i], k);
      apply(i << 1 | 1, d[i], k);
      d[i] = 0;
    }
  }
}

void modify(int l, int r, int value) {
  if (value == 0) return;
  push(l, l + 1);
  push(r - 1, r);
  int l0 = l, r0 = r, k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l & 1) apply(l++, value, k);
    if (r & 1) apply(--r, value, k);
  }
  build(l0, l0 + 1);
  build(r0 - 1, r0);
}

int query(int l, int r) {
  push(l, l + 1);
  push(r - 1, r);
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += t[l++];
    if (r & 1) res -= t[--r];
  }
  return res;
}
