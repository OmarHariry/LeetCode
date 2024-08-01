class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(string person : details) {
            // get the 12 and 13 character
            int age = stoi(person.substr(11, 2));
            // compare
            if (age > 60)
                ++ans;
        }
        return ans;
    }
};