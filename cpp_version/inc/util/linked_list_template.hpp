#ifndef LINKED_LIST_TEMPLATE_HPP
#define LINKED_LIST_TEMPLATE_HPP

template<typename T>
class LinkedListTemplate {
public:
    struct Node {
        Node* prev;
        T* data;
        Node* next;
        
        Node(T* item) : prev(nullptr), data(item), next(nullptr) {}
        
        Node* getNext() const { return next; }
        Node* getPrev() const { return prev; }
        void setNext(Node* newNext) { next = newNext; }
        void setPrev(Node* newPrev) { prev = newPrev; }
    };

private:
    Node* head;
    Node* tail;

public:
    LinkedListTemplate() : head(nullptr), tail(nullptr) {}
    
    virtual ~LinkedListTemplate() {
        clear();
    }

    void addNode(T* item) {
        Node* newNode = new Node(item);
        
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeNode(Node* nodeToRemove) {
        if (!nodeToRemove) return;

        Node* prevNode = nodeToRemove->getPrev();
        Node* nextNode = nodeToRemove->getNext();

        if (prevNode)
            prevNode->setNext(nextNode);
        if (nextNode)
            nextNode->setPrev(prevNode);

        if (nodeToRemove == head)
            head = nextNode;
        if (nodeToRemove == tail)
            tail = prevNode;

        delete nodeToRemove;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void clearWithData() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current->data;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }

    void printList(void (*printFunction)(T*)) const {
        Node* current = head;
        while (current) {
            printFunction(current->data);
            current = current->next;
        }
    }
    
    // Access methods
    Node* getHead() const { return head; }
    Node* getTail() const { return tail; }
    void setHead(Node* newHead) { head = newHead; }
    void setTail(Node* newTail) { tail = newTail; }
    
    // Navigation methods
    Node* getNext(Node* current) const { 
        return current ? current->getNext() : nullptr;
    }
    
    T* getData(Node* current) const { 
        return current ? current->data : nullptr;
    }
    
    bool isEmpty() const { return head == nullptr; }
};

#endif