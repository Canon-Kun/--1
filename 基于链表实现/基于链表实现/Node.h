//Node.h

#ifndef __NODE_H__
#define __NODE_H__
#include<string>
#include<iostream>
using namespace std;
//ѧ����Ľṹ��
 typedef struct {
	int num;
	double grade;
	string name;
}student;
// �����
template <class ElemType>
struct Node 
{
// ���ݳ�Ա:
	ElemType data;				// ������
	Node<ElemType> *next;		// ָ����
// ���캯��:
	Node();						// �޲����Ĺ��캯��
	Node(ElemType e, Node<ElemType> *link = NULL);	// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
};
//�޲εĹ��캯��
template<class ElemType>
Node<ElemType>::Node(){
	next = NULL;
}
//��֪����Ԫ��ֵ��ָ�뽨���ṹ
template<class ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType> *link = NULL) {
	data = e;
	head = link;
}



#endif