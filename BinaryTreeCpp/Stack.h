#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
	Stack(int stackCapacity = 10);
	//처음에 크기가 stackCapacity인 공백 스택을 생성

	bool IsEmpty() const;
	//스택의 원소수가 0이면 true, 아니면 false를 반환

	T* Top() const;
	//스택의 톱원소를 반환

	void Push(const T* item);
	//스택의 톱에 item을 삽입

	void Pop();
	//스택의 톱 원소를 삭제

	void ChangeSizeId(T*& a, const int oldSize, const int newSize);

private:
	T* stack;
	int top;
	int capacity;
};


template<class T>
void Stack<T>::ChangeSizeId(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0)
		throw "New Length must be >= 0";
	T* temp = new T[newSize];
	std::copy(a, a + oldSize, temp);
	delete[] a;
	a = temp;
}

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity)
{
	if (capacity < 1)
		throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T* Stack<T>::Top() const
{
	if (IsEmpty())
		throw "Stack is empty";
	return &stack[top];
}

template <class T>
void Stack<T>::Push(const T* x)
{
	if (top == capacity - 1)
	{
		ChangeSizeId(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = *x;
}

template <class T>
void Stack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--].~T();
}

#endif