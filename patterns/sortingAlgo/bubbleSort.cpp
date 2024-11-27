#include <iostream>
#include <vector>

class sorting{
    public:
    void bubbleSort(std::vector<int>& nums){
        int i, j, min=0;
        int n = nums.size();

        for(i=0; i<n-1; i++){
            for(j=0; j<n-i-1; j++){
                if(nums[j] > nums[j+1]){
                    std::swap(nums[j], nums[j+1]);
                }
            }
            
        }
    }
};

int main(){
    std::vector<int> nums = {13, 46, 24, 52, 20, 9};
    sorting s;
    s.bubbleSort(nums);

    for (int i:nums){
        std::cout << i << " ";
    }
}