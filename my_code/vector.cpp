#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
	if (v.size() == 0) {
		cout << "Vector is empty." << endl;
		exit(1);
	}
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}


MyVec::MyVec() : sz(0), capacity(1) {
	try
	{
		data = new int[sz];
	}
	catch (std::bad_alloc& error)
	{
		std::cerr << "bad_alloc caught: " << error.what() << '\n';
	}
}

MyVec::MyVec(const MyVec& v2) {
	data = new int[v2.sz];
	sz = v2.sz;
	capacity = v2.capacity;
	for (int i = 0; i < sz; ++i) {
		data[i] = v2[i];
	}
}

MyVec::~MyVec() {
	delete [] data;
	data = nullptr;
	sz = 0;
	capacity = 1;
}

MyVec& MyVec::operator=(const MyVec& v2) {
	if (this != &v2) {
		delete [] data;
		data = new int[v2.sz];
		sz = v2.sz;
		capacity = v2.capacity;
		for (int i = 0; i < sz; ++i) {
			data[i] = v2[i];
		}
	}
	return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2) {
	if (v1.size() != v2.size()) return false;
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) return false;
	}
	return true;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val) {
	if (sz == capacity) capacity *= 2;
	data[sz] = val;
	++sz;
}

/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const {
	if (sz == 0) {
		cout << "Vector is empty." << endl;
		exit(1);
	}
	return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i) {
	if (sz == 0) {
		cout << "Vector is empty." << endl;
		exit(1);
	}
	return data[i];
}