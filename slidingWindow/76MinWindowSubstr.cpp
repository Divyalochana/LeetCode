#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if(s.empty() || t.empty()){
            return "";
        }
        int i=0, j=0,cnt = 0, minLen = INT_MAX, ind = -1;
        int m = s.length();
        int n = t.length();
        std::unordered_map<char, int>map;
        for(int k=0; k<n; k++){
            map[t[k]]++;
        }
    
        while(j<m){
            if(map[s[j]] > 0){
                cnt++;
            }
            map[s[j]]--;

            while(cnt == n){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    ind = i;
                }
                map[s[i]]++;
                if(map[s[i]] > 0){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ind==-1?"":s.substr(ind, minLen);  
    }
};

int main(){
    std:: string s= "ADOBECODEBANC";
    std::string t = "ABC";

    Solution sol;
    std::string res = sol.minWindow(s,t);
    std::cout << res ;
}