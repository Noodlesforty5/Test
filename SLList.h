#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {  // constructor (inistialzie varialbes)
      head = nullptr;
      tail = nullptr;
      num_items = 0;
    }

    ~SLList() {  // destructor
      // clean up memory
      clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return head;
    }

    void push_back(T item) {
        // implement push_back here
        Node* n = new Node(item);
        if (head == nullptr) {
          head = n;
          tail = n;
        }
        else {
            tail->next = n;
            tail = n;
        }


        num_items++;
    }

    void pop_back() {
        if (head == nullptr) return; // List is empty

        if (head == tail) { // Only one element
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next; // Traverse to the second-to-last node
            }
            delete tail; // Delete the last node
            tail = current; // Update tail to the second-to-last node
            tail->next = nullptr; // Set next of new tail to nullptr
        }
        num_items--;
    }
    const T& front() const {
        // implement front here
        if (head == nullptr) {
          return T();

        }
        else {
          return head->value;
        }
    }

    int size() const {
        // implement size here
        return num_items;
    }

    void clear() {
        // implement clear here
        Node* current = head;
        while (current != nullptr) {
            Node* tmp = current;
            current = current->next;
            delete tmp;
        }
        head = nullptr;
        tail = nullptr;
        num_items = 0;
    }

private:
  Node* head;
  Node* tail;
  int num_items;
};
