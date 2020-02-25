#ifndef UTM_H
#define UTM_H

class UTM{
    float latitud;
    float longitud;

public:
    //constructor vacío
    UTM(){
        latitud=0;
        longitud=0;
    }
    //constructor de parametros
    UTM(float l, float lon){
        latitud=l;
        longitud=lon;
    }
    UTM &operator=(UTM &orig){
        latitud=orig.getLati();
        longitud=orig.getLong();
    }
    float getLati(){return latitud;}
    float getLong(){return longitud;}
    void setLati(float l){latitud=l;}
    void setLong(float lon){latitud=lon;}
};
#endif /* UTM_H */

