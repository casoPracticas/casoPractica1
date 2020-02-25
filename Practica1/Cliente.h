#ifndef CLIENTE_H
#define CLIENTE_H

#include <fstream>
#include "Pedido.h"
#include "UTM.h"


class PharmaDron;


class Cliente{
    string dni;
    string nombre;
    string pass;
    string direccion;
    UTM posicion;
    Pedido ped;
    PharmaDron *pharma;

public:
    Cliente(string dNi, string name, string pas, string dire, UTM posi, PharmaDron *phar){
        dni=dNi;
        nombre=name;
        pass=pas;
        direccion=dire;
        posicion = posi;
        pharma=phar;
    }
    Cliente(string dNi){
        dni=dNi;
        nombre="";
        pass="";
        direccion="";
    }
    string getDNI(){return dni;}
    
    string getName(){return nombre;}
    
    string getPass(){return pass;}
    
    string getDirec(){return direccion;}
    
    Pedido getPed(){return ped;}
    
    void cambiar(string dNi, string name, string pas, string dire, UTM posi);
    
    vector<Producto*> buscarProducto(string subcadena);
    
    void addProductoPedido(Producto *pro){ped.nuevoProducto(pro);}
    
    Cliente &operator=(Cliente C);
    
    bool operator<(Cliente c){return dni<c.dni;}
    
    bool operator>(Cliente c){return dni>c.dni;}
    
    bool operator==(Cliente c){return dni==c.dni;}
    
    /*ostream operator<<(Cliente c){
        ostream os;
            os  << "Cliente: " << c.nombre
                << " con DNI:" << c.dni
                << ", dirección: " << c.direccion
                << " y posición:" << c.posicion.getLati() << " " 
                << c.posicion.getLong()<<endl;
        return os;
    }*/
    
};

#endif /* CLIENTE_H */

