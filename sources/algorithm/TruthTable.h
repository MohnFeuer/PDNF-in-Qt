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


void make_Truthtable(int** &, int );   //制作真值表的变元部分


void show_Truthtable(int **&, int, int);   //打印n行m列真值表


void make_AlphaArr(int**, string* &, int, int, set <char>);   //建立存放小项的数组   n=m^2 m变元数

void show_arrstr(string*, int);   //打印小项数组
