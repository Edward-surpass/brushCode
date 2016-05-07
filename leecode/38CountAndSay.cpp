/*********************************************************************************
*     File Name           :     38CountAndSay.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-19 15:02]
*     Last Modified       :     [2015-07-19 15:42]
*     Description         :     The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
**********************************************************************************/
#include <string>
#include <map>
#include <iostream>

using namespace std;
class Solution {
    public:
        string countAndSay(int n) {
            int i,len,j,cnt;
            string news,lasts = "1";
            map<char,int> mci;
            map<char,int>::iterator p;
            for (i = 1; i < n; ++i) {
                len = lasts.size();
                for (j = 0; j <len; ++j) {
                    cnt = 0;
                    while(j+1<len && lasts[j] == lasts[j+1])
                    {
                        ++cnt;
                        ++j;
                    }
                    ++cnt;
                    news += to_string(cnt) + lasts[j];
                }
                lasts = news;
                news.clear();
            }
            return lasts;
        }
};

int main(int argc, char *argv[])
{
    Solution so;
    cout << so.countAndSay(4) << endl;
    return 0;
}
