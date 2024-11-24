// Longest substring with k distinct characters

#include <iostream>
#include <string>
#include <unordered_map>

class solution {
    public :
    int longestSubstr(std::string s, int k){
        std::unordered_map<char, int> map;
        int i=0, j=0, maxLen = 0;
        while(j<s.length()){
            map[s[j]]++;
            if(map.size() <= k){
                maxLen = std::max(maxLen, j-i+1);
            }else{
                map[s[i]]--;
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return maxLen;

    }
};

int main(){
    std::string s = "baccddddba";
    solution sol;
    int maxLen = sol.longestSubstr(s, 3);
    std::cout << "maxLen: " << maxLen;
}