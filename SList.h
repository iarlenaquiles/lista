#ifndef SLIST_H
#define SLIST_H
#include "SNode.h"
#include <iostream>
using namespace std;
struct SList{

    SNode * head;

    ~SList(){
        this->destroy();
    }
    //Criar
    void criar(){
        head = new SNode;
    }

    void clone(SList lista_other){
        if(this->front() != nullptr){
            this->destroy();
            this->criar();
        }

        auto node = lista_other.front();
        while(node != nullptr){
            this->push_back(node->value);
            node = node->next;
        }
    }

    //inserir
    void push_front(int value){
        SNode * node = new SNode(value, head->next);
        head->next = node;
    }

    void push_back(int value){
        if(this->size() == 0){
            this->push_front(value);
            return;
        }
        auto node = new SNode(value, this->back()->next);
        this->back()->next = node;

    }

    //destruir
    void destroy(){
        if(this->front() == nullptr)
            return;
        auto node = this->front();
        while(node != nullptr){
            this->pop_back();
            node = node->next;
        }
        delete this->head;
        this->head = nullptr;

    }

    //remover
    void pop_front(){
//        if(this->front() == nullptr)
//            return;
//        auto node = this->front();
//        head->next = node->next;
//        delete node;
        remove(this->front()->value);
    }

    void pop_back(){
//        if(this->front()->next == nullptr){
//            if(this->front() == nullptr)
//                return;
//            delete head->next;
//            head->next = nullptr;
//            return;
//        }

//        auto node = this->front();
//        while(node->next->next != nullptr){
//            node = node->next;
//        }
//        delete node->next;
//        node->next = nullptr;
        remove(this->back()->value);
    }

    SNode * remove(int value){
        auto node = this->front();
        auto node_aux = this->head;

        while(node->value != value){
            node_aux = node;
            node = node->next;
        }
        node_aux->next = node->next;
        delete(node);
        return node_aux->next;
    }

    //acessar
    SNode * front(){
        return head->next;
    }

    SNode * back(){
        auto node = this->front();

        while(node->next != nullptr){
            node = node->next;
        }
        return node;
    }

    //visualizar
    void print(){
        auto node = this->front();
        cout << "[ ";
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << "]\n";
    }

    void reverse_print(){
        auto node = this->front();
        SList tmp;
        tmp.criar();

        while(node != nullptr){
            tmp.push_front(node->value);
            node = node->next;
        }

        auto node_aux = tmp.front();
        cout << "[ ";
        while(node_aux != nullptr){
            cout << node_aux->value << " ";
            node_aux = node_aux->next;
        }
        cout << "]\n";


    }

    //manipular
    bool is_empty(){
        //return (this->size() != 0);
        if(this->front() == nullptr)
            return true;
        return false;
    }

    SNode * find(int value){
        auto node = this->front();

        while(node != nullptr){
            if(node->value == value)
                return node;
            node = node->next;
        }

        return nullptr;
    }

    int size(){
        auto node = head->next;
        int cont = 0;

        while(node != nullptr){
            cont++;
            node = node->next;
        }
        return cont;
    }

    bool equals(SList list_other){
        if(this->size() != list_other.size())
            return false;
        if(list_other.is_empty())
            return false;

        auto node = this->front();
        auto node_aux = list_other.front();

        for(;node_aux != nullptr; node = node->next, node_aux = node_aux->next){
            if(node->value != node_aux->value)
                return false;
        }

        return true;
    }

};

#endif // SLIST_H
