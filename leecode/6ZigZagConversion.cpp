/*********************************************************************************
*     File Name           :     6ZigZagConversion.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-04 14:55]
*     Last Modified       :     [2015-07-04 16:33]
*     Description         :      
topic:The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**********************************************************************************/
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        string convert(string s, int numRows) {
            if(s.empty())
                return string("");
            if(numRows == 1)
                return s;
            int i,j,k=0,idex;
            int len = s.size();
            string re(len,'s');
            int numCols = len/(numRows+numRows-2);
            if(len%(numRows+numRows-2) != 0)
                ++numCols;
            bool si = true;
            for (i = 0; i < numRows; ++i) {
                if(i==0 || i == numRows-1)
                    si = true;
                else
                    si=false;
                for (j = 0; j < numCols; ++j) {
                    if(si==true)
                    {
                        re[k++] = s[j*(numRows+numRows-2)+i];
                        if(k==len)
                            return re;
                    }
                    else{
                        idex = j*(numRows+numRows-2)+i;
                        if(idex < len)
                            re[k++] = s[j*(numRows+numRows-2)+i];
                        if(k==len)
                            return re;
                        idex = j*(numRows+numRows-2)+numRows+numRows-2-i;
                        if(idex < len)
                            re[k++] = s[j*(numRows+numRows-2)+numRows+numRows-2-i];
                        if(k==len)
                            return re;
                    }
                    //cout << re << endl;
                }
            }
            return re;
        }

};
int main(int argc, char *argv[])
{
    string str ="ABCDE"; 
    Solution so;
    cout << so.convert(str,3) << endl;
    return 0;
}
