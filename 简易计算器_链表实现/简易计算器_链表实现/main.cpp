#include<iostream>
#include"Node.h"
#include"SqStack.h"
#include<string>
using namespace std;
void change(string &l);//讲中缀表达式转换成入赘表达式
void caul(string l);//计算后缀表达式;
int get(char a, char b ,char c);//简单计算
SqStack<char> list;
SqStack<int>behindList;//栈的初始化
int main(){

	string a;
	cout<<"请输入中缀表达式"<<endl;
	cin>>a;
	cout<<"中缀表达式转换为后缀表达式的结果如下"<<endl;
	change(a);
	string b;
	cout<<"请输入后缀表达式";
	cin>>b;
	cout<<"后缀表达式计算结果如下"<<endl;
	caul(b);
	system("pause");
	return 0;
}
//简单计算的定义,a,b是数字，c是操作符
int get(int a, int b ,char c){

	switch(c){
	case '+':  return  a+b;break;
	case '-':   return a-b;break;
	case '*':   return a*b;break;	
	case '/':   return a/b;break; 
	}
}
//计算后缀表达式定义
void caul(string l){
	for(int i = 0 ; i<l.length() ;i++){
		if(l[i]=='0'||l[i]=='1'||l[i]=='2'||l[i]=='3'||l[i]=='4'||l[i]=='5'||l[i]=='6'||l[i]=='7'||l[i]=='8'||l[i]=='9') {behindList.push(l[i]-'0');}
		if(l[i]=='+'||l[i]=='-'||l[i]=='*'||l[i]=='/'){int a=behindList.pop();int b =behindList.pop();behindList.push(get(a,b,l[i]));}
	}
	cout<<behindList.getTop()<<endl;
}
//中缀转前缀定义
void change(string &l){
	for(int i = 0;i<l.length();i++){
		if(l[i]=='0'||l[i]=='1'||l[i]=='2'||l[i]=='3'||l[i]=='4'||l[i]=='5'||l[i]=='6'||l[i]=='7'||l[i]=='8'||l[i]=='9')  {cout<<l[i];}//如果是数字直接输出
		//如果是操作符
		else{
			if(l[i]=='(')  list.push(l[i]);//如果是左括号入栈
			if(l[i]==')')	{ 
				while(list.getTop()!='(')
					{cout<<list.pop();}
					list.pop();
							} 
			if(l[i]=='+'||l[i]=='-') {while(list.getTop()=='+'||list.getTop()=='-'||list.getTop()=='*'||list.getTop()=='/'){cout<<list.pop();} list.push(l[i]);} 
			if(l[i]=='*'||l[i]=='/')  {while(list.getTop()=='*'||list.getTop()=='/'){cout<<list.pop();} list.push(l[i]);}
		}


	}
	list.isEmpty()?cout<<endl:cout<<list.pop();
}