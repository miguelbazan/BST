//
//  main.cpp
//  Arboles_Binarios
//
//  Created by Miguel Bazán on 10/13/15.
//  Copyright © 2015 MiguelBazan. All rights reserved.
//

#include <iostream>
using namespace std;
#include "BST.h"
int main(int argc, const char * argv[])
{
    BST miArbol;
    BST miArbol2;
    
    
    miArbol.add(10);
    miArbol.add(40);
    miArbol.add(42);
    miArbol.add(30);        // 1. preorden 2. inorden 3. postorden
    miArbol.add(20);
    miArbol.add(15);
    miArbol.add(5);
    miArbol.add(8);
    miArbol.add(7);
    miArbol.add(6);
    miArbol.add(2);
    miArbol.add(21);
    
    miArbol2.add(10);
    miArbol2.add(40);
    miArbol2.add(42);
    miArbol2.add(30);        // 1. preorden 2. inorden 3. postorden
    miArbol2.add(20);
    miArbol2.add(15);
    miArbol2.add(5);
    miArbol2.add(8);
    miArbol2.add(7);
    miArbol2.add(6);
    miArbol2.add(2);
    miArbol2.add(100);
    
    miArbol.print(1);
    miArbol.print(2);
    
     miArbol.print(3);
    
        miArbol.del(15);
    
    cout<<"El arbol tiene: "<<miArbol.count()<<" nodos"<<endl;
    
    cout<<"La altura del arbol es: "<<miArbol.height()<<endl;
    
    cout<<"Los ancestros de 35 son: ";
    miArbol.ancestors(35);
    cout<<"Los ancestros de 10 son: ";
    miArbol.ancestors(10);
    cout<<"Los ancestros de 41 son: ";
    miArbol.ancestors(41);
    
    cout<<"El 25 esta en el nivel: "<<miArbol.wherelevelIIam(25)<<endl;
    
   
    cout<< miArbol.nearst_relative(4,8 )<<endl;
    
    cout<<miArbol.elMayor()<<endl;
    
    cout<<miArbol.negativos2()<<endl;
    
   if (miArbol == miArbol2)
    {
        cout<<"SIII"<<endl;
    }
    else
        cout<<"nNOO"<<endl;
    
    stack<int> myStack1 = miArbol.arriba();
    
    while (!myStack1.empty())
    {
        cout<<myStack1.top()<<" ";
        myStack1.pop();
    }
    
        return 0;
}
