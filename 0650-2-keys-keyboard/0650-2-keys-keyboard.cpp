class Solution {
public:
    unordered_map<string, int>memo;
    int solve(int n, int clipboard, int window) {
        if (n == window)
            return 0;
        if (window > n)
            return INT_MAX / 2;
        
        string key = to_string(clipboard) + ',' + to_string(window);
            if (memo.find(key) != memo.end())
                return memo[key];
        int paste = 1 + solve(n, clipboard, window+clipboard);
        int copyAndPaste =  2 + solve(n, window, window * 2);
        // return min(paste, copyAndPaste);
        return memo[key] = min(paste, copyAndPaste);
    }
    int minSteps(int n) {
        if (n == 1)
            return 0;
        return 1 + solve(n, 1, 1);
    }
};