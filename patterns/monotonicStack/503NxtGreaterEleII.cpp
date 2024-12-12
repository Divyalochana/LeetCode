/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.
*/

#include <iostream>
#include <vector>
#include <stack>
#include<unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1) {
        std::stack<int> st;
        std::unordered_map<int, int> map;
        int n = nums1.size();
        std::vector<int>res(n,-1);
        for(int i = 2*n-1; i>=0; i--){
            int pos = i%n;
            while(!st.empty() && st.top() <= nums1[pos]){st.pop();}

            if(i<n){
                res[i] = st.empty()? -1 : st.top();
            }

            st.push(nums1[pos]);
        }
        return res;
    }
};

int main(){
    Solution s;
    std::vector<int> nums1 = {5,4,3,2,1};
    std::vector<int> res = s.nextGreaterElement(nums1);

    for (int i : res){
        std::cout << i << " ";
    }
    return 0;
}