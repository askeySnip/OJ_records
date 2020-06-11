/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {
 public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    cur = 0;
    len = 0;
  }

  void visit(string url) {
    if (history.size() == cur + 1) {
        history.push_back(url);
        cur++;
        len++;
    } else {
        cur++;
        len = cur;
        history[cur] = url;
    }
  }

  string back(int steps) {
    int id = max(0, cur - steps);
    cur = id;
    return history[cur];
  }

  string forward(int steps) {
    int id = min(len, cur + steps);
    cur = id;
    return history[cur];
  }

 private:
  vector<string> history;
  int cur, len;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end
