#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
namespace my_string

{

    class string {

        friend  istream& operator>> (istream& in, string& s);
        friend  ostream& operator<< (ostream& out, const string& s);
    public:

        typedef char* iterator;

        string(const char* str = "") {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        string(const string& s) {
            _str = new char[strlen(s._str) + 1];
            _size = s._size;
            _capacity = s._capacity;
            strcpy(_str, s._str);
        }

        string& operator=(const string& s) {
            _str = new char[strlen(s._str) + 1];
            _size = s._size;
            _capacity = s._capacity;
            strcpy(_str, s._str);
            return *this;
        }

        ~string() {
            delete[] _str;
            _str = nullptr;
            _size = 0;
            _capacity = 0;
        }

        iterator begin() {
            return _str;
        }

        iterator end() {
            return _str + _size;
        }

        void PushBack(char c) {
            if (_size == _capacity) {
                int newcapacity = _capacity == 0 ? 5 : _capacity * 2;
                reserve(newcapacity);
            }
            _str[_size++] = c;
            _str[_size] = '\0';
        }

        string& operator+=(char c) {
            this->PushBack(c);
            return *this;
        }

        void append(const char* str) {
            int len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            strcpy(_str + _size, str);
            _size += len;
        }

        string& operator+=(const char* str) {
            this->append(str);
            return *this;
        }

        void swap(string& s) {
            my_string::string tmp(*this);
            *this = s;
            s = tmp;
        }

        size_t size()const {
            return _size;
        }

        size_t capacity()const {
            return _capacity;
        }

        const char& operator[](size_t i) const
        {
            assert(i < _size);
            return _str[i];
        }

        void reserve(size_t newCapacity) {
            if (newCapacity > _capacity) {
                char* newstr = new char[newCapacity + 1];
                strcpy(newstr, _str);
                delete[] _str;
                _str = newstr;
                _capacity = newCapacity;

            }
        }

        bool operator<(const string& s) {
            int ret = strcmp(this->_str, s._str);
            return ret < 0;
        }

        bool operator<=(const string& s) {
            return *this < s || *this == s;
        }

        bool operator>(const string& s) {
            int ret = strcmp(this->_str, s._str);
            return ret > 0;
        }

        bool operator>=(const string& s) {
            return *this > s || *this == s;
        }

        bool operator==(const string& s) {
            int ret = strcmp(this->_str, s._str);
            return ret == 0;
        }

        bool operator!=(const string& s) {
            return *this > s || *this < s;
        }

        void resize(int n, char ch = '\0') {
            if (n < _size) {
                _str[n] = '\0';
                _size = n;
            }
            else {
                if (_capacity < n) {
                    reserve(n);
                }
                for (int i = _size; i < n; ++i) {
                    _str[i] = ch;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }

        string& insert(size_t pos, const char ch) {
            assert(pos < _size);
            if (_size == _capacity) {
                size_t newcapacity = _capacity == 0 ? 5 : _capacity * 2;
                reserve(newcapacity);
            }
            int end = _size;
            while (end >= pos) {
                _str[end + 1] = _str[end];
                --end;
            }
            _str[pos] = ch;
            _size++;
            return *this;
        }

        string& insert(size_t pos, const char* str) {
            assert(pos < _size);
            size_t len = strlen(str);
            if (len + _size > _capacity) {
                reserve(_size + len);
            }

            int end = _size;
            while (end >= (int)pos) {
                _str[end + len] = _str[end];
                --end;
            }

            strncpy(_str + pos, str, len);
            _size += len;

            return *this;
        }

        string& erase(size_t pos, size_t len) {
            assert(pos < _size);

            if (len >= _size - pos) {
                _str[pos] = '\0';
                _size = pos;
            }
            else {
                size_t i = pos + len;
                while (i <= _size) {
                    _str[i - len] = _str[i];
                    ++i;
                }
                _size -= len;
            }
            return *this;
        }

        size_t find(char ch, size_t pos = 0) {
            for (size_t i = pos; i < _size; ++i) {
                if (_str[i] == ch) {
                    return i;
                }
            }
            return -1;
        }

        size_t find(const char* str, size_t pos = 0) {
            char* p = strstr(_str, str);
            if (p == nullptr) {
                return -1;
            }
            else {
                return p - _str;
            }
        }

    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };



    istream& operator>> (istream& in, string& s) {
        while (1) {
            char ch;
            ch = in.get();
            if (ch == ' ' || ch == '\n') {
                break;
            }
            else {
                s += ch;
            }
        }

        return in;
    }

    ostream& operator<< (ostream& out, const string& s) {
        for (int i = 0; i < s._size; ++i) {
            cout << s[i];
        }
        return out;
    }

};




