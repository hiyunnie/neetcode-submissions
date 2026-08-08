class Solution {
   public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
                continue;
            }

            if (!isalnum(s[right])) {
                right--;
                continue;
            }

            if (tolower(s[right]) != tolower(s[left]))
                return false;
            else {
                right--;
                left++;
            }
        }
        return true;
    }
};

/**

## Clarification

- Is the comparison case-insensitive?
- Should non-alphanumeric characters be ignored?
- Can the string be empty?

## Brute Force

Create a cleaned string that contains only lowercase alphanumeric characters.
Then compare the cleaned string with its reversed version.

- Time: `O(n)`
- Space: `O(n)`

## Optimized Approach

Use two pointers.

- One pointer starts from the beginning.
- The other starts from the end.
- Skip non-alphanumeric characters.
- Compare the lowercase version of both characters.
- If they are different, return false.
- Move both pointers toward the center until they meet.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Edge Cases

1. Empty string
2. String containing only punctuation
3. Uppercase and lowercase letters mixed together

## Interview Explanation

I use two pointers, one starting from the left and one from the right.
I skip any non-alphanumeric characters on both sides.
Then I compare the characters after converting them to lowercase.
If they are different, I return false.
Otherwise, I move both pointers toward the center.
This takes O(n) time and O(1) extra space.

## Follow-up
How would you solve it without calling tolower()?

I can implement a simple lowercase conversion myself. If the character is between 'A' and 'Z', I add the difference between 'a' and 'A'. Otherwise, I return the original character.
1.
char c = 'B';
to_lower(&c);
void to_lower(char *c)
{
    if (*c >= 'A' && *c <= 'Z') {
        *c = *c + ('a' - 'A');
    }
}
2.
if (to_lower(s[left]) != to_lower(s[right])) {
    return false;
}
char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }

    return c;
}

## Note
isalnum
tolower
time O(n/2) still O(n)
**/