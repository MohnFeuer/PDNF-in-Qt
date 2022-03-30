#include<iostream>
#include<cstring>
#include<set>

using namespace std;

string changeCh(set <char> s, string str, int arr[])   //根据set的顺序将变元数组中的值替换掉输入串中字母
{
	set<char>::iterator it;
    
	int loc = 0;
	it = s.begin();
	int n = s.size();   //n为字母数

	while (n--)   //执行n次，每次替换掉字符串中的一个字母
	{

		for (unsigned int i = 0; i < str.length(); i++)   //对与字符串的每一个字符
		{

				if (str[i] == *it)   //如果目前的字符str[i]与迭代器当前指向set中的字符相同
					str[i] = arr[loc];   //用真值表中的真值换掉这个字符
			
		}
		
		loc++;   //下一个真值
		it++;   //下一个字母
	}

	return str;

}

char letters(char ch)   //为了便于switch语句的使用，将字符归类
{
	if (ch >= 'A'&&ch <= 'Z')   //字母
		return 'L';   //letter
	if (ch == '&' || ch == '|' || ch == '>' || ch == '~')   //二元运算符
		return 'O';   //operator
	else   //一元运算符'!'或'('或')'
		return ch;
}

char letters2(char ch)   //为了便于switch语句的使用，将字符归类
{
	if (ch == 0 || ch == 1)   //操作数
		return 'N';   //letter
	if (ch == '&' || ch == '|' || ch == '>' || ch == '~')   //二元运算符
		return 'O';   //operator
	else   //一元运算符'!'或'('或')'
		return ch;
}

