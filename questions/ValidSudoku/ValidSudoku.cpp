// Main file of the Project
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<string, bool> row_map = {};
        unordered_map<string, bool> col_map = {};
        unordered_map<string, bool> box_map = {};

        for (size_t row = 0; row < 9; row++)
        {
            for (size_t col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    int box = ((row / 3) * 3) + (col / 3);
                    if (row_map.count(to_string(row) + to_string(board[row][col])))
                        return false;
                    else
                        row_map.emplace(make_pair(to_string(row) + to_string(board[row][col]), true));

                    if (col_map.count(to_string(col) + to_string(board[row][col])))
                        return false;
                    else
                        col_map.emplace(make_pair(to_string(col) + to_string(board[row][col]), true));

                    if (box_map.count(to_string(box) + to_string(board[row][col])))
                        return false;
                    else
                        box_map.emplace(make_pair(to_string(box) + to_string(board[row][col]), true));
                }
            }
        }
        return true;
    }
};

class Solution2
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<string, bool> box_map = {};

        for (size_t row = 0; row < 9; row++)
        {
            unordered_map<string, bool> row_map = {};
            unordered_map<string, bool> col_map = {};
            if (row % 3 == 0)
                box_map.clear();
            for (size_t col = 0; col < 9; col++)
            {
                if (board[row][col] != '.')
                {
                    int box = ((row / 3) * 3) + (col / 3);
                    if (row_map.count(to_string(row) + to_string(board[row][col])))
                        return false;
                    else
                        row_map.emplace(make_pair(to_string(row) + to_string(board[row][col]), true));

                    if (box_map.count(to_string(box) + to_string(board[row][col])))
                        return false;
                    else
                        box_map.emplace(make_pair(to_string(box) + to_string(board[row][col]), true));
                }

                if (board[col][row] != '.')
                {
                    if (col_map.count(to_string(row) + to_string(board[col][row])))
                        return false;
                    else
                        col_map.emplace(make_pair(to_string(row) + to_string(board[col][row]), true));
                }
            }
        }
        return true;
    }
};

int main(int arg, char *argv[])
{
    vector<vector<char>> b =
        {{'6', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution2 s;

    s.isValidSudoku(b) ? cout << "Its valid" : cout << "Not valid";
    std::cout << std::endl;
    return 0;
}