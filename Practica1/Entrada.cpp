#include "Entrada.h"
void Entrada::inserta(Producto *p){
        datos.push_back(p);
        marca=Estado::OCUPADO;
    }
void Entrada::setIni(long int c, string t){
    clave=c;
    termino=t;
    marca=Estado::VACIO;
};
void Entrada::borrado(){
    datos.clear();
};
    

