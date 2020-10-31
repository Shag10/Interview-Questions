#include<string>
#include<vector>
int getLCS(std::string &str1, std::string &str2, std::vector<std::vector<int>> &dp, int i, int j, int m, int n) {
        if(i > m or j > n) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(str1[i] == str2[j]) {
            return dp[i][j] = 1 + getLCS(str1, str2, dp, i + 1, j + 1, m, n);
        }
        return dp[i][j] = std::max(getLCS(str1, str2, dp, i + 1, j, m, n), getLCS(str1, str2, dp, i, j + 1, m, n));
    }

    int getLongest(std::string a, std::string b) {
        if(a.empty() or b.empty()) {
            return 0;
        }
        std::vector<std::vector<int>> dp(a.size() + 1, std::vector<int>(b.size() + 1, -1));
        return getLCS(a, b, dp, 0, 0, a.size() - 1, b.size() - 1);
	}
