/*********************************************************************************
*     File Name           :     arrtSum.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-09-28 16:35]
*     Last Modified       :     [2015-09-28 16:44]
*     Description         :      
**********************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{
    string line;
    double m,n,i,res;
    while(getline(cin,line))
    {
        istringstream iss(line);
        iss >> m >> n;
        res = 0;
        for (i = 0; i < n; ++i) {
            res += m;
            m = sqrt(m);
        }
        cout << setiosflags(ios::fixed);
        cout << setprecision(2) << res << endl;
    }

    return 0;
}

