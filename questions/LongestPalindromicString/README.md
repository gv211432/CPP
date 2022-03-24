<!-- ┏━┓╻  ╻     ┏━┓┏┓ ┏━┓╻ ╻╺┳╸
     ┣━┫┃  ┃     ┣━┫┣┻┓┃ ┃┃ ┃ ┃
     ╹ ╹┗━╸┗━╸   ╹ ╹┗━┛┗━┛┗━┛ ╹
     ╻  ┏━┓┏┓╻┏━╸┏━╸┏━┓╺┳╸┏━┓┏━┓╻  ╻┏┓╻╺┳┓┏━┓┏━┓┏┳┓╻┏━╸┏━┓╺┳╸┏━┓╻┏┓╻┏━╸
     ┃  ┃ ┃┃┗┫┃╺┓┣╸ ┗━┓ ┃ ┣━┛┣━┫┃  ┃┃┗┫ ┃┃┣┳┛┃ ┃┃┃┃┃┃  ┗━┓ ┃ ┣┳┛┃┃┗┫┃╺┓
     ┗━╸┗━┛╹ ╹┗━┛┗━╸┗━┛ ╹ ╹  ╹ ╹┗━╸╹╹ ╹╺┻┛╹┗╸┗━┛╹ ╹╹┗━╸┗━┛ ╹ ╹┗╸╹╹ ╹┗━┛ -->

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.

<!-- ===================================================================== -->

Summary

This article is for intermediate readers. It introduces the following ideas: Palindrome, Dynamic Programming and String Manipulation. Make sure you understand what a palindrome means. A palindrome is a string which reads the same in both directions. For example, SSS = "aba" is a palindrome, SSS = "abc" is not.
Solution

<!-- ===================================================================== -->

Approach 1: Longest Common Substring

Common mistake

Some people will be tempted to come up with a quick solution, which is unfortunately flawed (however can be corrected easily):

    Reverse SSS and become S′S'S′. Find the longest common substring between SSS and S′S'S′, which must also be the longest palindromic substring.

This seemed to work, let’s see some examples below.

For example, SSS = "caba", S′S'S′ = "abac".

The longest common substring between SSS and S′S'S′ is "aba", which is the answer.

Let’s try another example: SSS = "abacdfgdcaba", S′S'S′ = "abacdgfdcaba".

The longest common substring between SSS and S′S'S′ is "abacd". Clearly, this is not a valid palindrome.

Algorithm

We could see that the longest common substring method fails when there exists a reversed copy of a non-palindromic substring in some other part of SSS. To rectify this, each time we find a longest common substring candidate, we check if the substring’s indices are the same as the reversed substring’s original indices. If it is, then we attempt to update the longest palindrome found so far; if not, we skip this and find the next candidate.

This gives us an O(n2)O(n^2)O(n2) Dynamic Programming solution which uses O(n2)O(n^2)O(n2) space (could be improved to use O(n)O(n)O(n) space). Please read more about Longest Common Substring here.

<!-- ===================================================================== -->

Approach 2: Brute Force

The obvious brute force solution is to pick all possible starting and ending positions for a substring, and verify if it is a palindrome.

Complexity Analysis

    Time complexity : O(n3)O(n^3)O(n3). Assume that nnn is the length of the input string, there are a total of (n2)=n(n−1)2\binom{n}{2} = \frac{n(n-1)}{2}(2n​)=2n(n−1)​ such substrings (excluding the trivial solution where a character itself is a palindrome). Since verifying each substring takes O(n)O(n)O(n) time, the run time complexity is O(n3)O(n^3)O(n3).

    Space complexity : O(1)O(1)O(1).

<!-- ===================================================================== -->

Approach 3: Dynamic Programming

To improve over the brute force solution, we first observe how we can avoid unnecessary re-computation while validating palindromes. Consider the case "ababa". If we already knew that "bab" is a palindrome, it is obvious that "ababa" must be a palindrome since the two left and right end letters are the same.

We define P(i,j)P(i,j)P(i,j) as following:

P(i,j)={true,if the substring Si…Sj is a palindromefalse,otherwise. P(i,j) = \begin{cases} \text{true,} &\quad\text{if the substring } S_i \dots S_j \text{ is a palindrome}\\ \text{false,} &\quad\text{otherwise.} \end{cases} P(i,j)={true,false,​if the substring Si​…Sj​ is a palindromeotherwise.​

Therefore,

P(i,j)=(P(i+1,j−1) and Si==Sj) P(i, j) = ( P(i+1, j-1) \text{ and } S_i == S_j ) P(i,j)=(P(i+1,j−1) and Si​==Sj​)

The base cases are:

P(i,i)=true P(i, i) = true P(i,i)=true

P(i,i+1)=(Si==Si+1) P(i, i+1) = ( S*i == S*{i+1} ) P(i,i+1)=(Si​==Si+1​)

This yields a straight forward DP solution, which we first initialize the one and two letters palindromes, and work our way up finding all three letters palindromes, and so on...

Complexity Analysis

    Time complexity : O(n2)O(n^2)O(n2). This gives us a runtime complexity of O(n2)O(n^2)O(n2).

    Space complexity : O(n2)O(n^2)O(n2). It uses O(n2)O(n^2)O(n2) space to store the table.

Additional Exercise

Could you improve the above space complexity further and how?

<!-- ===================================================================== -->

Approach 4: Expand Around Center

In fact, we could solve it in O(n2)O(n^2)O(n2) time using only constant space.

We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2n−12n - 12n−1 such centers.

You might be asking why there are 2n−12n - 12n−1 but not nnn centers? The reason is the center of a palindrome can be in between two letters. Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.

JAVA Implementation

<!-- ================================================================ -->
<!--
public String longestPalindrome(String s) {
    if (s == null || s.length() < 1) return "";
    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = Math.max(len1, len2);
        if (len > end - start) {
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substring(start, end + 1);
}

private int expandAroundCenter(String s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
        L--;
        R++;
    }
    return R - L - 1;
}
 -->
<!-- ================================================================ -->

Complexity Analysis

    Time complexity : O(n2)O(n^2)O(n2). Since expanding a palindrome around its center could take O(n)O(n)O(n) time, the overall complexity is O(n2)O(n^2)O(n2).

    Space complexity : O(1)O(1)O(1).

<!-- ===================================================================== -->

Approach 5: Manacher's Algorithm

There is even an O(n)O(n)O(n) algorithm called Manacher's algorithm, explained here in detail. However, it is a non-trivial algorithm, and no one expects you to come up with this algorithm in a 45 minutes coding session. But, please go ahead and understand it, I promise it will be a lot of fun.
