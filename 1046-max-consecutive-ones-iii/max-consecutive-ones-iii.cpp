class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int maxLen=0;
        // for(int i=0; i<nums.size(); i++){
        //     int zeros=0; 

        //     for(int j=i; j<nums.size();j++){

        //         if(nums[j]==0){
        //             zeros++;
        //         }

        //         if(zeros>k) break;

        //         maxLen = max(maxLen, j-i+1);
        //     }
        // }
        // return maxLen;



        // int left=0;
        // int zeros =0;
        // int maxLen =0; 

        // for(int right =0; right<nums.size(); right++){
        //     if(nums[right]==0){
        //         zeros++;
        //     }

        //     while(zeros>k){
        //         if(nums[left]==0){
        //             zeros--;
        //         }
        //         left++;
        //     }

        //     maxLen = max(maxLen, right-left+1);
        // }
        // return maxLen;



        int left=0; 
        int zero=0;
        int maxLen=0;

        for(int right=0; right<nums.size();right++){
            if(nums[right]==0){
                zero++;
            }
            if(zero>k){
                if(nums[left]==0){
                    zero--;
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};