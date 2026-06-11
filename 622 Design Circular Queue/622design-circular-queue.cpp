class MyCircularQueue {
public:
    vector<int> v;
    int f;
    int b;
    int size;
    int count;
    MyCircularQueue(int k) {
        v.resize(k);
        f = 0;
        b = -1;
        size = k;
        count = 0;
    }

    bool enQueue(int value) {
        if (count == size) return false;

        b = (b + 1) % size;
        v[b] = value;
        count++;
        return true;
    }

    bool deQueue() {
        if (count == 0) return false;
        f = (f + 1) % size;
        count--;
        return true;
    }

    int Front() {
        if (count == 0) return -1;
        return v[f];
    }

    int Rear() {
        if (count == 0) return -1;
        return v[b];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};