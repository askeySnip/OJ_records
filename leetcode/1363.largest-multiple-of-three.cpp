/*
 * @lc app=leetcode id=1363 lang=cpp
 *
 * [1363] Largest Multiple of Three
 */

// @lc code=start
class Solution {
 public:
  string largestMultipleOfThree(vector<int>& digits) {
    sort(digits.begin(), digits.end());
    int n = digits.size();
    int s = accumulate(digits.begin(), digits.end(), 0);
    if (s % 3 == 0) {
      string ans;
      for (int i = n - 1; i >= 0; i--) {
        ans += digits[i] + '0';
      }
      if(ans[0] == '0') return "0";
      return ans;
    } else if (s % 3 == 2) {
      int f = -1;
      for (int i = 0; i < n; i++) {
        if (digits[i] % 3 == 2) {
          f = i;
          break;
        }
      }
      string ans;
      if (f < 0) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
          if (digits[i] % 3 == 1 && cnt < 2) {
            cnt++;
            continue;
          }
          ans = (char)(digits[i] + '0') + ans;
        }
      } else {
        for (int i = n - 1; i >= 0; i--) {
          if (i == f) continue;
          ans += digits[i] + '0';
        }
      }
      return ans;
    }
    string ans;
    int f = -1;
    for (int i = 0; i < n; i++) {
      if (digits[i] % 3 == 1) {
        f = i;
        break;
      }
    }
    if (f >= 0) {
      for (int i = n - 1; i >= 0; i--) {
        if (i == f) continue;
        ans += digits[i] + '0';
      }
    } else {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (digits[i] % 3 == 2 && cnt < 2) {
          cnt++;
          continue;
        }
        ans = (char)(digits[i] + '0') + ans;
      }
    }
    return ans;
  }
};
// @lc code=end
