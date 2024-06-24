#ifndef MOCK_H_INCLUDED
#define MOCK_H_INCLUDED
#include "movimientos.h"
#include "cliente.h"

void getName(char name []);
void getLastName(char lastName []);
void getDni(char dni[]);
void getEmailCliente(stCliente* cliente);
void getTelefonoRandom(char telefono[]);
void getCliente2ArchivoRandom(char nombreArchivo[]);
void getCalle(char calle []);
void getLocalidad (char localidad []);
void getProvincia (char provincia []);
void getCpos (char cpos []);
void getNumDomicilio (char numeroDomicilio []);
stDomicilio getDomicilioRandom();
void getDetalle(char detalle[]);
void getDetalleSaldoNegativo(char detalle[]);
float getImporte();
int getDia();
int getMes();
int getAnio();
stMovimientos getMovimientosRandom();
int getIdCuentaRandom(char nombreArchivo[]);
int cargaMovimientosRandomEnArchi(char nombreArchivoMov[],char nombreArchivoCuen[], int idCuenta);
void cargaMilMovimientosRandomEnArchi(char nombreArchivoMov[], char nombreArchivoCuenta[]);


#endif // MOCK_H_INCLUDED
