// 计算日期到天数转换
#include<iostream>
using namespace std;

void getmonth(int year,int *month) {
	if (year % 4 == 0 && year % 100 != 0) {
		month[2] = 29;

	}
	else if (year % 100 == 0 && year % 400 == 0) {
		month[2] = 29;
	}
	else {
		month[2] = 28;
	}
}

int main() {
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int _year;
	int _month;
	int _day;
	while (cin >> _year >> _month >> _day) {
		getmonth(_year,month);
		int sum = 0;
		for (int i = 1; i <= _month; ++i) {
			sum += month[i];
		}
		sum = sum - (month[_month] - _day);
		cout << sum << endl;
	}
	return 0;
}