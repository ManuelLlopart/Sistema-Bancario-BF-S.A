#ifndef MOVIMIENTOS_H_INCLUDED
#define MOVIMIENTOS_H_INCLUDED

typedef struct
{
  int id;
  int idCuenta; ///por movimiento
  char detalle[100];
  float importe;
  int anio; ///fecha en la q envio el importe
  int mes;
  int dia;
  int eliminado; ///si el mov. se bajo

}stMovimientos;

stMovimientos crearMovimiento(int idCuenta);
void muestraMovimiento(stMovimientos movimiento);
void guardaMovimientoEnArchi(char nombreArchivo[],stMovimientos movimiento);
stMovimientos getMovimientos();
void cargaMovimientosEnArchi(char nombreArchivo[]);
void muestraVariosMovimientos(char nombreArchivo[]);
stMovimientos cargaFechaMovimiento(stMovimientos movimiento);
stMovimientos fechaActualModificacionMov(stMovimientos mov);
stMovimientos eliminaMovimiento(char nombreArchivo[],int idMovimiento);
void modificaMovimiento(char nombreArchivo[],int idMovimiento,int idCuenta,char detalleMov[],float importeMov,int diaModif,int mesModif,int anioModif);
void listadoMovimientosPorIdCuenta(char nombreArchivo[],int idCuenta);
void listadoMovimientosPorMes(char nombreArchivo[],int mes);
void buscaMovimientosPorFecha(char nombreArchivo[],int diaBuscado,int mesBuscado, int anioBuscado);
void muestraMovimientosPorIdCuenta(char nombreArchivo[], int nroCuenta);
int cuentaRegistros(char nombreArchivo[],int sizeEstructura);

#endif // MOVIMIENTOS_H_INCLUDED
