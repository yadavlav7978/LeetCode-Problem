class Node{

    public:

    int key,value;
    Node *prev,*next;

    Node(int key,int value){
        this->key=key;
        this->value=value;
        prev=NULL;
        next=NULL;
    }
};

class LRUCache {
public:

    unordered_map<int,Node*>mp;
    int cap;
    Node *head,*tail;

    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
        
    }

    void deleteNode(Node* cur){
        
    Node* prevNode = cur->prev;
    Node* nextNode = cur->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

        mp.erase(cur->key);
    }

    void insertNode(Node* cur){

        Node* prevNode=tail->prev;
        prevNode->next=cur;
        tail->prev=cur;

        cur->prev=prevNode;
        cur->next=tail;

        mp.insert({cur->key,cur});
    }
    
    int get(int key) {

        if(mp.find(key)==mp.end()) return -1;

        Node* cur=mp[key];

        deleteNode(cur);
        insertNode(cur);

        return cur->value;    
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){
            Node* cur=mp[key];
            deleteNode(cur);
        }else if(mp.size()==cap){
            Node* headNext=head->next;
            deleteNode(headNext);
        }

        Node* newNode=new Node(key,value);
        insertNode(newNode);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */