class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key, int value){
        this->key=key;
        this->value=value;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*> mp;
    Node *old;
    Node *newe;
    LRUCache(int capacity) {
        this->capacity=capacity;
        old = new Node(0,0);
        newe=new Node(0,0);
        old->next=newe;
        newe->prev=old;
    }

    void remove(Node *node){
        Node *prevN=node->prev;
        Node *nextN=node->next;
        prevN->next=nextN;
        nextN->prev=prevN;
    }

    void setList(Node *node){
        Node *prevN=newe->prev;
        Node *nextN=newe;
        prevN->next=node;
        nextN->prev=node;
        node->next=nextN;
        node->prev=prevN;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node *node = mp[key];
            remove(node);
            setList(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            remove(mp[key]);
        }
        Node *newNode = new Node(key,value);
        mp[key]=newNode;
        setList(newNode);
        if(mp.size()>capacity){
            Node *lru = old->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */