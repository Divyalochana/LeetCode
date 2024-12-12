/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2.
If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
*/

#include <iostream>
#include <vector>
#include <stack>
#include<unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int>res;
        std::stack<int> st;
        std::unordered_map<int, int> map;
        for(int i = nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){st.pop();}

            map[nums2[i]] = st.empty()? -1 : st.top();

            st.push(nums2[i]);
        }
        
        for(int i:nums1){
            res.push_back(map[i]);
        }
        return res;
    }
};

int main(){
    Solution s;
    std::vector<int> nums1 = {1,3,5,2,4};
    std::vector<int> nums2 = {6,5,4,3,2,1,7};
    std::vector<int> res = s.nextGreaterElement(nums1, nums2);

    for (int i : res){
        std::cout << i << " ";
    }
    return 0;
}