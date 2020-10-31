#include<string>
#include<vector>
std::vector<std::string> grid;
std::vector<std::vector<bool>> visited;
	void dfs(int i, int j){
		if(i < 0 || i >= grid.size() || j<0 || j >= grid[i].size()) return;
		if(visited[i][j]) return;
		if(grid[i][j] == '0') return;
		visited[i][j] = true;
		dfs(i-1,j);
		dfs(i+1,j);
		dfs(i,j-1);
		dfs(i,j+1);
		dfs(i-1,j-1);
		dfs(i-1,j+1);
		dfs(i+1,j-1);
		dfs(i+1,j+1);
	}
	int getCount(std::vector<std::string> grid) {
		int count = 0;
		this->grid = grid;
		if(grid.size() == 0) return 0;
		visited = std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(),false));
		for(int i=0; i<grid.size(); i++){
			for(int j = 0; j<grid[i].size(); ++j){
				if(visited[i][j] == false && grid[i][j] == '1'){
					count += 1;
					dfs(i,j);
				}
			}
		}
		return count;
	}
