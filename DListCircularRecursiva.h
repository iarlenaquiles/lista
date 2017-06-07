#ifndef DLISTCIRCULARRECURSIVA_H
#define DLISTCIRCULARRECURSIVA_H
#include "DNode.h"
#include <iostream>
using namespace std;
struct DListCircular{
    DNode * head;
    DNode * tail;

    //criar
    DListCircular(){
        head = new DNode;
        tail = new DNode;
        head->next = tail;
        head->prev = tail;
        tail->prev = head;
        tail->next = head;
    }

    ~DListCircular(){

    }

    void _clone(DNode * node){
        if(node == tail)
            return;
        this->push_back(node->value);
        _clone(node->next);
    }


    void clone(DListCircular lista_other){
        _clone(lista_other.head->next);
    }

    //Destruir
    void rdestroy(DNode * node){
        if(node == tail->next)
            return;
        rdestroy(node->next);
        delete node;
    }

    void destroy(){
        rdestroy(head);
    }

    //inserir
    void insert_before(DNode * node, int value){
        DNode * x = new DNode(value);
        x->next = node;
        x->prev = node->prev;
        node->prev = x;
        x->prev->next = x;
    }

    void push_back(int value){
        insert_before(tail, value);
    }

    void push_front(int value){
        insert_before(head->next, value);
    }

    //visualizar
    void rshow(DNode * node){
        if(node == tail)
            return;
        cout << node->value << " ";
        rshow(node->next);
    }

    void show(){
        cout << "[ ";
        rshow(head->next);
        cout << "]" << endl;
    }

    void _reverse_print(DNode * node){
        if(node == tail)
            return;
        _reverse_print(node->next);
        cout << node->value << " ";
    }

    void reverse_print(){
        cout << "[ ";
        _reverse_print(this->front());
        cout << "]\n";
    }


    //acessar
    DNode * front(){
        return head->next;
    }

    DNode * _back(DNode * node){
        if(node->next == tail)
            return node;
        return _back(node->next);
    }
    DNode * back(){
        return _back(this->front());
    }

    //manipular
    bool _is_empty(DNode * node){
        if(node == tail)
            return true;
        return false;
        _is_empty(node->next);
    }

    bool is_empty(){
        return _is_empty(this->front());
    }

    DNode * _find(DNode * node, int value){
        if(node == tail)
            return nullptr;
        if(node->value == value)
            return node;
        _find(node->next, value);
    }

    DNode * find(int value){
        return _find(head->next, value);
    }

    int _size(DNode * node){
        if(node == tail)
            return 0;
        return 1 + _size(node->next);
    }

    int size(){
        return _size(head->next);
    }

    bool _equals(DListCircular lista, DNode * node, DNode * nodeaux){
        if(this->size() != lista.size())
            return false;
        if(node == tail  || nodeaux == tail)
            return true;
        else if(node->value != nodeaux->value)
            return false;
        return _equals(lista, node->next, nodeaux->next);
    }

    bool equals(DListCircular lista){
        return _equals(lista, this->head->next, lista.front());
    }

    //remover
    void pop_front(){
        remove(this->front()->value);
    }

    void pop_back(){
        remove(this->back()->value);
    }

    DNode * _remove(DNode * node, int value){
        if(node->next == tail)
            return nullptr;
        else if(node->next->value == value){
            auto aux = node->next;
            node->next = aux->next;
            aux->next = nullptr;
            return aux;
        }

        return _remove(node->next, value);
    }

    DNode * remove(int value){
        return _remove(this->head, value);
    }
};
#endif // DLISTCIRCULARRECURSIVA_H
