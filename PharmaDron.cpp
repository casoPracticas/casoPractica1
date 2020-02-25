#include "PharmaDron.h"
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

void PharmaDron::cargaProductos(string fileNameProductos){
        set<string> terminos;
        unsigned char* unc;
        ifstream archivo;  
        stringstream term;
        string linea="";
        string num="";
        string desc="";
        string pvp="0";
        char delim = ';';
        bool prueba = true;
        Producto nuevo(num,desc,stof(pvp));
        archivo.open(fileNameProductos);    
        if(archivo.good()){
            while (!archivo.eof()){
            
            getline(archivo, num, delim);
            getline(archivo,desc, delim);
            getline(archivo,pvp,delim);
            replace(pvp.begin(),pvp.end(),',','.');
            nuevo.cambiar(num,desc,stof(pvp));

            try{lista.push_back(nuevo);}    //insercion de datos
            catch(exception &e){cout<< '\n' << e.what();}
            
            transform(desc.begin(), desc.end(), desc.begin(), ::tolower);
            
            //creacion del set  
            term.str(desc);
            while(term.tellp()==0){
                getline(term,linea,' ');     
                if(linea.size() >= 4){
                    terminos.insert(linea);
                }
            }
            term.clear();
            getline(archivo,linea);
            }           
        }
        //carga del hash   
        unsigned long a;
        string aux;
        miHash.cambiaTam(terminos.size());
        
        list<Producto>::iterator it = lista.begin(); 
        while(it != lista.end()){ 
            aux =(*it).getDes();
            transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
            term.str(aux);
            while(term.tellp()==0){
                getline(term,linea,' ');     
                
                if(linea.size() >= 4){
                    unc = (unsigned char*)linea.c_str();
                    a = djb2(unc);
                    miHash.insertar(a,linea,&(*it));

                }
                
            }
            term.clear();
            ++it;
        }
        //cout<< miHash.numTerminos() << "ccc" << miHash.maxColisiones() << " " <<miHash.tamaTabla();
        
    };
void PharmaDron::creaClientes(string fileNameClientes){
        ifstream arch;   
        string vacio="";
        string dni="";
        string name="";
        string contra="";
        string direc="";
        string lati="0.0";
        string longi="0.0";
        char del = ';';
        UTM utm(stof(lati),stof(longi));
        Cliente cli(dni,name,contra,direc,utm, this);
        
        arch.open(fileNameClientes);    
        if(arch.good()){
            getline(arch,vacio);
            while (!arch.eof()){
            
            getline(arch, dni, del);
            getline(arch,contra, del);
            getline(arch,name,del);
            getline(arch,direc,del);
            getline(arch,lati,del);
            replace(lati.begin(),lati.end(),',','.');
            getline(arch,longi,del);
            replace(longi.begin(),longi.end(),',','.');
            
            utm.setLati(stof(lati));
            utm.setLong(stof(longi));
            
            cli.cambiar(dni,name,contra,direc,utm);
            
            try{ArbolC.insert(pair<string,Cliente>(cli.getDNI(),cli));}    //insercion de datos
            catch(exception &e){cout<< '\n' << e.what();}          
            getline(arch,vacio);
            }           
        }
    };
    
vector<Producto*> PharmaDron::buscaProducto(string subcadena){
        vector<Producto*> aux;
        Producto *p;
        list<Producto>::iterator it = lista.begin();
        while(it != lista.end()){
            if((*it).descripcion.find(subcadena)!= string::npos){
                p=&(*it);
                aux.push_back(p); 
            }
            ++it;
        }
    return aux;    
    };
vector<Producto*> PharmaDron::buscaTerm(string subcadena){
    unsigned char *unc = (unsigned char*)subcadena.c_str();
    return miHash.buscar(djb2(unc),subcadena);
};
Cliente* PharmaDron::ingresaCliente(string dni, string pass){
        map<string,Cliente>::iterator i = ArbolC.find(dni);
            if(i != ArbolC.end()){
                if((*i).second.getPass() == pass)
                    return &(*i).second;
            }           
        return 0;
};
unsigned long PharmaDron::djb2(unsigned char *str){
    unsigned long hash = 5381;
    int c;
    while (c = *str++) hash = ((hash << 5) + hash) + c;
    return hash;
};
bool PharmaDron::borraT(string termino){
    string aux = termino;
    unsigned char *unc = (unsigned char*)aux.c_str();
    miHash.borrarTer(djb2(unc),termino);
};
bool PharmaDron::borraPro(Producto *p){
    list<Producto>::iterator it = lista.begin();
        while(it != lista.end()){
            if((*it).descripcion.find(p->descripcion)!= string::npos){
                (*it).cambiar("","",0.0);
            }
            ++it;
        }
};


    