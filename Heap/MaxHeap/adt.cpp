#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Move element upward
    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Move element downward
    void heapifyDown(int i) {
        while (true) {
            int left = leftChild(i);
            int right = rightChild(i);
            int largest = i;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    // Constructor
    MaxHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heap = new int[capacity];
    }

    // Insert element
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full\n";
            return;
        }

        heap[size] = value;
        size++;

        heapifyUp(size - 1);
    }

    // Get maximum element
    int getMax() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }

        return heap[0];
    }

    // Delete maximum element
    int deleteMax() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }

        int maxValue = heap[0];

        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);

        return maxValue;
    }

    // Display heap
    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";

        cout << endl;
    }

    // Check empty
    bool isEmpty() {
        return size == 0;
    }

    // Check full
    bool isFull() {
        return size == capacity;
    }
};


// -------------------- Main --------------------
int main() {

    MaxHeap heap(10);

    heap.insert(50);
    heap.insert(30);
    heap.insert(70);
    heap.insert(20);
    heap.insert(40);
    heap.insert(60);
    heap.insert(80);

    cout << "Max Heap: ";
    heap.display();

    cout << "Maximum: " << heap.getMax() << endl;

    cout << "Deleted: " << heap.deleteMax() << endl;

    cout << "After deletion: ";
    heap.display();

    return 0;
}