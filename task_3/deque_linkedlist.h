#ifndef DEQUE_LINKEDLISTH_H
#define DEQUE_LINKEDLISTH_H

#include <QDebug>
#include <sstream>

template <typename T>
class Deque_linkedList {
public:
    Deque_linkedList()
        : front(nullptr)
        , back(nullptr)
        , dequeSize(0) { }
    void pushFront(const T& value);
    void pushBack(const T& value);
    T popFront();
    T popBack();
    T* toArray() const;
    std::string toString() const;
    void clear();
    bool isEmpty() const;
    int size() const;

    class Iterator;

    Iterator begin() {
        return Iterator(front);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    ~Deque_linkedList();

private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value)
            : data(value)
            , next(nullptr)
            , prev(nullptr) { }
    };

    Node* front;
    Node* back;
    int dequeSize;
};

template <typename T>
class Deque_linkedList<T>::Iterator {
public:
    Iterator(Node* current)
        : current(current) { }

    Iterator& operator++() {
        current = current->next;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }

    T& operator*() const {
        return current->data;
    }

private:
    Node* current;
};

template <typename T>
void Deque_linkedList<T>::pushFront(const T& value) {
    Node* newNode = new Node(value);
    if (!front) {
        front = back = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    dequeSize++;
}

template <typename T>
void Deque_linkedList<T>::pushBack(const T& value) {
    Node* newNode = new Node(value);
    if (!back) {
        front = back = newNode;
    } else {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    dequeSize++;
}

template <typename T>
T Deque_linkedList<T>::popFront() {
    if (!front)
        throw std::runtime_error("Deque is empty");

    T value = front->data;
    Node* temp = front;

    if (front == back) {
        front = back = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }

    if (temp != nullptr) {
        delete temp;
    }
    dequeSize--;
    return value;
}

template <typename T>
T Deque_linkedList<T>::popBack() {
    if (!back)
        throw std::runtime_error("Deque is empty");

    T value = back->data;
    Node* temp = back;

    if (front == back) {
        front = back = nullptr;
    } else {
        back = back->prev;
        back->next = nullptr;
    }

    if (temp != nullptr) {
        delete temp;
    }
    dequeSize--;
    return value;
}

template <typename T>
T* Deque_linkedList<T>::toArray() const {
    T* arr = new T[dequeSize];
    Node* current = front;
    int index = 0;
    while (current) {
        arr[index++] = current->data;
        current = current->next;
    }
    return arr;
}

template <typename T>
std::string Deque_linkedList<T>::toString() const {
    if (isEmpty()) {
        return "Deque is empty.";
    }

    std::stringstream ss;
    Node* current = front;
    while (current) {
        ss << current->data;
        if (current->next) {
            ss << ", ";
        }
        current = current->next;
    }
    ss << ".";

    return ss.str();
}

template <typename T>
void Deque_linkedList<T>::clear() {
    while (!isEmpty()) {
        popBack();
    }
}

template <typename T>
bool Deque_linkedList<T>::isEmpty() const {
    return dequeSize == 0;
}

template <typename T>
int Deque_linkedList<T>::size() const {
    return dequeSize;
}

template <typename T>
Deque_linkedList<T>::~Deque_linkedList() {
    qDebug() << "~Deque_linkedList";

    Node* current = front;
    while (current) {
        Node* nextNode = current->next;
        if (current != nullptr) {
            delete current;
        }
        current = nextNode;
    }

    // на всякий случай
    front = nullptr;
    back = nullptr;

    qDebug() << "~Deque_linkedList finished";
}

#endif // DEQUE_LINKEDLISTH_H
