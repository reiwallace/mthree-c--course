#include <iostream>
#include <stdexcept>
//#define DEBUG

template <typename T>
class Node {
private:
    Node* next = nullptr;
    Node* previous = nullptr;

    T data;

public:
    Node<T>(T data): data(data) {}
    ~Node() {
        #ifdef DEBUG 
        std::cout << "Destroying node with data: " << data << "\n";
        #endif
        
    }

    T& getData() {
        return data;
    }

    void setData(T data) {
        this->data = data;
    }

    Node* getNext() {
        return next;
    }

    Node* getPrevious() {
        return previous;
    }

    void setNext(Node* next) {
        this->next = next;
    }

    void setPrevious(Node* prev) {
        this->previous = prev;
    }
};

template <typename T>
class LinkedList {
private:
    Node<T>* root = nullptr;
    Node<T>* last = nullptr;

    Node<T>* getNodeAt(int idx) {
        // Pointer to a node starting at the root
        Node<T>* currentNode = root;
        int currentIdx = 0;

        if(idx < 0) {
            return nullptr;
        }

        // Loop until root is nullptr or index is reached
        while(currentIdx < idx && currentNode) {
            currentNode = currentNode->getNext();
            currentIdx += 1;
        }

        // Return nullptr if node not found
        return currentNode;
    }

public:
    LinkedList<T>() {}
    ~LinkedList() {
        #ifdef DEBUG 
        std::cout << "\nDELETING CHILDREN\n";
        #endif
        Node<T>* currentNode = root;
        while(currentNode) {
            Node<T>* temp = currentNode;
            currentNode = currentNode->getNext();
            delete temp; 
        }
    }

    /**
        Inserts a value at the end of the list
        @param val - Value of T type to insert
    */
    void insert(T val) {
        if(last) {
            // Set the next pointer on the last node to a new node of the value
            last->setNext(new Node<T>(val));
            // Set the last node to the new value
            Node<T>* prev = last;
            last = last->getNext();
            last->setPrevious(prev);
        } else {
            // Handle first node
            root = new Node<T>(val);
            last = root;
        }
    }

    /**
        Gets a pointer to the value of node at idx
        @param idx - Index of node to retreive value
    */
    T* get(int idx) {
        Node<T>* node = getNodeAt(idx);
        return (node ? &(node->getData()) : nullptr);
    }

    /**
        Finds an item in the list
        @param item - Item to find
        @returns Index of the found item or -1
    */
    int find(T item) const {
        // Pointer to a node starting at the root
        Node<T>* currentNode = root;
        int idx = 0;

        // Loop until the end of the list
        while(currentNode) {
            if(currentNode->getData() == item) {
                return idx; 
            }

            idx += 1;
            currentNode = currentNode->getNext();
        }

        // Return -1 if item not found
        return -1;
    }

    /**
        Removes an item from the list
        @param idx - Index of item to remove
    */
    T remove(int idx) {
        // Calls internet get function to get the node at idx
        Node<T>* nodeAt = getNodeAt(idx);
        if(nodeAt == nullptr) {
            throw std::runtime_error("List index out of bounds");
        }

        if(!nodeAt->getPrevious()) {
            // Node was root
            root = nodeAt->getNext();
            root->setPrevious(nullptr);
        } else if(!nodeAt->getNext()) {
            // Node was head
            last = nodeAt->getPrevious();
            last->setNext(nullptr);
        } else {
            // Node was in the middle
            nodeAt->getPrevious()->setNext(nodeAt->getNext());
            nodeAt->getNext()->setPrevious(nodeAt->getPrevious());
        }

        T data = nodeAt->getData();
        delete nodeAt;
        return data;
    }
};

int main() {
    /*
    Node<int>* root = new Node(10);
    Node<int>* cur = root;
    Node<int>* prev;

    cur->setNext(new Node(100));
    prev = cur;
    cur = cur->getNext();

    cur->setNext(new Node(1000));
    cur->setPrevious(prev);
    prev = cur;
    cur = cur->getNext();

    Node<int>* last = new Node(10000);
    cur->setNext(last);
    cur->setPrevious(prev);
    prev = cur;
    cur = cur->getNext();
    cur->setPrevious(prev);

    cur = root;
    std::cout << "GOING FORWARDS!\n";
    while(cur) {
        std::cout << "CURRENT VAL: " << cur->getData() << "\n";
        cur = cur->getNext();
    }

    std::cout << "\nGOING BACKWARDS!\n";
    cur = last;
    while(cur) {
        std::cout << "CURRENT VAL: " << cur->getData() << "\n";
        cur = cur->getPrevious();
    }

    std::cout << "\nDeleting\n";
    cur = root;
    while(cur) {
        Node<int>* temp = cur->getNext();
        delete cur;
        cur = temp;
    }
    */

    LinkedList<int>* list = new LinkedList<int>();

    list->insert(1000);
    list->insert(100);
    list->insert(10);
    list->insert(1);

    // Get at index
    std::cout << "Val at idx 3 " << *(list->get(3)) << "\n";

    // Loop through the list
    int i = 0;
    std::cout << "\nLooping through list\n";
    while(list->get(i) != nullptr) {
        std::cout << "Node at index " << i << ": " << *(list->get(i)) << "\n";
        i++;
    }

    // Insert new
    list->insert(20);
    i = 0;
    std::cout << "\nLooping through list\n";
    while(list->get(i) != nullptr) {
        std::cout << "Node at index " << i << ": " << *(list->get(i)) << "\n";
        i++;
    }

    // List contains
    std::cout << "\nList contains 10? " << (list->find(10) != -1 ? "true" : "false") << "\n";
    std::cout << "List contains 11? " << (list->find(11) != -1 ? "true" : "false") << "\n";

    // Remove
    i = 0;
    list->remove(1);
    std::cout << "\nLooping through list - Removed IDX 1\n";
    while(list->get(i) != nullptr) {
        std::cout << "Node at index " << i << ": " << *(list->get(i)) << "\n";
        i++;
    }

    delete list;

    std::cout << std::endl;
    return 0;
}