/**
 * @param {number[]} v
 * @param {number} h
 * @return {number}
 */
function findMax(v){
    let maxi = -Infinity;
    let n=v.length;
    for(let i=0; i<n; i++){
        maxi = Math.max(maxi, v[i]);
    }
    return maxi
}

function calculateTotalHours(v,h){
    let totalH=0;
    let n= v.length;
    for(let i=0; i<n; i++){
        totalH+=Math.ceil(v[i]/h);
    }
    return totalH;
}

var minEatingSpeed = function(v, h) {
    let low =1;
    let high = findMax(v);

    while(low<=high){
        let mid = Math.floor((low+high)/2);
        let totalH = calculateTotalHours(v,mid);

        if(totalH<=h){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
};