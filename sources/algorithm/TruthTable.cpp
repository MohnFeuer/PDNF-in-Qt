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

void make_Truthtable(int** &arr, int num)   //������ֵ��ı�Ԫ����
{
	int n = pow(2, num);

	arr = (int**)malloc(n * sizeof(int*));   //����ͷ����2^num�ռ�
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(num * sizeof(int));   //��ÿ�з���num�ռ�

	for (int i = 0; i < n; i++)
		for (int j = 0; j < num; j++)
			arr[i][j] = 0;   //��ά����ȫ����ʼ��Ϊ0

	for (int i = 1; i < n; i++)    //ģ������ƣ�����01
	{
		arr_assign(arr[i - 1], arr[i], num);
		arr[i][num - 1] += 1;   //���һ������һ

		for (int j = num - 1; j > 0; j--)  //����ÿ�У��Ӻ���ǰֱ���ڶ���
		{
			if (arr[i][j] == 2)   //�����һ
			{
				arr[i][j] = 0;
				arr[i][j - 1] += 1;
			}
		}
	}

}

void show_Truthtable(int **&arr, int n, int m)   //��ӡn��m����ֵ��
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}

void make_AlphaArr(int** arr, string* &arrstr, int n, int m,set <char> setAlpha)   //�������С�������   n=m^2 m��Ԫ��
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

void show_arrstr(string* arrstr, int n)   //��ӡС������
{
	for (int i = 0; i < n; i++)
		cout << arrstr[i] << endl;
}