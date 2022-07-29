class Solution {
public:
    int findMin(vector<int>& arr) {
        int minElement = INT_MAX;
        int left = 0,right = arr.size() - 1;
        
        while(left <= right){
            if(arr[left] <= arr[right]){
                minElement = min(minElement, arr[left]);
                return minElement;
            }
            
            int mid = left + (right - left)/2;
            minElement = min(minElement, arr[mid]);
            
            if(arr[mid] >= arr[left])
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return minElement;
    }
};