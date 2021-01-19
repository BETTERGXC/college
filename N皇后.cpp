class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>> attack(n,vector<int>(n));        //保存皇后的攻击范围
		vector<vector<string>> ret;     //保存N皇后的解法
		vector<string> queue(n);                             //保存N皇后的一种解法
		
		//初始化attack数组和queue数组
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				attack[i][j] = 0;
				queue[i] += '.';
			}
		}
		
		backtrack(ret, attack, queue, 0, n);
		return ret;
		
	}
	
	//修改attack和queue
	void put_queue(int x, int y, vector<vector<int>>& attack) {
		
		static const int dx[] = {-1,-1,-1,0,0,1,1,1};
		static const int dy[] = {-1,0,1,-1,0,-1,0,1};
		//当前位置先占位
		attack[x][y] = 1;
		//设定当前皇后的攻击范围
        //当前皇后的8个方向，attack.size()距离
		for(int i = 1; i < attack.size(); i++) {
			for(int j = 0; j < 8; j++) {
				int nexti = x + i*dx[j];
				int nextj = y + i*dy[j];
				
				if(nexti >=0 && nexti < attack.size() && nextj >=0 && nextj < attack.size()) {
					attack[nexti][nextj] = 1;
				}
			}
		}
		
	}
	
	void backtrack(vector<vector<string>>& ret, 
		vector<vector<int>>& attack, vector<string>& queue, int k, int n) {
			
		if(k == n) {
			ret.push_back(queue);
			return;
		}
		
		for(int i = 0; i < n; i++) {
			if(attack[k][i] == 0) {
				queue[k][i] = 'Q';
				vector<vector<int>> tmp(attack);
				put_queue(k, i, attack);
				backtrack(ret, attack, queue, k+1, n);
				attack = tmp;
				queue[k][i] = '.';
			}
		}
	}
};