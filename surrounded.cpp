#include <iostream>
#include <vector>
class Solution {
public:
    typedef std::pair<int,int> ii;
    void solve(std::vector<std::vector<char>> &board) {
        std::array<ii, 4> dirs = {{{0,1},{0,-1},{1,0},{-1,0}}};
        auto dfs = [&](auto &&ff, const int row, const int col) -> void {
            board[row][col] = '#';
            for (const auto &d : dirs) {
                int new_row = row+d.first, new_col = col+d.second;
                if (board[new_row][new_col] == 'O') {
                    ff(ff,new_row,new_col);
                }
            }
        };
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size();++j) {
                if (board[i][j] == 'O') dfs(dfs,i,j);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size();++j) {
                if (board[i][j] == 'O') board[i][j]  = 'X';
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size();++j) {
                if (board[i][j] == '#') board[i][j]  = 'O';
            }
        }

    }

};
int main(int argc, char **argv){

    


    return 0;
}
