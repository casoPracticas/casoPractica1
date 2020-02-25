#ifndef Producto_H
#define Producto_H


#include <string>
using std::string;


class Producto{   
public:
    string codigo;
    string descripcion;
    float pvp;
    Producto(){
       codigo="";
       descripcion="";
       pvp=0;
    };
    Producto(const Producto &e){
        codigo=e.codigo;
        descripcion=e.descripcion;
        pvp=e.pvp;
    };
    Producto(string cod, string des,float pre){
        codigo=cod;
        descripcion=des;
        pvp=pre;
    };
    void cambiar(string cod, string des,float pre);   
    float getPvp(){return pvp;}
    string getCod(){return codigo;}
    string getDes(){return descripcion;}
};
#endif /* Producto_H */

