#ifndef Stack_h
#define Stack_h
#include "MyVector_h.h"
template <class AnyT>
class Stack : protected MyVector<AnyT>
{
public: 
	Stack() = default;
	~Stack() = default;
	void push(const AnyT&);
	AnyT pop();
private:
	Stack(Stack&) = default;
	Stack& operator=(Stack&) = default;
	int st_ptr = 0;
};

template <class AnyT>
void Stack<AnyT>::push(const AnyT& var) {
	this->push_back(var);
	st_ptr++;
}
template <class AnyT>
AnyT Stack<AnyT>::pop() {
	this->pop_back();
	st_ptr--;
	return this->at(st_ptr);
}
#endif //Stack_h