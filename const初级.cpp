//const�޶���
#include<iostream>
#include"const.h"			//����ͷ�ļ�
using namespace std;

int main() {

	//**1.const��������ʼ��
	const int n1 = 42;		//��ȷ


//**2.Ĭ��״̬�£�const��������ļ�����Ч
	extern const int bufsiz;	//��Ҫʹ���ⲿ��const������Ҫ�ڶ���ǰ����extern
	const int bufsiz = 512;		//һ����ǰ����extern�����涨���ͬ�����󽫲�������
	cout << bufsiz << endl;		//���1024


//**3.const����ļ�����
	const int n2 = 888;			//const����
	const int& n2_ptr1 = n2;	//const���ð󶨳�������,��ȷ

	int n3 = 999;				//��ͨ����
	const int& n3_ptr1 = n3;	//const���ð���ͨ����,������ͨ��n3_ptr1�޸�n3��ֵ,��ȷ

	//const int c = 666;		//const����
	//int& ci = c;				//���ܽ���ͨ���ð�const���ã�����

	//****NOTE: ��ʱ��
	double d1 = 3.14;
	const int& d1_ptr = d1;		//������������һ����ʱ������const int tmp = dval;

	//double dval = 3.14;
	//int& d = dval;			//����,�����﷨ϣ��ͨ��d���޸�dval��ֵ��ʵ���޸ĵ���������ʱ�������Բ��С�


//**4.ָ���const
	//�ھ�: ��ָ�ұ�
	//const��*����ߣ������ָ��ָ��һ��const����
	//const��*���ұߣ������ָ�뱾���Ǹ�constָ��

	const double d2 = 3.14;		//const����
	//double* d2_ptr = &d2;		//������ָͨ�벻��ָ��const����
	const double* d2_ptr = &d2;	//��ȷ����ָ�����ָ��const����

	double d3 = 3.8;			//��ͨ����
	const double* d3_ptr = &d3;	//��ȷ��������ʹ�ø�ָ�����޸�d3��ָ
	//const int* d3_ptr = &d3;	//���󣬲�������ʱ�����������ò�ͬ

	//tip:����ָ������ָ������ã����Ǻ�����Ϊ�ǣ�������Ϊָ����Ǹ��������������ǲ�Ը���޸���ָ��Ķ���
	int n4 = 2020;
	const int* n4_ptr = &n4;


	//**5.����const �� �ײ�const
	int n5 = 100;
	int* const n5_ptr1 = &n5;		//����const��ʾ���ָ�뱾����const���������ɱ��޸ġ�(�ұ�)
	const int* n5_ptr2 = &n5;		//�ײ�const��ʾ����ָ��Ķ��󲻿�ͨ����ָ���޸ġ�(��ָ)
	const int& n5_r = n5;		//NOTE:�����������õ�const�ǵײ�const��
	//������������:���Ժ��Ӷ���const�����⵽�ײ�const����
	//����ֵΪ�ײ�constʱ����ָҲ����Ϊ�ײ�const��(�ҵ���ص�)

	const int n6 = 200;
	const int* n6_ptr = &n6;
	//int* const n6_ptr = &n6;
	//int* tmp = n6_ptr;			//����:��߲��ǵײ�const�����ұ���
	int n7 = 400;
	int* n7_ptr1 = &n7;
	const int* n7_ptr2 = n7_ptr1;		//��ȷ:�ұ߲��ǵײ�const����Ӱ��

	//�ܽ�:�ҵ���ص�


//**6.constexpr����
	int null = 0, * p = &null;
}