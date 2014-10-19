#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <iostream>
namespace codemaster{
const int UNINIT_COUNT = 0;
const int INIT_COUNT = 1;
template<typename Type>
class SharedPtr{
public:
	SharedPtr():_count(new int(INIT_COUNT)), _ptr(NULL){}
	SharedPtr(Type val):_count(new int(INIT_COUNT)), _ptr(new Type()){ *_ptr = val; }
	SharedPtr(const SharedPtr<Type>& shared_ptr);
	SharedPtr<Type>& operator=(const SharedPtr<Type>& shared_ptr);
	~SharedPtr();
	void set_val(Type);
	Type operator*();

private:
	int* _count;
	Type* _ptr;
};
template<typename Type>
void SharedPtr<Type>::set_val(Type val){
	--*(this->_count);
	if (this->_count == 0){
		delete this->_count;
		delete this->_ptr;
	}
	this->_count = new int(INIT_COUNT);
	this->_ptr = new Type();
	*_ptr = val;
}
template<typename Type>
SharedPtr<Type>::SharedPtr(const SharedPtr<Type>& shared_ptr){
	std::cout << " using copy constructor " << std::endl;
	this->_count = shared_ptr._count;
	std::cout << "before assign: " << *(this->_count) << std::endl;
	*(this->_count) = *(this->_count) + 1;
	std::cout << "after assign: " << *(this->_count) << std::endl;
	this->_ptr = shared_ptr._ptr;
}
template<typename Type>
SharedPtr<Type>::~SharedPtr(){
	*(this->_count) = *(this->_count) - 1;
	// only delete when there's no other ptr
	if (*(this->_count) == 0){
		delete _ptr;
		delete this->_count;
	}
}
template<typename Type>
SharedPtr<Type>& SharedPtr<Type>::operator=(const SharedPtr<Type>& shared_ptr){
	std::cout << "using operator = " << std::endl;
	// increase right ptr's count first to avoid delete the same object;
	++*(shared_ptr._count);

	// decrease this count
	--*(this->_count);

		// delete object if no others hold this ptr
	if (*(this->_count) == 0){
		delete this->_ptr;
		delete this->_count;
	}

	// assign the proper ptr
	this->_ptr = shared_ptr._ptr;
	this->_count = shared_ptr._count;

	return *this;
}
template<typename Type>
Type SharedPtr<Type>::operator*(){
	return *_ptr;
}

}
#endif
