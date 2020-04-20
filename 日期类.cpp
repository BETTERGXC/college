#include<iostream>
using namespace std;

class Date {
public:
	int GetMonthDay(int year, int month) {
		static int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		// 如果是闰年，2月返回29天
		if (month = 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) {
			return 29;
		}
		return monthDays[month];
	}

	Date(int year = 0, int month = 1, int day = 1) {
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "非法日期" << endl;
	}

	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator==(const Date& d) {
		return this->_year == d._year && this->_month == d._month && this->_day == d._day;
	}

	Date& operator=(const Date& d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date operator+(int day) {
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month)) {
			ret._day -= GetMonthDay(ret._year, ret._day);
			ret._month++;
			if (ret._month == 13) {
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}

	// 日期减天数
	Date operator-(int day) {
		Date ret = *this;
		ret -= day;
		return ret;
	}

	// 日期减日期
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;

		}
		int day = 0;

		while (min < max)
		{
			++(min);
			++day;
		}
		return day * flag;
	}

	Date& operator+=(int day) {
		/*if (day > 0) {
			return *this -= -day;
		}*/
		_day += day;
		while (_day > GetMonthDay(_year, _month)) {
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13) {
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	Date& operator -=(int day) {
		if (day < 0) {
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0) {
			--_month;
			if (_month == 0) {
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	Date& operator++() {
		*this += 1;
		return *this;
	}

	Date& operator--() {
		*this -= 1;
		return *this;
	}

	Date& operator++(int) {
		Date tmp(*this);
		*this += 1;
		return tmp;
	}

	Date& operator--(int) {
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	bool operator>(const Date& d) {
		if (_year > d._year) {
			return true;
		}
		else if (_year == d._year && _month > d._month) {
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day) {
			return true;
		}
		else
			return false;
	}

	bool operator<(const Date& d) {
		if (_year < d._year) {
			return true;
		}
		else if (_year == d._year && _month < d._month) {
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day) {
			return true;
		}
		else
			return false;
	}

	bool operator >=(const Date& d) {
		if (_year > d._year) {
			return true;
		}
		else if (_year == d._year && _month > d._month) {
			return true;
		}
		else if (_year == d._year && _month == d._month && _day >= d._day) {
			return true;
		}
		else
			return false;
	}

	bool operator <=(const Date& d) {
		if (_year < d._year) {
			return true;
		}
		else if (_year == d._year && _month < d._month) {
			return true;
		}
		else if (_year == d._year && _month == d._month && _day <= d._day) {
			return true;
		}
		else
			return false;
	}

	void print() {
		cout << _year << " - " << _month << " - " << _day << endl;
	}

private:
	int _year = 0;
	int _month = 1;
	int _day = 1;
};