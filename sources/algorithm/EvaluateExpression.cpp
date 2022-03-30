#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>

#include "publicFun.h"

using namespace std;

int data_Precede[8][8] =   //���ȼ���ά����
{   //!  &  | -> <-> (  )  #
	{-1, 1, 1, 1, 1,-1, 1, 1},//!
	{-1, 1, 1, 1, 1,-1, 1, 1},//&
	{-1,-1, 1, 1, 1,-1, 1, 1},//|
	{-1,-1,-1, 1, 1,-1, 1, 1},//->
	{-1,-1,-1,-1, 1,-1, 1, 1},//<->
	{-1,-1,-1,-1,-1,-1, 0, 0},//(
	{ 1, 1, 1, 1, 1, 0, 1, 1},//)
	{-1,-1,-1,-1,-1,-1, 0, 0}//#
};  //6,8  7,6   8,7�е�0ֻ������ռλ��ʵ������������

int Precede(char op1, char op2)   //1��op1>op2 ջ������������Ŀǰ������;  0��op1=op2 ;   -1: op1<op2 ; 
{
	int row;
	int col;

	switch (op1)   //������1
	{
	case '!':
		row = 0;
		break;
	case '&':
		row = 1;
		break;
	case '|':
		row = 2;
		break;
	case '>':
		row = 3;
		break;
	case '~':
		row = 4;
		break;
	case '(':
		row = 5;
		break;
	case ')':
		row = 6;
		break;
	case '#':
		row = 7;
		break;
	default:
		break;
	}

	switch (op2)   //������2
	{
	case '!':
		col = 0;
		break;
	case '&':
		col = 1;
		break;
	case '|':
		col = 2;
		break;
	case '>':
		col = 3;
		break;
	case '~':
		col = 4;
		break;
	case '(':
		col = 5;
		break;
	case ')':
		col = 6;
		break;
	case '#':
		col = 7;
		break;
	default:
		break;
	}

	return data_Precede[row][col];
}

int Operate(int a, char theta, int b)
{
	switch (theta)
	{
	case '!':
		return !b;
		break;
	case '&':
		return a && b;
		break;
	case '|':
		return a || b;
		break;
	case '>':
		if (a == 1 && b == 0)
			return 0;
		else
			return 1;
		break;
	case '~':
		return a == b;
		break;
	default:
		return -1;
		break;
	}
}



int EvaluateExpression(string s)   //�������ʽ��ֵ����������㷨�� OPTR��OPND�ֱ�Ϊ�����ջ��������ջ��
{
	vector <int> OPTR;   //�����
	vector <int> OPND;   //������


	for (unsigned int i = 0; i < s.length(); i++)
	{
		char jud = letters2(s[i]);

		int a = -1;
		int b = -1;
		char theta;

		if (jud == 'N')   //���������������ջ
		{
			OPND.push_back(s[i]);
		}
		else   //�������
			if (OPTR.empty())
				OPTR.push_back(s[i]);   //��һ���޸�
			else
			{
			loc:
				switch (Precede(OPTR.back(), s[i]))   //��һ�ε�ʽ��switch (Precede(OPTR.back(),s[i]))  �����״ε���ʱ������ջ��û��Ԫ�ء�
				{
				case -1:   //ջ��Ԫ������Ȩ��

					OPTR.push_back(s[i]);
					break;

				case 0:   //����Ȩ��ȣ�����ƥ��

					OPTR.pop_back();
					break;

				case 1:   //ջ��Ԫ������Ȩ�ߣ�ִ������

					b = OPND.back();
					OPND.pop_back();

					if (OPTR.back() != '!')   //��Ԫ����
					{
						a = OPND.back();
						OPND.pop_back();
					}

					theta = OPTR.back();
					OPTR.pop_back();

					OPND.push_back(Operate(a, theta, b));

					goto loc;
					break;
				default:
					break;
				}
			}
	}

	return OPND.back();
}

int EEmain(string str)
{

	str = "#" + str + "#";

	return EvaluateExpression(str);
}