#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue
{
public:
	Queue(int queueCapacity = 10);
	bool IsEmpty()const;
	void ChangeSizeId(T*& a, const int oldSize, const int newSize);
	T Front() const;
	//큐의 앞에 있는 원소를 반환
	T Rear() const;
	//큐의 뒤에 있는 원소를 반환
	void Push(const T& item);
	//큐의 뒤에 item을 삽입
	void Pop();
	//큐의 앞 원소를 삭제
private:
	int capacity, front, rear;
	T *elem;
};

template<class T>
Queue<T>::Queue(int queueCapacity = 10)
{
	capacity = queueCapacity;
	front = rear = 0;
	elem = new T[capacity];
}


template<class T>
bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template<class T>
T Queue<T>::Front() const
{
	if (IsEmpty())
		throw "Error";
	else
		return elem[front + 1];
}

template<class T>
T Queue<T>::Rear() const
{
	if (IsEmpty())
		return NULL;
	else
		return elem[rear];
}

template<class T>
void Queue<T>::ChangeSizeId(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0)
		throw "New Length must be >= 0";
	T* temp = new T[newSize];
	std::copy(a, a + oldSize, temp);
	delete[] a;
	a = temp;
}

template<class T>
void Queue<T>::Push(const T& item)
{
	if ((rear + 1) % capacity == front)
	{
		ChangeSizeId(elem, capacity, 2 * capacity);
		capacity *= 2;
	}
	rear = (rear + 1) % capacity;
	elem[rear] = item;
}

template<class T>
void Queue<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	front = (front + 1) % capacity;
	elem[front].~T();
}
#endif