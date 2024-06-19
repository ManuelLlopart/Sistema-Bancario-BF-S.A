#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
int id; /// campo único y autoincremental
int nroCliente;
char nombre[30];
char apellido[30];
char dni[10];
char email[100];
//stDomicilio domicilio;
char telefono[12];
int eliminado; /// 0 si está activo - 1 si está eliminado
}stCliente;

stCliente cargaCliente(char nombreArchivo[]);
int validarDni(char dni[]);
void muestraCliente(stCliente cliente);//consulta
void listadoClientes(char nombreArchivo[]);
void bajaCliente(stCliente a);
void altaCliente(stCliente a);
int buscaPosClientePorDni(char nombreArchivo[], char dniBuscado[]);
int cuentaCantidadClientes(char nombreArchivo[]);
int buscaPosClientePorId(char nombreArchivo[], int idBuscado);
void muestraClientePos(char nombreArchivo[], int pos);
stCliente modificarCliente(stCliente a);
int menuModif();
stCliente modificarCliente(stCliente a);








#endif // CLIENTE_H_INCLUDED
