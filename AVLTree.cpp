#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode {

	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	// 平衡因子
	int _bf;

	pair<K, V>_kv;
	AVLTreeNode(const  pair<K,V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template <class K,class V>
class AVLTree {
	typedef AVLTreeNode<K, V> Node;
public:
	bool insert(const pair<K,V>& kv) {
		// 1.如果根不存在,直接让新结点作为根
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}

		// 按照二叉搜索树的方式插入
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (cur && cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else if (cur && cur->_kv.first <= kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > kv.first) {
			parent->_left = cur;
			cur->_parent = parent;
		}
		else {
			parent->_right = cur;
			cur->_parent = parent;
		}

		// 2.更新平衡因子
		while (parent) {
			if (cur == parent->_right) {
				parent->_bf++;
			}
			else
				parent->_bf--;

			// 说明子树高度未发生变化，不用继续更新平衡因子，退出循环
			if (parent->_bf == 0)
				break;
			
			// 说明子树高度发生变化，需要往上更新平衡因子
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}

			// 说明子树高度已经不平衡，需要调节
			else if (parent->_bf == 2 || parent->_bf == -2) {
				if (parent->_bf == 2) {
					// 新结点插入在较高右子树的右侧：右右 -- 左旋
					if (cur->_bf == 1) {
						RotateL(parent);
					}
					// 新结点插入在较高右子树的左侧：右左 -- 右左双旋
					else if (cur->_bf == -1) {
						RotateRL(parent);
					}
				}
				else if (parent->_bf == -2) {
					// 新结点插入在较高左子树的左侧：左左 -- 右旋
					if (cur->_bf == -1) {
						RotateR(parent);
					}
					// 新结点插入在较高左子树的右侧：左右 -- 左右双旋
					else if (cur->_bf == 1) {
						RotateLR(parent);
					}
				}
				// 旋转完成后，parent的高度就恢复到插入之前的高度，更新结束
				break;
			}
		}
		return true;
	}

	// 左旋
	void RotateL(Node *parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if(subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;

		// 1.如果parent是原来这棵树的根，那么现在 subR 是根
		// 2.如果不是根，让subR顶替原来parent的位置
		if (parent == _root) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else if (parent == ppNode->_right) {
			ppNode->_right = subR;
			subR->_parent = ppNode;
		}
		else if (parent == ppNode->_left) {
			ppNode->_left = subR;
			subR->_parent = ppNode;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateR(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;


		if (parent == _root) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else if (parent == ppNode->_right) {
			ppNode->_right = subL;
			subL->_parent = ppNode;
		}
		else if (parent == ppNode->_left) {
			ppNode->_left = subL;
			subL->_parent = ppNode;
		}

		parent->_bf = subL->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == -1) {
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1) {
			subR->_bf = 0;
			parent->_bf = -1;
			subRL->_bf = 0;
		}
		else if (bf == 0) {
			subR->_bf = 0;
			parent->_bf = 0;
			subRL->_bf = 0;
		}
	}

	void RotateLR(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(subL);
		RotateR(parent);

		if (bf == 1) {
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1) {
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0) {
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}

	void _InOrder(Node* root) {
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder() {
		_InOrder(_root);
	}

	int Height(Node* root) {
		if (root == nullptr)
			return 0;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return lefeHeight > rightHeight ? lefeHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root) {
		if (root == nullptr)
			return true;

		int lefeHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return abs(lefeHeight - rightHeight) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	bool IsBalance() {
		return _IsBalance(_root);
	}
private:
	Node* _root = nullptr;
};


