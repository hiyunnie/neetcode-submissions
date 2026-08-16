class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) return false;

                if ((s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[') ||
                    (s[i] == ')' && st.top() == '(')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

/**

## Approach

Use a stack to store opening brackets.

For each character:

1. If it is an opening bracket, push it into the stack.
2. If it is a closing bracket:
   - First check whether the stack is empty.
   - Check whether the top of the stack is the matching opening bracket.
   - If it matches, pop it.
   - Otherwise, return false.
3. After processing all characters, the stack must be empty.

## Complexity

- Time: `O(n)`
- Space: `O(n)`

## Interview Explanation

I use a stack to keep track of opening brackets.

When I see an opening bracket, I push it onto the stack.

When I see a closing bracket, I first check whether the stack is empty. Then I compare it with the top of the stack.

If they match, I pop the opening bracket. Otherwise, I return false.

At the end, the stack must be empty for the string to be valid.

## Follow-up

Can you simplify the matching logic so you don't need to check all three bracket pairs in one long `if` statement?
class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                st.push('}');
            } else if (s[i] == '[') {
                st.push(']');
            } else if (s[i] == '(') {
                st.push(')');
            } else {
                if (st.empty()) return false;

                if (s[i] == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

## Note

Always check `st.empty()` before calling `st.top()`.

Also remember to return `st.empty()` at the end.
**/
