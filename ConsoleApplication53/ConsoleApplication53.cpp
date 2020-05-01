/*
github: mine counting

Counting the number of mines around a cell

*/

#include <iostream>
#include <vector>
using namespace std;

struct mine_data {
	int total_mines;
	int not_mines;
	int unkown;
};

void print(vector<vector<mine_data>> input) {
	for (vector<mine_data> ve : input) {
		for (mine_data i : ve) {
			cout << i.total_mines << " ";
			cout << i.not_mines << " ";
			cout << i.unkown << "    ";
		}
		cout << "\n\n";
	}
	cout << "\n";
}
vector<vector<mine_data>> find_mines(vector<vector<int>> mine_grid) {
	vector<mine_data> tmp(mine_grid.size(), { 0, 0, 0 });
	int len = mine_grid.size();
	int m = mine_grid.size();
	int n = mine_grid[0].size();
	int total_mines = 0;
	int not_mines = 0;
	int unkown = 0;
	vector<vector<mine_data>> output(len, tmp);
	vector<int> new_y{ -1, -1, -0, +1, +1 ,+1, -0, -1 };
	vector<int> new_x{ -0, +1, +1, +1, -0, -1, -1, -1 };

	for (int row = 0; row < tmp.size(); row++) {
		for (int col = 0; col < mine_grid.size(); col++) {
			for (int i = 0; i < 8; i++) {
				if (col + new_y[i] < n && col + new_y[i] >= 0) {
					if (row + new_x[i] < m && row + new_x[i] >= 0) {
						if (mine_grid[row + new_x[i]][col + new_y[i]] == 1) {
							total_mines++;
						}
						
						if (mine_grid[row + new_x[i]][col + new_y[i]] == 0) {
							not_mines++;
						}
							
						if (mine_grid[row + new_x[i]][col + new_y[i]] == 2) {
								unkown++;
						}
					} 
						
					
				}
			}
			
			mine_data tmp1{ total_mines, not_mines, unkown };
			output[row][col] = tmp1;
			total_mines = 0;
			not_mines = 0;
			unkown = 0;
		}
	}
	return output;
}

int main()
{
	vector<vector<int>> input;
	vector<int> tmp1{ 0, 0, 1, 0 };
	vector<int> tmp2{ 0, 1, 2, 0 };
	vector<int> tmp3{ 0, 0, 0, 0 };
	vector<int> tmp4{ 1, 0, 2, 0 };
	input.push_back(tmp1);
	input.push_back(tmp2);
	input.push_back(tmp3);
	input.push_back(tmp4);
	vector<vector<mine_data>> output = find_mines(input);
	print(output);
	return 0;
}