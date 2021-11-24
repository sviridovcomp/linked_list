#ifndef LINKED_LIST_LINKEDLIST_HPP
#define LINKED_LIST_LINKEDLIST_HPP

#include <LinkedListNode/LinkedListNode.hpp>
#include <LinkedListIterator/LinkedListIterator.hpp>

template <typename Type>
class LinkedList {
public:
    LinkedList() = default;
    LinkedList(std::initializer_list<Type> data) {
        for (auto &&i : data) {
            push_back(i);
        }
    }
    ~LinkedList() {
        clear();
    }

    [[nodiscard]] bool empty() const {
        return _head == nullptr;
    }

    [[nodiscard]] size_t size() const {
        return _size;
    }

    void push_back(const Type& data) {
        LinkedListNode<Type>* node = nullptr;
        if (empty()) {
            node = new LinkedListNode<Type>;
            _head = node;
        } else {
            node = _tail;
            node->next = new LinkedListNode<Type>;
            node = node->next;
        }

        node->data = data;
        node->next = nullptr;
        _tail = node;
        _size++;
    }

    void remove_at(const size_t index) {
        auto node = _head;

        if (index == 0) {
            _head = node->next;
            delete node;
            if (empty()) {
                _tail = nullptr;
            }
        } else {
            for (auto i = 0; i < index - 1; ++i) {
                node = node->next;
            }

            auto* temp_node = node->next;
            node->next = node->next->next;
            delete temp_node;

            if (index == _size - 1) {
                _tail = node;
            }
        }

        _size--;
    }

    void push_front(const Type& data) {
        auto* node = new LinkedListNode<Type>;
        node->data = data;
        node->next = _head;

        if (empty()) {
            _tail = node;
        }

        _head = node;
        _size++;
    }

    void pop_back() {
        remove_at(_size - 1);
    }

    void pop_front() {
        remove_at(0);
    }

    void clear() {
        auto* next = _head;
        LinkedListNode<Type>* current = nullptr;
        while (next != nullptr) {
            current = next;
            next = next->next;
            delete current;
        }
    }

    Type operator[] (const size_t index) {
        auto node = _head;
        LinkedListNode<Type>* current = nullptr;
        for (auto idx = 0; idx <= index && node != nullptr; idx++) {
            current = node;
            node = node->next;
        }
        return current->data;
    }

    Type front() const {
        return _head->data;
    }

    Type back() const {
        return _tail->data;
    }

    LinkedListIterator<Type> begin() {
        return LinkedListIterator<Type>(_head);
    }

    LinkedListIterator<Type> end() {
        return LinkedListIterator<Type>(_tail->next);
    }
private:
    LinkedListNode<Type>* _head;
    LinkedListNode<Type>* _tail;
    size_t _size = 0;
};

#endif //LINKED_LIST_LINKEDLIST_HPP
