class LRUCache {
public:
    class Node{
    public: 
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            next=prev=NULL;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);

    unordered_map<int,Node*> m;
    int limit;
    void addNode(Node* node){
        Node* oldNxt=head->next;
        node->prev=head;
        oldNxt->prev=node;
        head->next=node;
        node->next=oldNxt;
    }
    void deleteNode(Node* oldNode){
        Node* oldPrev=oldNode->prev;
        Node* oldNext=oldNode->next;

        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;
    }
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* ansNode=m[key];
        int ans=ansNode->val;
        
        deleteNode(ansNode);
        m.erase(key);

        addNode(ansNode);
        m[key]=ansNode;
        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* oldNode=m[key];
            deleteNode(oldNode);
            m.erase(key);
        }
        if(m.size()==limit){
            Node* lruNode=tail->prev;
            deleteNode(lruNode);
            m.erase(lruNode->key);
            delete lruNode;      
        }
        Node* newNode=new Node(key,value);
        m[key]=newNode;
        addNode(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */