/*********************************************************************************
*     File Name           :     27ImplementStrStr.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-11 22:14]
*     Last Modified       :     [2015-07-11 22:20]
*     Description         :      
topic:Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack
**********************************************************************************/
#include <string>
using namespace std;
class Solution {
    public:
        int strStr(string haystack, string needle) {
            return haystack.find(needle);
        }

};
