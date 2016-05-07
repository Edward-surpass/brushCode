/*********************************************************************************
*     File Name           :     79WordSearch.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-17 16:29]
*     Last Modified       :     [2016-04-18 16:36]
*     Description         :      
**********************************************************************************/
#include <vector>
#include <string>
#include <vector>
#include <string>
#include <vector>
#include <string>

class Solution {
    public:
        bool exist(std::vector<std::vector<char>>& board, std::string word) {
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board[i].size(); ++j)
                {
                    //std::vector<std::vector<char>> tmp(board);
                    if ( judeg_exist(board, word, 0, i, j)  )
                        return true;
                }
            }
            return false;
        }
        bool judeg_exist(std::vector<std::vector<char>> &board, std::string &word, int idx, int i, int j)
        {
            if (idx  == word.size())
                return true;
            if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size())
                return false;
            if(word[idx] != board[i][j])
                return false;

            board[i][j] = '#';
            ++idx;
            bool ret = judeg_exist(board, word, idx, i, j+1) ||
                judeg_exist(board, word, idx, i + 1, j) ||
                judeg_exist(board, word, idx, i, j-1) ||
                judeg_exist(board, word, idx, i-1, j);
            board[i][j] = word[idx-1];
            return ret;
        }
};
