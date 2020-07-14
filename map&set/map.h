#pragma once
#include<iostream>
#include"RBTree.h"
using namespace std;
namespace bit
{
	
	template<class K, class V>
	class map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return  _t.end();
		}

		bool Insert(const pair<K, V>& kv)
		{
			 _t.Insert(kv);
			 return true;
		}

	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};

	void test_map()
	{
		map<int, int> m;
		m.Insert(make_pair(1, 1));
		m.Insert(make_pair(3, 3));
		m.Insert(make_pair(10, 10));
		m.Insert(make_pair(5, 5));
		m.Insert(make_pair(6, 6));

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;

		for (auto kv : m)
		{
			cout << kv.first << ":" << kv.second << endl;
		}

		cout << endl;
	}
}