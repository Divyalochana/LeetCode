// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int cnt = 0, i=0, j=1;
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int>& a, std::vector<int> &b){return a[1]<b[1];});
        while(i<j && j<intervals.size()){
            if(intervals[i][1] <= intervals[j][0]){
                i=j;
            }else{
                cnt++;
            }
            j++;
        }
        
        return cnt;
    }
};

int main(){
    std::vector<std::vector<int>> intervals = {{1,2}, {2,3}};
    Solution s;
    int count = s.eraseOverlapIntervals(intervals);

    std::cout << "count: " << count;
}