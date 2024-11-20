#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> decrypt(std::vector<int>& code, int k) {
        int n = code.size();
        std::vector<int> res(n,0);
        int sum = 0, i, j, it;
        if(k==0){
            return res;
        }

        if(k>0){
            i=1;
            j=k;
        }else{
            i = n+k;
            j = n-1;
        }
        for(it = i; it<=j; it++){
            sum += code[it%n];
        }
        
        it=0;
        while(it < n){
            res[it] = sum;
            sum -= code[(i++)%n];
            sum += code[(++j)%n];
            it++;
        }
        return res;
    }
};

int main(){
    std::vector<int> code = {2,4,9,3};
    Solution s;
    std::vector<int> res = s.decrypt(code, 0);

    for (int i:res){
        std::cout << i << " ";
    }
}