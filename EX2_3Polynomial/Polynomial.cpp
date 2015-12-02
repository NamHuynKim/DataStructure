#include <iostream>

class Polynomial;

class Term{
	friend Polynomial;
private:
	float coef; //계수
	int exp;	//지수
};

class Polynomial
{
//다항식의 순서쌍 집합, <ei,ai>의 집합
private:
	Term *termArray;	//0이 아닌 항의 배열
	int capacity;		//termArray의 크기
	int terms;			//0이 아닌 항의 수
public:
	Polynomial();
	//다항식 p(x) = 0 을 생성

	Polynomial Add(Polynomial poly);
	//다항식 *this와 poly의 합을 봔환

	Polynomial Mult(Polynomial poly);
	//다항식 *this와 poly의 곱을 봔환

	float Eval(float f);
	//다항식 *this에 f를 대입한 값을 계산하여 그 결과를 반환
};