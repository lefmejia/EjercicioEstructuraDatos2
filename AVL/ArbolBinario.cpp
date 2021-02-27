#include "ArbolBinario.h"
#include <iostream>
#include <ctime>
#include <iomanip>


void ArbolBinario::print()
{
   // raiz->print();
   // std::cout << '\n';
    if (raiz == nullptr)
        std::cout << "Arbol vacio!" <<
        std::endl;

    else if (raiz->Altura > 4)
        std::cout << "Not currently supported!" <<
        std::endl;

    else {
        int max = raiz->Altura;
        for (int depth = 0; depth <= max; depth++) {
            printSubtree(raiz, depth, max - depth + 1, true);
            std::cout << std::endl;
        }
    }
}

void ArbolBinario::print2()
{
    raiz->print();
    std::cout << '\n';
}

void ArbolBinario::Node::print()
{
    std::cout << data << '\n';

    if (left != nullptr || right != nullptr)
    {
        std::cout << "{";
        if (left != nullptr)
        {
            left->print();
        }
        if (right != nullptr)
        {
            right->print();
        }

        std::cout << '}';
    }

    //std::cout<< data <<'\n';
}

void ArbolBinario::Node::print2()
{
    if (left != nullptr)
        left->print2();

    std::cout << data << ' ';

    if (right != nullptr)
        right->print2();

    //std::cout<< data <<'\n';
}


void ArbolBinario::insert(int data)
{
    if (raiz == nullptr)
    {
        raiz = new Node(data);
        return;
    }

    insertRec(data, raiz);
    raiz->Altura = raiz->AlturaD >= raiz->AlturaI ? raiz->AlturaD : raiz->AlturaI;
}

void ArbolBinario::insertRec(int data, Node* root)
{

    if (root->data == data)
        return;

    if (data < root->data)
    {
        if (root->left == nullptr)
        {
            root->left = new Node(data);
            root->left->parent = root;
            root->AlturaI++;
            root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
            //if (root->right == nullptr)
            //{
            //    //root->Altura++;
            //    return 1;
            //}
            //else
            //    return 0;
            return;
        }
        else
        {
            //n = root->left;
            insertRec(data, root->left);
            root->AlturaI = root->left->Altura + 1;
            root->FactorEquilibrio = root->AlturaD - root->AlturaI;
            if (root->FactorEquilibrio < -1 || root->FactorEquilibrio>1)
            {
                Balancear(root, root->FactorEquilibrio);
                /*root->AlturaI = 0;
                root->AlturaD = 0;*/
                
            }
            root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
            return;
        }

    }
    else
    {
        if (root->right == nullptr)
        {
            root->right = new Node(data);
            root->right->parent = root;
            root->AlturaD++;
            root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
            //if (root->left == nullptr)
            //{
            //    //root->Altura++;
            //    return 1;
            //}
            //else
            //    return 0;
            return;
        }
        else
        {
            insertRec(data, root->right);
            root->AlturaD = root->right->Altura + 1;
            root->FactorEquilibrio = root->AlturaD - root->AlturaI;
            if (root->FactorEquilibrio < -1 || root->FactorEquilibrio>1)
            {
                Balancear(root, root->FactorEquilibrio);
                /*root->AlturaI = 0;
                root->AlturaD = 0;*/
                
            }
            root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
            return;
        }
    }
}

void ArbolBinario::Balancear(Node* root, int FE)
{
    if (FE < -1)
    {
        if (root->left->right != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->left->AlturaI = 0;
            root->left->AlturaD = 0;
            root->left->Altura = 0;
            root->left->right->AlturaD += 1;
            root->left->right->AlturaI += 1;
            root->left->right->Altura += 1;
            rotarI(root->left);
            rotarD(root);
        }
        else if (root->left->left != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->left->AlturaI += 0;
            root->left->AlturaD += 1;
            root->left->Altura = root->left->AlturaD > root->left->AlturaI ? root->left->AlturaD : root->left->AlturaI;
            rotarD(root);
        }
    }
    else if (FE > 1)
    {
        if (root->right->left != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->right->AlturaI = 0;
            root->right->AlturaD = 0;
            root->right->Altura = 0;
            root->right->left->Altura += 1;
            root->right->left->AlturaD += 1;
            root->right->left->AlturaI += 1;
            rotarD(root->right);
            rotarI(root);
        }
        else if (root->right->right != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->right->AlturaI += 1;
            root->right->AlturaD += 0;
            root->right->Altura = root->right->AlturaD > root->right->AlturaI ? root->right->AlturaD : root->right->AlturaI;
            rotarI(root);
        }
    }
}

void ArbolBinario::rotarD(Node* root)
{
    if (root == raiz)
    {
        Node* nuevo = root->left;
        root->left = root->left->right;
        root->parent = nuevo;
        nuevo->right = root;
        nuevo->parent = nullptr;
        nuevo->right->parent = nuevo;
        root = nuevo;
        raiz = root;
    }
    else
    {
        Node* nuevo = root->left;
        nuevo->parent = root->parent;
        nuevo->right = root;

        if (root->parent->data < nuevo->data)
            root->parent->right = nuevo;
        else
            root->parent->left = nuevo;
        root->parent = nuevo;

        if (root->left->right != nullptr)
        {
            root->parent = root->left;
            root->left = root->left->right;
        }
        else if (root->left->left != nullptr)
        {
            root->parent = root->left;
            root->parent->right = root->left->left;
        }
        else
        {
            root->left = nullptr;
        }
        //nuevo->right->parent = nuevo;
        
        //root = nuevo;
    }
    
}

void ArbolBinario::rotarI(Node* root)
{
    if (root == raiz)
    {
        Node* nuevo = root->right;
        root->right = root->right->left;
        root->parent = nuevo;
        nuevo->left = root;
        nuevo->parent = nullptr;
        nuevo->left->parent = nuevo;
        root = nuevo;
        raiz = root;
    }
    else
    {
        Node* nuevo = root->right;
        nuevo->parent = root->parent;
        nuevo->left = root;
        if (root->parent->data < nuevo->data)
            root->parent->right = nuevo;
        else
            root->parent->left = nuevo;
        root->parent = nuevo;

        if (root->right->left != nullptr)
        {
            root->parent = root->right;
            root->right = root->right->left;
        }
        else if (root->right->right != nullptr)
        {
            root->parent = root->right;
            root->parent->left = root->right->right;
        }
        else
        {
            root->right = nullptr;
        }
        
        //nuevo->left->parent = nuevo;
        //root = nuevo;
    }
}

void ArbolBinario::printSubtree(Node* subtree, int depth,
    int level, bool first) {

    if (depth > 0) {
        if (subtree == nullptr) {
            printSubtree(subtree, depth - 1, level, first);
            printSubtree(subtree, depth - 1, level, false);
        }
        else {
            printSubtree(subtree->left, depth - 1,
                level, first);
            printSubtree(subtree->right, depth - 1,
                level, false);
        }
    }
    else if (subtree == nullptr)
        std::cout << std::setw((first) ?
            spacing(level) / 2 : spacing(level)) << "-";

    else
        std::cout << std::setw((first) ?
            spacing(level) / 2 : spacing(level)) <<
        subtree->data;
}

int ArbolBinario::spacing(int level) {
    int result = 2;
    for (int i = 0; i < level; i++)
        result += result;
    return result;
}