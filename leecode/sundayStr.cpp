/*********************************************************************************
*     File Name           :     sundayStr.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-13 19:44]
*     Last Modified       :     [2015-07-13 20:43]
*     Description         :      
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;
class Solusion{
    public:
    int strStr(string haystack, string needle) {
        int i,j=i=needle.length()-1,len = haystack.size(),sublen = needle.size(),index;
        while(j < len)
        {
            //cout << j << endl;
            i = sublen - 1;
            while(i>=0)
            {
                if(haystack[j] != needle[i])
                    break;
                else
                    --i,--j;
            }
            if(i==-1)
                return j+1;
            index = haschar(needle,haystack[j+sublen-i]);
            if(index >= 0)
            {
                j = j+sublen-i+sublen-index-1;
            }
            else
            {
                j=j+sublen-i+sublen;
            }
        }
        return -1;
    }
    int haschar(string needle,char c)
    {
        int i = needle.size()-1;
        for (; i >= 0; --i) {
            if((needle[i]!=c))
                continue;
            else
                return i;
        }
        return -1;
    }
};
int main(int argc, char *argv[])
{
    Solusion so;
    string hay = "abcdbbcd",nee = "cdbbcd";
    cout << so.strStr(hay,nee) << endl;
    return 0;
}
