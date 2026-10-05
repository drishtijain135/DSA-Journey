// 3 ms | 71.8 MB
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maxSum = INT_MIN;
        for(int num:nums){
            currentSum+=num;
            maxSum = max(currentSum,maxSum);
            if(currentSum<0) currentSum=0;
        }
        return maxSum;
    }
};