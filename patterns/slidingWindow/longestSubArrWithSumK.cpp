// You are given an array 'a' of size 'n' and an integer 'k'.
// Find the length of the longest subarray of 'a' 
// whose sum is equal to 'k'.

#include <iostream>
#include <vector>

class solution{
    public:
    int longestSubstrOfSumK(std::vector<int>& vec, int k){
        int i = 0, j = 0, len = 0, maxLen = 0;
        long long sum =0;
        while(j < vec.size()){
            sum += vec[j];
            while(sum > k){
                sum -= vec[i];
                i++;
            }
            if(vec[j] == k || sum == k){
                len = j-i+1;
                maxLen = std::max(maxLen, len);     
            }
            j++;
        }
        return maxLen;
    }
};

int main(){
    std::vector<int> nums = {8, 15, 17, 0, 11 };
    solution s;
    int maxlen = s.longestSubstrOfSumK(nums, 17);
    std::cout << "len: " << maxlen;
}