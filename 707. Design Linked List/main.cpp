struct Node {
    int data;
    Node* next;
};

class MyLinkedList {
private:
    Node* head;
    Node* tail;
    int size; 
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        
        Node* curr = head;
    
        for (int i = 0; i < index; ++i) 
            curr = curr->next;

        return curr->data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        if (size == 0)
            tail = newNode;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        
        if (size == 0) {
            head = newNode;
            tail = newNode;
        }
        
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        
        curr->next = newNode;
        tail = newNode;
        
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) { addAtHead(val); return; }
        if (index == size)  { addAtTail(val); return; }
        
        Node* newNode = new Node();
        newNode->data = val;
        
        int i = 0;
        Node* curr = head;
        Node* prev = NULL;
        
        while (i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        prev->next = newNode;
        newNode->next = curr;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* curr = head;

        if (index == 0) {
            head = curr->next;
            --size;
            return;
        }
        int i = 0;
        Node* prev = NULL;
        
        while (i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }
            
        prev->next = curr->next;
        
        if (index == size - 1) tail = curr;
        
        delete curr;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
