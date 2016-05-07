/*********************************************************************************
*     File Name           :     71SimplifyPath.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-10-04 21:27]
*     Last Modified       :     [2015-10-04 22:08]
*     Description         :     Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
**********************************************************************************/
#include <string>
#include <stack>
#include <iostream>

using namespace std;


class Solution {
    public:
        string simplifyPath(string path) {
            stack<string> res;
            len = path.size();
            string temp;
            int i;
            if(len < 2)
                return path;
            for (i = 1; i < len; ++i) {
                while(path[i] != '/' && i < len)
                {
                    temp.push_back(path[i]);
                    ++i;
                }
                if(temp == ".")
                {
                    temp.clear();
                    continue;
                }
                else if(temp == "..")
                {
                    if(!res.empty())
                        res.pop();
                }
                else if(temp.empty())
                {
                    temp.clear();
                    continue;
                }
                else
                {
                    res.push("/" + temp);
                }
                temp.clear();
            }
            if(res.empty())
                return "/";
            temp.clear();
            while(!res.empty())
            {
                temp = res.top() + temp;
                res.pop();
            }
            return temp;
        }
    private:
        int len;

};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.simplifyPath("/home/foo/./bar/") << endl;
    return 0;
}
