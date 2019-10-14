#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
// ANSI C++��׼��ͷ�ļ�
#include <cstring>
#include"Node.h"				// ��׼������
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
								 
	Node<ElemType> *head;					
public:
//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SqStack();				// ���캯��
	int getLength() const;							// ��ջ�ĳ���			 
	bool isEmpty() ;							// �ж�ջ�Ƿ�Ϊ��
	void clear();									// ��ջ���
	void traverse(void (*Visit)(const ElemType &)) const;	// ����ջ
	int push(const ElemType e);				    // ��ջ
	ElemType getTop();				    // ȡ��Ԫ��
	ElemType pop();					    // ��ջ
	SqStack(const SqStack<ElemType> &s);		// ���ƹ��캯��
	SqStack<ElemType> &operator =(const SqStack<ElemType> &s); // ��ֵ�������
};
//���캯��
template<class ElemType>
SqStack<ElemType>::SqStack(){
	top=-1;
	head = new Node<ElemType>;
	head->next = NULL;
	
}
//��ջ�ĳ���
template<class ElemType>
int SqStack<ElemType>::getLength() const{
	return top+1;
}
//�ж�ջ�Ƿ�Ϊ��
template<class ElemType>
bool SqStack<ElemType>::isEmpty() {if(top==-1) return true;else return false;}
//����ջ
template<class ElemType>
void SqStack<ElemType>::traverse(void (*Visit)(const ElemType &)) const{
	Node<ElemType> *p = head;
	while(p){Visit(p->data),p=p->next}
}
//��ջ
template<class ElemType>
int SqStack<ElemType>::push(const ElemType e){
	Node<ElemType> *p = head;
	Node<ElemType> *q = new Node<ElemType> ;
	if(p->next==NULL){
		q->data = e;
		q->next = NULL;
		p->next=q;
		top++;
		return 1;
	}
	while(p->next!=NULL){	
		p = p->next;//�����ƶ������һλ��
	}
		q->data = e;
		q->next = NULL;
		p->next = q;
		top++;
	return 1;
}
//ȡջ��Ԫ��
template<class ElemType>
ElemType SqStack<ElemType>::getTop(){
	Node<ElemType>* p = head;
	while(p->next!=NULL){p=p->next;}
	return p->data;
}
//��ջ
template<class ElemType>
ElemType SqStack<ElemType>::pop(){
	Node<ElemType>* q=head;
	
	while(q->next->next){q=q->next;}
	ElemType e =q->next->data ;
	q->next = q->next->next;
	top--;
	return e;
}
//���ƹ��캯��
template<class ElemType>
SqStack<ElemType>::SqStack(const SqStack<ElemType> &s){
	Node<ElemType> *p1 = head;
	Node<ElemType> *p2 = s.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	top = s.top;

}
//���������
template<class ElemType>
SqStack<ElemType> & SqStack<ElemType>::operator =(const SqStack<ElemType> &s)
{
	SqStack<ElemType> a;
	a.top = s.top;
	Node<ElemType> *p1 = a.head;
	Node<ElemType> *p2 = s.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	return a;
}
#endif
