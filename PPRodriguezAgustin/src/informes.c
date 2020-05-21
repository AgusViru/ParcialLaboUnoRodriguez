/*
 * informes.c
 *
 *  Created on: 16 may. 2020
 *      Author: Agustin
 */

#include "informes.h"

void informes_gestionarClientes(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("1-Cliente con mas prestamos activos\n");
        printf("2-Cliente con mas prestamos saldados\n");
        printf("3-Cantidad de prestamos mayores a 1000\n");
        printf("4-Salir de gestion clientes\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
            	Informe_ClienteConMasPrestamosActivos(arrayPrestamo,cantidadElementos,arrayCliente,cantidadElementosCliente);
                system("pause");
                break;
            case 2:
            	Informe_ClienteConMasPrestamosSaldados(arrayPrestamo,cantidadElementos,arrayCliente,cantidadElementosCliente);
                system("pause");
                break;
            case 3:
            	Informe_cantidadDePrestamosDeMasDe1000(arrayPrestamo,cantidadElementos,arrayCliente,cantidadElementosCliente);
                system("pause");
                break;
            case 4:
            	continuarMenu='n';
                break;
            default:
                printf("\nError. Opcion invalida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
int Informe_ClienteConMasPrestamosActivos(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayCliente,int cantidadElementosCliente)
{
	int retorno=-1;
	int i;
	int auxiliarId;
	int masActivas=0;
	int flag=0;
	    if(arrayCliente!=NULL && cantidadElementosCliente>0)
	    {
	        for(i=0;i<cantidadElementosCliente;i++)
	        {
	            if(arrayCliente[i].isEmpty==0)
	            {
	                if(flag==0 || masActivas <  Prestamo_ContadorDePrestamosPorIdCliente(arrayPrestamo,cantidadElementos,arrayCliente[i].id,1))
	                {
	                    flag=1;
	                    masActivas=Prestamo_ContadorDePrestamosPorIdCliente(arrayPrestamo,cantidadElementos,arrayCliente[i].id,1);
	                    auxiliarId=arrayCliente[i].id;
	                    retorno=0;
	                }
	            }
	        }
	       if(masActivas==0)
	        {
	            printf("\nNo posee prestamos activos. (POSEE 0) \n");
	        }
	       else
	        {
	            printf("\nNumero mayor de prestamos activos: %d\n",masActivas);
	            Cliente_imprimirPorId(arrayCliente,cantidadElementosCliente,auxiliarId);
	        }
	    }
	return retorno;
}
int Informe_ClienteConMasPrestamosSaldados(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayCliente,int cantidadElementosCliente)
{
	int retorno=-1;
	int i;
	int auxiliarId;
	int masSaldados=0;
	int flag=0;
	    if(arrayCliente!=NULL && cantidadElementosCliente>0)
	    {
	        for(i=0;i<cantidadElementosCliente;i++)
	        {
	            if(arrayCliente[i].isEmpty==0)
	            {
	                if(flag==0 || masSaldados <  Prestamo_ContadorDePrestamosPorIdCliente(arrayPrestamo,cantidadElementos,arrayCliente[i].id,0))
	                {
	                    flag=1;
	                    masSaldados=Prestamo_ContadorDePrestamosPorIdCliente(arrayPrestamo,cantidadElementos,arrayCliente[i].id,0);
	                    auxiliarId=arrayCliente[i].id;
	                    retorno=0;
	                }
	            }
	        }
	       if(masSaldados==0)
	        {
	            printf("\nNo posee prestamos saldados. (POSEE 0) \n");
	        }
	       else
	        {
	            printf("\nNumero mayor de prestamos saldados: %d\n",masSaldados);
	            Cliente_imprimirPorId(arrayCliente,cantidadElementosCliente,auxiliarId);
	        }
	    }
	return retorno;
}
int Informe_cantidadDePrestamosDeMasDe1000(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente)//g
{
	int retorno=-1;
	int i;
	int contador=0;
	    if(arrayPrestamo!=NULL && cantidadElementos>0 && arrayCliente!=NULL && cantidadElementosCliente>0)
	    {
	        for(i=0;i<cantidadElementosCliente;i++)
	        {
	            if(arrayCliente[i].isEmpty==0 && Prestamo_ContadorDePrestamosDeMasDe1000PorCliente(arrayPrestamo,cantidadElementos,arrayCliente[i].id,1))
	            {
	                    contador++;
	                    retorno=0;
	            }
	        }
	                if(contador==0)
	                {
	                    printf("\nNingun cliente obtuvo un prestamo de mas de $1000\n");
	                }
	                    else
	                    {
	                        printf("\nLa cantidad de clientes que sacaron un prestamo de mas de $1000 es: %d",contador);
	                        prestamo_mostrar(arrayPrestamo,cantidadElementos);
	                    }
	    }
		return retorno;
}
int Informe_ClienteConMasPrestamos(Prestamo* arrayPrestamo,int cantidadElementos,Cliente* arrayCliente,int cantidadElementosCliente)
{
	int retorno=-1;
	int i;
	int auxiliarId;
	int masActivas=0;
	int flag=0;
	    if(arrayCliente!=NULL && cantidadElementosCliente>0)
	    {
	        for(i=0;i<cantidadElementosCliente;i++)
	        {
	            if(arrayCliente[i].isEmpty==0)
	            {
	                if(flag==0 || masActivas <  Prestamo_contadorDePrestamos(arrayPrestamo,cantidadElementos,arrayCliente[i].id))
	                {
	                    flag=1;
	                    masActivas=Prestamo_contadorDePrestamos(arrayPrestamo,cantidadElementos,arrayCliente[i].id);
	                    auxiliarId=arrayCliente[i].id;
	                    retorno=0;
	                }
	            }
	        }
	       if(masActivas==0)
	        {
	            printf("\nNo posee prestamos. (POSEE 0) \n");
	        }
	       else
	        {
	            printf("\nNumero mayor de prestamos activos: %d\n",masActivas);
	            Cliente_imprimirPorId(arrayCliente,cantidadElementosCliente,auxiliarId);
	        }
	    }
	return retorno;
}
int Informe_cantidadDePrestamosCon12CuotasSaldadas(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente)//g
{
	int retorno=-1;
	int i;
	int contador=0;
	    if(arrayPrestamo!=NULL && cantidadElementos>0 && arrayCliente!=NULL && cantidadElementosCliente>0)
	    {
	        for(i=0;i<cantidadElementosCliente;i++)
	        {
	            if(arrayCliente[i].isEmpty==0 && Prestamo_ContadorDePrestamosDeMasDe12CuotasPorCliente(arrayPrestamo,cantidadElementos,arrayCliente[i].id,1))
	            {
	                    contador++;
	                    retorno=0;
	            }
	        }
	                if(contador==0)
	                {
	                    printf("\nNingun cliente saldo un prestamo de 12 cuotas\n");
	                }
	                    else
	                    {
	                        printf("\nLa cantidad de clientes que saldaron un prestamo de mas de 12 cuotas es: %d",contador);
	                        prestamo_mostrar(arrayPrestamo,cantidadElementos);
	                    }
	    }
		return retorno;
}

void Informar_mostrarPrestamoPorCantidadDeCuotas(Prestamo* arrayPrestamo,int cantidadElementos)
{
    int auxiliarCantidadCuotas;
    int indexPrestamo;
    if(Prestamo_buscarIndiceVacio(arrayPrestamo,cantidadElementos,&indexPrestamo)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
    	if(utn_getEntero(&auxiliarCantidadCuotas,5,"\nIngrese Cant de cuotas: \n","\nError, no es un ID valido.\n",6,48)==0)
    	{
    		arrayPrestamo[indexPrestamo].cantidadCuotas=auxiliarCantidadCuotas;
    		prestamo_buscarPorCuota(&arrayPrestamo[indexPrestamo],cantidadElementos,auxiliarCantidadCuotas);
    		prestamo_mostrarUnoSoloPorCuota(arrayPrestamo[indexPrestamo],cantidadElementos,auxiliarCantidadCuotas);
    	}

    }
}

