/*********************************************************************************
*     File Name           :     13InergerToRoman.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-06 15:16]
*     Last Modified       :     [2015-07-06 16:18]
*     Description         :      
topic:Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
**********************************************************************************/
#include <string>
#include <iostream>

using namespace std;
class Solution {
    public:
        string intToRoman(int num) {
            string roman;
            if(num>=1000)
            {
                string romanM(num/1000,'M');
                roman += romanM;
                num = num - num/1000 * 1000;
            }
            if(num >= 900)
            {
                roman += "CM";
                num = num - num/900 * 900;
            }
            if(num>=500)
            {
                string romanD(num/500,'D');jj
                roman += romanD;
                num = num - num/500 * 500;
            } 
            if(num >= 400)
            {
                roman += "CD";
                num = num - num/400 *400;
            }
            if(num>=100)
            {
                string romanC(num/100,'C');
                roman += romanC;
                num = num - num/100 * 100;
            }
            if(num >= 90)
            {
                roman += "XC";
                num = num - num/90 * 90;
            }
            if(num >= 50)
            {
                roman += "L";
                num = num - num/50 *50;
            }
            if(num >= 40)
            {
                roman += "XL";
                num = num - num/40 *40;
            }
            if(num >= 10)
            {
                string romanX(num/10,'X');
                roman += romanX;
                num = num - num/10 * 10;
            }
            if(num == 9)
            {
                roman += "IX";
                num = num - 9;
                return roman;
            }
            if(num >= 5)
            {
                roman += "V";
                num = num -  5;
            }
            if(num == 4)
            {
                roman += "IV";
                return roman;
            }
            if(num >= 1)
            {
                string romanI(num,'I');
                roman += romanI;
            }
            return roman;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.intToRoman(4) << endl;
    return 0;
}
