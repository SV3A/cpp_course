// Doubly-Linked Lists
// The goal of the exercise is to implement a class List of doubly-linked lists.
#include <iostream>

// Struct implementing the list element
template<typename T>
struct Node {
  T Value;
  Node<T> *next;
  Node<T> *prev;
};


template<typename T>
class List {

public:
  // Constructor and destructor
  List () {
    head  = nullptr;
    tail  = nullptr;
    lsize = 0;
  }

  ~List () {}

  // Public handle to internal insert method
  void insert(T n) {
    insert_intr(n);
  }

  void reverse(void) {
    Node<T> *p   = head;
    Node<T> *tmp = nullptr;

    while (p != nullptr) {
      tmp     = p->next;
      p->next = p->prev;
      p->prev = tmp;

      p = tmp;
    }

    // Switch head and tail
    tmp  = head;
    head = tail;
    tail = tmp;
  }

  // Display the contents of the list
  void print(void) {
    Node<T> *p = head;

    std::cout << "List: ";
    while (p != nullptr) {
      std::cout << p->Value << " ";
      p = p->next;
    }
    std::cout << std::endl;
  }

  // Return size of the list
  int size(void) { return lsize; }


private:

  Node<T> *head, *tail; // Beginning and end of the list
  int lsize;            // The size of the list

   // insert function that traverses the entire list
  void insert_intr_slow(T n, Node<T> * & head) {

    // If list is empty or if we have arrived at the end of the list
    if (head == nullptr) {
      Node<T> *p = new Node<T>;

      p->Value = n;
      p->next  = nullptr;
      p->prev  = tail;

      head = p;
      tail = p;

      lsize++; // Increment list size
      return;  // Base case return
    }

    // Call recursively with the pointer to the next element
    insert_intr_slow(n, head->next);
  };

  // Optimized insert function that goes directory to tail and appends new
  // node element
  void insert_intr(T n) {

    Node<T> *p = new Node<T>;
    p->Value = n;
    p->next  = nullptr;

    // The pointer to the proceeding element depends on wether the list is empty
    if (head == nullptr)
      head = p;
    else
      tail->next = p;

    // Update tail
    p->prev = tail;
    tail    = p;
    lsize++;
  };
};


int main(void) {
  // Initiate and populate list
  List<int> l;
  for(unsigned int i = 0; i < 10; i++){ l.insert(i); }
  l.print();

  l.reverse();
  l.print();

  l.reverse();
  l.print();

  std::cout << "List size: " << l.size() << std::endl;
}
