class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        for(string c : tokens) {
            if (c == "+" || c == "-" || c=="*" || c=="/") {
                int first = stoi(s.top());
                s.pop();
                int second = stoi(s.top());
                s.pop();
                if (c == "+")
                    s.push(to_string(second + first));
                else if (c=="-")
                    s.push(to_string(second - first));
                else if (c=="*")
                    s.push(to_string(second*first));
                else
                    s.push(to_string(second/first));
            }
            else
                s.push(c);
        }
        return stoi(s.top());
    }
};