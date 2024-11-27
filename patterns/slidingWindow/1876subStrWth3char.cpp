// Given a string s​​​​​, return the number of good substrings of 
// length three in s​​​​​​.

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int countGoodSubstrings(std::string s) {
        int k=3; //fixed windoow size
        int i=0, j=k-1, count = 0;
        std::unordered_map<char, int>map;

        for(int x = i; x<=j; x++){
            map[s[x]]++;
        }

        i = k, j = 0;
        while(i<=s.length()){
            if(map.size() == k){
                count++;
            }

            map[s[j]]--;
            map[s[i]]++;
            if(map[s[j]] == 0){
                map.erase(s[j]);
            }
            i++;
            j++;
        }
        return count;

    }
};

int main(){
    std::string s = "";
    Solution sol;
    int cnt = sol.countGoodSubstrings(s);

    std::cout << "cnt: " << cnt;
}