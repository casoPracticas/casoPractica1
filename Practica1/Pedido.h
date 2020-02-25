#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include "Producto.h"
using namespace std; 

class Pedido {
    int ID;
    enum Estados{PAGADO,ENALMACEN,ENTRANSITO,ENTREGADO};
    Estados estado;
    vector<Producto*> cesta;
    float total;
    
public:
    Pedido(){
        //ID = idpedido;
        estado = PAGADO;
        //idpedido++;
        total=0;
    }
    
    void nuevoProducto(Producto *p);
    float importe(){return total;}
    Producto* getP(int n){return cesta[n];}
    int getTam();
    void setEstado(Estados a){estado=a;}
};

#endif /* PEDIDO_H */

