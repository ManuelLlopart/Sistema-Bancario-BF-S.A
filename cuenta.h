#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED

typedef struct
{
    int id; /// campo �nico y autoincremental
    int idCliente; /// Id del Cliente due�o de la Cuenta;
    int nroCuenta;
    int tipoDeCuenta; /// 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en D�lares, 3. Cta Cte en $
    float costoMensual; /// Costo de mantenimiento del producto;
    float saldo; /// Debe actualizarse al modidificar o cargar un movimiento.
    int eliminado; /// 0 si est� activo - 1 si est� eliminado
} stCuenta;

stCuenta cargar_cuenta ();
void mostrar_cuenta (stCuenta cuenta);
void actualizar_saldo(stCuenta *cuenta, float monto);
void baja_cuenta(stCuenta cuenta[], int BuscarCuenta, int CantidadCuentas);
void modificacion_cuenta (stCuenta cuenta[], int CantidadCuentas,int BuscarId);
void cargar_cuenta_archivo(char NombreArchivo []);
void listado_de_cuenta(char NombreArchivo[]);


#endif // CUENTA_H_INCLUDED
