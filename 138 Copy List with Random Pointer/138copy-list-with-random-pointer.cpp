class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* dummy = new Node(-100);
        Node* d = dummy;
        Node* temp = head;
        while(temp){
            d->next = new Node(temp->val);
            d = d->next;
            temp = temp->next;
        }
        Node* tempA = head;
        Node* tempB = dummy->next;
        unordered_map<Node*,Node*> m;
        while(tempA){
            m[tempA]=tempB;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        for(auto x:m){
            Node* i=x.first;
            Node* j=x.second;
            if(i->random){
                Node* iRandom=i->random;
                Node* jRandom=m[iRandom];
                j->random=jRandom;
            }
        }
        return dummy->next;

    }
};