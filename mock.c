#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "mock.h"


void getCalle(char calle [])
{
    char calles[][30]= {"Avenida Constitución","Avenida Colón","Avenida Independencia","Avenida Luro","Avenida Juan B. Justo","Avenida Jara",
                        "Avenida Mario Bravo","Avenida Champagnat","Avenida Pedro Luro","Boulevard Marítimo","Calle Güemes","Calle San Martín","Calle Mitre","Calle Alberti",
                        "Calle Entre Ríos","Calle 12 de Octubre","Calle Peralta Ramos","Calle Tucumán","Calle Alsina","Calle Buenos Aires"
                       };

    strcpy(calle,calles[rand()%(sizeof(calles)/30)]);
}


void getLocalidad (char localidad [])
{

    char localidades [] [20]= {"Mar del Plata","Batán","Chapadmalal","Sierra de los Padres"};

    strcpy ( localidad, localidades [rand () % (sizeof (localidades)/20]);

}

void getProvincia (char provincia [])
{

    char provincias [] [20]= {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa",
                              "La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego",
                              "Tucumán"
                             };


    strcpy (provincia, provincias [rand () % sizeof (provincias) /20]);

}

void getCpos (char cPos [])
{
       printf(codigoPostal, "%04d", rand() % 10000);

}

void getNumDomicilio (char numeroDomicilio [])
{

    int numDom=rand ()%100 + 9999;
    char cadena [10];
    printf (cadena, "%d", numDom);
    strcpy ( numeroDomicilio, cadena);

}


