#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int Number, Type, MaxNum, printType, Bracket, PerNumber;//����Ϊ������ʽ����������ʽ�������͡�������㷶Χ��������͡��Ƿ�������š���ʽ�����ֵ�������
string suanshi[100];//��������ʽ�ļ���
int NeedFloat; //�Ƿ���ҪС����
void UserChoice()
{
	printf("��ӭʹ��Сѧ���������Զ����ɳ���\n");
	printf("��������Ҫ������ʽ��������\n");
	scanf("%d", &Number);
	printf("��ѡ����Ҫ������ʽ���������ͣ�1 �ӷ�,2 ����,3 �˷�,4 ����,5�Ӽ���ϣ�6�˳���ϣ�7�Ӽ��˳����\n");
	scanf("%d", &Type);
	printf("��������ʽ��������Χ(����10��100��1000.....)��\n");
	scanf("%d", &MaxNum);
	printf("�Ƿ�������ţ�1 ������2 ������\n");
	scanf("%d", &Bracket);
	printf("ÿ����ʽ�����������ֵĸ�����\n");
	scanf("%d", &PerNumber);
	printf("�Ƿ����С����1 �ǣ�2��\n");
	scanf("%d", &NeedFloat);
	printf("��ѡ�������ʽ��1 �������Ļ,2 ������ļ�\n");
	scanf("%d", &printType);
}
float RandDigit()//���������
{
	return rand() % MaxNum + 1;//�������0��
}
/*���������λС���ĸ�����*/
float RandFloat()
{
	return (rand() % (MaxNum * 100)) / 100.00;
}
/*�������ÿ����ʽ�а������ĸ���*/
int RandPerNumber()
{
	return rand() % PerNumber + 1;
}
/*����������������*/
int RandTwo()
{
	return rand() % 2;
}
/*��n=1ʱ������+����n=2ʱ������-����n=3ʱ������*����n=4ʱ������/��
��n=5ʱ������+��-����n=6ʱ������*��/����n=7ʱ������+��-��*��/��*/
char RandOperator()
{
	int n = Type;
	if (n == 1)
	{
		return '+';
	}
	if (n == 2)
	{
		return '-';
	}
	if (n == 3)
	{
		return '*';
	}
	if (n == 4)
	{
		return '/';
	}
	if (n == 5)
	{
		if (RandTwo() == 0)
		{
			return '+';
		}
		else
		{
			return '-';
		}
	}
	if (n == 6)
	{
		if (RandTwo() == 0)
		{
			return '*';
		}
		else
		{
			return '/';
		}
	}
	if (n == 7)
	{
		int temp = rand() % 4;
		if (temp == 1)
		{
			return '+';
		}
		else if (temp == 2)
		{
			return '-';
		}
		else if (temp == 3)
		{
			return '*';
		}
		else
		{
			return '/';
		}
	}
}
/*
itoa�������÷���
itoa(i ,num ,10 );
i ---- ��Ҫת�����ַ�������
num ---- ת���󱣴��ַ����ı���
10 ---- ת�����ֵĻ����������ƣ���10����˵��10����ת�����֡���������2��8��16�ȵ���ϲ���Ľ�������
����ֵ��ָ��num����ַ�����ָ��
*/
/*
_gcvt_s�������÷���
_gcvt_s(char* _Buffer, size_t _BufferCount, double _Value, int _DigitCount);
˵������ʾ�����š�С����
_Digitcount����ʾ��λ������1.25����ʾ��λ��1.3���������룩����ʾ��λ��1.25
_Value:��Ҫת�����ַ����ĸ�����
*/
/*������ת��Ϊ�ַ���*/
string int_string(float number)
{
	float temp = fabs(number);
	char str[200];
	if (NeedFloat == 1)
	{
		_gcvt_s(str, sizeof(str), temp, 7);//��������ת��Ϊ�ַ����������������ź�С����
	}
	else
	{
		_itoa(temp, str, 10);//��tempǿ��ת��Ϊ����Ȼ��ת��Ϊ�ַ���
	}
	string str_ = str;
	return str_;
}
/*������string�ͱ�����Ϊһ��*/
string combination(string str1, string str2, char k)
{
	string equation;
	equation = str1 + k + str2;
	return equation;
}
float Returnfloat()
{
	if (NeedFloat == 1)
	{
		return RandFloat();
	}
	else
	{
		return RandDigit();
	}
}
/*������ʽ�㷨*/
void Produce()
{
	int itemp = 0;//��¼�Ѿ���������ʽ�ĸ���
	float num1, num2;//�����������
	char symbol;//���ܷ��ص������
	string str_num1, str_num2;//��������������ַ�������ʽ
	while (itemp < Number)
	{
		num1 = Returnfloat();
		num2 = Returnfloat();
		symbol = RandOperator();
		str_num1 = int_string(num1);
		str_num2 = int_string(num2);
		suanshi[itemp] = combination(str_num1, str_num2, symbol);//��ʽ�е���Ϊ����ʱ��
		int count = RandPerNumber();//ÿ����ʽ�а������ĸ�����
		/*
		����ʽ�е�������2��ʱ
		*/
		if (count > 2)
		{
			for (count; count > 2; count--)
			{
				symbol = RandOperator();
				str_num1 = suanshi[itemp];
				if (Bracket == 1)//�û������Ƿ���Ҫ����
				{
					if (RandTwo() == 0)//�����������
					{
						str_num1 = '(' + str_num1 + ')';
					}
				}
				num2 = Returnfloat();
				str_num2 = int_string(num2);
				if (RandTwo() == 0)//������²����������������ŵ�ǰ��
				{
					suanshi[itemp] = combination(str_num2, str_num1, symbol);
				}
				else
				{
					suanshi[itemp] = combination(str_num1, str_num2, symbol);
				}
			}
		}
		itemp++;
	}
}
/*�����ɵ���ʽ��ӡ*/
void Display()
{
	int i;
	if (printType == 1)
	{
		cout << "������ʽ����" << endl;
		for (i = 0; i < Number; i++)
		{
			cout << suanshi[i] << "=" << endl;
		}
	}
	else
	{
		ofstream fp;
		fp.open("������ʽ.txt");
		fp << "������ʽ���£�" << endl;
		for (i = 0; i < Number; i++)
		{
			fp << suanshi[i] << "=" << endl;
		}
		fp.close();
	}
}
int main()
{
	srand((int)time(NULL));  //����ʱ������ ��ʹ�ó���ÿ�����еĽ������ͬ 
	UserChoice();
	Produce();
	Display();
	system("pause");
	return 0;
}

