#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
// ANSI C++��׼��ͷ�ļ�
#include <cstring>					// ��׼������
#include <iostream>					// ��׼������
using namespace std;				
#define DEFAULT_SIZE 100
// ˳��ջģ����
template<class ElemType>
class SqStack 
{
protected:
// ˳��ջ�����ݳ�Ա:
	int top;										// ջ��ָ�� 
	int maxSize;									// ջ��������� 
	ElemType *data;								// Ԫ�ش洢�ռ�
public:
//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SqStack();				// ���캯��
	
	int getLength() const;							// ��ջ�ĳ���			 
	bool isEmpty() ;							// �ж�ջ�Ƿ�Ϊ��
	void clear();									// ��ջ���
	void traverse(void (*Visit)(const ElemType &)) const;	// ����ջ
	int push(const ElemType e);				    // ��ջ
	ElemType getTop() const;				    // ȡ��Ԫ��
	ElemType pop() ;					    // ��ջ
	SqStack(const SqStack<ElemType> &s);		// ���ƹ��캯��
	SqStack<ElemType> &operator =(const SqStack<ElemType> &s); // ��ֵ�������
};

//���캯��
template<class ElemType>
SqStack<ElemType>::SqStack(){
	int size = DEFAULT_SIZE;
	top = -1;
	maxSize = size;
	data = new ElemType[size];
}

//��ջ�ĳ���
template<class ElemType>
int SqStack<ElemType>::getLength() const{return top+1;}
//�ж�ջ�Ƿ�Ϊ��
template<class ElemType>
bool SqStack<ElemType>::isEmpty(){if(top==-1) return true;
else return false;
}
//��ջ���
template<class ElemType>
void SqStack<ElemType>::clear(){
	while(top!=-1){
		top--;
		delete data[top];
	}
}
//����ջ��Ԫ��
template<class ElemType>
void SqStack<ElemType>::traverse(void (*Visit)(const ElemType &)) const{
	if(top==-1){cout<<"�ձ�"<<endl;}
	for(int i=top ; i>-1;i--){
		Visit(data[i]);
	}
}
//��ջ
template<class ElemType>
int SqStack<ElemType>::push(const ElemType e){
	data[++top] = e;
	return 1;
}
//ȡ��Ԫ��
template<class ElemType>
ElemType SqStack<ElemType>::getTop() const{
	ElemType e = data[top];
	return e;
}
//��ջ
template<class ElemType>
ElemType SqStack<ElemType>::pop() {
	ElemType e;
	e = data[top];
	top--;
	return e;
}
//���ƹ��캯��
template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType> &s){
	top = s.top;
	while(s.top!=-1&&top!=-1){
		data[top] = s.data[s.top];
		top--;s.top--;
	}
}
//��ֵ�������
template<class ElemType>
SqStack<ElemType>& SqStack<ElemType>::operator=(const SqStack<ElemType> &s){
	SqStack<ElemTyep> a;
	a.top = s.top;
	while(s.top!=-1&&a.top!=-1){
		a.data[top] = s.data[s.top];
		a.top--;s.top--;
	}
	return a;
}
#endif
