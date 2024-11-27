#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i=0, j=0, k=0;
        std::vector<int> nums3(m+n);
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                nums3[k++] = nums1[i++];
            }else{
                nums3[k++] = nums2[j++];
            }
        }
        while(i<m){
            nums3[k++] = nums1[i++];
        }
        while(j<n){
            nums3[k++] = nums2[j++];
        }
        nums1 = nums3;
        std::cout << std::endl;
    }
};

int main(){
    Solution s;
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {2,5,6};
    s.merge(nums1, 3, nums2, nums2.size());
}