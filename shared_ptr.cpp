//#include "shared_ptr.h"
//
//namespace codemaster{
//template<typename Type>
//SharedPtr<Type>::SharedPtr(const SharedPtr<Type>& shared_ptr){
//	this->_count = shared_ptr->_count;
//	*(this->_count) = *(this->_count) + 1;
//	this->_ptr = shared_ptr._ptr;
//}
//template<typename Type>
//SharedPtr<Type>::~SharedPtr(){
//	*(tihs->_count) = *(this->_count) - 1;
//	// only delete when there's no other ptr
//	if (*(this->_count) == 0){
//		delete _ptr;
//		delete this->_count;
//	}
//}
//template<typename Type>
//SharedPtr<Type>& SharedPtr<Type>::operator =(const SharedPtr<Type>& shared_ptr){
//
//	// increase right ptr's count first to avoid delete the same object;
//	++*(ptr._count);
//
//	// decrease this count
//	--*(this->_count)
//
//	// delete object if no others hold this ptr
//	if (*(this->count) == 0){
//		delete this->_ptr;
//		delete this->_count;
//	}
//
//	// assign the proper ptr
//	this->_ptr = shared_ptr._ptr;
//	this->_count = shared_ptr._count;
//}
//template<typename Type>
//Type SharedPtr<Type>::operator*(){
//	return *_ptr;
//}
//}