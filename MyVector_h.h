#pragma once
#ifndef MyVector_h
#define MyVector_h

#include<iostream>


template <class AnyT>
class MyVector
{
public:
	MyVector();
	MyVector(int& insize);
	MyVector(const MyVector& src);
	~MyVector();
	int length();
	void push_any_where( int index, const AnyT& inelem);
	void push_back(AnyT number);
	void pop_back();
	AnyT& operator[] (int index)const;
	AnyT at(const int& index, int num = 0);
	void reserve(int number);
private:
	void create_space(int space);
	void if_not_space(int num = 2, const int& index = -1);
	int size = 0;
	int capacity = 10;
	AnyT* arr;
};

template <class AnyT>
MyVector<AnyT>::MyVector() {
	create_space(capacity);
}
template <class AnyT>
MyVector<AnyT>::MyVector(int& insize) :capacity(insize)
{
	create_space(capacity);
}
template <class AnyT>
MyVector<AnyT>::MyVector(const MyVector& src) {
	create_space(capacity);
	for (int i = 0; i < (capacity > src.length() ? src.length() : capacity); i++)
	{
		if_not_space();
		arr[i] == src[i];
		++size;
	}
}
template <class AnyT>
MyVector<AnyT>::~MyVector() {
	delete[] arr;
}
template <class AnyT>
int MyVector<AnyT>::length() {
	return size;
}
template <class AnyT>
void MyVector<AnyT>::push_any_where(int index, const AnyT& inelem) {
	if_not_space(2, index);
	arr[index] = inelem;
	size++;
}
template <class AnyT>
void MyVector<AnyT>::push_back(AnyT number) {
	if_not_space();
	arr[size] = number;
	size++;
}

template <class AnyT>
AnyT& MyVector<AnyT>:: operator[] (int index)const {
	return arr[index];
}
template <class AnyT>
AnyT MyVector<AnyT>::at(const int& index, int num) {
	if (index >= 0 && index < capacity) {
		if (num == 0) {
			return arr[index];
		}
		arr[index] = num;
		return arr[index];
	}
	else
	{
		std::cout << index << "is biger then your vector capacity ";
		return NULL;
	}
}
template <class AnyT>
void MyVector<AnyT>::reserve(int number) {
	if (number > capacity) {
		if_not_space(number);
	}
};

template <class AnyT>
void MyVector<AnyT>::create_space(int space) {
	arr = new AnyT[capacity];
	if (arr == nullptr) {
		std::cout << "Sorry we haven't enought space";
	}
}
template <class AnyT>
void MyVector<AnyT>::if_not_space(int num, const int& index) {
	if (size == capacity) {
		if (num == 2) {
			capacity *= 2;
		}
		else
		{
			capacity = num;
		}
		AnyT* tmp = new AnyT[capacity];
		for (int i = 0; i < size; i++)
		{
			if (i == index) {
				continue;
			}
			else
			{
				tmp[i] = arr[i];
			}
		}
		delete[]arr;
		arr = tmp;
	}
}
template<class AnyT>
void MyVector<AnyT>::pop_back() {
	size--;
}
#endif //MyVector_h