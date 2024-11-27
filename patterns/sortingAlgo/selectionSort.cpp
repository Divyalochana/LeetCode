#include <iostream>
#include <vector>

class selSort{
    public:
    void selectionSort(std::vector<int>& nums){
        int i, j, min=0;
        int n = nums.size();

        for(i=0; i<n-1; i++){
            min = i;
            for(j=i; j<=n-1; j++){
                if(nums[j] < nums[min]){
                    min = j;
                }
            }
            std::swap(nums[min], nums[i]);
        }
    }
};

int main(){
    std::vector<int> nums = {13, 46, 24, 52, 20, 9};
    selSort s;
    s.selectionSort(nums);

    for (int i:nums){
        std::cout << i << " ";
    }
}