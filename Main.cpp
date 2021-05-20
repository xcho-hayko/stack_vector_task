#include <iostream>
#include "MyVector_h.h"
#include "Stack_h.h"

int main() {
	MyVector <int> myvec;
	Stack<int> myst;

	myvec.push_back(6);
	myvec.push_back(23);
	myvec.push_back(15);
	myvec.push_back(16);
	myvec.push_back(18);
	myvec.push_any_where( 5 , 0);
	myvec.push_back(300);
	myvec.push_any_where(7, 0);
	myst.push(12);
	myst.push(13);
	myst.push(14);
	myst.push(15);

	std::cout << myst.pop() << "asklas" << std::endl;
	std::cout << myvec.length() << std::endl;
	for (int i = 0; i < myvec.length(); i++) {
		std::cout << myvec[i] << std::endl;
	}
}