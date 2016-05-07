/*********************************************************************************
*     File Name           :     43MultiplyStrings.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-22 10:13]
*     Last Modified       :     [2015-07-22 12:35]
*     Description         :     Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
**********************************************************************************/
#include <string>
#include <iostream>

using namespace std;
class Solution {
    public:
        string multiply(string num1, string num2) {
            string sinmulres,res;
            int muler,mulcand,car,mulres,len2 = num2.size(),len = num1.size();
            int i = num1.size()-1,j = num2.size()-1;
            for (i=len-1;i>=0 ;--i) {
                muler = num1[i]-'0';
                car = 0;
                sinmulres.clear();
                for (j=len2-1; j >= 0; --j) {
                    mulcand = num2[j]-'0';
                    mulres = muler * mulcand + car;
                    sinmulres =  char(mulres%10+'0')+sinmulres ;
                    car = mulres/10;
                }
                if(car>0)
                    sinmulres = char(car+'0') + sinmulres;
                sinmulres += string(num1.size()-1-i,'0');
                interplus(res,sinmulres);
            }
                auto p = res.find_first_not_of('0');
                if(p>0)
                {
                    if(p != string::npos)
                        res = res.substr(p,res.size()-p);
                    else
                        res = string("0");
                }
            return res;
        }
        void interplus(string &res,string &sinmulres)
        {
            int len1 = res.size(),len2 = sinmulres.size(),car = 0;
            int i = len1-1,j = len2-1,plusres,lfplus,riplus;
            string temp = res;
            res.clear();
            for (; i >=0 || j>=0; --i,--j) {
                if(i>=0)
                    lfplus = temp[i]-'0';
                else
                    lfplus = 0;
                if(j>=0)
                    riplus = sinmulres[j]-'0';
                else 
                    riplus = 0;
                plusres = lfplus + riplus + car;
                res = char(plusres%10 + '0') + res;
                car = plusres/10;
            }
            if(car > 0)
                res = char(car+'0') + res;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.multiply("0","999") << endl;
    return 0;
}
