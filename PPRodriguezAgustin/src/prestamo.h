/*
 * prestamo.h
 *
 *  Created on: 16 may. 2020
 *      Author: Agustin
 */

#ifndef PRESTAMO_H_
#define PRESTAMO_H_
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define PRESTAMO 50
typedef struct
{
   int importe;
   int cantidadCuotas;
   int isEmpty;
   int id;
   int idCliente;
   int estado;
   char cuitCliente[12];
}Prestamo;

int Prestamo_init(Prestamo* arrayPrestamo, int cantidadElementos);
int Prestamo_Alta(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayClientes,int cantidadElementosArrayClientes);
int Prestamo_modificarPrestamo(Prestamo* arrayPrestamo, int cantidadElementos);
int Prestamo_buscarIndiceVacio(Prestamo* arrayPrestamo, int cantidadElementos, int* indice);
int Prestamo_ContadorPrestamoPorId(Prestamo* arrayPrestamo,int cantidadElementos,int idCliente);

//------------------------------------------------------------------------------------
int Prestamo_ContadorDePrestamosPorIdCliente(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente, int flag);
int Prestamo_ContadorDePrestamosPorIdClienteTotales(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente);
int Prestamo_ContadorAfichesPorZona(Prestamo* arrayPrestamo,int cantidadElementos, int zona);
int Prestamo_ContadorDePrestamosDeMasDe1000PorCliente(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente,int flag);
int Prestamo_ACobrarAfiches(Prestamo* arrayPrestamo,int cantidadElementos,int idCliente);
int Prestamo_alta(Prestamo* arrayPrestamo,int id,int limite,int cantidadCuotas,int importe);
//-------------------------------------------------------------------------------------

int cliente_imprimirClientesYSusPrestamos(Prestamo* arrayPrestamos, int cantidadElementos,Cliente* arrayClientes, int cantidadElementosClientes);
int Prestamo_imprimirPrestamoConCuilDeCliente(Prestamo* arrayPrestamos, int cantidadElementos,Cliente* arrayClientes, int cantidadElementosClientes);
int prestamo_buscarPorIsEmpty(Prestamo* arrayPrestamo,int cantidadElementos,int isEmptyABuscar);
void prestamo_mostrarUnoSolo(Prestamo unPrestamo, int indicePrestamo);
int Prestamo_buscarPorId(Prestamo* arrayPrestamo,int cantidadElementos,int idABuscar);
void prestamo_mostrar(Prestamo* arrayPrestamo,int cantidadElementos);
int Prestamo_renaudarPrestamo(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente, int ID, int indice);
int Prestamo_saldarPrestamo(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente, int ID,int indice);
void prestamo_mostrarCuit(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayCliente);
void prestamo_mostrarUnoSoloDOS(Prestamo unPrestamo, int indicePrestamo,Cliente unCliente);
int prestamo_buscarPorCuit(Prestamo* arrayPrestamo,int cantidadElementos,char* cuitABuscar,Cliente* arrayCliente);
int Prestamo_contadorDePrestamosActivos(Prestamo* arrayPrestamo, int cantidadElementos);
int Prestamo_contadorDePrestamosSaldados(Prestamo* arrayPrestamo, int cantidadElementos);
int Prestamo_ContadorPrestamoPorCuit(Prestamo* arrayPrestamo,int cantidadElementos,char* cuitCliente,Cliente* arrayCliente,int cantidadElementosCliente);
int prestamo_imprimirPorId(Prestamo* arrayPrestamo, int cantidadElementos, int ID,Cliente* arrayClientes, int cantidadElementosClientes);
int prestamo_imprimirPorCUIT(Prestamo* arrayPrestamo, int cantidadElementos, char* cuit,Cliente* arrayClientes, int cantidadElementosClientes);
int Prestamo_ContadorDePrestamosPorIdClienteTOTALES(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente, int flag,int flagDos);
int Prestamo_contadorDePrestamos(Prestamo* arrayPrestamo, int cantidadElementos,int idCliente);
int Prestamo_ContadorDePrestamosDeMasDe12CuotasPorCliente(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente,int flag);
void prestamo_mostrarUnoSoloPorCuota(Prestamo unPrestamo, int indicePrestamo, int cantidadDeCuotas);
int prestamo_buscarPorCuota(Prestamo* arrayPrestamo,int cantidadElementos,int cuotaABuscar);

#endif /* PRESTAMO_H_ */
