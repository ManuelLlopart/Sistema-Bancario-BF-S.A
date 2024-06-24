#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "domicilio.h"

typedef struct{
int id; /// campo único y autoincremental
int nroCliente;
char nombre[30];
char apellido[30];
char dni[10];
char email[100];
stDomicilio domicilio;
char telefono[12];
int eliminado; /// 0 si está activo - 1 si está eliminado
}stCliente;

stCliente cargaCliente(char nombreArchivo[]);//Carga un cliente
int validarDni(char dni[]);//Valida si un dni es valido
void muestraCliente(stCliente cliente);//consulta
void listadoClientes(char nombreArchivo[]);//Muestra todos los clientes cargados
void bajaCliente(stCliente *a);
void altaCliente(stCliente *a);
int buscaPosClientePorDni(char nombreArchivo[], char dniBuscado[]);//devuelve la posicion de un cliente por dni
int cuentaCantidadClientes(char nombreArchivo[]);//devuelve la cantidad de clientes
int buscaPosClientePorId(char nombreArchivo[], int idBuscado);//devuelve la posicion de un cliente por id
void muestraClientePos(char nombreArchivo[], int pos);//Muestra un cliente buscado por posicion
stCliente modificarCliente(stCliente a);//menu para que modifique el usuario un cliente
int menuModif();//visualizacion de menu de modificacion de cliente
void reemplazaClientePos(char nombreArchivo[],stCliente a, int pos);
stCliente clientePos(char nombreArchivo[], int pos);//retorna el cliente de esa posicion
int validarTelefono(char telefono[]);//Valida si el telefono tiene entre 9 y 10 caracteres
int getIdCliente(stCliente a);
void listadoClientesActivos(char nombreArchivo[]);
void listadoClientesInactivos(char nombreArchivo[]);












#endif // CLIENTE_H_INCLUDED
