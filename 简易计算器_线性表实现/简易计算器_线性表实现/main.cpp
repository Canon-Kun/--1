#include<iostream>
#include"SqStack.h"
#include<string>
/*
��׺ת��׺C++����ʵ��(�ȽϷ���)
1.��������������ӵ���׺���ʽ�л�ֱ�����
2.ջ��ʱ�������������ֱ����ջ
3.���������ţ�������ջ
4.���������ţ�ִ�г�ջ�������������׺���ʽ��ֱ����������������
ע�⣺�����Ų��������׺���ʽ
5.��������������������������ȼ����ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ
6.��ջ��ʣ���������ε�����׺���ʽ
*/
//*************************************************************
//��׺���ʽ�ļ���
/*
������ɨ���׺���ʽ
1�����ǲ���������ѹջ��
2�����ǲ���������������������������
3��ջ����ֵ��Ϊ������
ע���ȵ������ǵ�һ���������󵯳����ǵڶ�������
*/

using namespace std;
void change(string &l);//����׺���ʽת������׸���ʽ
void caul(string l);//�����׺���ʽ;
int get(char a, char b ,char c);//�򵥼���
SqStack<char> list;
	SqStack<int>behindList;//ջ�ĳ�ʼ��
int main(){
	/*string a,b;
	cout<<"��������׺���ʽ"<<endl;
	cin>>a;
	cout<<"��׺���ʽת��Ϊ��׺���ʽ�Ľ������"<<endl;
	change(a);*/
	string b;
	cout<<"�������׺���ʽ";
	cin>>b;
	cout<<"��׺���ʽ����������"<<endl;
	caul(b);
	system("pause");
	return 0;

}
//�򵥼���Ķ���,a,b�����֣�c�ǲ�����
int get(int a, int b ,char c){

	switch(c){
	case '+':  return  a+b;break;
	case '-':   return a-b;break;
	case '*':   return a*b;break;	
	case '/':   return a/b;break; 
	}
}
//�����׺���ʽ����
void caul(string l){
	for(int i = 0 ; i<l.length() ;i++){
		if(l[i]=='0'||l[i]=='1'||l[i]=='2'||l[i]=='3'||l[i]=='4'||l[i]=='5'||l[i]=='6'||l[i]=='7'||l[i]=='8'||l[i]=='9') {behindList.push(l[i]-'0');}
		if(l[i]=='+'||l[i]=='-'||l[i]=='*'||l[i]=='/'){int a=behindList.pop();int b =behindList.pop();behindList.push(get(a,b,l[i]));}
	}
	cout<<behindList.getTop()<<endl;
}
//��׺תǰ׺����
void change(string &l){
	for(int i = 0;i<l.length();i++){
		if(l[i]=='0'||l[i]=='1'||l[i]=='2'||l[i]=='3'||l[i]=='4'||l[i]=='5'||l[i]=='6'||l[i]=='7'||l[i]=='8'||l[i]=='9')  {cout<<l[i];}//���������ֱ�����
		//����ǲ�����
		else{
			if(l[i]=='(')  list.push(l[i]);//�������������ջ
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