// 0 ms | 102.2 MB
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum =0;
        for(int num:nums) totalSum+= num;
        int target = totalSum-x;
        if(target==0) return n;
        int maxLen =-1;
        int left=0; int sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(left<=right && sum>target){
                sum-=nums[left];
                left++;
            }
            if(sum==target){
                maxLen = max(maxLen , right-left+1);
            }
        }
        if(maxLen ==-1) return -1;
        return n-maxLen;
    }
};