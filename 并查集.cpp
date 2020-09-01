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