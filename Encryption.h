#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include <string>
using namespace std;

class Encryption
{
public:
	//各种编码方式
	/**
	*最简单的异或法:A^B=C;C^B=A;
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
	*偏移法:A+B+C=D;D-B-C=A
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
	*其他算法应满足F(a,b)=c	其中a,b,c属于[33,126]
	*/

	/**
	*折半法:(a+b)/2=c,a=2c-b
	*因为有小数的关系,采用转义法输出转义字符代表这个为小数,计算时应加上0.5
	*(33+34)/2=33.5 先输出转义"/"在输出33字符,读入时则先读"/"表示有转移加上0.5在计算
	*如果恰巧为转义字符,则替换为不可见31(概率应该很小),读到31表示与转义字符相等
	*本函数采用key[j]做转义字符
	*
	*/
	static string Binary(string str, string key){
		string Code = "";
		for (int i = 0; i<str.length(); i++){
			int j = i%key.length();
			char tch; float result;

			result = (str.at(i) + key.at(j)) / 2.0;
			tch = (int)result;
			if ((float)((float)result - (int)result)>0){	//折半有小数
				Code += key.at(j);//取key第j个做转义
			}
			else{
				//不用转义,但若恰好为转义字符,再转义
				if (tch == key.at(j))tch = 31;	//换成31不可见,下次碰见31直译
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

			//转义字符直接等于它了
			if (str.at(i) != 31){
				//遇到转义字符时
				if (str.at(i) == key.at(j)){
					i++;
					result += 0.5 + str.at(i);//还原
				}
				else result += str.at(i);//没有转义下还原				
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