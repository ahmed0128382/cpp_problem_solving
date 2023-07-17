#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum > mx) mx = sum;
            if(sum < 0) sum = 0;
        }
        return mx;
    }
};
int main(){
    
    Solution s1;
    vector<int> nums={1,-2,3,-5,5,6,-8,7};
    cout<< s1.maxSubArray(nums);


}