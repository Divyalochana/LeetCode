#include <iostream>
#include <vector>

class sorting{
    public:
    void quickSort(std::vector<int>& nums, int low, int high){
        if(low<high){
            int pivot = nums[low];
            int i=low, j=high;
            while(i<j){
                while(i<high && nums[i]<=pivot){i++;}
                while(nums[j]>pivot){j--;}
                if(i<j){
                    std::swap(nums[i], nums[j]);
                }
            }
            std::swap(nums[low], nums[j]);
            int pInd = j;            // Partition Index
            quickSort(nums, low, pInd-1);
            quickSort(nums, pInd+1, high);
        }
    }
};

int main(){
    std::vector<int> nums = {13, 46, 24, 52, 20, 9};
    sorting s;
    s.quickSort(nums, 0, nums.size()-1);

    for (int i:nums){
        std::cout << i << " ";
    }
}