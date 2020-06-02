#include<iostream>
#include<assert.h>
using namespace std;

namespace M {
	// 节点类
	template<class T>
	struct Node {
		Node(const T&x = T()) 
		:_prev(nullptr)
		,_next(nullptr)
		,data(x) {
		}

		Node<T>* _prev;
		Node<T>* _next;
		T data;
	};

	// list 的迭代器类
	template <class T,class Ref,class Ptr>
	class List_Iterator {
		typedef Node<T> Node;
		typedef List_Iterator<T, Ref, Ptr>Self;
	public:
		List_Iterator(Node* node = nullptr)
			:_pnode(node) {
			
		}

		List_Iterator(const Self& l)
			:_pnode(l._pnode) {

		}

		T& operator*() {
			return _pnode->data;
		}

		T& operator->() {
			return &*this;
		}

		Self& operator++() {
			_pnode = _pnode->_next;
			return *this;
		}

		Self& operator++(int) {
			Self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
		}

		Self& operator--() {
			_pnode = _pnode->_prev;
			return *this;
		}

		Self& operator--(int) {
			Self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}

		bool operator!=(const Self& l) {
			return _pnode != l._pnode;
		}

		bool operator==(const Self& l) {
			return _pnode == l._pnode;
		}



		Node* _pnode;

	};

	// list 类
	template<class T>
	class list {

		typedef Node<T> Node;

	public:
		typedef List_Iterator<T,T&,T*> iterator;
		typedef List_Iterator<const T, const T&, const T*>const_iterator;

	public:
		list() {
			CreatHead();
		}

		list(int n,const T& value = T()) {
			CreatHead();
			for (int i = 0; i < n; ++i) {
				push_back(value);
			}
		}

		template<class iterator>
		list(iterator first,iterator last) {
			CreatHead();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}

		list(const list<T>& l) {
			CreatHead();
			list<T>tmp(l.cbegin(), l.cend());
			this->swap(tmp);

		}

		list<T>& operator==(const list<T>l) {
			this->swap(l);
			return &*this;
		}

		~list() {
			clear();
			delete _phead;
			_phead = nullptr;
		}


		// list iterator
		iterator begin() {
			return iterator(_phead->_next);
		}

		iterator end() {
			return iterator(_phead);
		}

		const_iterator begin()const {
			return iterator(_phead->next);
		}

		const_iterator end()const {
			return iterator(_phead);
		}

		// list capcity
		size_t size()const {
			size_t size = 0;
			Node* p = _phead->_next;
			while (p != _phead) {
				size++;
				p = p->_next;
			}
			return size;
		}

		bool empty() {
			return size() == 0;
		}

		T& front() {
			assert(!empty());
			return _phead->_next->data;
		}

		T& back() {
			assert(!empty());
			return _phead->_next->_prev->data;
		}

		const T& front()const {
			ssert(!empty());
			return _phead->_next->data;
		}

		const T& back()const {
			assert(!empty());
			return _phead->_next->_prev->data;
		}

		void push_back(const T& val) {
			insert(end(),val);
		}

		void pop_back() {
			erase(--end());
		}

		void push_front(const T& val) {
			insert(begin(),val);
		}

		void pop_front() {
			erase(begin());
		}

		iterator insert(iterator pos, const T& val) {
			Node* newnode = new Node(val);
			Node* pcur = pos._pnode;

			newnode->_prev = pcur->_prev;
			newnode->_next = pcur;
			newnode->_prev->_next = newnode;
			pcur->_prev = newnode;
			return iterator(newnode);
		}

		iterator erase(iterator pos) {
			Node* del = pos._pnode;
			Node* ret = del->_next;

			del->_next->_prev = del->_prev;
			del->_prev->_next = del->_next;
			delete del;
			return iterator(ret);
		}

		void clear() {
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
		}

		void swap(list<T>& l) {
			Node* tmp = _phead;
			_phead = l._phead;
			l._phead = tmp;
		}

	private:
		void CreatHead() {
			_phead = new Node;
			_phead->_next = _phead;
			_phead->_prev = _phead;
		}
		Node*  _phead;
	};
}

