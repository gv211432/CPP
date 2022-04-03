<!-- ┏━┓╻  ╻     ┏━┓┏┓ ┏━┓╻ ╻╺┳╸   ┏━┓┏━╸┏━╸┏━╸╻ ╻┏┳┓┏━┓┏━╸╻ ╻╻┏┓╻┏━╸
     ┣━┫┃  ┃     ┣━┫┣┻┓┃ ┃┃ ┃ ┃    ┣┳┛┣╸ ┃╺┓┣╸ ┏╋┛┃┃┃┣━┫┃  ┣━┫┃┃┗┫┃╺┓
     ╹ ╹┗━╸┗━╸   ╹ ╹┗━┛┗━┛┗━┛ ╹    ╹┗╸┗━╸┗━┛┗━╸╹ ╹╹ ╹╹ ╹┗━╸╹ ╹╹╹ ╹┗━┛ -->

10. Regular Expression Matching
    Hard

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '\*' where:

    '.' Matches any single character.​​​​
    '*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input: s = "ab", p = "._"
Output: true
Explanation: "._" means "zero or more (\*) of any character (.)".

Constraints:

    1 <= s.length <= 20
    1 <= p.length <= 30
    s contains only lowercase English letters.
    p contains only lowercase English letters, '.', and '*'.
    It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

<!-- ===================================================================== -->

Approach 1: Recursion

Intuition

If there were no Kleene stars (the \* wildcard character for regular expressions), the problem would be easier - we simply check from left to right if each character of the text matches the pattern.

When a star is present, we may need to check many different suffixes of the text and see if they match the rest of the pattern. A recursive solution is a straightforward way to represent this relationship.

Algorithm

Without a Kleene star, our solution would look like this:

Python:

<!-- ================================================================ -->

<!--
def match(text, pattern):
    if not pattern: return not text
    first_match = bool(text) and pattern[0] in {text[0], '.'}
    return first_match and match(text[1:], pattern[1:])
 -->

<!-- ================================================================ -->

If a star is present in the pattern, it will be in the second position pattern[1]\text{pattern[1]}pattern[1]. Then, we may ignore this part of the pattern, or delete a matching character in the text. If we have a match on the remaining strings after any of these operations, then the initial inputs matched.

JAVA:

<!-- ================================================================ -->

<!-- class Solution {
    public boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) return text.isEmpty();
        boolean first_match = (!text.isEmpty() &&
                               (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.'));

        if (pattern.length() >= 2 && pattern.charAt(1) == '*'){
            return (isMatch(text, pattern.substring(2)) ||
                    (first_match && isMatch(text.substring(1), pattern)));
        } else {
            return first_match && isMatch(text.substring(1), pattern.substring(1));
        }
    }
} -->

<!-- ================================================================ -->

Complexity Analysis

    Time Complexity: Let T,PT, PT,P be the lengths of the text and the pattern respectively. In the worst case, a call to match(text[i:], pattern[2j:]) will be made (i+ji)\binom{i+j}{i}(ii+j​) times, and strings of the order O(T−i)O(T - i)O(T−i) and O(P−2∗j)O(P - 2*j)O(P−2∗j) will be made. Thus, the complexity has the order ∑i=0T∑j=0P/2(i+ji)O(T+P−i−2j)\sum_{i = 0}^T \sum_{j = 0}^{P/2} \binom{i+j}{i} O(T+P-i-2j)∑i=0T​∑j=0P/2​(ii+j​)O(T+P−i−2j). With some effort outside the scope of this article, we can show this is bounded by O((T+P)2T+P2)O\big((T+P)2^{T + \frac{P}{2}}\big)O((T+P)2T+2P​).

    Space Complexity: For every call to match, we will create those strings as described above, possibly creating duplicates. If memory is not freed, this will also take a total of O((T+P)2T+P2)O\big((T+P)2^{T + \frac{P}{2}}\big)O((T+P)2T+2P​) space, even though there are only order O(T2+P2)O(T^2 + P^2)O(T2+P2) unique suffixes of PPP and TTT that are actually required.

<!-- ===================================================================== -->

Approach 2: Dynamic Programming

Intuition

As the problem has an optimal substructure, it is natural to cache intermediate results. We ask the question dp(i, j)\text{dp(i, j)}dp(i, j): does text[i:]\text{text[i:]}text[i:] and pattern[j:]\text{pattern[j:]}pattern[j:] match? We can describe our answer in terms of answers to questions involving smaller strings.

Algorithm

We proceed with the same recursion as in Approach 1, except because calls will only ever be made to match(text[i:], pattern[j:]), we use dp(i, j)\text{dp(i, j)}dp(i, j) to handle those calls instead, saving us expensive string-building operations and allowing us to cache the intermediate results.

Top-Down Variation :JAVA

<!-- ================================================================ -->
<!--
enum Result {
    TRUE, FALSE
}

class Solution {
    Result[][] memo;

    public boolean isMatch(String text, String pattern) {
        memo = new Result[text.length() + 1][pattern.length() + 1];
        return dp(0, 0, text, pattern);
    }

    public boolean dp(int i, int j, String text, String pattern) {
        if (memo[i][j] != null) {
            return memo[i][j] == Result.TRUE;
        }
        boolean ans;
        if (j == pattern.length()){
            ans = i == text.length();
        } else{
            boolean first_match = (i < text.length() &&
                                   (pattern.charAt(j) == text.charAt(i) ||
                                    pattern.charAt(j) == '.'));

            if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                ans = (dp(i, j+2, text, pattern) ||
                       first_match && dp(i+1, j, text, pattern));
            } else {
                ans = first_match && dp(i+1, j+1, text, pattern);
            }
        }
        memo[i][j] = ans ? Result.TRUE : Result.FALSE;
        return ans;
    }
}
-->

<!-- ================================================================ -->

Bottom-Up Variation: JAVA

<!-- ================================================================ -->
<!--
class Solution {
    public boolean isMatch(String text, String pattern) {
        boolean[][] dp = new boolean[text.length() + 1][pattern.length() + 1];
        dp[text.length()][pattern.length()] = true;

        for (int i = text.length(); i >= 0; i--){
            for (int j = pattern.length() - 1; j >= 0; j--){
                boolean first_match = (i < text.length() &&
                                       (pattern.charAt(j) == text.charAt(i) ||
                                        pattern.charAt(j) == '.'));
                if (j + 1 < pattern.length() && pattern.charAt(j+1) == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
}
 -->
<!-- ================================================================ -->

Complexity Analysis

    Time Complexity: Let T,PT, PT,P be the lengths of the text and the pattern respectively. The work for every call to dp(i, j) for i=0,...,Ti=0, ... ,Ti=0,...,T; j=0,...,Pj=0, ... ,Pj=0,...,P is done once, and it is O(1)O(1)O(1) work. Hence, the time complexity is O(TP)O(TP)O(TP).

    Space Complexity: The only memory we use is the O(TP)O(TP)O(TP) boolean entries in our cache. Hence, the space complexity is O(TP)O(TP)O(TP).
