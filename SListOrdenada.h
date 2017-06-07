#ifndef SLISTORDENADA_H
#define SLISTORDENADA_H
#include "SNode.h"

#include <iostream>
using namespace std;
struct SListOrdenada{

    SNode * head;

    //Criar
    SListOrdenada(){
        head = new SNode(0);
    }

    void _clone(SListOrdenada lista_other, SNode * node){
        if(node == nullptr)
            return;
        this->insert(node->value);
        _clone(lista_other, node->next);
    }

    void clone(SListOrdenada lista_other){
        _clone(lista_other, lista_other.front());
    }

    //inserir

    //insere o valor de forma ordenado na lista.
    void _insert(SNode * nodeaux, SNode * node, int value){

        SNode * aux;

        if(head->next == nullptr){
            aux = new SNode(value, head->next);
            head->next = aux;
            return;
        }

        if(node == nullptr){
            aux = new SNode(value, this->back()->next);
            this->back()->next = aux;
            return;
        }

        if(node->value > value){
            aux = new SNode(value);
            aux->next = node;
            nodeaux->next = aux;
            return;
        }

        _insert(nodeaux->next, node->next, value);

    }

    void insert(int value){
        _insert(head, head->next, value);
    }

    //destruir
    void rdestroy(SNode * node){
        if(node == nullptr)
            return;
        rdestroy(node->next);
        delete node;
    }

    void destroy(){
        rdestroy(head);
    }

    //remover
    void pop_front(){
        remove(this->front()->value);
    }

    void pop_back(){
        remove(this->back()->value);
    }

    SNode * _remove(SNode * node, int value){
        if(node->next == nullptr)
            return nullptr;
        else if(node->next->value == value){
            auto aux = node->next;
            node->next = aux->next;
            aux->next = nullptr;
            return aux;
        }

        return _remove(node->next, value);
    }

    SNode * remove(int value){
        return _remove(this->head, value);
    }

    //acessar
    SNode * front(){
        return head->next;
    }

    SNode * _back(SNode * node){
        if(node->next == nullptr)
            return node;
        return _back(node->next);
    }

    SNode * back(){
        return _back(this->front());
    }

    //visualizar
    void _print(SNode * node){
        if(node == nullptr)
            return;

        cout << node->value << " ";
        _print(node->next);

    }

    void print(){
        cout << "[";
        _print(head->next);
        cout << "]\n";
    }

    void _reverse_print(SNode * node){
        if(node == nullptr)
            return;

        _reverse_print(node->next);
        cout << node->value << " ";

    }

    void reverse_print(){
        cout << "[ ";
        _reverse_print(this->front());
        cout << "]\n";
    }

    //manipular
    bool _is_empty(SNode * node){
        if(node == nullptr)
            return true;
        return false;
        _is_empty(node->next);
    }

    bool is_empty(){
        return _is_empty(this->front());
    }

    SNode * _find(SNode * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value)
            return node;
        _find(node->next, value);
    }

    SNode * find(int value){
        return _find(head->next, value);
    }

    int _size(SNode * node){
        if(node == nullptr)
            return 0;
        return 1 + _size(node->next);
    }

    int size(){
        return _size(head->next);
    }

    bool _equals(SNode * node, SNode * nodeaux){
        if(node == nullptr && nodeaux == nullptr)
            return true;
        else if(node->value != nodeaux->value)
            return false;
        return _equals(node->next, nodeaux->next);
    }

    bool equals(SListOrdenada lista){
        return _equals(this->head->next, lista.head->next);
    }

};
#endif // SLISTORDENADA_H
