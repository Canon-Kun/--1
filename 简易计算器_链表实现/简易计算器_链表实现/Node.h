#ifndef __NODE_H__
#define __NODE_H__
// �����
template <class ElemType>
 struct Node
{
// ���ݳ�Ա:
	ElemType data;			// ������
	Node<ElemType> *next;		// ָ����

// ���캯��:
	Node()		;		// �޲����Ĺ��캯��
	Node(ElemType item, Node<ElemType> *link = NULL);// ��֪������Ԫ��ֵ��ָ�뽨���ṹ
} ;
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

