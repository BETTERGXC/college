// �������
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
			//�����ҽڵ�������ڵ�����Ϊ�������  ������
			//ջ �����ȳ�
			st.push(node->right);
			st.push(node->left);
		}
		return result;
	}
};

//�������
class Solution {
public:
		vector<int> inorder(TreeNode* root) {
			stack<TreeNode*> st;
			vector<int> result;
			TreeNode* cur = root;
			while(cur != NULL || !st.empey()) {
				if(cur != NULL) { //ָ�������ʽڵ㣬���ʵ���ײ�
					st.push(cur); //�����ʵĽڵ����ջ
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

//��������� ������ ����������� �����У�����ʵ���ϻ��ǰ����������
//���תһ�����鼴��
//ֻ�����ȷ����ҽڵ��ٷ�����ڵ�
//�������
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
			//�ȷ����ҽڵ��ٷ�����ڵ�
			st.push(left);
			st.push(right);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};