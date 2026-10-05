// 0 ms | 42.2 MB
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // pass1:find teh candidate
        int candidate=0;
        int count=0;
        for(int num:nums){
            if(count==0) candidate= num;
            if(num==candidate) count++;
            else count--; 
        }
        //verifying the candidate
        count=0;
        for(int num:nums){
            if(candidate==num) count++;
        }
        if(count>nums.size()/2) return candidate;
        return -1;
    }
};