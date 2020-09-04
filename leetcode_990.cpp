class UnionFindSet {
public :
	UnionFindSet(int n) {
		_v.resize(n,-1);
	}

	int FindRoot(int x) {
		while (_v[x] >= 0) {
			x = _v[x];
		}
		return x;
	}

	bool Union(int x1,int x2) {
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		// x1 和 x2 的根相同,本就在同一个集合中
		if (root1 == root2)
			return false;

		_v[root1] += _v[root2];
		_v[root2] = root1;
		return true;
	}
private:
	vector<int> _v;
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 无法确定大小，但是小写字母只有26个
        UnionFindSet ufs(26);
        
        // 先遍历一遍，将相等的，先放进同一个集合
        for(auto& str : equations) {
            if(str[1] == '=') {
                // 数组大小只有 26 ，所以存相对位置，减去字符 a
                ufs.Union(str[0] - 'a',str[3] - 'a');
            }
        }

        for(auto& str : equations) {
            // 如果在同一个集合，但是两个字母又不相等，就返回 false
            if(str[1] == '!') {
                if(ufs.FindRoot(str[0] - 'a')
                == ufs.FindRoot(str[3] - 'a'))
                return false;
            }
        }

        // 没有返回 false 说明都相等，没有在一个集合但又不相等的
        return true;
    }
};