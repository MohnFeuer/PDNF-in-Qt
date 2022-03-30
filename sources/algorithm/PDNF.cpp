#include<iostream>
#include<cstdlib>
#include<string>
#include<set>
#include<cmath>

#include "publicFun.h"   //changeCh
#include "EvaluateExpression.h"   //EEmain

using namespace std;

string PDNF(string s, int **arr, int n, set <char> set1,string* arrstr)  //principal disjunctive normal form �������ȡ��ʽ
{
	//s:�����ַ��� arr:��ֵ���Ԫ���� n:��Ԫ���� set1:��Ԫ��ĸset arrstr:С������

	string str;   //����ȡ��ʽ

	for (int i = 0; i < pow(2, n); i++)   //iΪ�б�
	{
		string OPstr;
		OPstr = changeCh(set1, s, arr[i]);   //�Ե�i�а���ĸ�滻Ϊ��i�е�����

		if (EEmain(OPstr) == 1)   //����һ�еı�Ԫֵ����ʹ����ʽΪ��
		{
			str += arrstr[i];   //����ȡ��ʽstr���϶�Ӧ��Ԫ�е�С��
			str += '|';
		}
	}

	str.pop_back();   //ȥ�����һ��'|'


	return str;
}

