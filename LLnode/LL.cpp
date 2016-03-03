
#include "LL.h"
#include <algorithm>
#include <stdexcept>
#include <sstream>      // for ostringstream

//  Node* head;

// Node class and functions
struct LLNode
{
    base_type data;
    LLNode*   next;
};

LLNode* CopyNodes(LLNode* srcNode)
{
    if (srcNode == nullptr) return nullptr;
    LLNode* copy = new LLNode;
    copy->data = srcNode->data;
    copy->next = CopyNodes(srcNode->next);
    return copy;
}

void DeleteNodes(LLNode* cur) 
{
    if (cur != nullptr) 
    {
        LLNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

// constructors
LL::LL()
{
    head = nullptr;
}

// Big 3.5
LL::LL(const LL& src)
{
    head = CopyNodes(src.head);
}

LL& LL::operator=(LL src)
{
    this->swap(src);
    return *this;
}

LL::~LL()
{
    DeleteNodes(head);
}

void LL::swap(LL& other)
{
    std::swap(head, other.head);
}

// helper
std::string intToString(int n)
{
    std::ostringstream out;
    out << n;
    return out.str();
}

// observers
const base_type& LL::at(int p) const
{
    LLNode* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}

int LL::size() const
{
    int count = 0;
    for(LLNode* cur = head; cur != nullptr; cur = cur->next)
        ++count;
    return count;
}

bool LL::empty() const
{
    return head == nullptr;
}


// mutators
base_type& LL::at(int p)
{
    LLNode* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}

void LL::push_front(base_type e)
{
    LLNode* cur = head;
    head = new LLNode;
    head->data = e;
    head->next = cur;
}

void LL::push_back(base_type e)
{
    if (head == nullptr)
    {
        push_front(e);
    }
    else
    {
        LLNode* cur = head; 
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new LLNode;
        cur->next->data = e;
        cur->next->next = nullptr;
    }
}

// friends

ostream& operator<<(ostream& out, const LL& list)
{
    LLNode* cur = list.head;    // friends can do this!
    out << "[";
    if (cur != nullptr)
    {
        while (cur->next != nullptr)
        {
            out << cur->data << ", ";
            cur = cur->next;
        }
        out << cur->data;
    }
    out << "]";
    return out;
}