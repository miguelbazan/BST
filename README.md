# BST

Class for the Binary Search Tree with functions


public:
 bool search(int data)<<endl;
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
