#include"BinaryTree.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi) {
	if (*pi > n - 1)
		return;
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (a[*pi] == '#')
		return NULL;
	root->_data = a[(*pi)];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi);
	(*pi)++;
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root->_left);
	free(root->_right);
	root = NULL;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root) {
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left)+ BinaryTreeSize(root->_right)+1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left)+ BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right,k-1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* ret;
	ret = BinaryTreeFind(root->_left,x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->_right,x);
	if (ret)
		return ret;
	return NULL;
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL)
		return;
	printf("%c ",root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ",root->_data);
	BinaryTreeInOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ",root->_data);
}

// 层序遍历
/****************************************************队列相关******************************************************/
/*****************************************************************************************************************/
/*****************************************************************************************************************/
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_back = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data,BTNode* root) {
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_data = data;
	newnode->_next = NULL;
	newnode->root = root;
	if (q->_back == NULL) {
		q->_front = q->_back = newnode;
	}
	else
	{
		q->_back->_next = newnode;
		q->_back = q->_back->_next;
	}
}

// 队头出队列 
void QueuePop(Queue* q) {
	assert(q);
	if (q->_front->_next == NULL) {
		printf("%c  ", q->_front->_data);
		free(q->_front);
		q->_front = q->_back = NULL;
	}
	else
	{
		QueueNode* next = q->_front->_next;
		printf("%c  ", q->_front->_data);
		free(q->_front);
		q->_front = next;
	}
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	return (q->_front == NULL) ? 1 : 0;
}

// 销毁队列 
void QueueDestroy(Queue* q) {
	assert(q);
	QueueNode* next;
	while (q->_front != q->_back)
	{
		next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
	free(q->_back);
	q->_front = NULL;
	q->_back = NULL;
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	QueueInit(queue);
	QueuePush(queue, root->_data,root);
	//PartLevelOrder( root,  queue);
	while (!QueueEmpty(queue)) {
		BTNode* ret = queue->_front->root;
		QueuePop(queue);
		if (ret->_left != NULL)
			QueuePush(queue, ret->_left->_data,ret->_left);
		if (ret->_right != NULL)
			QueuePush(queue, ret->_right->_data,ret->_right);
	}
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root) {
	int flag = 0;
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	QueueInit(queue);
	QueuePush(queue, root->_data, root);
	//PartLevelOrder( root,  queue);
	while (!QueueEmpty(queue)) {
		BTNode* ret = queue->_front->root;
		QueuePop(queue);
		if (ret->_left == NULL && ret->_right != NULL)
			flag = 1;
		if (ret->_left != NULL)
			QueuePush(queue, ret->_left->_data, ret->_left);
		if (ret->_right != NULL)
			QueuePush(queue, ret->_right->_data, ret->_right);
	}
		if (flag == 1)
			printf("\n这棵二叉树不是完全二叉树\n");
		else
			printf("\n这棵二叉树是完全二叉树\n");
}
