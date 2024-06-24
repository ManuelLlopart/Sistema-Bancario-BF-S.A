#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include "cliente.h"
#include "movimientos.h"

typedef struct
{
    int id; /// campo único y autoincremental
    int idCliente; /// Id del Cliente dueño de la Cuenta;
    int nroCuenta;
    int tipoDeCuenta; /// 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $
    float costoMensual; /// Costo de mantenimiento del producto;
    float saldo; /// Debe actualizarse al modidificar o cargar un movimiento.
    int eliminado; /// 0 si está activo - 1 si está eliminado
} stCuenta;


int cargarCuenta (stCuenta cuenta[],int v, int dim);
void cargaCuenta (char NombreArchivo [], stCliente cliente);
void mostrarCuenta (stCuenta cuenta[],int validos);
void arreglo2Archivo (char NombreArchivo[], int v,stCuenta cuenta[]);
int consultaCuenta(char NombreArchivo[], int BuscarId);
void mostrarCuentaIndividual(stCuenta cuenta);
void muestraArchivoCuentas(char nombreArchivo[]);
int cantidadCuentasCliente (char NombreArchivo[], int BuscarId);
int tipoCuentas ();
void muestraCuentaPos(char NombreArchivo[], int pos);
void reemplazaCuentaPos(char nombreArchivo[],stCuenta a, int pos);
int buscaPosCuentaPorId(char nombreArchivo[], int idBuscado,int nroCuenta);
stCuenta bajaCuenta(stCuenta cuenta);
stCuenta cuentaPos(char nombreArchivo[], int pos);
int muestraCuentaEspecificaEliminada(char NombreArchivo[], int BuscarId);
stCuenta altaCuenta (stCuenta cuenta);
stCuenta cargarCuentaIndividual (stCuenta cuenta);
int modificarCuenta();
stCuenta modificaPorSeccion (stCuenta cuenta);
int buscaPosCuentaPorIdModificacion(char nombreArchivo[], int idBuscado, int tipoCuenta, int opcionSeleccionada);
int mostrarTodasLasCuentasActivas (char NombreArchivo[]);
int mostrarTodasLasCuentasInactivas (char NombreArchivo[]);
int cuentaCuentasCliente (char NombreArchivo[], int BuscarId);
stCuenta buscaCuentaPorIdClienteNroCuenta(char nombreArchivo[], int idCliente, int nroCuenta);
void actualizarSaldo2(char nombreArchivo[], stMovimientos mov);
void listadoCuentasPorCliente (char NombreArchivo[], int BuscarId);
void modificacion_cuenta (char NombreArchivo[], int BuscarId);


#endif // CUENTA_H_INCLUDED
