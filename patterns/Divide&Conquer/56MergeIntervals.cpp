// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
#include <iostream>
#include <vector>
#include <algorithm>

// O(n^2) time complexity
#if 0
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0, j=1;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a,std::vector<int>&b){return a[0]<b[0];});
        while(i<intervals.size() && j<intervals.size()){
            if(intervals[i][1] >= intervals[j][0]){
                if(intervals[i][1] < intervals[j][1]){
                    intervals[i][1] = intervals[j][1];
                }
                intervals.erase(intervals.begin()+j);
            }else{
                i++;
                j++;
            }
        }
        return intervals;   
    }
};
#endif

// Optimized version with nlogn complexity
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1){
            return intervals;
        }
        std::vector<std::vector<int>>res;
        sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int>&b){return a[0]<b[0];});
        
        for(const auto& ele: intervals){
            if(res.empty() || res.back()[1] < ele[0]){
                res.push_back(ele);
            }else{
                res.back()[1] = std::max(res.back()[1], ele[1]);
            }
        }
        return res;  
    }
};

int main(){
    std::vector<std::vector<int>>nums = {{0,2}, {1,4}, {3,5}};
    Solution s;
    std::vector<std::vector<int>>res = s.merge(nums);

    for(const auto& row:res){
        for(const auto &j: row){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}