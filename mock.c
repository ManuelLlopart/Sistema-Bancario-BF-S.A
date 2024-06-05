#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "mock.h"

void getName(char name [])
{
    char names[][30]={"Juan","Apolonio","Tulio","Maria","Julian", "Arturo", "Pascual", "Carlos", "Ramon", "Beatriz", "Teresa", "Patricia", "Ines", "Pedro", "Pablo", "Daniel",
     "Benjamin", "Selene", "Diego", "Santiago", "Gustavo", "Jorgelina", "Azul", "Leandro", "Christian", "Devora", "Laureano", "Laia", "Humberto",
     "Sofia", "Nora", "Natalia", "Ricardo", "Lorena", "Analia", "Marisol", "Federico", "Victoria", "Ludmila", "Luz", "Catalina", "Thiago",
     "Mateo", "Lautaro", "Martin", "Martina", "Taiel", "Natanael", "Hector", "Gabriel", "Kiara", "Dylan", "Brandon", "Eithan", "Polo", "Luciano", "Agustina",
     "Aylen", "Maximo", "Maximiliano", "Penelope", "Ambar", "Robert"};
    strcpy(name,names[rand()%(sizeof(names)/30)]);
}

void getLastName(char lastName [])
{
    char lastNames[][30]={"Jurjo","Trozo","Jon","Quito","Molina", "Chavez", "Paz", "Llopart", "Gimenez", "Olivera", "Cortez", "Cheres", "Butaccio",
    "Sanchez", "Fernandez", "Del Rio", "Del Mar", "Maglione", "Aquino", "Querales", "Libonati", "Lima", "Linares", "Garcia", "Almiron", "Costa", "Turtur", "Cepeda",
    "Aguirre", "Perales", "Amalfitano", "Dolce", "Tusar", "Roldan", "Ochoa", "Hidalgo", "Kristiansen", "Millan", "Martinez", "Ale", "Irene", "Baden Powell", "Rios", "Vilar", "Borrel",
    "Luna", "Nu ez", "Bordon", "Bonilla", "Maldonado", "Ledesma", "Bravo", "Torres", "Messi", "Suarez", "Aguero", "Romero", "Barco", "Montiel", "Mcalister", "Acu a", "Armani", "Maradona", "Paez", "Paic", "Cerati",
    "Espineta", "Porro", "Fazolari", "Luque", "Milei"};
    strcpy(lastName, lastNames[rand()%(sizeof(lastNames)/30)]);
}


void getDni(char dni[])
{
    int numero = rand()%1000000+37826321;
    char cadena[10];
    sprintf(cadena, "int", numero);
    strcpy(dni, cadena);
}

void getEmailCliente(stCliente* cliente)
{
    char dominio[][30]={"@gmail.com","@hotmail.com","@yahoo.com","@hotmail.com.ar"};
    strcpy(cliente->email, cliente->nombre);
    printf("hola");
    char *ptr = strcat(cliente->email, cliente->apellido);
    ptr = strcat(cliente->email, dominio[rand()%(sizeof(dominio)/30)]);


}
