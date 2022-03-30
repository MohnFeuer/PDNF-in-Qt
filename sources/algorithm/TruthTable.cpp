#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

void arr_assign(int* arr1, int* &arr2, int len)
{
	for (int i = 0; i < len; i++)
		arr2[i] = arr1[i];
}

void make_Truthtable(int** &arr, int num)   //制作真值表的变元部分
{
	int n = pow(2, num);

	arr = (int**)malloc(n * sizeof(int*));   //给行头分配2^num空间
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(num * sizeof(int));   //给每行分配num空间

	for (int i = 0; i < n; i++)
		for (int j = 0; j < num; j++)
			arr[i][j] = 0;   //二维数组全部初始化为0

	for (int i = 1; i < n; i++)    //模拟二进制，排列01
	{
		arr_assign(arr[i - 1], arr[i], num);
		arr[i][num - 1] += 1;   //最后一个数加一

		for (int j = num - 1; j > 0; j--)  //对于每行，从后往前直到第二个
		{
			if (arr[i][j] == 2)   //逢二进一
			{
				arr[i][j] = 0;
				arr[i][j - 1] += 1;
			}
		}
	}

}

void show_Truthtable(int **&arr, int n, int m)   //打印n行m列真值表
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

void make_AlphaArr(int** arr, string* &arrstr, int n, int m,set <char> setAlpha)   //建立存放小项的数组   n=m^2 m变元数
{
	arrstr = new string[n];

	for (int i = 0; i < n; i++)
	{
		set<char>::iterator ite1 = setAlpha.begin();
		string str;

		str += '(';
		for (int j = 0; j < m; j++)
		{
			char ch = *ite1;

			if (arr[i][j] == 0)
			{
				str += "!";
				str += ch;
				str += "&";
			}
			else
			{
				str += " ";
				str += ch;
				str += "&";
			}

			ite1++;

		}
		

		str.pop_back();
        str += ')';

		arrstr[i] = str;
	}

}

void show_arrstr(string* arrstr, int n)   //打印小项数组
{
	for (int i = 0; i < n; i++)
		cout << arrstr[i] << endl;
}