/*
 * cliente.h
 *
 *  Created on: 16 may. 2020
 *      Author: Agustin
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char sexo[51];
    char cuit[12];
    int isEmpty;
}Cliente;

void cliente_gestionarClientes(Cliente* arrayCliente,int cantidadElementos,int* contAltas);
void cliente_inicializarDatos(Cliente* arrayCliente,int cantidadElementos);
void cliente_harcodearDatos(Cliente* arrayCliente);
void cliente_mostrarUnoSolo(Cliente unCliente,int indiceCliente);
void cliente_mostrar(Cliente* arrayCliente,int cantidadElementos);
int cliente_buscarPorIsEmpty(Cliente* arrayCliente,int cantidadElementos,int isEmptyABuscar);
int cliente_buscarPorId(Cliente* arrayCliente,int cantidadElementos,int idABuscar);
int cliente_darDeAlta(Cliente* arrayCliente,int cantidadElementos,int* contAltas);
int cliente_darDeBaja(Cliente* arrayCliente,int cantidadElementos);
int cliente_modificarDatos(Cliente* arrayCliente,int cantidadElementos);
void cliente_pedirDatosAModificar(Cliente* arrayCliente,int cantidadElementos,int indice);
void cliente_ordenarDatos(Cliente* arrayCliente,int cantidadElementos);
void cliente_mostrarUnoSoloDos(Cliente* unCliente, int indiceCliente);
int Cliente_imprimirPorId(Cliente* arrayClientes, int cantidadElementos, int ID);

#endif /* CLIENTE_H_ */
