#include<iostream>
#include<cstring>
#include<set>

using namespace std;

string changeCh(set <char> s, string str, int arr[])   //����set��˳�򽫱�Ԫ�����е�ֵ�滻�����봮����ĸ
{
	set<char>::iterator it;
    
	int loc = 0;
	it = s.begin();
	int n = s.size();   //nΪ��ĸ��

	while (n--)   //ִ��n�Σ�ÿ���滻���ַ����е�һ����ĸ
	{

		for (unsigned int i = 0; i < str.length(); i++)   //�����ַ�����ÿһ���ַ�
		{

				if (str[i] == *it)   //���Ŀǰ���ַ�str[i]���������ǰָ��set�е��ַ���ͬ
					str[i] = arr[loc];   //����ֵ���е���ֵ��������ַ�
			
		}
		
		loc++;   //��һ����ֵ
		it++;   //��һ����ĸ
	}

	return str;

}

char letters(char ch)   //Ϊ�˱���switch����ʹ�ã����ַ�����
{
	if (ch >= 'A'&&ch <= 'Z')   //��ĸ
		return 'L';   //letter
	if (ch == '&' || ch == '|' || ch == '>' || ch == '~')   //��Ԫ�����
		return 'O';   //operator
	else   //һԪ�����'!'��'('��')'
		return ch;
}

char letters2(char ch)   //Ϊ�˱���switch����ʹ�ã����ַ�����
{
	if (ch == 0 || ch == 1)   //������
		return 'N';   //letter
	if (ch == '&' || ch == '|' || ch == '>' || ch == '~')   //��Ԫ�����
		return 'O';   //operator
	else   //һԪ�����'!'��'('��')'
		return ch;
}

