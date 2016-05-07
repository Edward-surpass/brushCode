/*********************************************************************************
*     File Name           :     22GenerateParentheses.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-11 09:53]
*     Last Modified       :     [2015-07-11 11:09]
*     Description         :      
topic:Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
**********************************************************************************/
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            if(n<=0)
                return vector<string> ();
            vector<string> lasts,nows;
            vector<pair<int,int>> lastindex,nowindex;
            n = n+n;
            size_t i,j;
            for (i = 0; i < n; ++i) {
                if(lasts.empty())
                {
                    lasts.push_back("(");
                    lastindex.push_back({n/2-1,n/2});
                }
                else{
                    for (j = 0; j < lasts.size(); ++j) {
                        if(lastindex[j].second > 0 && lastindex[j].first<lastindex[j].second)
                        {
                            nows.push_back(lasts[j]+")");
                            nowindex.push_back({lastindex[j].first,lastindex[j].second-1});
                        }
                        if(lastindex[j].first > 0)
                        {
                            nows.push_back(lasts[j]+"(");
                            nowindex.push_back({lastindex[j].first-1,lastindex[j].second});
                        }
                    }
                    lasts = nows;
                    lastindex = nowindex;
                    nows.clear();
                    nowindex.clear();
                }
                //for (j = 0; j < lasts.size(); ++j) {
                //    cout << i << ":" << lasts[j] << endl;//"\t" << lastindex[j]<< endl;
                //}
            }
            return lasts;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    so.generateParenthesis(2);
    return 0;
}
