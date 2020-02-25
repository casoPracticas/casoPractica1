#include "THashCerradaProducto.h"
/*
long int THashCerradaProducto::hash1(unsigned long x, int a){
    long int aux;
    aux=(x^2 + 2*x*a + a^2)%tamat;
    return aux;
};//cuadratica
*/
long int THashCerradaProducto::hash1(unsigned long x, int a){
    long int aux;
    aux=( x*2 + a*(2543-x%2543))%tamat;
    return aux;
};//doble, en teoría mejor

//best double aux=( x + a*(2543-x%2543))%tamat;
bool THashCerradaProducto::insertar(unsigned long clave, const string& termino, Producto* dato){
    int i =0;
    long int c;
    while(i<tamat){
        c=hash1(clave,i); //cambio de hash
        if(tabla[c].getMarc() == Estado::VACIO){
            tabla[c].setIni(c,termino);
            if(i>coli) coli=i;
            mcoli = (mcoli+i);
            tabla[c].inserta(dato);
            ++nterm;
            ++npro;
            return true;
        }
        else if(tabla[c].getMarc() == Estado::OCUPADO && tabla[c].getTerm() == termino){
            tabla[c].inserta(dato);
            if(i>coli) coli=i;
            mcoli = (mcoli+i);
            ++npro;
            return true;
        }
    ++i;
    }
    return false;
};
bool THashCerradaProducto::inyectarterm(unsigned long clave, string termino){
    int i =0;
    long int c;
    while(i<tamat){
        c=hash1(clave,i); //cambio de hash
        if(tabla[c].getTerm() == ""){
            tabla[c].setIni(c,termino);
            if(i>coli) coli=i;
            mcoli = (mcoli+i)/2;
            ++nterm;
            return true;
        }
    ++i;
    }
    return false;
};
vector<Producto*> THashCerradaProducto::buscar(unsigned long clave, const string& termino){
    int i =0;
    long int c;
    vector<Producto*> v;
    while(i<tamat){
        c=hash1(clave,i); //cambio de hash
        if(tabla[c].getMarc() == Estado::BORRADO && tabla[c].getTerm()== termino)return v;
        else if(tabla[c].getMarc() == Estado::VACIO) return v;
        else if(tabla[c].getMarc() == Estado::OCUPADO && tabla[c].getTerm()== termino){
            return tabla[c].getVector();
        } 
    ++i;
    }
    return v;
};
void THashCerradaProducto::cambiaTam(long int num_datos_base){
    tamat = num_datos_base/lambda;
    tamat = primosig(tamat);
    Entrada ent;
    for(int i =0; i<tamat; i++){
        tabla.push_back(ent);
    }
};
bool THashCerradaProducto::IsP(int numb){
    if (numb % 2 == 0 || numb % 3 == 0)
        return false;

    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= numb){
        if (numb % (divisor - 1) == 0)
            return false;
        if (numb % (divisor + 1) == 0)
            return false;
        divisor += 6;
    }
    return true;
};

int THashCerradaProducto::primosig(int a){
    while (!IsP(++a)){ }
    return a;
}
bool THashCerradaProducto::borrarTer(unsigned long cl,string ter){
    int i =0;
    long int c;
    vector<Producto*> v;
    while(i<tamat){
        c=hash1(cl,i); //cambio de has
        if(tabla[c].getMarc() == Estado::OCUPADO && tabla[c].getTerm()== ter){
            tabla[c].borrado();
            tabla[c].setMarc(Estado::BORRADO);
            return true;
        } 
    ++i;
    }
    return false;
}



