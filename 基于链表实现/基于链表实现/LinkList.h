#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"	
#include<iostream>// �����

// ��������
template <class ElemType>
class LinkList 
{
protected:
//  ����������ݳ�Ա
	Node<ElemType> *head;				// ͷ���ָ��
	int length;					// �������� 

public:
//  ������ĺ�����Ա 
	LinkList();							// �޲����Ĺ��캯��
	LinkList(ElemType v[], int n);		// �в����Ĺ��캯��
	
	int GetLength() const;				// ��������			 
	bool IsEmpty() const;	 			// �жϵ������Ƿ�Ϊ��
	void Clear();						// �����������
	void Traverse(void (*Visit)(const ElemType &)) const;// ����������
	int LocateElem(const ElemType &e) const;	         // Ԫ�ض�λ 
	ElemType GetElem(int index) const;	 // ��ָ��λ�õ�Ԫ��	
	int SetElem(int index, const ElemType &e);	 // ����ָ��λ�õ�Ԫ��ֵ
	int DeleteElem(int index);		 // ɾ��Ԫ��		
	int InsertElem(int index, const ElemType &e);	 // ���ƶ�λ�ò���Ԫ��
	int InsertElem(const ElemType &e);	             // �ڱ�β����Ԫ��
	LinkList(const LinkList<ElemType> &la);            // ���ƹ��캯��
	LinkList<ElemType> &operator =(const LinkList<ElemType> &la); // ���ظ�ֵ���� 
};
//�޲ι��캯��
template<class ElemType>
LinkList<ElemType>::LinkList(){
	head = new Node<ElemType>;
	head->next = NULL;
	length = 0;

}
//�в������캯��
template<class ElemType>
LinkList<ElemType>::LinkList(ElemType v[] , int n ){

	head = new ElemType v[];
	length = n;
}
//����������..
template<class ElemType>
int LinkList<ElemType>::GetLength()const{
	return length;

}
//�ж���������Ƿ�Ϊ�ձ�
template<class ElemType>
bool LinkList<ElemType>::IsEmpty()const{
	length==0?true:false;
}
//�������
template<class ElemType>
void LinkList<ElemType>::Clear(){
	Node<ElemType> *p = head->next;
	while(head->next!=NULL && p->next!=NULL){
		head->next = p->next;
		delete p ;
		p = head->next;
	}
	head->next = NULL;
	delete p;

	length = 0;
}
//��������
template<class ElemType>
void LinkList<ElemType>::Traverse(void (*Visit)(const ElemType &)) const{
Node<ElemType> *p= head ;
while(p->next){
	Visit(p->next->data);
	p = p->next;
}


}
//Ԫ�ض�λ
template<class ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const{
	int count = 1;
	Node<ElemType>*p = head;
	while(p->next!=NULL){
		if((*p).data==e) return count;
		p = p->next;
	}
	if((*p).data==e) return count;


	return 0;
}
//��ָ��λ�õ�Ԫ��ֵ
template<class ElemType>
ElemType LinkList<ElemType>::GetElem(int index) const{

	int count = 1;
	Node<ElemType>*p = head;
	while(p->next){
		if(count==index) {return p->next->data;}
		p = p->next;count++;
	}
	if(p->next==NULL&&index==length){return p->data;}
}
//����ָ��λ�õ�Ԫ��ֵ
template<class ElemType>
int LinkList<ElemType>::SetElem(int index, const ElemType &e){
	int count = 1;
	Node<ElemType> *p = head;
	while(p){
		if(count==index){p->next->data = e;return 1;}
		else {
		p = p->next;
		count++;
		}
	}
}
//ɾ��ָ��Ԫ��
template<class ElemType>
int  LinkList<ElemType>::DeleteElem(int index){
	int count = 1;
	Node<ElemType> *p = head;
	while(p->next){
		if(count==index){
			Node<ElemType> *q = p->next;
			if(q->next==NULL){delete q;p->next = NULL;length--;return 1;}
			else {
				p->next=q->next;
				delete q;
				
				length--;
				return 1;
			}
			
		}
			p = p->next;
			count++;
	}
}
//��ָ��λ�ò���Ԫ��
template<class ElemType>
int LinkList<ElemType>::InsertElem(int index, const ElemType &e){
	int count = 1;
	Node<ElemType> *p = head;
	Node<ElemType> *q;
	if(index==1){q->data = e;q->next = p;head = q; return 1; }//�ڵ�һ��λ�ò��룻
	while(p){
		if(count==index-1){q->data = e;q->next = p->next;p->next = q; return 1;}
		else {
			count++;
			p = p->next;
		}
	}
}
//�ڱ��β������Ԫ��
template <class ElemType>
int LinkList<ElemType>::InsertElem(const ElemType &e){
	Node<ElemType> *p = head;
	Node<ElemType> *q = new Node<ElemType> ;
	if(p->next==NULL){
		q->data = e;
		q->next = NULL;
		p->next=q;
		length++;
		return 1;
	}
	while(p->next!=NULL){	
		p = p->next;//�����ƶ������һλ��
	}
		q->data = e;
		q->next = NULL;
		p->next = q;
		length++;
	return 1;
}
//���ƹ��캯��
template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &la){
	pheader = new Node<ElemType>;
	Node<ElemType> *p1 = head;
	Node<ElemType> *p2 = la.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	length = la.length;

}        
//���������
template<class ElemType>
LinkList<ElemType>& LinkList<ElemType>::operator =(const LinkList<ElemType> &la){
	LinkList<ElemType> a;
	a.length = la.length;
	Node<ElemType> *p1 = a.head;
	Node<ElemType> *p2 = la.head;
	while(p2){
		p1->data = p2->data;
		p1->next = new Node<ElemType>;
		p1 = p1->next;
		p2 = p2->next;
	}
	return a;
} 
#endif