# BST

Class for the Binary Search Tree with functions


public:
 bool search(int data) <br />
    bool add(int data)<br />
    void print(int tipo)<br />
    bool del (int dato)<br />
    int count()<br />
    int height()<br />
    void ancestors(int data)<br />
    int wherelevelIIam(int data)<br />
    int max_width()<br />
    int nearst_relative(int dato1, int dato2)<br />
    bool isBalanced()<br />
    bool operator==(BST arbol)<br />
    int elMayor()<br />
    int negativos2()<br />
    stack<int> arriba()<br />
    
    
  private:
    nodeT *root;
    void preorden(nodeT *r);<br />
    void inorden (nodeT *r); <br />     
    void postorden(nodeT *r);<br />hol
    void delAll(nodeT * r);<br />
    int CuantosHijos(nodeT *r);<br />
    int pred(nodeT *r);<br />
    int succ(nodeT *r);<br />
    int countR(nodeT *r);<br />
    void printLeaves(nodeT *r);<br />
    int muestraAltura(nodeT *r);<br />
    void printporNivel(nodeT *r);<br />
    int getWidth(nodeT *r, int level);<br />
    void Copiar(nodeT *r);<br />
    int getBal(nodeT *r);<br />
    int pariente(int dato1, int dato2, nodeT *r);<br />
    bool igual(nodeT *aux,nodeT *r);<br />
    int negativos(nodeT *R);<br />
    stack<int> inorden2(nodeT *r,stack<int> myStack);<br />
