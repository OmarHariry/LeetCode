class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string token;
        vector<int>numbers;
        while (ss >> token) {
            if(token[0] >= '0' && token[0] <= '9')
                numbers.push_back(stoi(token));

        }
        
        for(int i = 1;i<numbers.size(); ++i) {
            if(numbers[i] <= numbers[i-1])
                return false;
        }
        
        return true;
    }
};