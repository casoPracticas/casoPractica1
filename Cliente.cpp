#include "Cliente.h"
void Cliente::cambiar(string dNi, string name, string pas, string dire, UTM posi){
        dni=dNi;
        nombre=name;
        pass=pas;
        direccion=dire;
        posicion = posi;
    };
vector<Producto*> Cliente::buscarProducto(string subcadena){
        vector<Producto*> aux;
        for (int i = 0;i<ped.getTam();i++){
            if(ped.getP(i)->descripcion.find(subcadena)!= string::npos){
                aux.push_back(ped.getP(i));
            }
        }
        return aux;
    };
    
Cliente& Cliente::operator=(Cliente C){
        dni=C.dni;
        nombre=C.nombre;
        pass=C.pass;
        direccion=C.direccion;
        posicion = C.posicion;
    };
    

