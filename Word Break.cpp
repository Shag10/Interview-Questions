#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
bool isPossible(std::string s, std::vector<std::string> words) {
		if(s == "")
            return true;

        if(words.size() == 0)
            return false;

        int S = 0, N = s.length();

        std::unordered_set<std::string> stringSet;
        for(auto x: words) {
            stringSet.insert(x);
            S = std::max(S, (int)x.length());
        }
        std::vector<bool> DP(N+1, false);
        DP[0] = true;

        for(int i=1; i<=N; ++i) {
            std::string substr = "";
            if(DP[i-1] == true) {
                for(int j=i; j<(S+i) && j<=N; ++j) {
                    substr += s[j-1];
                    if (stringSet.find(substr) != stringSet.end())
                        DP[j] = true;
                }
            }
        }
        return DP[N];
	}
