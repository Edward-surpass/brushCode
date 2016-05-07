/*********************************************************************************
*     File Name           :     5LongestPalindromicSubstring.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-02 10:41]
*     Last Modified       :     [2015-07-03 10:48]
*     Description         :      
topic:Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
**********************************************************************************/

#include <string>
#include <iostream>

using namespace std;
class Solution {
    public:
        string longestPalindromeMancher(string s) {//O(n^2)
            if(s.empty())
            {
                return string("");
            }
            string buf(2*s.size()+1,'#');
            int i,j,length = buf.size(),id=0;
            int p[length];
            p[0]=1;
            for (i = 1,j=0; i < length; ++j) {
                buf[i]=s[j];
                i+=2;
            }
            for (i = 1; i < length; ++i) {
                if(id+p[id]-1 <= i)
                    p[i]=1;
                else
                {
                    p[i] = p[id+id-i]<id+p[id]-i?p[id+id-i]:id+p[id]-i;
                }
                    while((i+p[i]<length && i-p[i]>=0)&& buf[i+p[i]] == buf[i-p[i]])
                        ++p[i];
                if(p[i]+i>p[id]+id)
                    id=i;
            }
            for (i = 0; i < length; ++i) {
                id=p[id]>p[i]?id:i;
            }
            return s.substr((id-p[id]+1)/2,p[id]-1);
        }
        string longestPalindrome(string s) {//O(n^2)
            if(s.empty())
                return string("");
            int be=0,en=s.size()-1;
            int maxlen=1;
            string maxstring=s;
            int i,lj,rj,len;
            for (i = 0; i < en; ++i) {
                len=0;
                if(s[i]==s[i+1])
                {
                    ++len;
                    for (lj = i-1,rj=i+2; lj >=be && rj <= en ; --lj,++rj) {
                        if(s[lj] == s[rj])
                        {
                            ++len;
                            //cout << lj << " " << s[lj] << rj << " " << s[rj] << endl;
                        }
                        else
                            break;
                    }
                    if(2*len > maxlen)
                    {
                        maxlen=2*len;
                        maxstring = s.substr(++lj,len+len);
                        //cout << i << " " << maxstring << endl;
                    }
                }
                len=0;
                for (lj = i-1,rj=i+1; lj >=be && rj <= en ; --lj,++rj) {
                    if(s[lj]==s[rj])
                    {
                        ++len;
                        //cout << lj << " " << s[lj] << rj << " " << s[rj] << endl;
                    }
                    else
                        break;
                }
                if(2*len +1 >maxlen)
                {
                    maxlen=len*2+1;
                    maxstring = s.substr(++lj,len+len+1);
                    //cout << i << " lj: "<< lj << "len:"<< len<< maxstring << endl;
                }
            }
            return maxstring;
        }
        string longestPalindromeDP(string s) {//O(n^3)
            if(s.empty())
                return string("");
            bool table[1000][1000] = {false};
            int maxlen=1;
            int longestbegin=0,i,n=s.size(),len;
            for (i = 0; i < n-1; ++i) {
                table[i][i]=true;
                if(s[i] == s[i+1])
                {
                    table[i][i+1]=true;
                    maxlen=2;
                    longestbegin=i;
                }
            }
            table[n-1][n-1]=true;
            for (len = 3; len <=n ; ++len) {
                for (i = 0; i < n-len+1; ++i) {
                    int j=i+len-1;
                    if(s[i]==s[j]&&table[i+1][j-1]==true)
                    {
                        table[i][j]=true;
                        longestbegin = i;
                        maxlen=len;
                    }
                }
            }
            return s.substr(longestbegin,maxlen);
        }

};
int main(int argc, char *argv[])
{
    string s = "aaaabccba";
    Solution so;
    cout << so.longestPalindromeMancher(s) << endl;
    return 0;
}
