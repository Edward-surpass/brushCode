/*********************************************************************************
*     File Name           :     14RomanToInteger.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-06 16:19]
*     Last Modified       :     [2015-07-06 17:28]
*     Description         :      
**********************************************************************************/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
class Solution {
    public:
        int romanToInt(string s) {
            map<string,int> rtoi = {{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
            vector<string> rom {"CM","M","CD","D","XC","C","XL","L","IX","X","IV","V","I"};
            int num=0;
            for (size_t i = 0; i < rom.size(); ++i) {
                while(1){
                    size_t index = s.find(rom[i]);
                    if(index != s.npos)
                    {
                        num += rtoi[rom[i]];
                        s.erase(index,rom[i].size());
                    }
                    else 
                        break;
                }
            }
            return num;
        }

};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.romanToInt("MMCM") << endl;
    return 0;
}
