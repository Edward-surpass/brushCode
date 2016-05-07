/********************************************************************************* *     File Name           :     51N-Queens.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-27 16:46]
*     Last Modified       :     [2015-07-27 19:17]
*     Description         :     iThe n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:'
**********************************************************************************/
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;
class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>> res;
            vector<string> interRes(n,string(n,'.'));
            set<int> sx,sy;
            for (int i = 0; i < n; ++i) {
                sx.insert(i);
                sy.insert(i);
            }
            interQueens(res,interRes,sx,sy,n);
            return res;
        }
        bool interQueens(vector<vector<string>> &res,vector<string> &interRes,set<int> sx, set<int> sy,int n)
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
                                //for (size_t i = 0; i < interRes.size(); ++i) {
                                //    cout << interRes[i] << endl;
                                //}
                                //cout << "==============" << endl;
                                res.push_back(interRes);
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
    vector<vector<string>> res;
    res = so.solveNQueens(1);
    for (auto &i : res) {
        for (auto &j : i) {
            cout << j << endl;
        }
        cout << "====" << endl;
    }
    return 0;
}
