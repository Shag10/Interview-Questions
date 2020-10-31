#include<unordered_set>
	bool isHappy(int num) {
	  std::unordered_set<int> seen;
        while(num != 1) {
            if(seen.count(num) == 1) return false;
            seen.insert(num);
            int nxt = 0;
            while(num > 0) {
                int dig = num % 10;
                nxt += dig * dig;
                num /= 10;
            }
            num = nxt;
        }
        return true;
		
}
