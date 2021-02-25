// 先序遍历
class Solution {
public:
	vector<int> preorder(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		st.push(root);
		while(!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			if(node) 
				result.push_back(node->val);
			else
				continue;
			//先入右节点再入左节点是因为先序遍历  中左右
			//栈 后入先出
			st.push(node->right);
			st.push(node->left);
		}
		return result;
	}
};

//中序遍历
class Solution {
public:
		vector<int> inorder(TreeNode* root) {
			stack<TreeNode*> st;
			vector<int> result;
			TreeNode* cur = root;
			while(cur != NULL || !st.empey()) {
				if(cur != NULL) { //指针来访问节点，访问到最底层
					st.push(cur); //将访问的节点放入栈
					cur = cur->left;
				}
				else {
					cur = st.top();
					st.pop();
					result.push_back(cur->val);
					cur = cur->right;
				}
			}
			return result;
		}
};

//先序遍历是 中左右 而后序遍历是 左右中，所以实际上还是按照先序遍历
//最后反转一下数组即可
//只不过先访问右节点再访问左节点
//后序遍历
class Solution{
public:
	vector<int> postorder(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> result;
		st.push(root);
		while(!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			if(node)
				result.push_back(node->val);
			else
				continue;
			//先访问右节点再访问左节点
			st.push(left);
			st.push(right);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};