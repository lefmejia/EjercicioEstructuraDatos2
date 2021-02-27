#pragma once
#ifndef ARBOL_BINARIO_
#define ARBOL_BINARIO_

class ArbolBinario
{
public:

    class Node
    {
    public:
        Node(int data)
            : data(data), left(nullptr), right(nullptr),FactorEquilibrio(0),Altura(0),AlturaD(0),AlturaI(0),parent(nullptr)
        {}
        void print();
        void print2();
        int data;
        Node* left;
        Node* right;
        Node* parent;
        int Altura;
        int AlturaD;
        int AlturaI;
        int FactorEquilibrio;

    };
    ArbolBinario()
        :raiz(nullptr) {}

    void insert(int data);
    void print();
    void print2();
    void Balancear(Node*, int);
    int AlturaArbol() {return raiz != nullptr ? (raiz->AlturaD > raiz->AlturaI? raiz->AlturaD : raiz->AlturaI) : 0; }
    void rotarD(Node*);
    void rotarI(Node*);

private:
    Node* raiz;
    void insertRec(int data, Node* root);
};
#endif // !ARBOL_BINARIO_
