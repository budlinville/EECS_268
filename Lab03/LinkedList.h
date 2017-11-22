#include <vector>

class LinkedList{
  private:
    Node *m_front;
    int m_size;

  public:
    LinkedList();

    ~LinkedList();

    bool isEmpty() const;

    int size() const;

    bool search(int value) const;

    void printList() const;

    void addBack(int value);

    void addFront(int value);

    bool removeBack();

    bool removeFront();

    std::vector<int> toVector() const;
}
