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

//set <char> setAlpha;   //存放变元字母的set

int AlphaNum(string str)   //查看str中有几个变元
{

    for (unsigned int i = 0; i < str.length(); i++)
        if (isupper(str[i]))
            MainWindow::setAlpha.insert(str[i]);

    return MainWindow::setAlpha.size();
}

int SourceMain(string str,string &state)//输入字符串
{
    MainWindow::setAlpha.clear();//每次调用主函数清空set

    //cin >> str;

    //1.检查表达式合法和变元个数
    int num=AlphaNum(str);   //变元个数
    int n = pow(2, num);   //真值表行数

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

    //2.建立真值表与小项数组
    //int** arr;   //真值表

    //string* arrstr = {};   //小项数组

    make_Truthtable(MainWindow::arr, num);

    make_AlphaArr(MainWindow::arr, MainWindow::arrstr, n, num, MainWindow::setAlpha);

    //2.求主析取范式
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
