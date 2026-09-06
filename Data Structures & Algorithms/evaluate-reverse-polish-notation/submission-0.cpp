class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();

                if (s == "+")
                    stk.push(val2 + val1);
                else if (s == "-")
                    stk.push(val2 - val1);
                else if (s == "*")
                    stk.push(val2 * val1);
                else if (s == "/")
                    stk.push(val2 / val1);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};
