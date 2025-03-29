#include <cassert>
#include "max_heap.h"

void testInsertAndGetMax() {
    MaxHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    assert(heap.get_max() == 20);
}

void testExtractMax() {
    MaxHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    assert(heap.extract_max() == 20);
    assert(heap.get_max() == 15);
}

void testRemoveElement() {
    MaxHeap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.remove(0);  // Remove 20
    assert(heap.get_max() == 15);
}

void testEmptyHeapBehavior() {
    MaxHeap<int> heap;
    try {
        heap.get_max();
        assert(false); // Should not reach here
    }
    catch (const out_of_range&) {}

    try {
        heap.extract_max();
        assert(false); // Should not reach here
    }
    catch (const out_of_range&) {}
}

void testInsertMultipleElements() {
    MaxHeap<int> heap;
    for (int i = 1; i <= 100; ++i) {
        heap.insert(i);
    }
    assert(heap.get_max() == 100);
}

int main() {
    testInsertAndGetMax();
    testExtractMax();
    testRemoveElement();
    testEmptyHeapBehavior();
    testInsertMultipleElements();

    cout << "All tests passed!" << endl;
    return 0;
}

