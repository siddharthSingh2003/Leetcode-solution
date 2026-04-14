class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n  = height.size();
    //     int totalWater = 0;

    //     for( int i=0; i<n; i++){
    //         int maxLeft = 0;
    //         int maxRight = 0;

    //         for(int j=0; j<=i; j++){
    //             if(height[j]>maxLeft){
    //                 maxLeft = height[j];
    //             }
    //         }

    //         for(int j=i; j<n; j++){
    //             if(height[j]>maxRight){
    //                 maxRight = height[j];
    //             }
    //         }

    //         totalWater += min(maxLeft, maxRight) - height[i];
    //     }

    //     return totalWater;
    // }


    int trap(vector<int>&height){
        int n = height.size();

        int left = 0;
        int right = n-1;

        int maxLeft=0;
        int maxRight=0;

        int totalWater = 0;

        while(left<=right){
            if(height[left]<= height[right]){
                if(height[left]>= maxLeft){
                    maxLeft = height[left];
                }
                else{
                    totalWater += maxLeft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>= maxRight){
                    maxRight = height[right];
                }
                else{
                    totalWater +=maxRight - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};