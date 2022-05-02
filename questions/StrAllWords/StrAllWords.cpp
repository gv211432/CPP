// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

// ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻╺┓
// ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫ ┃
// ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹╺┻╸
// self made not efficient but works for small inputes
class Solution
{
    string s = "";
    vector<string> word_private;
    size_t wordLen = 0;
    bool isPrint = false;

    void ToPrint(string str, string app = "")
    {
        if (isPrint)
        {
            std::cout << str << app;
        }
    }

    // this finds all the occurance of the given string
    vector<int> findAll(string w, string s)
    {
        vector<int> ans = {};
        size_t pos = s.find(w);
        // try to find the string and starts searching after word size
        while (pos != std::string::npos)
            ans.push_back(pos), s.find(w, pos + w.size()), pos = s.find(w, pos + wordLen);
        return ans;
    }

    // this generates the factorial of the given number
    int Factorial(unsigned int n)
    {
        unsigned int res = 1;
        while (n > 1)
            res *= n, n -= 1;
        return res;
    }

    // generates all permutations
    void Permute(size_t k = 0)
    {
        for (size_t i = k; i < word_private.size(); i++)
        {
            swap(word_private[i], word_private[k]);
            Permute(k + 1);
            swap(word_private[k], word_private[i]);
        }
        if (k == word_private.size() - 1)
        {
            string tempWord = "";
            ToPrint("[ ");
            for (auto w : word_private)
            {
                // std::cout << w << ", ";
                ToPrint(w, ", ");
                tempWord += w;
            }
            // std::cout << "]" << std::endl;
            ToPrint("]", "\n");
            // std::cout << tempWord << std::endl;
            ToPrint(tempWord, "\n");
            for (auto n : findAll(tempWord, s))
            {
                // std::cout << "Found at : " << n << std::endl;

                bool present = false;
                for (auto e : answer2)
                    if (e == n)
                        present = true;

                present ? ToPrint("Present : True", "\n")
                        : ToPrint("Present : False", "\n");

                if (!present)
                    answer1 = answer1 + to_string(n) + " ",
                    answer2.push_back(n);
            }
        }
    }

public:
    string answer1 = "";
    vector<int> answer2 = {};

    vector<int> findSubstring(string str, vector<string> &words)
    {
        wordLen = words[0].size();
        s = str, word_private = words;
        Permute();
        return answer2;
    }

    void setPrint(bool b)
    {
        isPrint = b;
    }
};

// ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻┏━┓
// ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫┏━┛
// ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹┗━╸

class Solution2
{
    map<string, int> word_count = {};
    int n = 0,              // string length
        k = 0,              // words array length
        word_len = 0,       // single word length
        substring_size = 0; // length of the substring to searched

    void sliding_window(int left, string &s, vector<int> &answer)
    {
        std::cout << "\033[35m"
                  << "================ left is : =============== "
                  << left << "\033[0m" << std::endl;

        std::cout << "Sliding window is called" << std::endl;
        map<string, int> word_found = {};
        int words_used = 0;
        bool excess_word = false;

        for (int right = left; right <= n - word_len; right += word_len)
        {
            std::cout << "Sliding window loop => iterations : "
                      << right << std::endl;
            string sub = s.substr(right, right + word_len);
            std::cout << "\033[31m" << sub << "\033[0m"
                      << " => ";
            if (word_count.count(sub)) // if word found
            {

                std::cout << "Word found" << std::endl;
                word_found.clear();
                words_used = 0;
                excess_word = false;
                left = right + word_len;
            }
            else // If we reached max window size or have an excess word
            {
                std::cout << "Word not found" << std::endl;

                while (((right - left) == substring_size) || excess_word)
                {
                    string left_most_word = s.substr(left, left + word_len);
                    left += word_len;
                    if (word_found.count(left_most_word))
                        (word_found.find(left_most_word)->second -= 1);

                    if (word_found.find(left_most_word)->second >=
                        word_count.find(left_most_word)->second)
                        excess_word = false; // This word was an excess word
                    else
                        words_used--; // Otherwise we actually needed it
                }

                // Keep track of how many times this word occurs in the window
                if (word_found.count(sub))
                    word_found.find(sub)->second += 1;
                else
                    word_found.emplace(make_pair(sub, 1));

                if (word_found.find(sub)->second <= word_count.find(sub)->second)
                    words_used++;
                else
                    excess_word = true; // Found too many instances already

                std::cout << "words_used : " << words_used
                          << " and k : " << k << " excess_word : "
                          << excess_word << std::endl;

                std::cout << "\033[33m"
                          << "left = " << left << "\033[0m" << std::endl;
                if ((words_used == k) && !excess_word)
                    answer.push_back(left), std::cout << "\033[32m"
                                                      << "Inserted!!"
                                                      << "\033[0m" << std::endl; // Found a valid substring
            }
        }
    }

public:
    vector<int> findSubstring(string &s, vector<string> &words)
    {
        n = s.size();
        k = words.size();
        word_len = words[0].size();
        substring_size = word_len * k;

        // std::cout << "word_len = " << word_len << std::endl;
        // word_count.count("omg") ? std::cout << "omg : " << word_count.find("omg")->second << std::endl : std::cout << "omg : 0" << std::endl;

        for (auto word : words)
            if (word_count.count(word))
                word_count.find(word)->second += 1;
            else
                word_count.emplace(make_pair(word, 1));
        // word_count.emplace(make_pair(word, (word_count.count(word) ? word_count.find(word)->second += 1 : 1)));

        for (auto w : word_count)
            std::cout << w.first << " = " << w.second << std::endl;

        vector<int> answer = {};
        for (int i = 0; i < word_len; i++)
            sliding_window(i, s, answer);

        return answer;
    }
};

// ┏━┓┏━┓╻  ╻ ╻╺┳╸╻┏━┓┏┓╻┏━┓
// ┗━┓┃ ┃┃  ┃ ┃ ┃ ┃┃ ┃┃┗┫╺━┫
// ┗━┛┗━┛┗━╸┗━┛ ╹ ╹┗━┛╹ ╹┗━┛

class Solution3
{
    map<string, int> word_count = {};
    int n = 0,              // string length
        k = 0,              // words array length
        word_len = 0,       // single word length
        substring_size = 0; // length of the substring to searched

    // string s = "";
    // vector<string> words;
    vector<int> answer = {};

    void sliding_window(int &left, string &s, vector<string> &words)
    {
        map<string, int> word_found = {};
        int word_used = 0;
        bool excess_word = false;

        for (int right = left; right <= n - word_len; right += word_len)
        {
            string sub = s.substr(right, right + word_len);
            if (word_count.count(sub))
            {
                word_found.clear();
                word_used = 0;
                excess_word = false;
                left = right + word_len;
            }
            else
            {
                while (right - left == substring_size or excess_word)
                {
                    string leftmost_word = s.substr(left, left + word_len);
                    left += word_len;
                    word_found.find(leftmost_word)->second--;

                    if (word_found.count(leftmost_word) &&
                        word_count.count(leftmost_word) &&
                        word_found.find(leftmost_word)->second ==
                            word_count.find(leftmost_word)->second)
                        excess_word = false;
                    else
                        word_used--;

                    word_found.find(sub)->second++;
                    if (word_found.count(sub) && word_found.find(sub)->second ==
                                                     word_count.find(sub)->second)
                        word_used++;
                    else
                        excess_word = true;

                    if (word_used == k and !excess_word)
                        answer.push_back(left);
                }
            }
        }
    }

public:
    vector<int> findSubstring(string &s, vector<string> &words_org)
    {
        n = s.size();
        k = words_org.size();
        word_len = words_org[0].size();
        substring_size = word_len * k;

        for (auto word : words_org)
            if (word_count.count(word))
                word_count.find(word)->second++;
            else
                word_count.emplace(make_pair(word, 1));

        for (int i = 0; i < word_len; i++)
            sliding_window(i, s, words_org);

        return answer;
    }
};

int main(int arg, char *argv[])
{
    string s = "barfoofoobarthefoobarman";
    vector<string> w = {"bar", "foo", "the"};
    Solution sol;
    // sol.setPrint(true);

    // vector<string> v = {"dhvf", "sind", "ffsl", "yekr", "zwzq", "kpeo", "cila",
    //                     "tfty", "modg", "ztjg", "ybty", "heqg", "cpwo", "gdcj",
    //                     "lnle", "sefg", "vimw", "bxcb"};
    // string s;
    // s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel ";

    // sol.findSubstring(s, v);

    // vector<string> w = {"a", "a"};
    // string s = "aaa";

    for (auto v : sol.findSubstring(s, w))
        std::cout
            << v << std::endl;

    // std::cout
    //     << sol.answer1 << std::endl;
    // std::cout << sol.Factorial(words.size()) << std::endl;

    return 0;
}