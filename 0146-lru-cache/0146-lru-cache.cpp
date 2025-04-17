class LRUCache {
public:
    class node{
        public:
        int val,key;
        node* next;
        node* prev;
        node(int _key,int _val){
            val=_val;
            key=_key;
            prev = next = nullptr;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*> mp;
    int cap;
        LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insertNodeAfterHead(node* newNode){
        node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void delNodeBeforeTail(node* delNode){
         delNode->prev->next = delNode->next;
        delNode->next->prev = delNode->prev;
    }
    
    int get(int _key) {
       if( mp.find(_key)!=mp.end()){
            node* resNode=mp[_key];
            int res=resNode->val;
            mp.erase(_key);
            delNodeBeforeTail(resNode);
            insertNodeAfterHead(resNode);
            mp[_key]=head->next;
            return res;
       }
       return -1;
    }
    
    void put(int _key, int _value) {
        if(mp.find(_key)!=mp.end()){
            node* existingNode=mp[_key];
            mp.erase(_key);
            delNodeBeforeTail(existingNode);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            delNodeBeforeTail(tail->prev);
        }
        insertNodeAfterHead(new node(_key,_value));
        mp[_key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */