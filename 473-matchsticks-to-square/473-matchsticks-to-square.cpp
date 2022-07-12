class Solution {
public:
    bool backtrack(vector<int>&matchsticks, vector<int>&sides,int sideLength,int i){
        if(i == matchsticks.size())
            return true;
        
        for(int j=0;j<4;++j){
            if(sides[j] + matchsticks[i] <= sideLength){
                sides[j] += matchsticks[i];
                if(backtrack(matchsticks,sides,sideLength,i+1))
                    return true;
                
                sides[j] -= matchsticks[i];
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int length = accumulate(matchsticks.begin(), matchsticks.end(),  0);
        
        if(length % 4 != 0)
            return false;
        
        vector<int>sides(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        int sideLength = length / 4;
        return backtrack(matchsticks, sides,sideLength,0);
    }
};