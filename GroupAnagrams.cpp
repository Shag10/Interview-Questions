#include<string>
#include<vector>
#include <map>
#include <algorithm>
std::vector<std::vector<std::string>> getGroups(std::vector<std::string> words) {
std::map<std::string,std::vector<std::string>> sorted;
   std::string temp_str;
        for(int i=0;i<words.size();i++)
        {
            temp_str=words[i];
            sort(temp_str.begin(),temp_str.end());
            sorted[temp_str].push_back(words[i]);
        }
        std::vector<std::vector<std::string>> res;
        for(auto i=sorted.begin();i!=sorted.end();i++)
        {
            res.push_back(i->second);
        }

        return res;
}
