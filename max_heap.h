#ifndef MAX_HEAP
#define MAX_HEAP

#include <iostream>
#include<vector>
using namespace std;

template<typename T>
class MaxHeap {
private:
    vector<T> heap;
    void heapifyDown(int index);
    void heapifyUp(int index);

public:
    void insert(T value);
    void printHeap();
    void remove(int index);
    bool isEmpty() { return heap.empty(); }

    T get_max();
    T extract_max();
};


template<typename T>
void MaxHeap<T>::heapifyDown(int index)
{
    int left, right, largest;
    while (true) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        largest = index;
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
        }
        else {
            break;
        }


    }
}

template<typename T>
void MaxHeap<T>::heapifyUp(int index)
{
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }

}

template<typename T>
void MaxHeap<T>::insert(T value)
{
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

template<typename T>
void MaxHeap<T>::printHeap()
{
    for (const auto& x : heap) {
        cout << x << " ";
    }
    cout << endl;
}

template<typename T>
void MaxHeap<T>::remove(int index)
{
    if (index >= heap.size()) {
        throw out_of_range("index out of range");
    }
    if (index == heap.size() - 1) {
        heap.pop_back();
        return;
    }
    heap[index] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {
        if (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            heapifyUp(index);
        }
        else {
            heapifyDown(index);
        }
    }
}

template<typename T>
T MaxHeap<T>::get_max()
{
    if (isEmpty()) {
        throw out_of_range("heap is empty");
    }
    return heap[0];
}

template<typename T>
T MaxHeap<T>::extract_max()
{
    if (isEmpty()) {
        throw out_of_range("heap is empty");
    }

    T maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!isEmpty()) {
        heapifyDown(0);
    }
    return maxValue;
}

#endif // !MAX_HEAP
