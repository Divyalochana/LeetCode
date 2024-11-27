#include <iostream>
#include <vector>

class sorting{
    public:
    void merge(std::vector<int>& nums, int low, int mid, int high);
    void mergeSort(std::vector<int>& nums, int low, int high){
        if(low < high){
            int mid = (low+high)/2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
        return;
    }
};

void sorting::merge(std::vector<int>& nums, int low, int mid, int high){
   std::vector<int> res;
   int i = low;
   int j = mid+1;
    while(i<=mid && j<=high){
        if(nums[i] < nums[j]){
            res.push_back(nums[i++]);
        }else{
            res.push_back(nums[j++]);
        }
    }

    while(i<=mid){
        res.push_back(nums[i++]);
    }
    while(j<=high){
        res.push_back(nums[j++]);
    }

    for(int i = low; i<=high; i++){
        std::cout << "low: " << low << " i: " << i << std::endl;
        nums[i] = res[i-low];
    }
    std::cout << "**************" << std::endl;

    // return res;
}

int main(){
    std::vector<int> nums = {13, 46, 24, 52, 20, 9};
    sorting s;
    s.mergeSort(nums, 0, nums.size()-1);

    std::cout << std::endl;
    for (int i:nums){
        std::cout << i << " ";
    }

    
}