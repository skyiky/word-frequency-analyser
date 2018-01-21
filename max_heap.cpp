/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include "text_item.hpp"
#include <stdexcept>
#include <algorithm>

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

text_item& max_heap::top() {
    if (empty()) {
        throw std::logic_error("Heap is empty, can't access top!");
    }
    return data[0];
}

text_item max_heap::find(int i) {
    return data[i];
}

//--- You must comple the following functions: 


text_item max_heap::delete_max() {
    if (empty()) {
        throw std::logic_error("Cannot delete, heap is empty!");
    } else {
        text_item temp = data[0];
        data[0] = data[numItems - 1];
        data[numItems - 1] = temp;
        numItems--;
        swap_down(0);
        return temp;
    }
}

void max_heap::swap_down(int i) {
    // ADD CODE HERE
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int max = i;
    if (leftChild < numItems && data[leftChild].freq > data[max].freq)
        max = leftChild;
    if (rightChild < numItems && data[rightChild].freq > data[max].freq)
        max = rightChild;
    if (max != i) {
        text_item temp = data[max];
        data[max] = data[i];
        data[i] = temp;
        swap_down(max);
    }
}

void max_heap::insert(const text_item & item) {
    if (full()) {
        throw std::logic_error("Cannot insert, heap array is full!");
    } else {
        numItems++;
        data[numItems - 1] = item;
        swap_up(numItems - 1);
    }
    return;
}

void max_heap::swap_up(int i) {
    // ADD CODE HERE
    int parent = (i-1)/2;
    int max = i;
    if (data[max].freq > data[parent].freq)
        max = parent;
    if (max != i) {
        text_item temp = data[max];
        data[max] = data[i];
        data[i] = temp;
        swap_up(max);
    }
    return;
}
