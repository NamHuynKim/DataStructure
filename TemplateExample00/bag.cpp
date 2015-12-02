#include <iostream>


template<typename T>
class Bag
{
public:
	Bag(int bagCapacity = 10);
	~Bag();

	int Size() const { return top + 1; }
	bool IsEmpty() const { return Size() == 0; }
	T& Element() const{
		if (IsEmpty())
			throw "Bag is empty";
		return array[0];
	}

	void push(const T& x);
	void Pop();

private:
	T* array;
	int capacity;
	int top;
};

template<typename T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity){
	if (capacity < 1)
		throw "Capacity must be > 0";
	array = new T[capacity];
	top = -1;
}

template<typename T>
Bag<T>::~Bag() { delete[]array; }

template<typename T>
void Bag<T>::push(const T& x){
	if (capacity == top + 1)
	{
		ChangeSizeId(array, capacity, 2 * capacity);
		capacity *= 2;
	}
	array[++top] = x;
}

template<typename T>
void Bag<T>::Pop(){
	if (IsEmpty())
		throw"Bag is empty, cannot delete";
	int deletePos = top / 2;
	std::copy(array + deletePos + 1, array + top + 1, array + deletePos);
	array[top--].~T();
}

template<typename T>
void ChangeSizeId(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0)
		throw "New Length must be >= 0";
	T* temp = new T[newSize];
	std::copy(a, a + oldSize, temp);
	delete[] a;
	a = temp;
}

int main(int argc, char* argv[])
{
	Bag<int> b;
	b.push(1);
	b.Element();
	b.Pop();

	return 0;
}
