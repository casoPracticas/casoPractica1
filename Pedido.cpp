#include "Pedido.h"
int Pedido::getTam(){return cesta.size();};
void Pedido::nuevoProducto(Producto *p){
        cesta.push_back(p); 
        total= total + p->getPvp();
    };