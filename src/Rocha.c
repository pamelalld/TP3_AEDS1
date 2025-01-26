#include "../include/Rocha.h" 
#include <string.h> 
#include <stdio.h>




/**
 * @brief Inicializa uma rocha, atribuindo todas as suas informações.
 */
void Inicializa_Rocha(RochaMineral *rocha, Lista_minerais* lista_minerais, float peso, float latitud, float longitude) {
                           
    rocha->peso = peso;                   
    rocha->latitude = latitud;           
    rocha->longitude = longitude;         
    rocha->minerais=*lista_minerais;  
    
    setCategoria(rocha); 
    //printf("Rocha identificada: %s \n",rocha->categoria);
}

/**
 * @brief Imprime as informações de uma rocha.
 */
void ImprimeRocha(RochaMineral *rocha) {
    printf("Peso: %.2f kg\n", rocha->peso);
    printf("Categoria: %s\n", rocha->categoria);
    printf("Localização: (%.2f, %.2f)\n", rocha->latitude, rocha->longitude);
    imprime_lista_minerais(rocha->minerais);  
    printf("\n");
}


/**
 * @brief Verifica os minerais presentes na rocha e compara com combinações conhecidas para atribuir sua categoria.
 */
void setCategoria(RochaMineral *rocha) {
    
    int temFerrolita = contem_mineral(&(rocha->minerais), "Ferrolita");
    int temSolarium = contem_mineral(&(rocha->minerais), "Solarium");
    int temAquavitae = contem_mineral(&(rocha->minerais), "Aquavitae");
    int temTerranita = contem_mineral(&(rocha->minerais), "Terranita");
    int temCalaris = contem_mineral(&(rocha->minerais), "Calaris");
    
    
    if (temFerrolita && !temSolarium && !temAquavitae && !temTerranita && !temCalaris) {
        strcpy(rocha->categoria, "Ferrom");
    }
    else if (temSolarium && !temFerrolita && !temAquavitae && !temTerranita && !temCalaris) {
        strcpy(rocha->categoria, "Solaris");
    }
    else if (temFerrolita && temAquavitae && !temSolarium && !temTerranita && !temCalaris) {
        strcpy(rocha->categoria, "Aquaferro");
    }
    else if (temTerranita && temCalaris && !temFerrolita && !temSolarium && !temAquavitae) {
        strcpy(rocha->categoria, "Terrolis");
    }
    else if (temTerranita && temSolarium && !temFerrolita && !temAquavitae && !temCalaris) {
        strcpy(rocha->categoria, "Terrasol");
    }
    else if (temAquavitae && temTerranita && !temFerrolita && !temSolarium && !temCalaris) {
        strcpy(rocha->categoria, "Aquaterra");
    }
    else if (temCalaris && temAquavitae && !temFerrolita && !temSolarium && !temTerranita) {
        strcpy(rocha->categoria, "Calquer");
    }
    else if (temSolarium && temFerrolita && !temAquavitae && !temTerranita && !temCalaris) {
        strcpy(rocha->categoria, "Solarisfer");
    }
    else if (temTerranita && temFerrolita && !temSolarium && !temAquavitae && !temCalaris) {
        strcpy(rocha->categoria, "Terralis");
    }
    else if (temAquavitae && temCalaris && temFerrolita && !temSolarium && !temTerranita) {
        strcpy(rocha->categoria, "Aquacalis");
    }
    else {
        strcpy(rocha->categoria, "Indefinida");
    }
}

/**
 * @brief Recebe todas as informações de uma rocha e copia para uma outra variável. Funcionalidade utilizada para evitar a parda de atributos da rocha ao ser retirada de um compartimento.
 */
void copia_Rocha(RochaMineral *rocha, Lista_minerais* lista_minerais,float peso, float latitud, float longitude,char* cat) {

                       
    rocha->peso = peso;                   
    rocha->latitude = latitud;           
    rocha->longitude = longitude;         
    strcpy(rocha->categoria,cat);
    inicializa_lista_minerais(&rocha->minerais); 
    for (int i=0;i<lista_minerais->prox_disponivel;i++){
        insere_mineral(&rocha->minerais,lista_minerais->arranjo_minerais[i]);
    }

}/**
 * @brief Verifica a presença de um mineral em uma lista de minerais.
 */

int contem_mineral(Lista_minerais* lista,char* nome){
    if (verifica_l_vazia(lista)) {
        return 0;
    }
    for(int i = lista->primeiro; i < lista->prox_disponivel; i++) {
        if(strcmp(lista->arranjo_minerais[i].nome, nome) == 0) {
            return 1; 
        }
    }
    return 0;
}
