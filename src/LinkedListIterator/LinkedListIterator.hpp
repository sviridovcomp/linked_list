#ifndef LINKED_LIST_LINKEDLISTITERATOR_HPP
#define LINKED_LIST_LINKEDLISTITERATOR_HPP

#include <LinkedList/LinkedList.hpp>
#include <LinkedListNode/LinkedListNode.hpp>
#include <iterator>

template<typename Type>
class LinkedListIterator : public std::iterator<std::bidirectional_iterator_tag,
        Type,
        Type,
        const Type *,
        Type &> {
public:
    LinkedListIterator() : _node(nullptr) {};
    LinkedListIterator(LinkedListNode<Type>* node) : _node(node) {};

    bool operator != (const LinkedListIterator<Type>& iterator) const {
        return _node != iterator._node;
    }

    Type& operator*() const {
        return _node->data;
    }

    LinkedListIterator<Type> operator++() {
        auto temp_node = *this;
        _node = _node->next;
        return temp_node;
    }

private:
    LinkedListNode<Type> *_node;
};

#endif //LINKED_LIST_LINKEDLISTITERATOR_HPP
