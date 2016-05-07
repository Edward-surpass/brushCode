/*********************************************************************************
*     File Name           :     66PlusOne.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-09-27 21:32]
*     Last Modified       :     [2015-09-28 08:07]
*     Description         :     Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
**********************************************************************************/
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int i = digits.size()-1;
            vector<int> res(digits.size());
            int a = 1;
            for (;  i >= 0; --i) {
                res[i] = digits[i] + a;
                if(res[i] == 10)
                {
                    a = 1;
                    res[i] = 0;
                }
                else 
                {
                    a = 0;
                }
            }
            if(a == 1)
            {
                res.insert(res.begin(),1);
            }
            return std::move(res);
                
        }

};

