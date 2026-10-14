
class LFUCache {
public:
    class Node {
    public:
        int key, val, cnt;
        Node* prev;
        Node* next;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->cnt = 1;
            prev = next = nullptr;
        }
    };
    class DLL {
    public:
        int size;
        Node* head;
        Node* tail;
        DLL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addFront(Node* node) {
            Node* temp = head->next;

            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;

            size++;
        }
        void removeNode(Node* node) {
            Node* p = node->prev;
            Node* n = node->next;

            p->next = n;
            n->prev = p;

            node->prev = node->next = NULL;
            size--;
        }
        Node* removeLRU() {
            if (size == 0) return NULL;
            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
    };

    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLL*> freqListMap;

    int limit;
    int minFreq;
    int curSize;

    void updateListFreq(Node* node) {
        int freq = node->cnt;
        DLL* list = freqListMap[freq];
        list->removeNode(node);
        if (freq == minFreq && list->size == 0) {
            minFreq++;
        }
        node->cnt++;
        if (freqListMap.find(node->cnt) == freqListMap.end()) {
            freqListMap[node->cnt] = new DLL();
        }
        freqListMap[node->cnt]->addFront(node);
    }

    LFUCache(int capacity) {
        limit = capacity;
        minFreq = 0;
        curSize = 0;
    }
    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }
        Node* node = keyNode[key];
        int value = node->val;
        updateListFreq(node);
        return value;
    }
    void put(int key, int value) {
        if (limit == 0) return;
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateListFreq(node);
            return;
        }
        if (curSize == limit) {
            DLL* list = freqListMap[minFreq];
            Node* lruNode = list->removeLRU();
            keyNode.erase(lruNode->key);
            delete lruNode;
            curSize--;
        }
        Node* node = new Node(key, value);
        minFreq = 1;
        if (freqListMap.find(1) == freqListMap.end()) {
            freqListMap[1] = new DLL();
        }
        freqListMap[1]->addFront(node);
        keyNode[key] = node;
        curSize++;
    }
};
