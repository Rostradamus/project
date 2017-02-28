/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

bool debug = false;

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}

int max_heap::capacity() const {
	return max_capacity;
}

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions:


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {

		text_item temp = top();
		data[0] = data[--numItems];
		swap_down(0);
		return temp;

	}
}

void max_heap::swap_down(int i) {

	int leftChild = (2 * i) + 1;
	int rightChild = (2 * i) + 2;
	int min = i;

	if (leftChild < numItems && data[leftChild].freq > data[min].freq)
			min = leftChild;
	if (rightChild < numItems && data[rightChild].freq > data[min].freq)
			min = rightChild;
	if (min != i) {
		if (debug) {
			std::cout << "Swap down " << data[i].word << "(freq: " << data[i].freq << ") with "
			<< data[min].word << "(freq: " << data[min].freq << ")" << std::endl;
		}
		std::swap(data[min], data[i]);
		swap_down(min);
	}

}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {

		data[numItems++] = item;
		swap_up(numItems - 1);

	}
}

void max_heap::swap_up(int i) {

	if (i == 0) return;
	int parent = (i - 1) / 2;

	if (data[i].freq > data[parent].freq) {
		if (debug) {
			std::cout << "Swap up " << data[i].word << "(freq: " << data[i].freq << ") with "
			<< data[parent].word << "(freq: " << data[parent].freq << ")" << std::endl;
		}

		std::swap(data[i], data[parent]);
		swap_up(parent);
	}
}
