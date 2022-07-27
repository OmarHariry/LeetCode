class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>>maxHeap;
        
        for(int x : stones)maxHeap.push(x);
        
        while(maxHeap.size() > 1){
            int y = maxHeap.top();maxHeap.pop();
            int x = maxHeap.top();maxHeap.pop();
            
            if(x != y)
                maxHeap.push(y - x);
            
        }
        
        return maxHeap.size() == 1 ? maxHeap.top() : 0;
    }
};