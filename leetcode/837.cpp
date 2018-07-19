// First, the destination conditional probability is P(<=N | >= K) which equals to P(<= N && >= K) / P(>=K).

// Without limitations,
// P(x) = 1 / w * (P(x - 1) + P(x - 2) +... + P(x-w))
// = 1 / w * sumP(x - w, x - 1)
// = 1 / w * sumP(lb, ub).
// Here, P(x) means the probability of becoming x points after some draws.
// lb, ub means lower bound and upper bound.

// But there are some limitations to lb and ub:

// lb >= 0 (let P(0) = 1)
// ub <= K - 1, because when you have K points or more, you cannot draw a new card.
// To calculate all the P()s is very time-consuming, thus we can use the cumulative sum technique.

// Finally,
// P(<= N && >= K) = sumP(K, N), and
// P(>= K) = sumP(K, +∞).
// In fact, when x > K + W - 1, P(x) = 0, thus sumP(K, +∞) = sumP(K, K + W - 1);
// Also, sumP(K, N) = sumP(K, min(N, K + W - 1))

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if(K == 0 || N >= K + W - 1) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K) Wsum += dp[i]; else res += dp[i];
            if (i - W >= 0) Wsum -= dp[i - W];
        }
        return res;
    }
};