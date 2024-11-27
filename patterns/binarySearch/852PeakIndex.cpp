/*You are given an integer mountain array arr of length n where the values increase to 
a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.*/

#include <iostream>
#include <vector>

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int low = 0, high = arr.size()-1;
        return splitNSearch(arr, low, high);
    }

    int splitNSearch(std::vector<int>&arr, int low, int high){
        if(low<high){
            int mid = (low+high)/2;
            if( (arr[mid-1] < arr[mid]) && (arr[mid] > arr[mid+1])){
                return mid;
            }else if(arr[mid-1] > arr[mid]){
                return splitNSearch(arr, low, mid);
            }else if(arr[mid] < arr[mid+1]){
                return splitNSearch(arr, mid+1, high);
            }
        }
        return -1;
    }
};

int main(){
    std::vector<int> nums = {0,10,5,2};
    Solution s;
    int peakInd = s.peakIndexInMountainArray(nums);

    std::cout << "Index: " << peakInd;
    return 0;
}