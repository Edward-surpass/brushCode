/*********************************************************************************
*     File Name           :     daffodil.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-09-28 16:21]
*     Last Modified       :     [2015-09-28 16:34]
*     Description         :      
**********************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char *argv[])
{
    string line;
    int m,n,i,key,res,temp;
    bool hasVal;
    while(getline(cin,line))
    {
        istringstream iss(line);
        iss >> m >> n;
        hasVal = false;
        for (i = m; i <= n; ++i) {
            key = i;
            res = 0;
            while(key)
            {
                temp = key % 10;
                res += temp * temp * temp;
                key /= 10;
            }
            if(res == i)
            {
                cout << i << " ";
                hasVal = true;
            }
        }
        if(!hasVal)
            cout << "no" << endl;
        else
            cout << endl;
    }
    return 0;
}

