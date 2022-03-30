#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<set>
#include "publicFun.h"   //letters

using namespace std;

using std::vector;


bool parenthesis_matching(string str)   //����ƥ�䣬��ȷ����True������ȷ����False
{
    //ʹ�������ջS��������'('��'['ʱ��ջ������')'��']'��ջ���жϳ�ջԪ���Ƿ�Ϊ��Ӧ�ķ��ţ�
    //�����������һ���������㷨����

    int state = 1; //�ж��Ƿ�ƥ�䣬1ƥ�䣬0��ƥ��


    str="("+str+")";   //��ֹ�Կ�ջ���в���


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


void trasform(string &str)   //Ϊ�˱��ڼ��㣬���ڽ�'->','<->'ת��Ϊ�����ַ�'>','~'
{
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == '-')
        {
            if (str[i - 1] == '<')   //'<->'
            {
                str[i - 1] = '~';
                str.erase(i, 2);   //��<->�е�'<'��Ϊ~,��ɾ�������'->'
            }
            else   //'->'
            {
                str.erase(i, 1);   //ɾ��'-'
            }
        }
    }
}

int incorrectCh(string str)   //�������Υ���ַ�
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



int valid_expressions(string str)  //�жϱ��ʽ�Ϸ����Ϸ�����0�����Ϸ����ص�һ�����������λ��
{

    for (int i = 0; i < (int)str.length() - 1; i++)   //str.length()-1�����һ������Ҫ�ж�
    {
        char newChar;   //�������࣬�����жϵ����ַ�
        char nextChar;   //��һ�����ַ�

        newChar = letters(str[i]);
        nextChar = letters(str[i + 1]);

        switch (newChar)
        {
        case 'L':   //��ĸ
            if (nextChar == ')' || nextChar == 'O')   //�Ϸ�
                ;
            else
            {
                return i + 1;
            }
            break;
        case 'O':   //��Ԫ�����
            if (nextChar == '(' || nextChar == '!' || nextChar == 'L')   //�Ϸ�
                ;
            else
            {
                return i + 1;
            }
            break;
        case '!':   //!
            if (nextChar == '(' || nextChar == '!' || nextChar == 'L')   //�Ϸ�
                ;
            else
            {
                return i + 1;
            }
            break;
        case '(':   //(
            if (nextChar == '(' || nextChar == '!' || nextChar == 'L')   //�Ϸ�
                ;
            else
            {
                return i + 1;
            }
            break;
        case ')':   //)
            if (nextChar == ')' || nextChar == 'O')   //�Ϸ�
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
    if (parenthesis_matching(str))   //����ƥ����ȷ
        ;
    else
    {
        state="The parethesises in the expression has not a correct matching!";

        //cout << "The parethesises in the expression has not a correct matching!" << endl;
        return 0;
    }

    trasform(str);   //ת���ַ��������ڼ���Ϸ�
    getLocation = valid_expressions(str);
    locate=getLocation+48;

    if (!getLocation)   //���ʽ�Ϸ�
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
