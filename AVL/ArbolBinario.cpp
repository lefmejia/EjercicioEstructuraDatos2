#include "ArbolBinario.h"
#include <iostream>

void ArbolBinario::print()
{
    raiz->print();
    std::cout << '\n';
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
        std::cout << "{\n";
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
    raiz->Altura = 1 + raiz->AlturaD >= raiz->AlturaI ? raiz->AlturaD : raiz->AlturaI;
    //std::cout << raiz->Altura<<std::endl;
    /*Node* n = raiz;

    do {
        if (n->data == data)
            break;

        if (data < n->data)
        {
            if (n->left == nullptr)
            {
                if (n->right != nullptr)
                    n->Altura++;
                n->left = new Node(data);
                break;
            }
            else
            {
                n = n->left;
            }

        }
        else
        {
            if (n->right == nullptr)
            {
                n->right = new Node(data);
                break;
            }
            else
            {
                n = n->right;
            }
        }

    } while (true);*/
}

void ArbolBinario::insertRec(int data, Node* root)
{
    /*if (raiz == nullptr)
    {
        raiz = new Node(data);
        return;
    }*/


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
            //root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
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
            //root->Altura = root->AlturaD >= root->AlturaI ? root->AlturaD : root->AlturaI;
            return;
        }
    }
}

void ArbolBinario::Balancear(Node* root, int FE)
{
    if (FE < -1)
    {
        if (root->left->left != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->left->AlturaI = 1;
            root->left->AlturaD = 1;
            root->left->Altura = 1;
            rotarD(root);
        }
        else if (root->left->right != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->left->AlturaI = 0;
            root->left->AlturaD = 0;
            root->left->Altura = 0;
            root->left->right->AlturaD = 1;
            root->left->right->AlturaI = 1;
            root->left->right->Altura = 1;
            rotarI(root->left);
            rotarD(root);
        }
    }
    else if (FE > 1)
    {
        if (root->right->right != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->right->AlturaI = 1;
            root->right->AlturaD = 1;
            root->right->Altura = 1;
            rotarI(root);
        }
        else if (root->right->left != nullptr)
        {
            root->AlturaI = 0;
            root->AlturaD = 0;
            root->Altura = 0;
            root->right->AlturaI = 0;
            root->right->AlturaD = 0;
            root->right->Altura = 0;
            root->right->left->Altura = 1;
            root->right->left->AlturaD = 1;
            root->right->left->AlturaI = 1;
            rotarD(root->right);
            rotarI(root);
        }
    }
}

void ArbolBinario::rotarD(Node* root)
{
    if (root == raiz)
    {
        Node* nuevo = root->left;
        root->left = nullptr;
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
        if (root->parent->data < nuevo->data)
            root->parent->right = nuevo;
        else
            root->parent->left = nuevo;
        root->parent = nuevo;
        root->left = nullptr;
        nuevo->right = root;
        nuevo->right->parent = nuevo;
        
        //root = nuevo;
    }
    
}

void ArbolBinario::rotarI(Node* root)
{
    if (root == raiz)
    {
        Node* nuevo = root->right;
        root->right = nullptr;
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
        if (root->parent->data < nuevo->data)
            root->parent->right = nuevo;
        else
            root->parent->left = nuevo;
        root->parent = nuevo;
        root->right = nullptr;
        nuevo->left = root;
        
        //root = nuevo;
    }
}