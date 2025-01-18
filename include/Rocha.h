#ifndef ROCHA_H
#define ROCHA_H

#include "ListadeMinerais.h" 

typedef struct{
    char categoria[20]; //nome
    float peso;
    Lista_minerais minerais; 
    float latitude;
    float longitude;
    
}RochaMineral;
void Inicializa_Rocha(RochaMineral *rocha, Lista_minerais* lista_minerais, float peso, float latitud, float longitude);
void ImprimeRocha(RochaMineral *rocha);
void setCategoria(RochaMineral *rocha);
#endif