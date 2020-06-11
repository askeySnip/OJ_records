/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;

    int res = 10;
    int ud = 9;
    int ad = 9;
    while(n-- > 1 && ad > 0) {
        ud = ud * ad;
        res += ud;
        ad--;
    }
    return res;
  }
};
// @lc code=end
