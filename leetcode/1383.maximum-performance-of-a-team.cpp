/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    const int mod = 1e9 + 7;
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    sort(order.begin(), order.end(),
         [&](int a, int b) { return efficiency[a] > efficiency[b]; });
    priority_queue<int> pq;
    long long s = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      pq.push(-speed[order[i]]);
      s += speed[order[i]];
      while (pq.size() > k) {
        s += pq.top();
        pq.pop();
      }
      ans = max(ans, s * efficiency[order[i]]);
    }
    // for(int i=k; i<n; i++) {
    //     int spd = -pq.top(); pq.pop();
    //     s += speed[order[i]] - spd;
    //     pq.push(-speed[order[i]]);
    //     ans = max(ans, s * efficiency[order[i]]);
    // }
    return ans % mod;
  }
};
// @lc code=end
