#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "mock.h"
#include "domicilio.h"

void getName(char name [])
{
    char names[][30]= {"Juan","Apolonio","Tulio","Maria","Julian", "Arturo", "Pascual", "Carlos", "Ramon", "Beatriz", "Teresa", "Patricia", "Ines", "Pedro", "Pablo", "Daniel",
                       "Benjamin", "Selene", "Diego", "Santiago", "Gustavo", "Jorgelina", "Azul", "Leandro", "Christian", "Devora", "Laureano", "Laia", "Humberto",
                       "Sofia", "Nora", "Natalia", "Ricardo", "Lorena", "Analia", "Marisol", "Federico", "Victoria", "Ludmila", "Luz", "Catalina", "Thiago",
                       "Mateo", "Lautaro", "Martin", "Martina", "Taiel", "Natanael", "Hector", "Gabriel", "Kiara", "Dylan", "Brandon", "Eithan", "Polo", "Luciano", "Agustina",
                       "Aylen", "Maximo", "Maximiliano", "Penelope", "Ambar", "Robert", "Navila"
                      };
    strcpy(name,names[rand()%(sizeof(names)/30)]);
}

void getLastName(char lastName [])
{
    char lastNames[][30]= {"Jurjo","Trozo","Jon","Quito","Molina", "Chavez", "Paz", "Llopart", "Gimenez", "Olivera", "Cortez", "Cheres", "Butaccio",
                           "Sanchez", "Fernandez", "DelRio", "DelMar", "Maglione", "Aquino", "Querales", "Libonati", "Lima", "Linares", "Garcia", "Almiron", "Costa", "Turtur", "Cepeda",
                           "Aguirre", "Perales", "Amalfitano", "Dolce", "Tusar", "Roldan", "Ochoa", "Hidalgo", "Kristiansen", "Millan", "Martinez", "Ale", "Irene", "BadenPowell", "Rios", "Vilar", "Borrel",
                           "Luna", "Nunez", "Bordon", "Bonilla", "Maldonado", "Ledesma", "Bravo", "Torres", "Messi", "Suarez", "Aguero", "Romero", "Barco", "Montiel", "Mcalister", "Acunia", "Armani", "Maradona", "Paez", "Paic", "Cerati",
                           "Espineta", "Porro", "Fazolari", "Luque", "Milei"
                          };
    strcpy(lastName, lastNames[rand()%(sizeof(lastNames)/30)]);
}


void getDni(char dni[])
{
    int numero = rand()%1000000+37826321;
    char cadena[10];
    sprintf(cadena, "%d", numero);
    strcpy(dni, cadena);
}

void getEmailCliente(stCliente* cliente)
{
    char dominio[][30]= {"@gmail.com","@hotmail.com","@yahoo.com","@hotmail.com.ar"};
    strcpy(cliente->email, cliente->nombre);
    char id[20];
    sprintf(id, "%d", cliente->id);


    char *ptr = strcat(cliente->email, cliente->apellido);

    ptr = strcat(cliente->email, id);
    ptr = strcat(cliente->email, dominio[rand()%(sizeof(dominio)/30)]);




}

void getTelefonoRandom(char telefono[])
{
    long numero = rand()%1000000+2233000000;
    char celu[12];

    sprintf(celu, "%lld", numero);
    strcpy(telefono, celu);
}

void getCliente2ArchivoRandom(char nombreArchivo[])
{
    FILE* archi= fopen(nombreArchivo, "ab");
    stCliente a;
    if(archi)
    {
        getName(a.nombre);
        getLastName(a.apellido);
        getDni(a.dni);
        getTelefonoRandom(a.telefono);
        a.domicilio=getDomicilioRandom();
        fseek(archi,0,SEEK_END);
        a.id= (ftell(archi)/sizeof(stCliente)+1);
        getEmailCliente(&a);
        a.eliminado = 0;
        a.nroCliente=a.id;
        fwrite(&a,sizeof(stCliente),1, archi);


        fclose(archi);
    }
}


void getCalle(char calle [])
{
    char calles[][30]= {"Avenida Constitucion","Avenida Colon","Avenida Independencia","Avenida Luro","Avenida Juan B. Justo","Avenida Jara",
                        "Avenida Mario Bravo","Avenida Champagnat","Avenida Pedro Luro","Boulevard Maritimo","Guemes","San Martin","Mitre","Alberti",
                        "Entre Rios","12 de Octubre","Peralta Ramos","Tucuman","Alsina","Buenos Aires"
                       };

    strcpy(calle,calles[rand()%(sizeof(calles)/30)]);
}


void getLocalidad (char localidad [])
{

    char localidades [] [30]= {"Mar del Plata","Batan","Chapadmalal","Sierra de los Padres"};

    strcpy ( localidad, localidades [rand () % (sizeof (localidades))/30]);

}

void getProvincia (char provincia [])
{

    char provincias [] [20]= {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Cordoba","Corrientes","Entre Rios","Formosa","Jujuy","La Pampa",
                              "La Rioja","Mendoza","Misiones","Neuquen","Rio Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego",
                              "Tucuman"
                             };


    strcpy (provincia, provincias [rand () % sizeof (provincias) /20]);

}

void getCpos (char cPos [])
{
       for (int i = 0; i < 4; i++) {
        cPos[i] = (rand() % 10) + '0'; // Convertir el n�mero a valor ASCII de char
    }
    cPos[4] = '\0'; // Agregar el car�cter nulo al final de la cadena

    return cPos;
}



void getNumDomicilio (char numeroDomicilio [])
{

    int numDom=rand ()%100 + 999;
    char cadena [10];
    sprintf (cadena, "%d", numDom);
    strcpy ( numeroDomicilio, cadena);

}

stDomicilio getDomicilioRandom ()
{
    stDomicilio d;

    getCalle (d.calle);
    getNumDomicilio (d.nro);
    getLocalidad(d.localidad);
    getProvincia(d.provincia);
    getCpos (d.cPos);

    return d;
}
