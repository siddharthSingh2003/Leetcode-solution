/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

function countStudents(a, pages){
        var n= a.length;
        var students=1;
        var pagesStudent =0;
        for(var i=0; i<n; i++){
            if(pagesStudent+a[i] <= pages){
                pagesStudent+=a[i];
            }
            else{
                students++;
                pagesStudent = a[i];
            }
        }
        return students;
    }
function findPages(a, n, m)
    {
        //your code here
        
        if(m>n) return -1;
        
        var low = Math.max(...a);
        var high = a.reduce((a,b) => a+b, 0);
        
        while(low<=high){
            var mid = Math.floor((low+high)/2);
            var students= countStudents(a, mid);
            
            if(students>m){
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
        
        
        
        
        
    }
var splitArray = function(nums, k) {
    return findPages(nums, nums.length, k)
};