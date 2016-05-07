/*********************************************************************************
*     File Name           :     17LetterCombinationsOfAPhoneNumber.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-08 10:20]
*     Last Modified       :     [2015-07-08 11:28]
*     Description         :      
topic:Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
**********************************************************************************/
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution {
    public:
        vector<string> letterCombinations(string digits){
            if(digits.empty())
                return vector<string>();
            map<char,string> dtol = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
            vector<string> vstr = {""},resul;
            size_t len = digits.size();
            size_t i,j,k;
            string prestr;
            for (i = 0; i < len; ++i) {
                prestr = dtol[digits[i]];
                for (k = 0;  k< vstr.size(); ++k) {
                    for (j = 0; j < prestr.size(); ++j) {
                        resul.push_back(vstr[k]+prestr.substr(j,1));
                    }
                }
                vstr = resul;
                resul.clear();
            }
            return vstr;
        }
};
int main(int argc, char *argv[])
{
    string num = "234";
    Solution so;
    vector<string> vs = so.letterCombinations(num);
    for(auto e:vs)
        cout << e << " ";
    cout << endl;
    return 0;
}

