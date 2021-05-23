#pragma once
#include <vector>
#include <algorithm>

template <class T,std::size_t N>
class FixedHeapArray {
public:
	FixedHeapArray() {
		A.resize(N);
	}
	FixedHeapArray(const std::initializer_list<T>& In) {
		A.resize(N);
		std::copy(In.begin(), In.begin() + (In.size() < N ? In.size() : N), A.begin());
	
	}
	T& at(std::size_t Idx) {
		return A[Idx];
	}
	T& back() {
		return A.back();
	}
	T& front() {
		return A[0];
	}
	typename std::vector<T>::iterator begin() {
		return A.begin();
	}
	typename std::vector<T>::const_iterator begin() const{
		return A.cbegin();
	}	
	typename std::vector<T>::const_iterator cbegin() const{
		return A.cbegin();
	}
	typename std::vector<T>::iterator end() {
		return A.end();
	}
	typename std::vector<T>::const_iterator end() const{
		return A.cend();
	}
	typename std::vector<T>::const_iterator cend() const{
		return A.cend();
	}
	typename std::vector<T>::iterator rbegin() {
		return A.rbegin();
	}
	typename std::vector<T>::const_iterator rbegin() const{
		return A.crbegin();
	}
	typename std::vector<T>::const_iterator crbegin() const{
		return A.crbegin();
	}
	typename std::vector<T>::iterator rend() {
		return A.rend();
	}
	typename std::vector<T>::const_iterator rend() const{
		return A.crend();
	}
	typename std::vector<T>::const_iterator crend() const{
		return A.crend();
	}
	T* data() {
		return A.Data();
	}
	const T* data() const {
		return A.Data();
	}
	bool empty() const{
		return A.empty();
	}
	bool fill(const T& In) {
		std::fill_n(A.begin(), N, In);
		return true;
	}

	std::size_t size() {
		return A.size();
	}
	std::size_t max_size() {
		return N;
	}
	T& operator [](std::size_t Idx) {
		return A[Idx];
	}
	const T& operator [](std::size_t Idx)const {
		return A[Idx];
	}
protected:
	std::vector<T> A = std::vector<T>(0, N);
};