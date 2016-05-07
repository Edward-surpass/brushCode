/*********************************************************************************
*     File Name           :     68TextJustification.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-10-04 09:23]
*     Last Modified       :     [2015-10-04 14:55]
*     Description         :     Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
      "example  of text",
         "justification.  "

]
**********************************************************************************/
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            int index=0;
            vector<string> res;
            if(maxWidth == 0)
                return words;
            VSLen = words.size();
            while(index < VSLen)
            {
                res.push_back(getLine(words,index,maxWidth));
            }
            return std::move(res);
        }
        string getLine(vector<string> &words, int &index,int maxWidth)
        {
            int len,i,totolLen,num,extrSpace,be,en;
            string strRes;
            for (i = index,num=0,totolLen=0; i < VSLen; ++i) {
                len = words[i].length() ;
                if(totolLen + len + num  > maxWidth )
                {
                    strRes.pop_back();
                    break;
                }
                else
                {
                    totolLen += len;
                }
                strRes += (words[i] + string(" "));
                ++num;
            }
            if(i == VSLen || num == 1)
            {
                index = i;
                if(i == VSLen)
                    strRes.pop_back();
                i = strRes.size();
                if(maxWidth-i > 0)
                    strRes.append(maxWidth-i,' ');
                return std::move(strRes);
            }
            extrSpace = maxWidth-totolLen;
            be = index;
            en = i -1;
            while(extrSpace)
            {
                if(be < en)
                {
                    words[be] +=  string(" ");
                    ++be;
                    --extrSpace;
                    //if(be < en && extrSpace)
                    //{
                    //    words[en] = string(" ") + words[en];
                    //    --en;
                    //    --extrSpace;
                    //}
                }
                else
                {
                    be = index;
                    //en = i-1;
                }
            }
            strRes.clear();
            for (be = index,en=i-1; be <= en; ++be) {
                strRes += words[be];
            }
            index = i;
            return std::move(strRes);
        }
    private:
        int VSLen;
};
int main(int argc, char *argv[])
{
    Solution so;
    vector<string> test{"This", "is", "an", "example", "of", "text", "justification."};
    //vector<string> test{"Listen","to","many,","speak","to","a","few."};
    //vector<string> test{"a"};
    so.fullJustify(test,16);
    return 0;
}
