/*********************************************************************************
*     File Name           :     30SubstringWithConcatenationofAllWords.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-14 20:20]
*     Last Modified       :     [2015-07-17 19:25]
*     Description         :      
topic:You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;
class Solution {
    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            if(words.empty())
                return vector<int>();
            unordered_map<string,int> ori_words;
            unordered_map<string,int> cur_words;
            vector<int> res;
            string sst;
            int sublen = words[0].size(),len = s.size(),i,j,subcount = words.size();
            for (i = 0; i < subcount; ++i) {
                ++ori_words[words[i]];
            }
            for (i = 0; i < len-sublen*subcount+1; ++i) {
                cur_words.clear();
                for (j = 0; j < subcount; ++j) {
                    sst = s.substr(i+j*sublen,sublen);
                    if(ori_words.find(sst) == ori_words.end())
                        break;
                    cout <<"j" << j << " "<<  sst << ++cur_words[sst]  << endl;;
                    if(cur_words[sst]>ori_words[sst])
                        break;
                }
                if(j == subcount)
                {
                    res.push_back(i);
                    cout << "res:" << i << endl;
                }
            }
            return std::move(res);
        }
};
int main(int argc, char *argv[])
{
    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};
    Solution so;
    so.findSubstring(s,words);
    return 0;
}
