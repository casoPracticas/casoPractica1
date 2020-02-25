#ifndef ENTRADA_H
#define ENTRADA_H

#include <vector>
#include <string>
#include "Producto.h"

using namespace std;

enum class Estado{VACIO,BORRADO,OCUPADO};
class Entrada {
    long int clave;
    string termino;
    Estado marca;
    vector<Producto*> datos; 
public:
    Entrada(){
        clave =0;
        termino= "";
        marca=Estado::VACIO;
    }
    void setIni(long int c, string t);
    void inserta(Producto *p);
    long int getClave(){return clave;};
    string getTerm(){return termino;};
    Estado getMarc(){return marca;};
    vector<Producto*> getVector(){return datos;};
    void borrado();
    void setMarc(Estado a){marca=a;};
};

#endif /* ENTRADA_H */

