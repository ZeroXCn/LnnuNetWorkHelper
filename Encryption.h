#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <string>
using namespace std;

class Encryption
{
public:
	//���ֱ��뷽ʽ
	/**
	*��򵥵����:A^B=C;C^B=A;
	*
	*/
	static string XOR(string str, string key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			int j = i%key.length();
			char tch = str.at(i) ^ key.at(j);

			Code += tch;
		}
		return Code;
	}
	static string EnXOR(string str, string key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			int j = i%key.length();
			char tch = str.at(i) ^ key.at(j);

			Code += tch;
		}
		return Code;
	}

	static string XOR(string str, int key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			char tch = str.at(i) ^ key;

			Code += tch;
		}
		return Code;
	}
	static string EnXOR(string str, int key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			char tch = str.at(i) ^ key;

			Code += tch;
		}
		return Code;
	}
	/**
	*ƫ�Ʒ�:A+B+C=D;D-B-C=A
	*
	*/
	static string Offset(string str, string key, int offset = 0){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			int j = i%key.length();
			char tch = str.at(i) + key.at(j) + offset;

			Code += tch;
		}
		return Code;
	}
	static string EnOffset(string str, string key, int offset = 0){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			int j = i%key.length();
			char tch = str.at(i) - key.at(j) - offset;

			Code += tch;
		}
		return Code;
	}

	static string Offset(string str, int key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			char tch = str.at(i) + key;

			Code += tch;
		}
		return Code;
	}
	static string EnOffset(string str, int key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			char tch = str.at(i) - key;

			Code += tch;
		}
		return Code;
	}

	/*
	*�����㷨Ӧ����F(a,b)=c	����a,b,c����[33,126]
	*/

	/**
	*�۰뷨:(a+b)/2=c,a=2c-b
	*��Ϊ��С���Ĺ�ϵ,����ת�巨���ת���ַ��������ΪС��,����ʱӦ����0.5
	*(33+34)/2=33.5 �����ת��"/"�����33�ַ�,����ʱ���ȶ�"/"��ʾ��ת�Ƽ���0.5�ڼ���
	*���ǡ��Ϊת���ַ�,���滻Ϊ���ɼ�31(����Ӧ�ú�С),����31��ʾ��ת���ַ����
	*����������key[j]��ת���ַ�
	*
	*/
	static string Binary(string str, string key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			int j = i%key.length();
			char tch; float result;

			result = (str.at(i) + key.at(j)) / 2.0;
			tch = (int)result;
			if ((float)((float)result - (int)result)>0){	//�۰���С��
				Code += key.at(j);//ȡkey��j����ת��
			}
			else{
				//����ת��,����ǡ��Ϊת���ַ�,��ת��
				if (tch == key.at(j))tch = 31;	//����31���ɼ�,�´�����31ֱ��
			}
			Code += tch;
		}
		return Code;
	}

	static string EnBinary(string str, string key){
		string Code = ""; int k = 0;
		for (int i = 0; i<str.length(); i++){
			int j = k%key.length();
			char tch; float result = 0;

			//ת���ַ�ֱ�ӵ�������
			if (str.at(i) != 31){
				//����ת���ַ�ʱ
				if (str.at(i) == key.at(j)){
					i++;
					result += 0.5 + str.at(i);//��ԭ
				}
				else result += str.at(i);//û��ת���»�ԭ				
				tch = (int)(2 * result - key.at(j));
			}
			else tch = key.at(j);
			Code += tch;
			k++;
		}

		return Code;
	}

};

#endif