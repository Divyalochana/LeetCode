/*
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/

#include <iostream>
#include <vector>
#include <stack>
#include<unordered_map>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int>res(n, 0);
        std::stack<int> st;
        for(int i = temperatures.size()-1; i>=0; i--){
            int days = 0;
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]){st.pop();}

            if(!st.empty()){
                res[i] = st.top() - i;
            }

            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution s;
    std::vector<int> nums1 = {73,74,75,71,69,72,76,73};
    std::vector<int> res = s.dailyTemperatures(nums1);

    for (int i : res){
        std::cout << i << " ";
    }
    return 0;
}