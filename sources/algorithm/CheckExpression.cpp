#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include "publicFun.h"   //letters

using namespace std;

using std::vector;


bool parenthesis_matching(string str)   //括号匹配，正确返回True，不正确返回False
{
    //使用运算符栈S，当遇到'('、'['时进栈，遇到')'、']'出栈并判断出栈元素是否为相应的符号，
    //若是则继续下一个，否则算法结束

    int state = 1; //判断是否匹配，1匹配，0不匹配


    str="("+str+")";   //防止对空栈进行操作


    vector<int> stack;

    for (int i = 0; str[i] != '\0'; i++)
    {
        switch (str[i])
        {
        case'(':
            stack.push_back(str[i]);
            continue;
        case'[':
            stack.push_back(str[i]);
            continue;
        case')':
            if (stack.back() != '(')
                state = 0;
            stack.pop_back();
            break;
        case']':
            if (stack.back() != '[')
                state = 0;
            stack.pop_back();
            break;
        }
        if (!state)
            break;
    }
    if (stack.empty() && state == 1)
        return true;
    else
        return false;
}


void trasform(string &str)   //为了便于计算，用于将'->','<->'转化为单个字符'>','~'
{
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == '-')
        {
            if (str[i - 1] == '<')   //'<->'
            {
                str[i - 1] = '~';
                str.erase(i, 2);   //把<->中的'<'换为~,再删除后面的'->'
            }
            else   //'->'
            {
                str.erase(i, 1);   //删除'-'
            }
        }
    }
}

int incorrectCh(string str)   //检查有无违法字符
{
    for (int i = 0; i < str.length(); i++)
    {
        if((str[i]>='A'&&str[i]<='Z')||str[i]=='!'||str[i]=='&'||str[i]=='|'||str[i]=='('||str[i]==')'||str[i]=='-'||str[i]=='<'||str[i]=='>')
            ;
        else
            return i;
    }

    return -1;
}



int valid_expressions(string str)  //判断表达式合法，合法返回0，不合法返回第一个发生错误的位置
{

    for (int i = 0; i < (int)str.length() - 1; i++)   //str.length()-1，最后一个不需要判断
    {
        char newChar;   //经过归类，用于判断的新字符
        char nextChar;   //下一个新字符

        newChar = letters(str[i]);
        nextChar = letters(str[i + 1]);

        switch (newChar)
        {
        case 'L':   //字母
            if (nextChar == ')' || nextChar == 'O')   //合法
                ;
            else
            {
                return i + 1;
            }
            break;
        case 'O':   //二元运算符
            if (nextChar == '(' || nextChar == '!' || nextChar == 'L')   //合法
                ;
            else
            {
                return i + 1;
            }
            break;
        case '!':   //!
            if (nextChar == '(' || nextChar == '!' || nextChar == 'L')   //合法
                ;
            else
            {
                return i + 1;
            }
            break;
        case '(':   //(
            if (nextChar == '(' || nextChar == '!' || nextChar == 'L')   //合法
                ;
            else
            {
                return i + 1;
            }
            break;
        case ')':   //)
            if (nextChar == ')' || nextChar == 'O')   //合法
                ;
            else
            {
                return i + 1;
            }
            break;
        default:
            break;
        }

    }

    return 0;
}

bool CEmain(string &str,string &state)
{
    int getLocation;
    char locate;

    int lloc=incorrectCh(str);

    if(lloc==-1)
        ;
    else
    {
        char loch=lloc+'1';
        state="there is a illegal character locates in ";
        state+=loch;
        state+=" !";
        return 0;
    }
    if (parenthesis_matching(str))   //括号匹配正确
        ;
    else
    {
        state="The parethesises in the expression has not a correct matching!";

        //cout << "The parethesises in the expression has not a correct matching!" << endl;
        return 0;
    }

    trasform(str);   //转换字符串，用于检验合法
    getLocation = valid_expressions(str);
    locate=getLocation+48;

    if (!getLocation)   //表达式合法
        ;
    else
    {
        state="The character locates in ";
        state+= locate;
        state+= " and ";
        state+= locate+1 ;
        state+=" violated the rules!";
        //cout << str << endl;
        //cout << "The character locates in " << str[getLocation] << " and " << str[getLocation + 1] << " violated the rules!" << endl;
        return 0;
    }

   // cout << "Pass!" << endl;

    return 1;
}
