#include <iostream>

class Polynomial;

class Term{
	friend Polynomial;
private:
	float coef; //���
	int exp;	//����
};

class Polynomial
{
//���׽��� ������ ����, <ei,ai>�� ����
private:
	Term *termArray;	//0�� �ƴ� ���� �迭
	int capacity;		//termArray�� ũ��
	int terms;			//0�� �ƴ� ���� ��
public:
	Polynomial();
	//���׽� p(x) = 0 �� ����

	Polynomial Add(Polynomial poly);
	//���׽� *this�� poly�� ���� ��ȯ

	Polynomial Mult(Polynomial poly);
	//���׽� *this�� poly�� ���� ��ȯ

	float Eval(float f);
	//���׽� *this�� f�� ������ ���� ����Ͽ� �� ����� ��ȯ
};