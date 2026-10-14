
class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    void addNode(Node* node) {
        Node* oldNxt = head->next;

        node->prev = head;
        node->next = oldNxt;
        head->next = node;
        oldNxt->prev = node;
    }

    void deleteNode(Node* node) {
        Node* oldPrev = node->prev;
        Node* oldNext = node->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        Node* node = m[key];
        int ans = node->val;

        deleteNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int value) {
        if (limit == 0) return;

        if (m.find(key) != m.end()) {
            Node* node = m[key];
            node->val = value;

            deleteNode(node);
            addNode(node);

            return;
        }

        if (m.size() == limit) {
            Node* lruNode = tail->prev;

            deleteNode(lruNode);
            m.erase(lruNode->key);
            delete lruNode;
        }

        Node* newNode = new Node(key, value);

        addNode(newNode);
        m[key] = newNode;
    }
};
