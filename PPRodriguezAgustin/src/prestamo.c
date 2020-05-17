/*
 * prestamo.c
 *
 *  Created on: 16 may. 2020
 *      Author: Agustin
 */

#include "prestamo.h"
static int generarId();
/** \brief iniciabiliza el array en 1 para saber que esta vacio
 *
 * \param el array de ventas
 * \param la cantidad de elementos del array
 * \return retorna 0 si esta todo bien -1 si esta mal
 *
 */

int Prestamo_init(Prestamo* arrayPrestamo, int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0 && arrayPrestamo!=NULL)
    {
        retorno = 0;
        for(i=0; i<cantidadElementos; i++)
        {
            arrayPrestamo[i].isEmpty=1; //esta vacio/libre
        }
    }
    return retorno;
}
/** \brief da de alta una venta a un cliente determinado pasandole su id y generando su propia id
 *
 * \param array de venta
 * \param los elementos del array
 * \param array de cliente
 * \param los elementos del array cliente
 * \return retorna 0 y da de alta la venta o -1 y error
 *
 */

int Prestamo_Alta(Prestamo* arrayPrestamo,int cantidadElementos,
                      Cliente* arrayClientes,int cantidadElementosArrayClientes)
{
    int retorno=-1;
    int auxiliarCantidadCuotas;
    int auxiliarImporte;
    int indexPrestamo;
    int idCliente;

        if(Prestamo_buscarIndiceVacio(arrayPrestamo,cantidadElementos,&indexPrestamo)==0)
        {
            if(arrayPrestamo!=NULL && cantidadElementos>0)
            {
                cliente_mostrar(arrayClientes,cantidadElementosArrayClientes);
                if(utn_getEntero(&idCliente,5,"\nIngrese ID de Cliente: \n","\nError, no es un ID valido.\n",0,999)==0)
                {
                    cliente_buscarPorId(arrayClientes, cantidadElementosArrayClientes,idCliente);
                    if(utn_getEntero(&auxiliarCantidadCuotas,5,"\nIngrese cantidad de cuotas, rango 6-48: \n","\nError, no es un numero valido.\n",6,48)==0)
                    {
                        if(utn_getEntero(&auxiliarImporte,5,"\nIngrese Importe, rango 100-10000: \n","\nError, no es un numero valido.\n",100,10000)==0)
                        {
                            arrayPrestamo[indexPrestamo].idCliente=idCliente;
                            arrayPrestamo[indexPrestamo].cantidadCuotas=auxiliarCantidadCuotas;
                            arrayPrestamo[indexPrestamo].importe = auxiliarImporte;
                            arrayPrestamo[indexPrestamo].isEmpty = 0;
                            arrayPrestamo[indexPrestamo].id = generarId();
                            arrayPrestamo[indexPrestamo].estado = 1;
                            retorno=0;
                        }
                    }
                }
            }
        }
    return retorno;
}
/** \brief modifica la venta ingresando la idPrestamo correspondiente y mostrando al cliente que tiene esa alta
 *
 * \param array venta
 * \param la cantidad de elementos del array
 * \return retorna 0 si esta bien modificando los datos o -1 habiendo un error
 *
 */

/*int Prestamo_modificarPrestamo(Prestamo* arrayPrestamo, int cantidadElementos)
{
    int retorno=-1;
    int auxiliarCantidadAfiches;
    int auxiliarZona;
    int indexPrestamo;
    int idPrestamo;

        if(arrayPrestamo!=NULL && cantidadElementos>0)
        {
            Prestamo_mostrar(arrayPrestamo, cantidadElementos);
            if(utn_getEntero(&idPrestamo,5,"\nIngrese ID de la Prestamo: \n","\nError, no es un ID valido.\n",0,999)==0)
            {
                Prestamo_buscarPorId(arrayPrestamo, cantidadElementos,idPrestamo, &indexPrestamo);
                if(utn_getEntero(&auxiliarCantidadAfiches,5,"\nIngrese cantidad de afiches: \n","\nError, no es un numero valido.\n",0,999)==0)
                {
                    if(utn_getEntero(&auxiliarZona,5,"\nIngrese ZONA: CABA 1 ZONA SUR 2 ZONA OESTE 3: \n","\nError, no es un numero valido.\n",1,3)==0)
                    {
                        arrayPrestamo[indexPrestamo].id=idPrestamo;
                        arrayPrestamo[indexPrestamo].cantidadAfiches = auxiliarCantidadAfiches;
                        arrayPrestamo[indexPrestamo].zona = auxiliarZona;
                        retorno=0;
                    }
                }
            }
        }
    return retorno;
}*/

/** \brief busca un indice vacio en el array para poder cargar un elemento
 *
 * \param  el array de venta
 * \param  los elementos del array
 * \param  un puntero indice que va a obtener los valores del indice que recorre al array
 * \return retorna 0 si encuentra indice -1 si no
 *
 */

int Prestamo_buscarIndiceVacio(Prestamo* arrayPrestamo, int cantidadElementos, int* indice)
{
    int retorno =-1;
    int i;
    if(arrayPrestamo !=NULL && cantidadElementos>0)
    {
        for(i=0; i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].isEmpty == 1)
            {
                *indice=i;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/** \brief genera un id automatico apra cada venta
 *
 *
 *
 * \return un contador de ids
 *
 */

static int generarId()
{
    static int contadorId=0;
    return contadorId++;
}
/** \brief busca un elemento del array por su id
 *
 * \param array de venta
 * \param la cantidad de elementos
 * \param una id para verificar que el id que le pase el usuario sea valido
 * \param un puntero indiceId para obtener los valores del indice que recorre a los elementos del array
 * \return 0 si lo encontre -1 si no
 *
 */

int prestamo_buscarPorId(Prestamo* arrayPrestamo,int cantidadElementos,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if((arrayPrestamo[i].isEmpty==0) && (arrayPrestamo[i].id==idABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

/*int Prestamo_buscarPorCuitEId(Prestamo* arrayPrestamo, int cantidadElementos,char* cuitParametro, int idClienteParametro,int* indice)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if((strcmp(arrayPrestamo[i].cuit,cuitParametro)==0) && (arrayPrestamo[i].idCliente==idClienteParametro))
        {
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}*/
/** \brief muestra a las ventas realizadas junto al id del cliente
 *
 * \param array venta
 * \param la cantidad de elementos
 * \return 0 si hay carga -1 si no hay carga de datos para mostrar
 *
 */
void prestamo_mostrar(Prestamo* arrayPrestamo,int cantidadElementos)
{
    int indiceBusqueda;
    int i;
    if(prestamo_buscarPorIsEmpty(arrayPrestamo,cantidadElementos,1)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        printf("\nID     Importe     CantidadCuotas      idCliente      Estado   \n");
        for(i=0;i<cantidadElementos;i++)
        {
            //indiceBusqueda=Prestamo_buscarPorIdDos(arrayPrestamo,cantidadPrestamo,arrayPrestamo[i].idCliente);
        	indiceBusqueda=prestamo_buscarPorId(arrayPrestamo,cantidadElementos,arrayPrestamo[i].id);
            if((arrayPrestamo[i].isEmpty==0) /*&& (arrayCliente[i].idNacionalidad==listaPais[indiceBusqueda].id*/)
            {
                prestamo_mostrarUnoSolo(arrayPrestamo[i],indiceBusqueda);
            }
        }
    }
}
/** \brief cancela la venta cuando se da de baja el cliente
 *
 * \param array venta
 * \param los elementos del array de venta
 * \param array cliente
 * \param los elementos del array del cliente
 * \param id para igualarlo al idcliente de la venta y asi liberar el espacio en el array
 * \return 0 si encontro el id de cliente para dar de baja la venta -1 si no
 *
 */

int Prestamo_saldarPrestamo(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente, int ID, int indice)
{
	int sePudo=-1;
	int confirmacion;
	int indiceBusqueda;
	char auxCodigoStr[256];
    int auxCodigoInt;
	if(prestamo_buscarPorIsEmpty(arrayPrestamo,cantidadElementos,0)==-1)
	    {
	        printf("\nNo hay ningun elemento en la lista\n");
	    }
	    else
	    {
	        prestamo_mostrar(arrayPrestamo,cantidadElementos); // poner prestamos
	        if(getStrNumerosSinRango("\nIngrese el id del prestamo a saldar: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
	        {
	            auxCodigoInt=atoi(auxCodigoStr);
	            indiceBusqueda=prestamo_buscarPorId(arrayPrestamo,cantidadElementos,auxCodigoInt);
	            if(indiceBusqueda==-1)
	            {
	                printf("\nEl id ingresado no existe\n");
	            }
	            else
	            {
	                confirmacion=confirmarCambios("\nEsta seguro que desea saldarlo? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
	                if(confirmacion==1)
	                {
	                    printf("\nSe ha saldado al numero de prestamo %d\n",auxCodigoInt);
	                    arrayPrestamo[indiceBusqueda].estado=0;
	                    sePudo=1;
	                }
	                else if(confirmacion==0)
	                {
	                    printf("\nla accion de saldar ha sido cancelada por el usuario\n");
	                    sePudo=0;
	                }
	            }
	        }
	        if(sePudo==-1)
	        {
	            printf("\naccion de saldar cancelada\n");
	        }
	    }
	return sePudo;
}

int Prestamo_renaudarPrestamo(Prestamo* arrayPrestamo, int cantidadElementos, Cliente* arrayCliente, int cantidadElementosCliente, int ID, int indice)
{
	int sePudo=-1;
	int confirmacion;
	int indiceBusqueda;
	char auxCodigoStr[256];
    int auxCodigoInt;
	if(prestamo_buscarPorIsEmpty(arrayPrestamo,cantidadElementos,0)==-1)
	    {
	        printf("\nNo hay ningun elemento en la lista\n");
	    }
	    else
	    {
	        prestamo_mostrar(arrayPrestamo,cantidadElementos); // poner prestamos
	        if(getStrNumerosSinRango("\nIngrese el id del prestamo a reanudar: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
	        {
	            auxCodigoInt=atoi(auxCodigoStr);
	            indiceBusqueda=prestamo_buscarPorId(arrayPrestamo,cantidadElementos,auxCodigoInt);
	            if(indiceBusqueda==-1)
	            {
	                printf("\nEl id ingresado no existe\n");
	            }
	            else
	            {
	                confirmacion=confirmarCambios("\nEsta seguro que desea reanudarlo? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
	                if(confirmacion==1)
	                {
	                    printf("\nSe ha reanudado al numero de prestamo %d\n",auxCodigoInt);
	                    arrayPrestamo[indiceBusqueda].estado=1;
	                    sePudo=1;
	                }
	                else if(confirmacion==0)
	                {
	                    printf("\nla accion de reanudar ha sido cancelada por el usuario\n");
	                    sePudo=0;
	                }
	            }
	        }
	        if(sePudo==-1)
	        {
	            printf("\naccion de reanudar cancelada\n");
	        }
	    }
	return sePudo;
}
/** \brief un contador que cuenta ventas con estado a activo (==1)
 *
 * \param array venta
 * \param la cantidad de elementos
 * \param un id de cliente pasado por parametro para verificar si es la id correcta
 * \return devuelve el contador
 *
 */

int Prestamo_ContadorPrestamoPorId(Prestamo* arrayPrestamo,int cantidadElementos,int idCliente)
{
    int i;
    int contador=0;
    for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].idCliente==idCliente && arrayPrestamo[i].estado == 1 && !arrayPrestamo[i].isEmpty)
            {
                contador++;
            }
        }
    return contador;
}
//para informes
/** \brief un contador que cuenta ventas ya sean cobradas o a cobrar por cada id de cliente
 *
 * \param el array de venta
 * \param su cantidad de elementos
 * \param un id cliente pasado por parametro para verificar que la id que le pase el usuario sea correcta
 * \param un flag para indicarle si queremos q cuente las cobradas o las a cobrar
 * \return el contador
 *
 */

int Prestamo_ContadorDePrestamosPorIdCliente(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente, int flag)//contador de ventas
{
    int i;
    int contador=0;
    if(arrayPrestamo!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].isEmpty==0 && ((flag==0 && arrayPrestamo[i].idCliente==idCliente && arrayPrestamo[i].estado == 0)||
               ((flag && arrayPrestamo[i].idCliente==idCliente && arrayPrestamo[i].estado==1))))
            {
                contador++;
            }
        }
    }
    return contador;
}
/** \brief contador que cuenta todas las ventas sin importar que sean a cobrar o cobradas
 *
 * \param array venta
 * \param su cantidad de elementos
 * \param un id cliente pasado por parametro para verificar en la condicion
 * \return el contador
 *
 */

int Prestamo_ContadorDePrestamosPorIdClienteTotales(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente)
{
    int i;
    int contador=0;
    if(arrayPrestamo!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].isEmpty==0 && arrayPrestamo[i].idCliente == idCliente)
            {
                contador++;
            }
        }
    }
    return contador;
}

/*
int Prestamo_ContadorAfichesPorZona(Prestamo* arrayPrestamo,int cantidadElementos, int zona)
{
    int i;
    int contador=0;
    if(arrayPrestamo!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].isEmpty==0 && arrayPrestamo[i].zona == zona)
            {
                contador+=arrayPrestamo[i].cantidadAfiches;
            }
        }
    }
    return contador;
}*/

int Prestamo_ContadorDePrestamosDeMasDe1000PorCliente(Prestamo* arrayPrestamo, int cantidadElementos, int idCliente,int flag)
{
    int i;
    int contador=0;
    if(arrayPrestamo!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(flag && arrayPrestamo[i].isEmpty==0 && arrayPrestamo[i].idCliente == idCliente && arrayPrestamo[i].estado==1 && arrayPrestamo[i].importe>1000)
            {
                contador+=arrayPrestamo[i].importe;
            }
        }
    }
    return contador;
}
/*
int Prestamo_ACobrarAfiches(Prestamo* arrayPrestamo,int cantidadElementos,int idCliente)
{
    int i;
    int contador=0;
    for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].idCliente==idCliente && arrayPrestamo[i].estado == 1 && !arrayPrestamo[i].isEmpty)
            {
                contador+=arrayPrestamo[i].cantidadAfiches;
            }
        }
    return contador;
}*/


int Prestamo_contadorDePrestamosSaldados(Prestamo* arrayPrestamo, int cantidadElementos)
{
    int i;
    int contador=0;
    if(arrayPrestamo!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].isEmpty==0)
            {
                contador+=arrayPrestamo[i].estado=0;
            }
        }
    }
    return contador;
}

int Prestamo_contadorDePrestamosActivos(Prestamo* arrayPrestamo, int cantidadElementos)
{
    int i;
    int contador=0;
    if(arrayPrestamo!=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].isEmpty==0)
            {
                contador+=arrayPrestamo[i].estado=1;
            }
        }
    }
    return contador;
}

int Prestamo_alta(Prestamo* arrayPrestamo,int id,int limite,int cantidadCuotas,int importe)
{
    int indice;
    int retorno=-1;
    if(arrayPrestamo!=NULL && limite>0 && cantidadCuotas>0)
        {
        retorno=0;
        if(Prestamo_buscarIndiceVacio(arrayPrestamo,limite,&indice)==0)
        {
            arrayPrestamo[indice].id=generarId();
            arrayPrestamo[indice].isEmpty=0;
            arrayPrestamo[indice].cantidadCuotas=cantidadCuotas;
            arrayPrestamo[indice].idCliente=id;
            arrayPrestamo[indice].importe=importe;
            arrayPrestamo[indice].estado=1;
        }
    }
    return retorno;
}
int cliente_imprimirClientesYSusPrestamos(Prestamo* arrayPrestamos, int cantidadElementos,Cliente* arrayClientes, int cantidadElementosClientes)
{
    int retorno=-1;
    int i;
    int prestamoActivos;
    if(arrayClientes!=NULL && cantidadElementosClientes>0)
    {
        for(i=0;i<cantidadElementosClientes;i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                printf("\nId: %d",arrayClientes[i].id);
                printf("\tNombre: %s",arrayClientes[i].nombre);
                printf("\tApellido: %s",arrayClientes[i].apellido);
                printf("\tCuit: %s",arrayClientes[i].cuit);
                prestamoActivos=Prestamo_ContadorPrestamoPorId(arrayPrestamos,PRESTAMO,arrayClientes[i].id);
                printf("\nCantidad activos: %d\n",prestamoActivos);
                retorno=0;
            }
        }
    }
    return retorno;
}
int Prestamo_imprimirPrestamoConCuilDeCliente(Prestamo* arrayPrestamos, int cantidadElementos,Cliente* arrayClientes, int cantidadElementosClientes)
{
    int retorno=-1;
    int i;
    int prestamoActivosConCuil;
    if(arrayPrestamos!=NULL && cantidadElementos>0 && arrayClientes!=NULL && cantidadElementosClientes>0)
    {
        for(i=0;i<cantidadElementos&&cantidadElementosClientes;i++)
        {
        	if(!arrayPrestamos[i].isEmpty && !arrayClientes[i].isEmpty)
        	{
	            prestamo_mostrarCuit(arrayPrestamos,cantidadElementos,arrayClientes);
      	        prestamoActivosConCuil=Prestamo_ContadorPrestamoPorCuit(arrayPrestamos,PRESTAMO,arrayPrestamos[i].cuitCliente,arrayClientes,cantidadElementosClientes);
      	        printf("\nCantidad activos: %d\n",prestamoActivosConCuil);
      	        retorno=0;
        	}
        }
    }
    return retorno;
}

int prestamo_buscarPorIsEmpty(Prestamo* arrayPrestamo,int cantidadElementos,int isEmptyABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if(arrayPrestamo[i].isEmpty==isEmptyABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
void prestamo_mostrarUnoSolo(Prestamo unPrestamo, int indicePrestamo)
{
    printf("\n%d\t",unPrestamo.id);
    printf("%4d",unPrestamo.importe);
    printf("%12d",unPrestamo.cantidadCuotas);
    printf("%15d",unPrestamo.idCliente);
    printf("%15d\n\t",unPrestamo.estado);
}
void prestamo_mostrarCuit(Prestamo* arrayPrestamo,int cantidadElementos, Cliente* arrayCliente)
{
    int indiceBusqueda;
    int i;
    if(prestamo_buscarPorIsEmpty(arrayPrestamo,cantidadElementos,1)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        printf("\nID     Importe     CantidadCuotas      idCliente      Cuit      Estado   \n");
        for(i=0;i<cantidadElementos;i++)
        {
            //indiceBusqueda=Prestamo_buscarPorIdDos(arrayPrestamo,cantidadPrestamo,arrayPrestamo[i].idCliente);
        	indiceBusqueda=prestamo_buscarPorId(arrayPrestamo,cantidadElementos,arrayPrestamo[i].id);
        	indiceBusqueda=prestamo_buscarPorCuit(arrayPrestamo,cantidadElementos,arrayPrestamo[i].cuitCliente,arrayCliente);
            if((arrayPrestamo[i].isEmpty==0) /*&& (arrayCliente[i].idNacionalidad==listaPais[indiceBusqueda].id*/)
            {
                prestamo_mostrarUnoSoloDOS(arrayPrestamo[i],indiceBusqueda,arrayCliente[i]);
            }
        }
    }
}
void prestamo_mostrarUnoSoloDOS(Prestamo unPrestamo, int indicePrestamo,Cliente unCliente)
{
    printf("\n%d\t",unPrestamo.id);
    printf("%4d",unPrestamo.importe);
    printf("%12d",unPrestamo.cantidadCuotas);
    printf("%15d",unPrestamo.idCliente);
    printf("%15s",unPrestamo.cuitCliente);
    printf("%15d\n\t",unPrestamo.estado);
}
int prestamo_buscarPorCuit(Prestamo* arrayPrestamo,int cantidadElementos,char* cuitABuscar,Cliente* arrayCliente)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if((arrayPrestamo[i].isEmpty==0) && strcpy(arrayPrestamo[i].cuitCliente,cuitABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
int Prestamo_ContadorPrestamoPorCuit(Prestamo* arrayPrestamo,int cantidadElementos,char* cuitCliente,Cliente* arrayCliente,int cantidadElementosCliente)
{
    int i;
    int contador=0;
    for(i=0;i<cantidadElementos&&cantidadElementosCliente;i++)
        {
            if(arrayPrestamo[i].estado == 1 && !arrayPrestamo[i].isEmpty)
            {
            	strcpy(arrayPrestamo[i].cuitCliente,cuitCliente);
                contador++;
            }
        }
    return contador;
}
int prestamo_imprimirPorId(Prestamo* arrayPrestamo, int cantidadElementos, int ID,Cliente* arrayClientes, int cantidadElementosClientes)
{
    int retorno=-1;
    int i;
    if(arrayPrestamo !=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].id == ID)
            {
                printf("\nId: %d",arrayPrestamo[i].id);
                printf("\t importe: %d",arrayPrestamo[i].importe);
                printf("\t CantCuotas: %d",arrayPrestamo[i].cantidadCuotas);
                printf("\t Cuit: %s\n",arrayPrestamo[i].cuitCliente);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
int prestamo_imprimirPorCUIT(Prestamo* arrayPrestamo, int cantidadElementos, char* cuit,Cliente* arrayClientes, int cantidadElementosClientes)
{
    int retorno=-1;
    int i;
    if(arrayPrestamo !=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPrestamo[i].cuitCliente == arrayClientes[i].cuit)
            {
                printf("\nId: %d",arrayPrestamo[i].id);
                printf("\t importe: %d",arrayPrestamo[i].importe);
                printf("\t CantCuotas: %d",arrayPrestamo[i].cantidadCuotas);
                printf("\t Cuit: %s\n",arrayPrestamo[i].cuitCliente);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
