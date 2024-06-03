/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */

function sumByD (nums, div){
    let n= nums.length;
    
    let sum = 0;
    for(let i=0 ;i<n ;i++){
        sum += Math.ceil(nums[i]/div)
    } 
    return sum;
} 


var smallestDivisor = function(nums, threshold) {
    let n=nums.length;
    if(n>threshold) return -1;

    let low =1;
    let high = Math.max(...nums);

    while(low<= high){
        let mid = Math.floor((low +high)/2);

        if(sumByD(nums,mid) <=threshold){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
};