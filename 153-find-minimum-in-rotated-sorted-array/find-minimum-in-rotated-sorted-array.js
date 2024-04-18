/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let low=0, high=nums.length-1;
    let ans= Infinity;
    while(low<=high){
        let mid = Math.floor((low+high)/2);

        if(nums[low]<=nums[high]){
            ans = Math.min(ans, nums[low])
        }

        if(nums[low]<= nums[mid]){
            ans = Math.min(ans, nums[low])
            low= mid+1
        }
        else{
            ans = Math.min(ans, nums[mid])
            high = mid-1
        }
    }
    return ans;
};