
#ifndef LL_H
#define LL_H

#include <iostream>
using std::ostream;

typedef int base_type;
struct LLNode;

class LL
{
public:
    // constructors
    LL();                   // default constructor

    // Big 3.5
    LL(const LL& src);      // copy constructor
    LL& operator=(LL src);  // assignment operator
    ~LL();                  // destructor
    void swap(LL& other);   // swap method

    // observers
    int size() const;
    bool empty() const;
    const base_type& at(int p) const;     // read-only access
                                          // for demonstration only
                                          // probably shouldn't have this
                                          // it's inefficient

    // mutators
    void push_front(base_type e);
    void push_back(base_type e);
    base_type& at(int p);                 // read-write access
                                          // as above!

    // friends
    friend ostream& operator<<(ostream& out, const LL& list);

private:
    LLNode* head;
};

#endif