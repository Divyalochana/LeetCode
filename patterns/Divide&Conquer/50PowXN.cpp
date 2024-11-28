// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <iostream>
#include <iomanip>

class Solution {
public:
    double myPow(double x, int n) {
        long double res = 1.0;
        if(n==0){return res;}
        long long absN = abs((long long)n);
        while(absN>0){
            if(absN%2 == 1){
                res *= x;
            }
            x *= x;
            absN /= 2; 
        }
        return n>0?res:(1/res);
    }
};

int main(){
    Solution s;
    int n = s.myPow(0.00001, 2147483647);
    std::cout << std::fixed << std::setprecision(15) <<"Power: " << n;
    return 0;
}