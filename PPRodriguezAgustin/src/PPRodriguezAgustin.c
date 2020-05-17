/*
 ============================================================================
 Name        : PPRodriguezAgustin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CLIENTES 50
#include "cliente.h"
#include "prestamo.h"
#include "validaciones.h"
#include "informes.h"

int main(void) {
	setbuf(stdout,NULL);
	Cliente arrayClienteMain[CLIENTES];
	cliente_inicializarDatos(arrayClienteMain,CLIENTES);
	Prestamo arrayPrestamoMain[PRESTAMO];
	Prestamo_init(arrayPrestamoMain,PRESTAMO);
	cliente_harcodearDatos(arrayClienteMain);
	int contAltasActores=6;
	int opcionMenu;
    char continuarMenu='s';
    int idMain=0;
    int indiceMain=0;
		    do
		    {
		        printf("\n1-Gestion de Clientes (ABM) \n");
		        printf("2-Prestamo\n");
		        printf("3-Saldar Prestamo\n");
		        printf("4-Reanudar Prestamo\n");
		        printf("5-Imprimir Clientes con prestamos activos\n");
		        printf("6-Imprimir Prestamo con cuil cliente  (No imprime cuit)\n");
		        printf("7-Informar de Clientes y Prestamo\n");
		        printf("8-Salir\n");
		        opcionMenu=getInt("\nIngrese una opcion: ");
		        switch(opcionMenu)
		        {
		            case 1:
		                cliente_gestionarClientes(arrayClienteMain,CLIENTES,&contAltasActores);
		                break;
		            case 2:
		                Prestamo_Alta(arrayPrestamoMain,PRESTAMO,arrayClienteMain,CLIENTES);
		                printf("\nSe ha hecho el prestamo satisfactoriamente. Su estado es activo.\n");
		                break;
		            case 3:
		            	Prestamo_saldarPrestamo(arrayPrestamoMain,PRESTAMO,arrayClienteMain,CLIENTES,idMain,indiceMain);
		                break;
		            case 4:
		            	Prestamo_renaudarPrestamo(arrayPrestamoMain,PRESTAMO,arrayClienteMain,CLIENTES,idMain,indiceMain);
		                break;
		            case 5:
		            	cliente_imprimirClientesYSusPrestamos(arrayPrestamoMain,PRESTAMO,arrayClienteMain,CLIENTES);
		            	break;
		            case 6:
		            	Prestamo_imprimirPrestamoConCuilDeCliente(arrayPrestamoMain,PRESTAMO,arrayClienteMain,CLIENTES);
		            	break;
		            case 7:
		            	informes_gestionarClientes(arrayPrestamoMain,PRESTAMO,arrayClienteMain,CLIENTES);
		            	break;
		            case 8:
		            	continuarMenu='n';
		            	break;
		            default:
		                printf("\nOpcion ingresada no valida\n");
		        }
		        system("cls");
		    }
		    while(continuarMenu=='s');

	return 0;
}
