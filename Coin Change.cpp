// Amazon Interview Question

#include<climits>
#include<vector>

int minCoins(std::vector<int> coins, int target) {

        int ans = 0, N = coins.size();
        std::vector<int> DP(target+1, INT_MAX);
        DP[0] = 0;

        for(int i = 1; i <= target; ++i) {
            for(int j = 0; j < N; ++j) {
                if(coins[j] <= i) {
                    if (DP[i - coins[j]] != INT_MAX && DP[i] > 1 + DP[i - coins[j]]) {
                        DP[i] = 1 + DP[i - coins[j]];
                    }
                }
            }
        }
        ans = DP[target];
        if(ans == INT_MAX){
            ans = -1;
        }
        return ans;
    }
};
