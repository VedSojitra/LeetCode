class MyCircularDeque {
private:
    vector<int> deque;
    int front, rear, size;
public:
    // Constructor to initialize the deque with size k
    MyCircularDeque(int k) {
        deque.resize(k + 1); // One extra space to differentiate between full and empty
        front = 0;
        rear = 0;
        size = k + 1;
    }

    // Insert an item at the front of the deque
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + size) % size; // Move front pointer backward
        deque[front] = value;
        return true;
    }

    // Insert an item at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) return false;
        deque[rear] = value;
        rear = (rear + 1) % size; // Move rear pointer forward
        return true;
    }

    // Delete an item from the front of the deque
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % size; // Move front pointer forward
        return true;
    }

    // Delete an item from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + size) % size; // Move rear pointer backward
        return true;
    }

    // Get the front item
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }

    // Get the rear item
    int getRear() {
        if (isEmpty()) return -1;
        return deque[(rear - 1 + size) % size];
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == rear;
    }
    
    // Check if the deque is full
    bool isFull() {
        return (rear + 1) % size == front;
    }
};
