class LRUCache {
public:

    class Node{
        public:
            int key, val;
            Node* next;
            Node* prev;

            Node(int k , int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map <int , Node*> mp;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;

        head->next = newNode;
        newNode->next = oldNext;
        oldNext->prev = newNode;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* ansNode = mp[key];
        int ans = ansNode->val;

        mp.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);
        mp[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* oldNode = mp[key];
            mp.erase(key);
            deleteNode(oldNode);
        }

        if(mp.size() == limit){
            Node* oldPrev = tail->prev;
            mp.erase(oldPrev->key);
            deleteNode(oldPrev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */