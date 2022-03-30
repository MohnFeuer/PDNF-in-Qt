#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>

#include "publicFun.h"

using namespace std;

int data_Precede[8][8] =   //优先级二维数组
{   //!  &  | -> <-> (  )  #
	{-1, 1, 1, 1, 1,-1, 1, 1},//!
	{-1, 1, 1, 1, 1,-1, 1, 1},//&
	{-1,-1, 1, 1, 1,-1, 1, 1},//|
	{-1,-1,-1, 1, 1,-1, 1, 1},//->
	{-1,-1,-1,-1, 1,-1, 1, 1},//<->
	{-1,-1,-1,-1,-1,-1, 0, 0},//(
	{ 1, 1, 1, 1, 1, 0, 1, 1},//)
	{-1,-1,-1,-1,-1,-1, 0, 0}//#
};  //6,8  7,6   8,7中的0只是用于占位，实际情况不会出现

int Precede(char op1, char op2)   //1：op1>op2 栈顶操作符大于目前操作符;  0：op1=op2 ;   -1: op1<op2 ; 
{
	int row;
	int col;

	switch (op1)   //操作符1
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

	switch (op2)   //操作符2
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



int EvaluateExpression(string s)   //算术表达式求值的算符优先算法。 OPTR和OPND分别为运算符栈和运算数栈。
{
	vector <int> OPTR;   //运算符
	vector <int> OPND;   //运算数


	for (unsigned int i = 0; i < s.length(); i++)
	{
		char jud = letters2(s[i]);

		int a = -1;
		int b = -1;
		char theta;

		if (jud == 'N')   //若是运算数，则进栈
		{
			OPND.push_back(s[i]);
		}
		else   //是运算符
			if (OPTR.empty())
				OPTR.push_back(s[i]);   //第一次修改
			else
			{
			loc:
				switch (Precede(OPTR.back(), s[i]))   //第一次调式：switch (Precede(OPTR.back(),s[i]))  错误，首次调用时，操作栈中没有元素。
				{
				case -1:   //栈顶元素优先权低

					OPTR.push_back(s[i]);
					break;

				case 0:   //优先权相等，括号匹配

					OPTR.pop_back();
					break;

				case 1:   //栈顶元素优先权高，执行运算

					b = OPND.back();
					OPND.pop_back();

					if (OPTR.back() != '!')   //二元运算
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