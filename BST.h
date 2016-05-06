//
//  BST.h
//  Arboles_Binarios
//
//  Created by Miguel Bazán on 10/13/15.
//  Copyright © 2015 MiguelBazan. All rights reserved.
//

#ifndef BST_h
#define BST_h
#include "nodeT.h"
#include <stack>
#include <queue>
class BST
{
public:
    BST();
    ~BST();
    BST(const BST &r);
    bool search(int data);
    bool add(int data);
    void print(int tipo);
    bool del (int dato);
    int count();
    int height();
    void ancestors(int data);
    int wherelevelIIam(int data);
    int max_width();
    int nearst_relative(int dato1, int dato2);
    bool isBalanced();
    bool operator==(BST arbol);
    int elMayor();
    int negativos2();
    stack<int> arriba();
    
    
private:
    nodeT *root;
    void preorden(nodeT *r);
    void inorden (nodeT *r);            // son privados porque es un metodo recursivo que arranca por medio de root que es privado
    void postorden(nodeT *r);
    void delAll(nodeT * r);
    int CuantosHijos(nodeT *r);
    int pred(nodeT *r);
    int succ(nodeT *r);
    int countR(nodeT *r);
    void printLeaves(nodeT *r);
    int muestraAltura(nodeT *r);
    void printporNivel(nodeT *r);
    int getWidth(nodeT *r, int level);
    void Copiar(nodeT *r);
    int getBal(nodeT *r);
    int pariente(int dato1, int dato2, nodeT *r);
    bool igual(nodeT *aux,nodeT *r);
    int negativos(nodeT *R);
    stack<int> inorden2(nodeT *r,stack<int> myStack);
};
int BST::negativos2()
{
    return negativos(root);
}
int BST::negativos(nodeT *r)
{
    
    nodeT *aux = root;
    int iCont = 0;
    if (aux != NULL)
    {
   // negativos(aux->getLeft());
    if (aux->getLeft() < 0)
    {
        iCont++;
    }
    negativos(aux->getRight());
    if (aux->getRight() < 0)
    {
        iCont++;
    }
    }
    return iCont;
    
    
}
int BST::elMayor()
{
    nodeT *aux = root;
    
    while (aux->getRight() != NULL)
    {
        aux = aux->getRight();
    }
    return aux->getData();
}
BST::BST()
{
    root = NULL;
}
BST::BST(const BST &r)
{
    root = NULL;
    Copiar(r.root);
}
void BST::Copiar(nodeT *r)
{
    if (r!= NULL)
    {
    add(r->getData());
    Copiar(r->getLeft());
    Copiar(r->getRight());
    }
}
void BST::delAll(nodeT *r)
{
    if (r != NULL)
    {
        delAll(r->getLeft());
        delAll(r->getRight());
        delete r;
    }
}
BST::~BST()
{
    delAll(root);
}
bool BST::search(int data)
{
    nodeT *aux = root;
    while (aux != NULL)
    {
        if (aux->getData() == data)
        {
            return true;
        }
        
        aux = (aux->getData() > data) ? aux->getLeft() : aux->getRight();
    }
    
    return false;
}
bool BST::add(int data)
{
    if (root == NULL)
    {
        root = new nodeT(data);
    }
    
    nodeT *dad = NULL;
    nodeT *aux = root;
    
    while (aux != NULL)
    {
        if (aux->getData() == data)
        {
            return false;
        }
        dad = aux;
        aux = (aux->getData() > data) ? aux->getLeft() : aux->getRight();
    }
    
    (dad->getData() > data) ? dad->setLeft(new nodeT(data)) : dad->setRight(new nodeT(data));
    return true;
}
void BST::preorden(nodeT *r)
{
    if (r != NULL)
    {
        cout<< r->getData() << " ";
        preorden(r->getLeft());
        preorden(r->getRight());
    }
}
void BST::inorden(nodeT *r)
{
    if (r != NULL)
    {
        inorden(r->getLeft());
        cout<<r->getData()<<" ";
        inorden(r->getRight());
    }
}
void BST::postorden(nodeT *r)           // raiz al ultimo
{
    if (r != NULL)
    {
        postorden(r -> getLeft());
        postorden(r -> getRight());
        cout<< r-> getData() <<" ";
    }
}
void BST::printLeaves(nodeT *r)
{
    if (r != NULL)
    {
        if (r->getLeft() == NULL && r->getRight() == NULL)
        {
        cout<< r->getData() << " ";
        printLeaves(r->getLeft());
        printLeaves(r->getRight());
        }
    }

    
}
void BST::printporNivel(nodeT *r)
{
    if (root == NULL)
    {
        cout<<"No hay datos"<<endl;
    }
    else
    {
        queue<nodeT*> miFila;
        miFila.push(root);
        while (!miFila.empty())
        {
            nodeT *aux = miFila.front();
            miFila.pop();
            cout<<aux->getData()<<" ";
            
            if (aux->getLeft() != NULL)
            {
                miFila.push(aux->getLeft());
            }
            if (aux->getRight() != NULL)
            {
                miFila.push(aux->getRight());
            }
        }
        cout<<endl;
    }
   
}
void BST::print(int tipo)
{
    switch (tipo)
    {
        case 1:
            preorden(root);
            break;
        case 2:
            inorden(root);
            break;
        case 3:
            postorden(root);
            break;
        case 4:
            printLeaves(root);
            break;
        case 5:
            printporNivel(root);
    }
    cout<<endl;
}
int BST::CuantosHijos(nodeT *r)
{
    int iCont = 0;
    
    if (r->getLeft() != NULL)
    {
        iCont++;
    }
    if (r->getRight() != NULL)
    {
        iCont++;
    }
    return iCont;
}
int BST::pred(nodeT *r)
{
    nodeT *aux = r->getLeft();
    
    while (aux->getRight() != NULL)
    {
        aux = aux->getRight();
    }
    return aux->getData();
}
int BST::succ(nodeT *r)
{
    nodeT *aux = r->getRight();
    
    while (aux ->getLeft() != NULL)
    {
        aux = aux->getLeft();
    }
    return aux->getData();
}
bool BST::del(int dato)
{
    nodeT *padre = NULL;
    nodeT *aux = root;
    
    while (aux != NULL && aux->getData() != dato)
    {
        padre = aux;
        aux = (aux ->getData() > dato ? aux->getLeft() : aux->getRight());
    }
    if (aux == NULL)
    {
        return false;
    }
    
    int iCont = CuantosHijos(aux);
    
    switch (iCont)
    {
        case 0:
            if (padre == NULL)
            {
                root = NULL;
            }
            else
            {
                padre->getData() > dato ? padre->setLeft(NULL) : padre->setRight(NULL);
            }
            delete aux;
            break;
            
        case 1:
            if (padre == NULL)
            {
                root = aux->getLeft() != NULL ? aux->getLeft() : aux->getRight();
            }
            else
            {
                if (padre->getData() > dato )
                {
                    if (aux->getLeft() != NULL)
                    {
                        padre->setLeft(aux->getLeft());
                    }
                    else
                    {
                        padre->setLeft(aux->getRight());
                    }
                }
                else
                {
                    if (aux->getLeft() != NULL)
                    {
                        padre->setRight(aux->getLeft());
                    }
                    else
                    {
                        padre->setRight(aux->getRight());
                    }
                }
            }
            delete aux;
            break;
        case 2:
            int d = succ(aux);
            del(d);
            aux->setData(d);
            
            break;
    }
    return true;
}
int BST::countR(nodeT *r)
{
    if (r == NULL)
    {
        return 0;
    }
    return 1 + countR(r->getLeft()) + countR(r->getRight());
}
int BST::count()
{
    return countR(root);
}
int BST::muestraAltura(nodeT *r)
{
    if (r != NULL)
    {
        int left = muestraAltura(r->getLeft());
        int right = muestraAltura(r->getRight());
        return max(left,right) +1 ;
    }
    return 0;
}
int BST::height()
{
    return muestraAltura(root);
}
void BST::ancestors(int data)
{
    stack<int> ans;
    nodeT *aux = root;
    
    while (aux != NULL && aux->getData() != data)
    {
        ans.push(aux->getData());
        aux = (aux->getData() > data ? aux->getLeft() : aux->getRight());
    }
    if (aux == NULL)
    {
        cout<<"No se encontro el dato"<<endl;
    }
    else if (ans.size() == 0)
    {
        cout<<"El dato no tiene ancestros"<<endl;
    }
    else
    {
        while (!ans.empty())
        {
            cout<<ans.top()<<" ";
            ans.pop();
        }
        
        cout<<endl;
    }
}

int BST::wherelevelIIam(int data)
{
    nodeT *aux = root;
    int level = 0;
    
    while (aux != NULL && aux->getData() != data)
    {
        level++;
        aux = (aux->getData() > data ? aux->getLeft() : aux->getRight());
    }
    if (aux == NULL)
    {
        return -1;
    }
    return level;
}
int BST::getWidth(nodeT *r, int level)
{
    if (r == NULL)
    {
        return 0;
    }
    if (level == 1)
    {
        return 1;
    }
    
    return getWidth(r->getLeft(), level-1 + getWidth(r->getRight(), level-1));
}
int BST::max_width()
{
    int iMax = 0;
    
    for (int iR = 0; iR<height(); iR++)
    {
        getWidth(root, iR) > iMax ? iMax=getWidth(root, iR) : iMax = iMax;
    }
    return iMax;
}
int BST::pariente(int dato1,int dato2, nodeT *r)
{
    if (r == NULL)
    {
        return 0;
    }
    else
    {
        if ((dato1 < r->getData() && dato2 > r->getData()) || (dato1 > r->getData() && dato2 < r->getData()))           // es root porque se fue uno a la izq y uno a la derecha
        {
            return r->getData();
        }
        else
        {
            if (dato1 < r->getData() && dato2 < r->getData())
            {
                r = r->getLeft();
                pariente(dato1, dato2, r);
            }
            else
            {
                r= r->getRight();
                pariente(dato1,dato2,r);
            }
        }
        return r->getData();
    }
    
}
int BST::nearst_relative(int dato1, int dato2)
{
    return pariente(dato1, dato2, root);
}
bool BST::igual(nodeT *r1, nodeT *r2)
{
    if (r1 != NULL && r2 != NULL)
    {
        
        if (!igual(r1->getLeft(), r2->getLeft()) ||!igual(r1->getRight(), r2->getRight()))
        {
            
            return false;
        }
        if (r1->getData() == r2->getData()){
            
            return true;
        }
        else
            return false;
    }
    if (r1==r2){
        
        return true;
    }
    return false;
}
bool BST::operator==(BST arbol)
{
    return igual(root, arbol.root);
}
stack<int> BST::arriba()
{
    stack<int> myStack;
    
   return myStack = inorden2(root,myStack);

}
stack<int> BST::inorden2(nodeT *r,stack<int> myStack)
{
    if (r != NULL)
    {
       myStack = inorden2(r->getRight(),myStack);
        myStack.push(r->getData());
      myStack = inorden2(r->getLeft(),myStack);
    }
    return myStack;
}
#endif // BST_h