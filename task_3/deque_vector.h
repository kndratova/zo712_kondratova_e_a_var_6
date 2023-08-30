#ifndef DEQUE_VECTOR_H
#define DEQUE_VECTOR_H

#include <QDebug>
#include <sstream>
#include <vector>

template <typename T>
class Deque_vector {
public:
    Deque_vector() { }

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
        return Iterator(elements.begin());
    }

    Iterator end() {
        return Iterator(elements.end());
    }

    ~Deque_vector() {
        qDebug() << "~Deque_vector()";
        elements.clear();
        qDebug() << "~Deque_vector() finished";
    }

private:
    std::vector<T> elements;
};

template <typename T>
class Deque_vector<T>::Iterator {
public:
    Iterator(typename std::vector<T>::iterator current)
        : current(current) { }

    Iterator& operator++() {
        ++current;
        return *this;
    }

    bool operator!=(const Iterator& other) const {
        return current != other.current;
    }

    T& operator*() const {
        return *current;
    }

private:
    typename std::vector<T>::iterator current;
};

template <typename T>
void Deque_vector<T>::pushFront(const T& value) {
    elements.insert(elements.begin(), value);
}

template <typename T>
void Deque_vector<T>::pushBack(const T& value) {
    elements.push_back(value);
}

template <typename T>
T Deque_vector<T>::popFront() {
    if (isEmpty())
        throw std::runtime_error("Deque is empty");

    T value = elements.front();
    elements.erase(elements.begin());
    return value;
}

template <typename T>
T Deque_vector<T>::popBack() {
    if (isEmpty())
        throw std::runtime_error("Deque is empty");

    T value = elements.back();
    elements.pop_back();
    return value;
}

template <typename T>
T* Deque_vector<T>::toArray() const {
    T* arr = new T[elements.size()];
    std::copy(elements.begin(), elements.end(), arr);
    return arr;
}

template <typename T>
std::string Deque_vector<T>::toString() const {
    if (isEmpty()) {
        return "Deque is empty.";
    }

    std::stringstream ss;
    for (size_t i = 0; i < elements.size(); ++i) {
        ss << elements[i];
        if (i < elements.size() - 1) {
            ss << ", ";
        }
    }
    ss << ".";

    return ss.str();
}

template <typename T>
void Deque_vector<T>::clear() {
    elements.clear();
}

template <typename T>
bool Deque_vector<T>::isEmpty() const {
    return elements.empty();
}

template <typename T>
int Deque_vector<T>::size() const {
    return elements.size();
}

#endif // DEQUE_VECTOR_H
