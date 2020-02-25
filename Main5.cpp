//int idpedido = 0;
#include <iostream>
#include <fstream>
#include <exception>
#include <list>
#include <map>
#include <vector>
#include <iterator>
#include "PharmaDron.h"
#include "UTM.h"
#include "Producto.h"
#include "Entrada.h"
#include "THashCerradaProducto.h"

using namespace std;

//calcular tamaño, numero elementos diferentes de definiciones partido el lamda que queremos y todo eso pues el siguiente primo
//en un main prueba hacer calculo de tablas hash con el numero de terminos de productos para saber como hacerlo
//un set con todos los terminos (lo podremos usar después), insertamos en el hash todo y vemos la colisiones.
//recuerda, no es dificil tenerlo en mente, pero programa poco a poco toda la semana, me lo agradecerás aunque no strimees

void prueba(){
    PharmaDron hola;
    hola.cargaProductos("pharma1.csv");
    cout<< "Terminos " <<hola.geth().numTerminos() << endl
        << "Numero de colisiones maximo " << hola.geth().maxColisiones() << endl
        << "Numero medio de colisiones " << hola.geth().promedioColisiones() << endl
        << "Lambda elegida " << hola.geth().factorCarga() << endl
        << "Tamanio total de tabla " << hola.geth().tamaTabla()<< endl;
}
int main(int argc, char**argv) {
    prueba();
    //inicializar Pharmadron y el nuevo cliente que se añade
    vector<Producto*> aux;
    PharmaDron hola;
    hola.cargaProductos("pharma1.csv");
    hola.creaClientes("clientes.csv");
    Cliente *c1=hola.ingresaCliente("68994208T","eoKr5a");
    Cliente *c2=hola.ingresaCliente("76988790F","2VuCOc6Il");
    Cliente *c3=hola.ingresaCliente("57356354P","YYm9hS");
    aux=hola.buscaTerm("inyectable");
    
    for(int i=0; i<aux.size();i++){
        c1->addProductoPedido(aux[i]);
    }
    
    aux=hola.buscaTerm("150mg");
    for(int i=0; i<aux.size();i++){
        if(aux[i]->pvp < 50.0){
            c2->addProductoPedido(aux[i]);
        }
    }
    
    cout<<c1->getPed().getP(4)->descripcion<<endl;
    cout<<c2->getPed().getP(3)->descripcion<<endl;
    
    hola.borraT("150mg");
    aux=hola.buscaTerm("150mg");
    for(int i=0; i<aux.size();i++){
        if(aux[i]->pvp < 50.0){
            c3->addProductoPedido(aux[i]);
        }
    }
    //hola.borraPro(aux[0]);
    cout<<"Despues del borrado el termino tiene "<<c3->getPed().getTam()<< " productos"<<endl;
    
    fflush;
    system("PAUSE");
    
    return 0;
}
