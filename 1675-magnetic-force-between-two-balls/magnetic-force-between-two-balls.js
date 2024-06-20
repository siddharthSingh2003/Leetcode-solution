/**
 * @param {number[]} position
 * @param {number} m
 * @return {number}
 */
function canWePlace (stalls, dist, cows){
        const n = stalls.length;
        let cntCows = 1; 
        let last = stalls[0];
        for (let i=1; i<n ; i++){
            if(stalls[i]-last >= dist){
                cntCows++;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }
var maxDistance = function(position, m) {
    let n= position.length;
    position.sort((a,b) => a-b);
        let low= 1, high = position[n-1] - position[0];
        
        while(low<=high){
            const mid = Math.floor((low+high)/2);
            if(canWePlace(position, mid, m)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
};