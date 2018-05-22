class Solution {
public:
    int dp[10000];
    int maxProfit(vector<int>& prices) {
        memset(dp, 0, sizeof(0));
        int len = prices.size();
        if(len < 2) return 0;
        for(int i=1; i<len; i++) dp[i] = max(dp[i], prices[i] - prices[0]);
        for(int i=2; i<len; i++){
            dp[i] = max(dp[i], dp[i-1]);		// notice this sentence
            for(int j=1; j<i; j++){
                if(j>=2) dp[i] = max(dp[i], prices[i]-prices[j] + dp[j-2]);
                else dp[i] = max(dp[i], prices[i]-prices[j]);
            }
        }
        return dp[len-1];
    }
};
/*
a dynamic programming problem:
dp[i] : the maxProfit from 0 to i.
dp[i] = max(dp[i-1], dp[i]) && (
dp[i] = max(dp[i], prices[i]-prices[j] + dp[j-2]) if j >= 2
or dp[i] = max(dp[i], prices[i]-prices[j]) j==1;
)
*/

// the better solution

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /***
         * 基于两个表达式来做：
         *  buy[i] = max(buy[i-1],sell[i-2]-curr_price)
         *  sell[i] = max(sell[i-1],buy[i-1]+curr_price)
         * */
        if(prices.empty())return 0;
        // 这里虽然i与前两个相关，但是我们只需要两个值，当前值可以用之前的两个值更新，因此不需要变量
        int pre_sell = 0;
        int curr_sell = 0;
        int pre_buy =0;
        // 因为初始化的时候，pre_buy(i-2)会等于buy(i-1),然后buy(i)等于max over buy(i-1) and sell(i-2)-curr_price
        // 因此我们需要确保初次购买max取得是sell(i-2) i.e pre_sell - curr_price
        int curr_buy = std::numeric_limits<int>::min();
        for(auto curr_price:prices){
            pre_buy = curr_buy;
            curr_buy = std::max(pre_buy,pre_sell-curr_price);
            pre_sell = curr_sell;
            curr_sell = std::max(pre_sell,pre_buy+curr_price);
        }
        // 最后返回sell，因为显然buy[i]<=sell[i]
        return curr_sell;
    }
};