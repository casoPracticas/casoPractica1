#ifndef PHARMADRON_H
#define PHARMADRON_H

#include <list>
#include <map>
#include <iterator>
#include "Cliente.h"
#include "THashCerradaProducto.h"
using namespace std;

class PharmaDron{
    map<string,Cliente> ArbolC;
    list<Producto> lista;   

    THashCerradaProducto miHash;
public:
    
    
    //leer fichero de productos
    void cargaProductos(string fileNameProductos);
    //leer fichero clientes
    void creaClientes(string fileNameClientes);
    //añadir producto a la lista
    void aniadeProducto(Producto &p){lista.push_back(p);}
    
    //añadir cliente al arbol
    void nuevoCliente(Cliente &c){ArbolC.insert(pair<string,Cliente>(c.getDNI(),c));}
    
    //obtener vector con productos
    vector<Producto*> buscaProducto(string subcadena);
    //busqueda en el hash
    vector<Producto*> buscaTerm(string subcadena);
    //acceder al cliente
    Cliente *ingresaCliente(string dni, string pass);
    //borrar un cliente y mandarlo a tomar por saco 
    void borracliente(Cliente c){ArbolC.erase(c.getDNI());}
    //obtener pedido
    Pedido verPedido(Cliente c){return c.getPed();}
    //cambiar texto a numero
    unsigned long djb2(unsigned char *str);
    THashCerradaProducto geth(){return miHash;};
    bool borraT(string termino);
    bool borraPro(Producto *p);
};  


#endif /* PHARMADRON_H */

