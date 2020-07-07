// 密码按如下规则进行计分,并根据不同的得分为密码进行安全等级划分。


#include<iostream>
#include<string>

using namespace std;
int grade_len(string& s)
{
	int len = s.size();
	if (len <= 4)
	{
		return 5;
	}
	else if (len >= 5 && len <= 7)
	{
		return 10;
	}
	else if (len >= 8)
	{
		return 25;
	}
}

//关于字母所得的分数
int grade_alpaha(string& s)
{
	int alpha = 0;
	int small = 0;
	int big = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			alpha++;
		}
		if (isupper(s[i]))
		{
			big++;
		}
		if (islower(s[i]))
		{
			small++;
		}
	}
	if (alpha == 0)
	{
		return 0;
	}
	if (big == s.size() || small == s.size())
	{
		return 10;
	}
	else if (big > 0 && small > 0)
	{
		return 20;
	}
}

//关于数字得分
int grade_digit(string& s)
{
	int dignum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]))
		{
			dignum++;
		}
	}
	if (dignum == 0)
	{
		return 0;
	}
	else if (dignum == 1)
	{
		return 10;
	}
	else if (dignum > 1)
	{
		return 20;
	}
}

//关于符号得分
int grade_symbol(string& s)
{
	//除去字母、数字、其它的都是字符
	int sym = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (!isalnum(s[i]))
		{
			sym++;
		}
	}
	if (sym == 0)
	{
		return 0;
	}
	else if (sym == 1)
	{
		return 10;
	}
	else if (sym > 1)
	{
		return 25;
	}
}

//关于奖励得分
int grade_rewd(string& s)
{
	if (grade_alpaha(s) > 0 && grade_digit(s) > 0)
	{
		if (grade_symbol(s) > 0)
		{
			if (grade_alpaha(s) == 20)
			{
				return 5;
			}
			return 3;
		}
		return 2;
	}

}

void passwd_grade_level()
{
	string s;
	while (getline(cin, s))
	{
		//int ret = grade_alpaha(s) + grade_digit(s) + grade_len(s) + grade_symbol(s) + grade_rewd(s);
		int ret1 = grade_len(s);
		int ret2 = grade_alpaha(s);
		int ret3 = grade_digit(s);
		int ret4 = grade_symbol(s);
		int ret5 = grade_rewd(s);

		int ret = ret1 + ret2 + ret3 + ret4 + ret5;

		if (ret >= 90)
		{
			cout << "VERY_SECURE" << endl;
		}
		else if (ret >= 80)
		{
			cout << "WEAK" << endl;
		}
		else if (ret >= 70)
		{
			cout << "AVERAGE" << endl;
		}
		else if (ret >= 60)
		{
			cout << "STRONG" << endl;
		}
		else if (ret >= 50)
		{
			cout << "VERT_STORONG" << endl;
		}
		else if (ret >= 25)
		{
			cout << "SECURE" << endl;
		}
		else if (ret >= 0)
		{
			cout << "VERY_WEAK" << endl;
		}
		cin.get();
	}
}
int main() {
	passwd_grade_level();
	return 0;
}