/*********************************************************************************
*     File Name           :     37SudokuSolver.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-19 12:45]
*     Last Modified       :     [2015-07-19 13:56]
*     Description         :     Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
**********************************************************************************/
#include <vector>
#include <set>
using namespace std;
class Solution {
    public:
        void solveSudoku(vector<vector<char>>& board) {
            insertsolveSudoku(board);
        }
        bool insertsolveSudoku(vector<vector<char>> &board)
        {
            int i,j,k;
            for (i = 0; i < 9; ++i) {
                for (j = 0; j < 9; ++j) {
                    if(board[i][j] == '.')
                    {
                        set<char> sc = validinsert(board,i,j);
                        if(sc.empty())
                            return false;
                        for (auto p = sc.begin(); p != sc.end(); ++p) {
                            board[i][j]=*p;
                            if(insertsolveSudoku(board))
                                return true;
                            board[i][j]='.';
                        }
                        return false;
                    }
                }
                
            }
            return true;
        }
        set<char> validinsert(vector<vector<char>> &board,int x,int y)
        {
            int i,j;
            set<char> sc = {'1','2','3','4','5','6','7','8','9'};
            for (i = 0; i < 9; ++i) {
                if(board[i][y] != '.')
                {
                    auto p = sc.find(board[i][y]);
                    if(p != sc.end())
                        sc.erase(p);
                }
            }
            for (j = 0; j < 9; ++j) {
                if(board[x][j] != '.')
                {
                    auto p = sc.find(board[x][j]);
                    if(p != sc.end())
                        sc.erase(p);
                }
            }
            for (i = (x/3)*3; i < (x/3+1)*3; ++i) {
                for (j = (y/3)*3; j < (y/3 +1)*3; ++j) {
                if(board[i][j] != '.')
                {
                    auto p = sc.find(board[i][j]);
                    if(p != sc.end())
                        sc.erase(p);
                }
                }
            }
            return sc;
        }
        bool isvalidsolveSudoku(vector<vector<char>> &board,int x,int y)
        {
            int i,j;
            for (i = 0; i < 9; ++i) {
                if(i!=x && board[i][y]==board[x][y])
                    return false;
            }
            for (j = 0; j < 9; ++j) {
                if(j!=y && board[x][j] == board[x][y])
                    return false;
            }
            for (i = (x/3)*3; i < (x/3+1)*3; ++i) {
                for (j = (y/3)*3; j < (y/3 +1)*3; ++j) {
                    if(i!=x&&j!=y && board[i][j] == board[x][y])
                        return false;
                }
                
            }
            return true;
        }

};
