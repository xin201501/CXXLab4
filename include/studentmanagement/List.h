#pragma once
#include "StudentManagement.h"
#include <iostream>
template<class T>
class List {
    friend class StudentManagement;

public:
    List() : pFirst(new Node{}) {}//构造函数
    void Add(T &value) {
        auto newNode = new Node{pFirst->pNext, &value};
        pFirst->pNext = newNode;
    }//在Link表头添加新结点
    void Remove(T &value) {
        auto pre = pFirst, cur = pFirst->pNext;
        for (; cur && *cur->pT != value; cur = cur->pNext, pre = pre->pNext)
            ;
        if (cur == nullptr) { return; }
        auto tmp = cur;
        pre->pNext = cur->pNext;
        delete tmp;
    }//在Link中删除含有特定值的元素
    T *Find(T &value) {
        Node *cur = pFirst->pNext;
        if (cur == nullptr) {
            return nullptr;
        }
        while (cur) {
            if (*cur->pT == value) {
                return cur;
            }
            cur = cur->pNext;
        }
        return nullptr;
    }//查找含有特定值的结点
    void PrintList() {
        Node *cur = pFirst->pNext;
        std::cout << "list{";
        if (cur == nullptr) {
            std::cout << "}";
            return;
        }
        while (cur->pNext) {
            std::cout << cur->pT->toString() << ',';
            cur = cur->pNext;
        }
        std::cout << cur->pT->toString() << "}";
    }// 打印输出整个链表
    ~List() {
        Node *tmp;
        while (pFirst) {
            tmp = pFirst->pNext;
            delete pFirst;
            pFirst = tmp;
        }
    }

protected:
    struct Node {
        Node *pNext;
        T *pT;
    };
    Node *pFirst;//链首结点指针
};