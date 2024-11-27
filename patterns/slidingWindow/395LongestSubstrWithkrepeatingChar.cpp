// Given a string s and an integer k, return the length of the 
// longest substring of s such that the frequency of each 
// character in this substring is greater than or equal to k.
// if no such substring exists, return 0.

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int longestSubstring(std::string s, int k) {
        std::unordered_map<char, int> map;
        int n = s.length();
        
        if(n<k) return 0;
        if(k == 0 || k == 1) return n;

        for(char c:s) map[c]++;

        int i =0;
        while(i<n && map[s[i]] >= k) i++;

        if(i >= n-1) return i;
        int cnt1 = longestSubstring(s.substr(0, i),  k);
        while(i<n && map[s[i]] < k) i++;
        int cnt2 = longestSubstring(s.substr(i),  k);

        return(std::max(cnt1, cnt2));
    }
};



int main(){
    std::string s = "aaabb";
    Solution sol;
    int count = sol.longestSubstring(s, 3);

    std::cout << std::endl <<"count: " << count;
}