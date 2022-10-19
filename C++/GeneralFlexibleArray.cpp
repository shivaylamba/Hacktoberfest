#pragma once
#include<iostream>
using namespace std;
class GFArray
{
private:
	int* A, size, last, first;
	float occupancy;
public:
	GFArray(int size) {
		A = new int[size];
		last = first = occupancy = 0;
	}
	bool isEmpty() {
		return last == first;
	}
	bool block() {
		occupancy = float(last / size);
		return occupancy >= 0.8;
	}
	bool needToShrink() {
		occupancy = float(last / size);
		return occupancy <= 0.4;
	}
	bool grow() {
		size *= 2;
		int *B = new int[size];
		for (int i = 0; i < last; i++) {
			B[i] = A[i];
		}
		A = B;
		delete B;
		return true;
	}
	bool shrink() {
		size /= 2;
		int* B = new int[size];
		for (int i = 0; i < last; i++)
			B[i] = A[i];
		A = B;
		delete B;
		return true;
	}
	bool updateAt(int key, int index) {
		if(!isEmpty())
			if (index >= 0 && index < last) {
				A[index] = key;
				return true;
			}
		return false;
	}
	bool searchByVal(int key) {
		if (!isEmpty()) 
			for (int i = 0; i < last; i++) 
				if (A[i] == key)
					return true;
		return false;
	}
	int searchOccurances(int key) {
		int count = 0;
		if (!isEmpty()) {
			for (int i = 0; i < last; i++) 
				if (A[i] == key)
					count++;
			return count;
		}
		return -1;
	}
	bool searchAndUpdate(int oldVal, int newVal) {
		if (!isEmpty()) {
			for (int i = 0; i < last; i++) 
				if (A[i] == oldVal) {
					A[i] = newVal;
					return true;
				}				
		}
		return false;
	}
	bool searchAndDelete(int key) {
		if (!isEmpty()) {
			for(int i=0; i<last; i++)
				if (A[i] == key) {
					for (int j = i; j < last; j++)
						A[j] = A[j + 1];
					last--;
				}
			return true;
		}
		return false;
	}

	bool deletefirst() {
		if (!isEmpty()) {
			if (first == last) {
				last--; 
				return true;
			}
			for (int i = 0; i < last; i++)
				A[i] = A[i + 1];
			if (needToShrink())
				shrink();
			return true;
		}
		return false;
	}
	bool deleteLast() {
		if (!isEmpty) {
			last--;
			if (needToShrink())
				shrink();
			return true;
		}
		return false;
	}
	bool deleteAfter(int index) {
		if (!isEmpty()) {
			if (index < last - 1) {
				int i = 0;
				for (i = index; i < last - 1; i++)
					A[i] = A[i + 1];
				last--;
				if (needToShrink())
					shrink();
				return true;
			}	
		}
		return false;
	}
	bool deletebefore(int index) {
		if (!isEmpty()) {
			if (index <= last && index > 0) {
				int i = 0;
				for (i = index - 1; i < last - 1; i++)
					A[i] = A[i + 1];
				last--;
				if (needToShrink())
					shrink();
				return true;
			}
		}
		return false;
	}
	bool deleteAt(int index) {
		if (index == last - 1) {
			last--;
			if (needToShrink())
				shrink();
			return true;
		}
		if (index < (last-1) && index >= 0) {
			int i = 0;
			for (int i = index; i < last-1; i++)
				A[i] = A[i + 1];
			last--;
			if (needToShrink())
				shrink();
			return true;
		}
		return false;
	}

	bool insertFirst(int key) {
		if (isEmpty) {
			A[first] = key;
			last++;
			return true;
		}
		return false;

	}
	bool insertLast(int key) {
		if (block())
			grow();
		if (isEmpty()) {
			A[last] = key;
			first = last;
			last++;
			return true;
		}
		A[last++] = key;
		return true;
	}
	bool insertAfter(int key, int index) {
		if (index < last && index >= 0) {
			if (block())
				grow();
			int i = 0;
			for (i = last - 1; i > index; i--) 
				A[i + 1] = A[i];
			A[i] = key;
			last++;
			return true;

		}
		return false;
	}
	bool insertBefore(int key, int index) {
		if (index > first && index <= last) {
			if (block())
				grow();
			int i = 0;
			for (int i = last - 1; i >= index - 1; i--)
				A[i + 1] = A[i];
			A[i] = key;
			last++;
			return true;
		}
		return false;
	}
	bool insertAt(int key, int index) {
		if (isEmpty()) {
			if (index > 0)
				return false;
			A[first] = key;
			last++;
			return true;
		}
		if (index <= last) {
			if (block())
				grow();
			int i = 0;
			for (i = last - 1; i >= index; i--)
				A[i + 1] = A[i];
			A[i] = key;
			last++;
			return true;
		}
		return false;
		
	}


};
