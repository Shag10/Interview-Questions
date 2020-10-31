#include<string>
#include<vector>
std::vector<int> X{-1, 0, 1, 0};
std::vector<int> Y{0, 1, 0, -1};
	
    bool isSafe(std::vector<std::string> &grid, std::string &target, int i, int j, int row, int col, int currPos) {
        return i >= 0 and j >= 0 and i < row and j < col and target[currPos] == grid[i][j];
    }

    bool isFound(std::vector<std::string> &grid, std::string &target, int i, int j, int row, int col, int currPos) {
        if(!isSafe(grid, target, i, j, row, col, currPos)) {
            return false;
        }
        if(currPos == target.size() - 1) {
            return true;
        }
        char prevChar = grid[i][j];
        grid[i][j] = '*';

        for(int itr = 0; itr < 4; itr++) {
            int next_x = i + X[itr];
            int next_y = j + Y[itr];
            if(isFound(grid, target, next_x, next_y, row, col, currPos + 1)) {
                return true;
            }
        }
        grid[i][j] = prevChar;
        return false;
    }

    bool exists(std::vector<std::string> grid, std::string target) {
        if(grid.empty() || target.empty()) {
            return false;
        }else if(grid[0].empty()) {
            return false;
        } else if(grid.size() * grid[0].size() < target.size()) {
            return false;
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(isFound(grid, target, i, j, grid.size(), grid[i].size(), 0)) {
                    return true;
                }
            }
        }
        return false;
    }
