#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

void arr_assign(int*, int* &, int);


void make_Truthtable(int** &, int );   //������ֵ��ı�Ԫ����


void show_Truthtable(int **&, int, int);   //��ӡn��m����ֵ��


void make_AlphaArr(int**, string* &, int, int, set <char>);   //�������С�������   n=m^2 m��Ԫ��

void show_arrstr(string*, int);   //��ӡС������
