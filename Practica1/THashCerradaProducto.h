#ifndef THASHCERRADAPRODUCTO_H
#define THASHCERRADAPRODUCTO_H

#include <vector>
#include <string>
#include "Producto.h"
#include "Entrada.h"
using namespace std;

class THashCerradaProducto {
    unsigned int tamat;
    unsigned int npro;
    unsigned int nterm;
    unsigned int coli;
    unsigned int mcoli;
    float lambda= 0.60;
    vector<Entrada> tabla;
    
public:
    
    THashCerradaProducto(){
        tamat=0;
        npro=0;
        nterm=0;
        coli=0;
        mcoli=0;
    };
    
    long int hash1(unsigned long x, int a);//cuadratica
    void cambiaTam(long int num_datos_base); //le inserto el numero de datos y calcula según el lambda el tamaño real de la tabla y se la asigna a tabla en un bucle
    bool insertar(unsigned long clave, const string& termino, Producto* dato); //insertar producto
    bool inyectarterm(unsigned long clave, string termino); //insertar termino cambiando el vacio de la entrada
    vector<Producto*> buscar(unsigned long clave, const string& termino);
    unsigned int tamaTabla(){return tamat;};
    unsigned int numProductos(){return npro;};
    unsigned int numTerminos(){return nterm;};
    unsigned int maxColisiones(){return coli;};
    unsigned int promedioColisiones(){return mcoli/nterm;};
    float factorCarga(){return lambda;};
    bool IsP(int numb);
    int primosig(int a);
    bool borrarTer(unsigned long cl,string ter);
};

#endif /* THASHCERRADAPRODUCTO_H */

