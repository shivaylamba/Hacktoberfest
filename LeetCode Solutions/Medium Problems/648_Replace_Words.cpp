/*
648. Replace Words
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
Return the sentence after the replacement.
Example 1:
Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:
Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
Constraints:
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
*/
class trie {
public:
    bool terminal;
    trie* next[26];
    trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};
class Solution {
    trie* base = new trie();

    void insert(string word) {
        int len = word.size();
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            if (!iter->next[word[i] - 97]) {
                iter->next[word[i] - 97] = new trie();
            }
            iter = iter->next[word[i] - 97];
        }
        iter->terminal = true;
    }
    string search(string &word) {
        int len = word.size();
        string cu;
        trie* iter = base;
        for (int i = 0; i < len; i++) {
            if (!iter->next[word[i] - 97]) {
                if (iter->terminal) return cu;
                return word;
            }
            cu += word[i];
            iter = iter->next[word[i] - 97];
            if (iter->terminal) return cu;
        }
        return cu;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        string ret, t;
        for (string i: dictionary) insert(i);
        for (char i: sentence) {
            if (i == ' ') {
                ret += search(t);
                ret += ' ';
                t.clear();
            } else {
                t += i;
            }
        }
        ret += search(t);
        return ret;
    }
};