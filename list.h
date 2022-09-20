#pragma once
#include <string>

class List 
{
public:
    List();
    List(std::initializer_list<int> values);
    List(const List& other);
    List(const List&& other);
    ~List();

    void push_back(int value);
    void push_front(int value);
    void clear(); 
    int  pop_back();
    int  pop_front();
    int  front() const;
    int  back() const;
    int  get(int index) const;
    bool empty() const;
    int  length() const;
    std::string to_string() const; 
    
    List& operator=(const List& other);

private:
    class Node
    {
    public:
        Node();
        Node(int value);
        Node(int value, Node* next);
        
        void set_next(Node* next);
        void set_value(int value);
        Node* get_next();
        int   get_value() const;
    private:
        int m_value;
        Node* m_next;
    };
    Node* m_head;
    Node* m_tail;
    int m_length;

    Node* get_node(int index) const;
};