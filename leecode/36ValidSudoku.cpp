/*********************************************************************************
*     File Name           :     36ValidSudoku.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-19 11:05]
*     Last Modified       :     [2015-07-19 12:35]
*     Description         :      
topic:Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
**********************************************************************************/
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;
class Solution {
    public:
        bool isValidSudoku(ve ctor<vector<char>>& board) {
            unordered_set<char> ud = {'1','2','3','4','5','6','7','8','9'};
            vector<unordered_set<char>> row_set(9,ud);
            vector<unordered_set<char>> col_set(9,ud);
            vector<unordered_set<char>> squar_set(9,ud);
            unordered_set<char>::iterator p;
            char c;
            size_t i,j;
            for (i = 0; i < 9;++i) {
                for (j = 0; j < 9; ++j) {
                    c = board[i][j];
                    if(c != '.')
                    {
                        cout << c << endl;
                        cout << i << endl;
                        cout << j << endl;
                        cout << (i/3)*3 + j/3 << endl;
                        cout << "=================" << endl;
                        p = row_set[i].find(c);
                        if(p!=row_set[i].end())
                            row_set[i].erase(p);
                        else
                            return false;
                        p = col_set[j].find(c);
                        if(p!=col_set[j].end())
                            col_set[j].erase(p);
                        else
                            return false;
                        p = squar_set[(i/3)*3+j/3].find(c);
                        if(p!=squar_set[(i/3)*3 + j/3].end())
                            squar_set[(i/3)*3 + j/3].erase(p);
                        else
                            return false;
                    }
                }
                
            }
            return true;
        }
};
int main(int argc, char *argv[])
{
    vector<vector<char>> board = {{'.','8','7','6','5','4','3','2','1'},{'2','.','.','.','.','.','.','.','.'},{'3','.','.','.','.','.','.','.','.'},{'4','.','.','.','.','.','.','.','.'},{'5','.','.','.','.','.','.','.','.'},{'6','.','.','.','.','.','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'8','.','.','.','.','.','.','.','.'},{'9','.','.','.','.','.','.','.','.'}};
    Solution so;
    so.isValidSudoku(board);
    return 0;
}
