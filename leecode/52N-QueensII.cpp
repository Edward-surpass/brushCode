/********************************************************************************* *     File Name           :     51N-Queens.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-27 16:46]
*     Last Modified       :     [2015-07-27 19:35]
*     Description         :     Follow up for N-Queens problem.

 Now, instead outputting board configurations, return the total number of distinct solutions.
  **********************************************************************************/
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;
class Solution {
    public:
        int totalNQueens(int n) {
            int res=0;
            vector<string> interRes(n,string(n,'.'));
            set<int> sx,sy;
            for (int i = 0; i < n; ++i) {
                sx.insert(i);
                sy.insert(i);
            }
            interQueens(res,interRes,sx,sy,n);
            return res;
        }
        bool interQueens(int &res,vector<string> &interRes,set<int> sx, set<int> sy,int n)
        {
            if(sx.empty() && sy.empty())
                return true;
            int x=*sx.begin(),y;
            int bigx = *(--sx.end()),bigy;
            for (;  x<=bigx; ++x) {
                y = *sy.begin();
                bigy = *(--sy.end());
                for (; y <=bigy; ++y) {
                    if(interRes[x][y] == '.')
                    {
                        if(isinsert(interRes,x,y,sx,sy,n))
                        {
                            interRes[x][y]='Q';
                            sx.erase(x);
                            sy.erase(y);
                            if( interQueens(res,interRes,sx,sy,n))
                            {
                                ++res;
                            }
                            interRes[x][y]='.';
                            sx.insert(x);
                            sy.insert(y);
                        }
                    }
                }
                return false;
            }
            return false;
        }
        bool isinsert(vector<string> &interRes,int i,int j,set<int> &sx,set<int> &sy,int n)
        {
            int x ,y ;
            for (x = i-1,y = j-1; x>=0 && y>=0; --x,--y){
                if(interRes[x][y] == 'Q')
                    return false;
            }
            for (x = i+1,y = j+1; x<n && y<n; ++x,++y){
                if(interRes[x][y] == 'Q')
                    return false;
            }
            for (x = i+1,y = j-1; x<n && y>=0; ++x,--y){
                if(interRes[x][y] == 'Q')
                    return false;
            }
            for (x = i-1,y = j+1; x>=0 && y<n; --x,++y){
                if(interRes[x][y] == 'Q')
                    return false;
            }
            if(sx.find(i)!=sx.end() && sy.find(j) != sy.end())
                return true;
            return false;
        }
};
int main(int argc, char *argv[])
{
    Solution so;
    cout << so.totalNQueens(1) << endl;;
    return 0;
}
