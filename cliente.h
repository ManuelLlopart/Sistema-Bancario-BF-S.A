#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
int id; /// campo �nico y autoincremental
int nroCliente;
char nombre[30];
char apellido[30];
char dni[10];
char email[30];
//stDomicilio domicilio;
char telefono[12];
int eliminado; /// 0 si est� activo - 1 si est� eliminado
}stCliente;

stCliente cargaCliente();
int validarDni(char dni[]);
void muestraCliente(stCliente cliente);



#endif // CLIENTE_H_INCLUDED
