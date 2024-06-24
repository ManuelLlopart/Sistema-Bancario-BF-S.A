#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "movimientos.h"
#include "mock.h"
#include "domicilio.h"
const int ESC=27;

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

void getDetalle(char detalle[]) ///descripcion del detalle de saldo positivo
{
    char detalles[][100]= {"Credito de haberes", "Transferencia de cuenta de ahorros","Acreditacion de plazo fijo",
                           "Transferencia electronica recibida","Cobro de dividendos", "Deposito de cheques","Pago por reembolso"
                          };


    strcpy(detalle,detalles[(rand()%(sizeof(detalles))/100)]);
}
void getDetalleSaldoNegativo(char detalle[]) ///descripcion del detalle de saldo negativo
{
    char detalleSaldoNegativo[][100]= {"Pago de factura","Retiro en cajero automatico","Transferencia a cuenta de terceros",
                                       "Pago de tarjeta de credito","Pago con tarjeta de debito","Pago de prestamo bancario"
                                      };

    strcpy(detalle,detalleSaldoNegativo[(rand()%(sizeof(detalleSaldoNegativo))/100)]);
}

float getImporte()
{
    return rand()%50000-rand()%40000;
}

int getDia()
{
    return rand()%31+1;
}

int getMes()
{
    return rand()%12+1;
}

int getAnio()
{
    return rand()%203+1822;
}

stMovimientos getMovimientosRandom() ///funcion que carga y retorna un movimiento
{
    stMovimientos mov;
    mov.importe=getImporte();
    if (mov.importe>0)
    {
        getDetalle(mov.detalle);
    }
    else
    {
        getDetalleSaldoNegativo(mov.detalle);
    }
    mov.dia=getDia();
    mov.mes=getMes();
    mov.anio=getAnio();

    return mov;
}

void muestraMovimientoRandom(stMovimientos movimiento)
{
    printf("Id:%d\n",movimiento.id);
    printf ("Detalle:%s\n",movimiento.detalle);
    printf("Importe:%.2f\n",movimiento.importe);
    printf("Dia:%d\n",movimiento.dia);
    printf("Mes:%d\n",movimiento.mes);
    printf("Anio:%d\n",movimiento.anio);
    printf("\n====================================\n");
}

int cargaMovimientosRandomEnArchi(char nombreArchivo[])
{
    FILE *archi=fopen(nombreArchivo,"wb");
    stMovimientos movimiento;
    int cantidadMovimientos = 0;
    char opcion=0;
    int idMovimiento =  cuentaRegistros(nombreArchivo, sizeof(stMovimientos));
    if (archi)
    {
        while(opcion!=ESC)

        {
            movimiento=getMovimientosRandom();
            idMovimiento++;
            movimiento.id=idMovimiento;
            muestraMovimientoRandom(movimiento);
            ///devuelve el nro de archivos que escribo
            cantidadMovimientos = cantidadMovimientos + fwrite(&movimiento,sizeof(stMovimientos),1,archi);
            printf("Ingrese ESC para salir o cualquier otra tecla si desea agregar un nuevo movimiento:\n");
            fflush(stdin);
            opcion=getch();
            system("cls");
        }

        fclose(archi);
    }
    return cantidadMovimientos;
}

void muestraVariosMovimientosRandom(char nombreArchivo[])
{
    FILE *archi=fopen(nombreArchivo,"rb");
    stMovimientos movimiento;

    if (archi)
    {
        while(fread(&movimiento,sizeof(stMovimientos),1,archi)>0)
        {
            muestraMovimientoRandom(movimiento);
        }

        fclose(archi);
    }
}
void cargaMilMovimientosRandomEnArchi(char nombreArchivo[])
{
    FILE *archi=fopen(nombreArchivo,"wb");
    stMovimientos movimiento;
    char opcion=0;
    int idMovimiento =  cuentaRegistros(nombreArchivo, sizeof(stMovimientos));
    if (archi)
    {
        for (int i=0; i<1000; i++)

        {
            movimiento=getMovimientosRandom();
            idMovimiento++;
            movimiento.id=idMovimiento;
            fwrite(&movimiento,sizeof(stMovimientos),1,archi);
        }

        fclose(archi);
    }
}

