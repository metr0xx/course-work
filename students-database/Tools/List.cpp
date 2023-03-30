#include "iostream"
#include <type_traits>
#include <typeinfo>
#include <cstring>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

#pragma once

template <typename T>
class List {
private:
    T* data;
    size_t length{};

    void fill(T t) {
        this->add(t);
    }

    template <typename... Args>
    void fill(T t, Args... args) {

        this->add(t);
        this->fill(args...);
    }

    void init() {
        this->data = new T[0];
        this->length = 0;
    }
public:
    typedef T* iterator;
    typedef const T* const_iterator;

    iterator begin() { return &data[0]; }
    [[nodiscard]] const_iterator begin() const { return &data[0]; }
    iterator end() { return &data[length]; }
    [[nodiscard]] const_iterator end() const { return &data[length]; }

    List() {
        this->init();
    }

    List(const char* arg) {
        this->init();
        for (int i = 0; i < strlen(arg); i++) {
            this->add(arg[i]);
        }
    }

    List(std::string arg) {
        this->init();
        for (int i = 0; i < arg.length(); i++) {
            this->add(arg[i]);
        }
    }

    template <typename... Args>
    List(T t, Args... args) {

        this->init();
        this->fill(t, args...);
    }

    T& operator[] (int i) {
        return data[i];
    }

    void print() {
        for(int i = 0; i < this->length; i++) {
            std::cout << this->data[i];
        }
    }

    void add(const char* arg) {
        for (int i = 0; i < strlen(arg); i++) {
            this->add(arg[i]);
        }
    }

    T sum() {
        T s = 0;
        for(int i = 0; i < this->length; i++) {
            s += this->data[i];
        }
        return s;
    }

    template <typename... Args>
    void add(T e, Args... args) {
        T* newData = new T[this->length + 1];
        for (int i = 0; i < this->length; i++) {
            newData[i] = std::move(this->data[i]);
        }
        newData[this->length++] = e;
        delete data;
        data = newData;
        add(args...);
    }

    void add(T e) {
        T* newData = new T[this->length + 1];
        for (int i = 0; i < this->length; i++) {
            newData[i] = std::move(this->data[i]);
        }
        newData[this->length++] = e;
        delete data;
        data = newData;
    }

    size_t size() {
        return this->length;
    }

    void remove(int id) {
        if (id < 0 || id >= this->length)
            return;

        T* newData = new T[this->length--];
        for (int i = 0; i < this->length; i++) {
            newData[i] = this->data[i + (i < id ? 0 : 1)];
        }
        delete data;
        data = newData;
    }

    friend List<T> operator + (List<T> s, List<T> ch) {
        List<T> res = *new List();
        for (auto k : s) {
            res.add(k);
        }
        for (auto k : ch) {
            res.add(k);
        }
        return res;
    }

    List<T> operator += (List<T> ch) {
        for (auto k : ch) {
            this->add(k);
        }
        return *this;
    }
};