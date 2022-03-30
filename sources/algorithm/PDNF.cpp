#include<iostream>
#include<cstdlib>
#include<string>
#include<set>
#include<cmath>

#include "publicFun.h"   //changeCh
#include "EvaluateExpression.h"   //EEmain

using namespace std;

string PDNF(string s, int **arr, int n, set <char> set1,string* arrstr)  //principal disjunctive normal form 求出主析取范式
{
	//s:输入字符串 arr:真值表变元部分 n:变元个数 set1:变元字母set arrstr:小项数组

	string str;   //主析取范式

	for (int i = 0; i < pow(2, n); i++)   //i为行标
	{
		string OPstr;
		OPstr = changeCh(set1, s, arr[i]);   //对第i行把字母替换为第i行的数字

		if (EEmain(OPstr) == 1)   //若这一行的变元值满足使输入式为真
		{
			str += arrstr[i];   //主析取范式str加上对应变元行的小项
			str += '|';
		}
	}

	str.pop_back();   //去掉最后一个'|'


	return str;
}

