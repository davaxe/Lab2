#pragma once
#include <string>

class List
{
public:
    List();
    List(std::initializer_list<int> values);
    List(const List &other);
    List(List &&other);
    ~List();

    void push_back(int value);
    void push_front(int value);
    void clear();
    void sort();

    int pop_back();
    int pop_front();
    int front() const;
    int back() const;
    int get(int index) const;
    int length() const;

    bool empty() const;
    std::string to_string() const;

    List &operator=(const List &other);
    List &operator=(List &&other);

private:
    class Node
    {
    public:
        Node();
        Node(int value);
        Node(int value, Node *next);

        void set_next(Node *next);
        void set_value(int value);
        Node *get_next();
        int get_value() const;

    private:
        int m_value;
        Node *m_next;
    };
    Node *m_head;
    Node *m_tail;
    int m_length;

    Node *get_node(int index) const;
    void clear_recursive(Node *node);

    void split_list(Node *head, Node *&front, Node *&back);
    Node *combine_lists(Node *head_a, Node *head_b);
    void merge_sort(Node *&head);
};