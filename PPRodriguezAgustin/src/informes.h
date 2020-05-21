/*
 * informes.h
 *
 *  Created on: 16 may. 2020
 *      Author: Agustin
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "prestamo.h"
#include "cliente.h"
void informes_gestionarClientes(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente);
int Informe_ClienteConMasPrestamosActivos(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayCliente,int cantidadElementosCliente);
int Informe_ClienteConMasPrestamosSaldados(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayCliente,int cantidadElementosCliente);
int Informe_cantidadDePrestamosDeMasDe1000(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente);
int Informe_ClienteConMasPrestamos(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayCliente,int cantidadElementosCliente);
int Informe_cantidadDePrestamosCon12CuotasSaldadas(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente);
void Informar_mostrarPrestamoPorCantidadDeCuotas(Prestamo* arrayPrestamo,int cantidadElementos);
#endif /* INFORMES_H_ */
