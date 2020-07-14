#pragma once
#include<iostream>
#include"RBTree.h"
using namespace std;
namespace bit
{

	template<class K>
	class set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
	public:
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return  _t.end();
		}

		bool Insert(const K& k)
		{
			_t.Insert(k);
			return true;
		}

	private:
		RBTree<K, K, SetKeyOfT> _t;
	};

	void test_set()
	{
		set<int> m;
		m.Insert(1);
		m.Insert(3);

		m.Insert(5);


		set<int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << *it << endl;
			++it;
		}
		cout << endl;


		cout << endl;
	}
}