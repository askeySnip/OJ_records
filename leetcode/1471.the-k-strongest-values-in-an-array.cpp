/*
 * @lc app=leetcode id=1471 lang=cpp
 *
 * [1471] The k Strongest Values in an Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int m = arr[(n - 1) / 2];
    int f = 0, t = n-1;
    vector<int> ans;
    while(ans.size() < k) {
        if(m - arr[f] > arr[t]-m) {
            ans.push_back(arr[f]);
            f++;
        } else {
            ans.push_back(arr[t]);
            t--;
        }
    }
    return ans;
  }
};
// @lc code=end
