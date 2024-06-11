class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> rem;
        unordered_map<int, int>mp;
        for(int x : arr1) mp[x]++;
        
        int j = 0;
        for(int i=0;i<arr2.size();++i){
            if(mp.find(arr2[i]) != mp.end()) {
                while(mp[arr2[i]] > 0) {
                    arr1[j++] = arr2[i];
                    --mp[arr2[i]];
                }
            }
        }
        
        for (auto it : mp) {
            while (it.second-- > 0)
                rem.push_back(it.first);
        }
        
        sort(rem.begin(), rem.end());
        
        int i = 0;
        while(j < arr1.size())
            arr1[j++] = rem[i++];
        return arr1;
    }
};