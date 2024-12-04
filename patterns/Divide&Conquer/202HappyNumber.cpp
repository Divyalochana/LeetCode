/*
A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
*/

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        int num=0, sum=0;
        std::unordered_set<int> seen;
        while(n != 1){
            while(n>0){
                num = n%10;
                n = n/10;
                sum += num*num;
            }
            
            if(seen.find(sum) != seen.end()){
                return false;
            }
            seen.insert(sum);
            n = sum; 
            sum = 0;
            
        }
        return true;
    }
};

int main(){
    Solution s;
    int nums = 3;
    if(s.isHappy(nums)){
        std::cout << "true";
    }else{
        std::cout << "false";
    }
    return 0;
}