#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
	Stack(int stackCapacity = 10);
	//ó���� ũ�Ⱑ stackCapacity�� ���� ������ ����

	bool IsEmpty() const;
	//������ ���Ҽ��� 0�̸� true, �ƴϸ� false�� ��ȯ

	T* Top() const;
	//������ ����Ҹ� ��ȯ

	void Push(const T* item);
	//������ �鿡 item�� ����

	void Pop();
	//������ �� ���Ҹ� ����

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