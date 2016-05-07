/*********************************************************************************
*     File Name           :     72EditDistance.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-10-05 10:48]
*     Last Modified       :     [2015-10-07 15:55]
*     Description         :     Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
**********************************************************************************/
#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
    public:
        int minDistance(string word1, string word2) {
            len1 = word1.size();
            len2 = word2.size();
            if(len1 == 0 || len2 == 0)
            {
                if(len1 == 0)
                    return len2;
                if(len2 == 0)
                    return len1;
            }
            vector<vector<int>> d(len1+1,vector<int>(len2+1,0));
            int i,j;
            int l,t,r;
            for (i = 0; i < len1+1; ++i) {
                d[i][0] = i;
            }
            for (i = 0; i < len2+1; ++i) {
                d[0][i] = i;
            }
            for (i = 1; i < len1+1; ++i) {
                for (j = 1; j < len2+1; ++j) {
                    if(word1[i-1] == word2[j-1])
                        d[i][j] = d[i-1][j-1];
                    else
                    {
                        l = d[i-1][j-1];
                        t = d[i-1][j];
                        r = d[i][j-1];
                        l = l < t ? l : t;
                        d[i][j] = (l < r ? l : r) + 1;
                    }
                }
                
            }
            return d[len1][len2];
        }
    private:
        int len1;
        int len2;
};

