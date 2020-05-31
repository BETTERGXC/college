#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct node {
	node* next;
	node* prev;
	int data;
}node;

class queue {
public:
	// 构造函数
	queue() {
		_head= (node*)malloc(sizeof(node));
		_front = _head;
		_back = _head;
		_head->next = _head;
		_head->prev = _head;
	}

	// 拷贝构造
	queue(const queue& q) {
		_head = (node*)malloc(sizeof(node));
		_head->next = _head;
		_head->prev = _head;
		node* cur = q._head->next;
		while (cur != q._head) {
			push_back(cur->data);
			cur = cur->next;
		}
	}

	// 析构函数
	~queue() {
		node* cur = _head->next;
		while (cur != _head) {
			cur = cur->next;
			free(cur->prev);
		}
		free(_head);
		_front = _back = _head = nullptr;
	}

	// 头插
	void push_front(int data) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->data = data;
		if (_head->next == _head) {
			_front = newnode;
			_head->next = _front;
			_head->prev = _front;
			_front->prev = _head;
			_front->next = _head;

			_back = _front;

		}
		else {
			_head->next = newnode;
			newnode->prev = _head;
			newnode->next = _front;
			_front->prev = newnode;

			_front = newnode;
			_back = _head->prev;
		}
	}

	// 头删
	void pop_front() {
		_head->next = _front->next;
		_front->next->prev = _head;
		free(_front);
		_front = _head->next;
	}

	// 尾插
	void push_back(int data) {
		node* newnode = (node*)malloc(sizeof(node));
		newnode->data = data;
		if (_head->next == _head) {
			_back = newnode;
			_head->next = _back;
			_head->prev = _back;
			_back->prev = _head;
			_back->next = _head;

			_front = _back;

		}
		else {
			_back->next = newnode;
			newnode->prev = _back;
			newnode->next = _head;
			_head->prev = newnode;

			_back = newnode;
			_front = _head->next;
		}
	}

	// 尾删
	void pop_back() {
		_head->prev = _back->prev;
		_back->prev->next = _head;
		free(_back);
		_back = _head->prev;
	}

	// 输出
	void print() {
		node* cur = _head->next;
		while (cur != _head) {
			cout << cur->data << " ";
			cur = cur->next;
		}
	}

	// 判空   如果为空 返回1，非空返回0
	int empty() {
		if (_head->next == _head) {
			return 1;
		}
		return 0;
	}

	// 赋值运算符重载
	queue& operator = (const queue& q) {
		node* cur = q._head->next;
		while (cur != q._head) {
			push_back(cur->data);
			cur = cur->next;
		}
		return *this;
	}

private:
	node* _head;
	node* _front;
	node* _back;
};