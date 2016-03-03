/**
@file LL.hpp
@author Chowdhury:Nrimoni:A00371596:csc34127
@version 1.0
@date 2014-06-12
@brief
This is hpp file which contains declaration and definitions
of LL which contains templated functions with struct node.
*/

/*
Author self-assessment statement:
This hpp file is completely built and runs perfectly.

And by the way, note that this is a C++ but non-doxygen comment,
so it will not appear in the HTML displays produced by doxygen.
*/


#ifndef LL_H
#define LL_H

#include <iostream>
#include <ostream>
#include <sstream>

using namespace std;
using std::ostream;

//typedef int base_type;

template <typename base_type>
struct LLNode
{
    base_type data;
    LLNode* next;
};

template <typename base_type>
LLNode<base_type>* CopyNodes(LLNode<base_type>* srcNode)
{
    if (srcNode == nullptr) return nullptr;
    LLNode<base_type>* copy = new LLNode<base_type>;
    copy->data = srcNode->data;
    copy->next = CopyNodes(srcNode->next);
    return copy;
}

template <typename base_type>
void DeleteNodes(LLNode<base_type>* cur) 
{
    if (cur != nullptr) 
    {
        LLNode<base_type>* temp = cur;
        cur = cur->next;
        delete temp;
    }
}

template <typename base_type>
class LL
{
public:
    LL();                       
    /**<
    @return none
    @param  none
    @post   prints out a default value if something is wrong
    */

    LL(const LL<base_type>& src);      
    /**<
    @return none
    @param  constant LL of base_type
    @post   swaps LL node
    */

    LL& operator=(LL<base_type> src);  
    /**<
    @return none
    @param  base_type of LL
    @post   prints out a default value if something is wrong
    */

    ~LL();                  
    /**<
    @return none
    @param  none
    @post   delete value
    */

    void swap(LL<base_type>& other);   
    /**<
    @return void
    @param  base_type of LL
    @post   swaps value
    */

    // observers
    int size() const;
    /**<
    @return int constant
    @param  none
    @post   prints out size
    */

    bool empty() const;
    /**<
    @return bool constant
    @param  none
    @post   prints out if it is true or false
    */

    const base_type& at(int p) const;     // read-only access
    /**<
    @return constant
    @param  int p
    @post   const base_type of at
    */
                                         
    void push_front(base_type e);
    /**<
    @return void 
    @param  base_type e
    @post   pushes front the values
    */

    void push_back(base_type e);
    /**<
    @return void
    @param  base_type e
    @post   pushes back the values
    */

    base_type& at(int p);                 
    /**<
    @return none
    @param  int p
    @post   base_type of at
    */

    template <typename base_type>
    friend ostream& operator<<(ostream& out, const LL<base_type>& list);
    /**<
    @return none
    @param  ostream out, constant base_type of LL and list
    @post   prints out a default value if something is wrong
    */

private:
    LLNode<base_type>* head;
};

template <typename base_type>
LL<base_type>::LL()
{
    head = nullptr;
}

// Big 3.5
template <typename base_type>
LL<base_type>::LL(const LL<base_type>& src)
{
    head = CopyNodes(src.head);
}

template <typename base_type>
LL<base_type>& LL<base_type>::operator=(LL<base_type> src)
{
    this->swap(src);
    return *this;
}

template <typename base_type>
LL<base_type>::~LL()
{
    DeleteNodes(head);
}

template <typename base_type>
void LL<base_type>::swap(LL<base_type>& other)
{
    std::swap(head, other.head);
}

//helper
std::string intToString(int n)
{
    std::ostringstream out;
    out << n;
    return out.str();
}

// observers
template <typename base_type>
const base_type& LL<base_type>::at(int p) const
{
    LLNode<base_type>* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}

template <typename base_type>
int LL<base_type>::size() const
{
    int count = 0;
    for(LLNode<base_type>* cur = head; cur != nullptr; cur = cur->next)
        ++count;
    return count;
}

template <typename base_type>
bool LL<base_type>::empty() const
{
    return head == nullptr;
}


// mutators
template <typename base_type>
base_type& LL<base_type>::at(int p)
{
    LLNode<base_type>* cur = head;
    for (int i = 0; i < p; ++i)
    {
        if (cur == nullptr)
            throw std::range_error("Invalid index: " + intToString(p));
        cur = cur->next;
    }
    return cur->data;
}

template <typename base_type>
void LL<base_type>::push_front(base_type e)
{
    LLNode<base_type>* cur = head;
    head = new LLNode<base_type>;
    head->data = e;
    head->next = cur;
}

template <typename base_type>
void LL<base_type>::push_back(base_type e)
{
    if (head == nullptr)
    {
        push_front(e);
    }
    else
    {
        LLNode<base_type>* cur = head; 
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new LLNode<base_type>;
        cur->next->data = e;
        cur->next->next = nullptr;
    }
}

// friends
template <typename base_type>
ostream& operator<<(ostream& out, const LL<base_type>& list)
{
    LLNode<base_type>* cur = list.head;    // friends can do this!
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

#endif