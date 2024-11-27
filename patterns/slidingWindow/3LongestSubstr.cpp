//*! Longest Substring Without Repeating Characters

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<char, int> map;
    int lengthOfLongestSubstring(std::string s) {
        int i=0,j=0, maxLen = 0, len=0;
        while(j<s.length()){
            if(map.find(s[j]) == map.end()){
                map[s[j]] = j;
            }else{
                if(map[s[j]] >= i){
                    i = map[s[j]]+1;
                }
                map[s[j]] = j;
            }
            len = (j-i)+1;
            maxLen = std::max(maxLen, len);
            j++;
        }
        return maxLen;
        
    }
};

int main(){
    Solution s;
    std::string str = "cadbzabcd";
    int len = s.lengthOfLongestSubstring(str);
    std::cout << "unique char: " << len << std::endl;
}