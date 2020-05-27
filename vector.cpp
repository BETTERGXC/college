#include<iostream>
#include<assert.h>
using namespace std;

namespace seft {

    template<class T>
    class vector {
    public:

        // Vector的迭代器是一个原生指针
        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin() {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        const_iterator cbegin() {
            return _start;
        }

        const_iterator cend() const {
            return _finish;
        }



        // construct and destroy

        vector() 
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endOfStorage(nullptr){
        }

        vector(int n, const T& value = T()) 
            :_start(nullptr)
            , _finish(nullptr)
            , _endOfStorage(nullptr) {

            reserve(n);
            while (n--) {
                push_back(value);
            }
        }

        template<class InputIterator>

        vector(InputIterator first, InputIterator last) {
            reserve(first - last);
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }

        vector(const vector<T>& v) 
            :_start(nullptr)
            ,_finish(nullptr)
            ,_endOfStorage(nullptr){

            reserve(v.capacity);
            iterator it = begin();
            const_iterator vit = v.cbegin;
            while (vit != v.cend) {
                *it = *vit;
            }
            _finish = _start + v.size();
            _endOfStorage = _start + v.capacity;
        }

        vector<T>& operator= (vector<T> v) {
            swap(v);
            return *this;
        }

        ~vector() {
            delete[] _start;
            _start = _finish = _endOfStorage = 0;
        }

            // capacity

        size_t size() const {
            return _finish - _start;
        }

        size_t capacity() const {
            return _endOfStorage - _start;
        }

        void reserve(size_t n) {
            if (capacity() < n) {
                size_t OldSize = size();
                T* tmp = new T[n];
                if (_start) {
                    for (size_t i = 0; i < OldSize; ++i) {
                        tmp[i] = _start[i];
                    }

                    _start = tmp;
                    _finish = _start + OldSize;
                    _endOfStorage = _start + n;
                }
            }
        }

        void resize(size_t n, const T& value = T()) {
            // 1. 当前的 size >= n
            if (size() >= n) {
                _finish = _start + n;
                return;
            }

            // 2. 当前的 size < n 空间不够，增容
            if (capacity() < n) {
                reserve(n);
            }

            // 将 size() 扩大到 n
            for (int i = _finish - _start; i < n; ++i) {
                _start[i] = value;
            }
        }



            ///////////////access///////////////////////////////

        T& operator[](size_t pos) {
            assert(pos < _finish);
            return _start[pos];
        }   

        const T& operator[](size_t pos)const {
            assert(pos < _finish);
            return _start[pos];
        }



            ///////////////modify/////////////////////////////

        void push_back(const T& x) {
            insert(end(), x);
        }

        void pop_back() {
            erase(--end());
        }

        void swap(vector<T>& v) {
            ::swap(_start,v._start);
            ::swap(_finish,v._finish);
            ::swap(_endOfStorage,v._endOfStorage);
        }

        iterator insert(iterator pos, const T& x) {
            assert(pos <= _finish);
            // 1. 如果空间不够，先增容
            int n = pos - _start;
            if (_endOfStorage == _finish) {
                int newcapacity = (_endOfStorage == 0) ? 2 : 2 * capacity();
                reserve(newcapacity);

                // 如果增容了，需要重置 pos
                pos = _start + n;
            }
            iterator end = _finish - 1;
            while (end >= pos) {
                (*end + 1) = *end;
                --end;
             }
            *pos = x;
            ++_finish;
            return pos;
        }

        iterator erase(iterator pos) {
            iterator begin = pos + 1;
            while (begin != _finish) {
                (*begin - 1) = *begin;
                ++begin;
            }
            --_finish;
            return pos;
        }

    private:

        iterator _start; // 指向数据块的开始
        iterator _finish; // 指向有效数据的尾
        iterator _endOfStorage; // 指向存储容量的尾

    };

}