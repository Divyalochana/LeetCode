#include <iostream>
#include <vector>

class sorting{
    public:
    void insertionSort(std::vector<int>& nums){
        int i, j, min=0;
        int n = nums.size();

        for(i=0; i<n; i++){
            j=i;
            while(j>0 && nums[j-1]>nums[j]){
               std::swap(nums[j-1], nums[j]);
               j--;
            }
            
        }
    }
};

int main(){
    std::vector<int> nums = {13, 46, 24, 52, 20, 9};
    sorting s;
    s.insertionSort(nums);

    for (int i:nums){
        std::cout << i << " ";
    }
}