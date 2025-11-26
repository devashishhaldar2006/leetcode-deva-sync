class MyLinkedList {
public:
    class DLL {
    public:
        int val;
        DLL* next;
        DLL* prev;
        DLL(int val) {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    DLL* head;
    int size = 0;
    MyLinkedList() {
        head=NULL;
    }

    int get(int index) {
        if (index > size - 1 || index < 0)
            return -1;
        DLL* temp = head;
        for (int i = 1; i <= index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        DLL* temp = new DLL(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void addAtTail(int val) {
        DLL* t = new DLL(val);
        if (!head) {
            head = t;
        } else {
            DLL* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = t;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        DLL* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        DLL* k = new DLL(val);
        k->next = temp->next;
        temp->next = k;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        if (index == 0) {
            DLL* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        DLL* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        DLL* DLLToDelete = temp->next;
        temp->next = DLLToDelete->next;
        delete DLLToDelete;
        size--;
    }
};
