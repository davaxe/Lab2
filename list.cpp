#include "list.h"
#include <sstream>

List::List()
    : m_head(nullptr), m_tail(nullptr), m_length(0)
{
}

List::List(std::initializer_list<int> values)
    : List{}
{
    for(int value : values)
    {
        push_back(value);
    }
}

List::List(const List& other)
    : List{}
{
    Node* current = other.m_head;
    while(current != nullptr)
    {
        push_back(current->get_value());
        current = current->get_next();
    }
}

List::List(const List&& other)
    : List{}
{
    List temp {*this};
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_length = other.m_length;
}

List::~List()
{
    
}

void List::push_back(int value)
{
    if (m_tail == nullptr)
    {
        m_tail = new Node{value};
        m_head = m_tail;
    }
    else
    {
        Node* temp = new Node{value, nullptr};
        m_tail->set_next(temp);
        m_tail = temp;
    }
    m_length++;
}

void List::push_front(int value)
{
    if (m_head == nullptr)
    {
        m_head = new Node{value};
        m_tail = m_head;
    }
    else
    {
        m_head = new Node{value, m_head};
    }
    m_length++;
}

int List::pop_back()
{
    int value;
    if (m_tail == nullptr)
    {
        throw std::logic_error("List is empty.");
    }
    else if (m_head == m_tail)
    {
        value = m_tail->get_value();
        m_head = nullptr;
        m_tail = nullptr;
        m_length = 0;
    }
    else
    {
        value = m_tail->get_value();
        Node* second_last = get_node(m_length - 2);
        second_last->set_next(nullptr);
        delete m_tail;
        m_tail = second_last;
        m_length--;
    }
    return value;
}


int List::pop_front()
{
    if (m_head == nullptr)
    {
        throw std::logic_error("List is empty.");
    }
    int value = m_head->get_value();
    Node* new_first = m_head->get_next();
    delete m_head;
    m_head = new_first;
    m_length--;
    return value;
}

void List::clear()
{

}

int List::front() const
{
    if (m_tail == nullptr)
    {
        throw std::logic_error("List is empty.");
    }
    return m_head->get_value();
}

int List::back() const
{
    if (m_tail == nullptr)
    {
        throw std::logic_error("List is empty.");
    }
    return m_tail->get_value();
}

int List::get(int index) const
{
    return get_node(index)->get_value();
}

bool List::empty() const
{
    return m_length == 0;
}

int List::length() const
{
    return m_length;
}

std::string List::to_string() const
{
    std::stringstream ss;
    if (m_head == nullptr)
    {
        return "[]";
    }
    Node* current {m_head};
    ss << "[";
    while (current->get_next() != nullptr)
    {
        ss << current->get_value() << ", ";
        current = current->get_next();
    }
    ss << current->get_value() << "]";
    return ss.str();
}

List& List::operator=(const List& other)
{
    List copy {other};
    m_head = copy.m_head;
    m_tail = copy.m_tail;
    m_length = copy.m_length;
    return *this;
}

List::Node* List::get_node(int index) const
{
    if (index < 0 || index >= m_length)
    {
        throw std::out_of_range("Index out of range.");
    }
    Node *current{m_head};
    for (int i = 0; i < index; i++)
    {
        current = current->get_next();
    }
    return current;
}

/*===========================================================================*/

List::Node::Node()
    : m_value{}, m_next{nullptr}
{
}

List::Node::Node(int value)
    : m_value{value}, m_next{nullptr}
{
}

List::Node::Node(int value, Node *next)
    : m_value{value}, m_next{next}
{

}

void List::Node::set_next(Node* next)
{
    m_next = next;
}
void List::Node::set_value(int value)
{
    m_value = value;
}

List::Node* List::Node::get_next()
{
    return m_next;
}


int List::Node::get_value() const
{
    return m_value;
}
