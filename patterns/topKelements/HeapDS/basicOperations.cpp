//Insertion, Deletion and creation of Heap Data Structure
#include <iostream>
#include <vector>

class Solution {
    std::vector<int> heapDS = {0,0, 0, 0, 1, 0, 2, 0};
public:
    void insertHeap(int ele){
        heapDS.push_back(ele);
        int len = heapDS.size();
        int i = len-1;
        while(i>1 && heapDS[i/2] < ele){
            heapDS[i] = heapDS[i/2];
            i=i/2;
        }
        heapDS[i] = ele;
    }

    void display(){
        for(int i=1; i<heapDS.size(); i++){
            std::cout << heapDS[i] << " ";
        }
    }

    void deleteHeap(){
        int n = heapDS.size();
        for(int pos=1; pos<n; pos++){
            int ele = heapDS[1];
            heapDS[1] = heapDS[n-pos];
            int i = 1;
            int j = 2*i;

            while(j < n-pos){
                if(j + 1 < n - pos && heapDS[j+1] > heapDS[j]){
                    j=j+1;
                }

                if(heapDS[j] > heapDS[i]){
                    std::swap(heapDS[j], heapDS[i]);
                    i=j;
                    j=2*i;
                }else{break;}
            }
            heapDS[n-pos] = ele;
        }
    }

    void create(){
        std::vector<int> nums = {7,9,5,25,15,10,10,35}; 
        for(int i=1; i<nums.size(); i++){
            insertHeap(nums[i]);
        }
    }

    void heapify(){
        int n = heapDS.size();
        int i=n-1;
        while(i>0){
            int j=2*i;
            
            if(2*i < n){
                if(j+1 < n && heapDS[j+1] > heapDS[j]){
                    j=j+1;
                }
                if(heapDS[j] > heapDS[i]){
                    std::swap(heapDS[i], heapDS[j]);
                    i=j;
                }else{
                    i--;
                }
            }else{i--;}
            
        }
    }

};

int main(){
    Solution s;
    // s.create();
    // s.display();
    // s.deleteHeap();
    // std::cout << std::endl << "---- After Deletion ----" << std::endl;
    // s.display();
    s.heapify();
    std::cout << std::endl <<"---- Heapify ----" << std::endl;
    s.display();
    return 0;
}