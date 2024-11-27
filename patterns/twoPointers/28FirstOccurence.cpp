#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int len = needle.length();
        int i=0;
        while(haystack[i] != '\0'){
            if(haystack.substr(i, len) == needle){
                return i;
                break;
            }else{
                i++;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    std::string s1 = "sadbutsad";
    std::string s2 = "dbu";
    int val = s.strStr(s1, s2);

    std::cout << "val: " << val;
}