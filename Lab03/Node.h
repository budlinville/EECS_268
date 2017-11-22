class Node{
  private:
    int m_value;    //stored value of type integer
    Node* m_next;   //pointer to next node in list

  public:
    Node();

    Node(int value, Node *nextNode);

    void setValue(int val);

    int getValue() const;

    void setNext(Node *prev);

    Node* getNext() const;
};
