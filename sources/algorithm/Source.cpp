#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<set>
#include<cmath>

#include "publicFun.h"
#include "CheckExpression.h"
#include "EvaluateExpression.h"
#include "PDNF.h"
#include "TruthTable.h"
#include "mainwindow.h"

using namespace std;

//set <char> setAlpha;   //��ű�Ԫ��ĸ��set

int AlphaNum(string str)   //�鿴str���м�����Ԫ
{

    for (unsigned int i = 0; i < str.length(); i++)
        if (isupper(str[i]))
            MainWindow::setAlpha.insert(str[i]);

    return MainWindow::setAlpha.size();
}

int SourceMain(string str,string &state)//�����ַ���
{
    MainWindow::setAlpha.clear();//ÿ�ε������������set

    //cin >> str;

    //1.�����ʽ�Ϸ��ͱ�Ԫ����
    int num=AlphaNum(str);   //��Ԫ����
    int n = pow(2, num);   //��ֵ������

    if (num > 4||num==0)
    {
        state="There are more than 4 variables or no variables in the input!";

        //cout << "There are more than 4 variables or no variables in the input!" << endl;
        //system("pause");

        return 0;
    }

    if (CEmain(str,state))
        ;
    else
    {
        //system("pause");
        return 0;
    }

    //2.������ֵ����С������
    //int** arr;   //��ֵ��

    //string* arrstr = {};   //С������

    make_Truthtable(MainWindow::arr, num);

    make_AlphaArr(MainWindow::arr, MainWindow::arrstr, n, num, MainWindow::setAlpha);

    //2.������ȡ��ʽ
    string strPDNF = {};

    strPDNF = PDNF(str, MainWindow::arr, num, MainWindow::setAlpha, MainWindow::arrstr);

    state=strPDNF;

    //cout << strPDNF << endl;

/*
    show_arrstr(arrstr, n);
    show_Truthtable(arr, n, num);
*/

    //system("pause");

    return 1;

}
