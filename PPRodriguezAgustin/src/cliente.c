/*
 * cliente.c
 *
 *  Created on: 16 may. 2020
 *      Author: Agustin
 */
#include "cliente.h"
#include "utn.h"
void cliente_gestionarClientes(Cliente* arrayCliente,int cantidadElementos, int* contAltas)
{
    int opcionMenu;
    char continuarMenu='s';
    do
    {
        system("cls");
        printf("1-Alta\n");
        printf("2-Modificar\n");
        printf("3-Baja\n");
        printf("4-Listar\n");
        printf("5-Salir de gestion clientes\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                cliente_darDeAlta(arrayCliente,cantidadElementos,contAltas);
                system("pause");
                break;
            case 2:
                cliente_modificarDatos(arrayCliente,cantidadElementos);
                system("pause");
                break;
            case 3:
                cliente_darDeBaja(arrayCliente,cantidadElementos);
                system("pause");
                break;
            case 4:
                cliente_mostrar(arrayCliente,cantidadElementos);
                system("pause");
                break;
            case 5:
                continuarMenu='n';
                break;
            default:
                printf("\nError. Opcion invalida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
/** \brief iniciabiliza el array en 1 para saber que esta vacio
 *
 * \param el array de cliente
 * \param la cantidad de elementos del array
 * \
 *
 */
void cliente_inicializarDatos(Cliente* arrayCliente,int cantidadElementos)
{
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        arrayCliente[i].id=-1;
        strcpy(arrayCliente[i].nombre,"VACIO");
        strcpy(arrayCliente[i].apellido,"VACIO");
        strcpy(arrayCliente[i].sexo,"VACIO");
        arrayCliente[i].isEmpty=1;
    }
}
void cliente_harcodearDatos(Cliente* arrayCliente)
{
    int id[5]={1,2,3,4,5};
    char nombre[5][51]={"agustin","ezequiel","claudio","claudia","josefa"};
    char apellido[5][51]={"Rodriguez","Rodriguez","buffa","Perez","Castro"};
    char sexo[5][51]={"Masculino","Femenino","Masculino","Femenino","Masculino"};
    char cuit[5][50]={"400","300","100","500","600"};
    int i;
    for(i=0;i<5;i++)
    {
        arrayCliente[i].id=id[i];
        strcpy(arrayCliente[i].nombre,nombre[i]);
        strcpy(arrayCliente[i].apellido,apellido[i]);
        strcpy(arrayCliente[i].sexo,sexo[i]);
        strcpy(arrayCliente[i].cuit,cuit[i]);
        arrayCliente[i].isEmpty=0;
    }
}
void cliente_mostrarUnoSolo(Cliente unCliente, int indiceCliente)
{
    printf("\n%d\t",unCliente.id);
    printf("%4s",unCliente.nombre);
    printf("%12s",unCliente.apellido);
    printf("%15s",unCliente.sexo);
    printf("%15s\n\t",unCliente.cuit);
}
void cliente_mostrar(Cliente* arrayCliente,int cantidadElementos)
{
    int indiceBusqueda;
    int i;
    if(cliente_buscarPorIsEmpty(arrayCliente,cantidadElementos,1)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        cliente_ordenarDatos(arrayCliente,cantidadElementos);
        printf("\nID      Nombre     Apellido      Genero                 Cuit   \n");
        for(i=0;i<cantidadElementos;i++)
        {
            //indiceBusqueda=Prestamo_buscarPorIdDos(arrayPrestamo,cantidadPrestamo,arrayPrestamo[i].idCliente);
        	indiceBusqueda=cliente_buscarPorId(arrayCliente,cantidadElementos,arrayCliente[i].id);
            if((arrayCliente[i].isEmpty==0))
            {
                cliente_mostrarUnoSolo(arrayCliente[i],indiceBusqueda);
            }
        }
    }
}
/** \brief busca un indice vacio en el array para poder cargar un elemento
 *
 * \param  el array de cliente
 * \param  los elementos del array
 * \param  una variable isempty que sea =lado a la variable de la estructura
 * \return retorna i si encuentra indice libre -1 si no
 *
 */
int cliente_buscarPorIsEmpty(Cliente* arrayCliente,int cantidadElementos,int isEmptyABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if(arrayCliente[i].isEmpty==isEmptyABuscar)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
/** \brief busca un indice lleno por medio de la id
 *
 * \param  el array de cliente
 * \param  los elementos del array
 * \param  una variable id para igualarla a la dde la estructura
 * \return retorna i si encuentra el id -1 si no
 *
 */
int cliente_buscarPorId(Cliente* arrayCliente,int cantidadElementos,int idABuscar)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        if((arrayCliente[i].isEmpty==0) && (arrayCliente[i].id==idABuscar))
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
/** \brief da de alta un cliente determinado generando su propia id verificando si el array esta lleno o libre
 *
 * \param array de cliente
 * \param los elementos del array
 * \return retorna 1 y da de alta la venta o -1 y error
 *
 */
int cliente_darDeAlta(Cliente* arrayCliente,int cantidadElementos,int* contAltas)
{
    int confirmacion;
    int retorno=-1;
    int indice;
    int ingreso=1;
    int auxCodigoInt=*contAltas;
    Cliente auxDatos;
    char auxiliarCuit[12];
    indice=cliente_buscarPorIsEmpty(arrayCliente,cantidadElementos,1);
    if(indice==-1)
    {
        printf("\nNo hay lugar libre en la lista\n");
    }
    else
    {
        if(!getStrLetras("\nIngrese el nombre: ",auxDatos.nombre,"\nError. reintente\n","\nRango 6 y 20\n",6,20,3))
        {
            ingreso=0;
        }
         if(!getStrLetras("\nIngrese el apellido: ",auxDatos.apellido,"\nError. reintente\n","\nRango 6 y 20\n",6,20,3))
        {
            ingreso=0;
        }
        if(ingreso==1)
        {
            confirmacion=validarGenero("\nIngrese el genero (m/f): ","\nERROR. ('m' o 'f'): ");
            if(confirmacion==1)
            {
                strcpy(auxDatos.sexo,"Masculino");
            }
            else if(confirmacion==0)
            {
                strcpy(auxDatos.sexo,"Femenino");
            }
        }

        if(!getStrNumeros("\nIngrese Cuit: ",auxDatos.cuit,"\nError. reintente\n","\nRango 12 numeros\n",1,999,3))
        {
        	strncpy(auxDatos.cuit,auxiliarCuit,999);
            ingreso=0;
        }

        if(ingreso==1)
        {
            confirmacion=confirmarCambios("\nDar de alta? (s/n): ","\n('s' o con 'n'): ");
            if(confirmacion==1)
            {
                auxDatos.id=auxCodigoInt;
                auxDatos.isEmpty=0;
                arrayCliente[indice]=auxDatos;
                *contAltas=auxCodigoInt+1;
                printf("\nSe ha dado de alta al numero %d\n",auxCodigoInt);
                retorno=1;
            }
        }
    }
    if(retorno==-1)
    {
        printf("\nAlta cancelada\n");
    }
    return retorno;
}
/** \brief da de baja un cliente determinado
 *
 * \param array de cliente
 * \param los elementos del array
 * \return retorna sePudo=1 y da de baja o -1 y error
 *
 */
int cliente_darDeBaja(Cliente* arrayCliente,int cantidadElementos)
{
    int sePudo=-1;
    int confirmacion;
    int indiceBusqueda;
    char auxCodigoStr[256];
    int auxCodigoInt;
    if(cliente_buscarPorIsEmpty(arrayCliente,cantidadElementos,0)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        cliente_mostrar(arrayCliente,cantidadElementos);
        if(getStrNumerosSinRango("\nIngrese el id a dar de baja: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceBusqueda=cliente_buscarPorId(arrayCliente,cantidadElementos,auxCodigoInt);
            if(indiceBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                confirmacion=confirmarCambios("\nEsta seguro que desea dar de baja? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                if(confirmacion==1)
                {
                    arrayCliente[indiceBusqueda].isEmpty=1;
                    printf("\nSe ha dado de baja al id numero %d\n",auxCodigoInt);
                    sePudo=1;
                }
                else if(confirmacion==0)
                {
                    printf("\nBaja cancelada por el usuario\n");
                    sePudo=0;
                }
            }
        }
        if(sePudo==-1)
        {
            printf("\nBaja cancelada\n");
        }
    }
    return sePudo;
}
/** \brief modifica datos de un cliente determinado por id
 *
 * \param array de cliente
 * \param los elementos del array
 * \return retorna sePudo=1 y si se modifica o -1 y error
 *
 */
int cliente_modificarDatos(Cliente* arrayCliente,int cantidadElementos)
{
    int sePudo=0;
    int indiceBusqueda;
    char auxCodigoStr[256];
    int auxCodigoInt;
    if(cliente_buscarPorIsEmpty(arrayCliente,cantidadElementos,0)==-1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        cliente_mostrar(arrayCliente,cantidadElementos);
        if(getStrNumerosSinRango("\nIngrese el id a modificar: ",auxCodigoStr,"\nSolo se permiten numeros\n",3))
        {
            auxCodigoInt=atoi(auxCodigoStr);
            indiceBusqueda=cliente_buscarPorId(arrayCliente,cantidadElementos,auxCodigoInt);
            if(indiceBusqueda==-1)
            {
                printf("\nEl id ingresado no existe\n");
            }
            else
            {
                cliente_pedirDatosAModificar(arrayCliente,cantidadElementos,indiceBusqueda);
                sePudo=1;
            }
        }
    }
    if(sePudo==0)
    {
        printf("\nModificacion cancelada\n");
    }
    return sePudo;
}
/** \brief pide datos de un cliente para modificar sus variables por id
 *
 * \param array de cliente
 * \param los elementos del array
 * \param indice
 */
void cliente_pedirDatosAModificar(Cliente* arrayCliente,int cantidadElementos,int indice)
{
   // int indiceBusqueda;
    int confirmacion;
    int flagPrimerCambio=0;
    int opcionMenu;
    char continuarMenu='s';
    Cliente proximosDatos;
    Cliente auxDatos;
    char auxCuitStr[256];
    proximosDatos=arrayCliente[indice];
    do
    {
        system("cls");
        printf("\nCODIGO      NOMBRE        APELLIDO        GENERO          CUIL\n");

        printf("\nDatos actuales seleccionados:\n");
        cliente_mostrarUnoSolo(arrayCliente[indice], indice);
        printf("\nDatos a modificar:\n");
        cliente_mostrarUnoSolo(proximosDatos,indice);

        printf("\nQue datos le gustaria modificar?\n");
        printf("1-NOMBRE\n");
        printf("2-APELLIDO\n");
        printf("3-GENERO\n");
        printf("4-CUIL\n");
        printf("5-CONFIRMAR CAMBIOS\n");
        printf("6-FINALIZAR MODIFICACION\n");
        opcionMenu=getInt("\nIngrese una opcion: ");
        switch(opcionMenu)
        {
            case 1:
                if(getStrLetras("\nIngrese el nombre: ",auxDatos.nombre,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
                {
                    strcpy(proximosDatos.nombre,auxDatos.nombre);
                    printf("\nSe ha ingresado el nombre\n");
                    flagPrimerCambio=1;
                }
                system("pause");
                break;
            case 2:
                if(getStrLetras("\nIngrese el apellido: ",auxDatos.apellido,"\nSolo se permiten letras\n","\nRango valido entre 3 y 12\n",3,12,3))
                {
                    strcpy(proximosDatos.apellido,auxDatos.apellido);
                    printf("\nSe ha ingresado el apellido\n");
                    flagPrimerCambio=1;
                }
                system("pause");
                break;
            case 3:
                confirmacion=validarGenero("\nIngrese el genero (m/f): ","\nSolo ingrese el genero con ('m' o con 'f'): ");
                if(confirmacion==1)
                {
                    strcpy(proximosDatos.sexo,"Masculino");
                }
                else if(confirmacion==0)
                {
                    strcpy(proximosDatos.sexo,"Femenino");
                }
                printf("\nSe ha ingresado el genero\n");
                flagPrimerCambio=1;
                system("pause");
                break;
            case 4:
            	 if(getStrNumerosSinRango("\nIngrese el cuit: ",auxCuitStr,"\nSolo se permiten numeros\n",3))
            	 {
            	     strcpy(proximosDatos.cuit,(auxCuitStr));
            	     printf("\nSe ha ingresado el cuit\n");
       	             flagPrimerCambio=1;

            	 }
                system("pause");
                break;
            case 5:
                if(flagPrimerCambio==1)
                {
                    confirmacion=confirmarCambios("\nDesea confirmar los cambios realizados? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                    if(confirmacion==1)
                    {
                        arrayCliente[indice]=proximosDatos;
                        printf("\nSe han confirmado los cambios realizados\n");
                        flagPrimerCambio=0;
                        system("pause");
                    }
                }
                else
                {
                    printf("\nNo se han realizado nuevos cambios que confirmar\n");
                    system("pause");
                }
                break;
            case 6:
                if(flagPrimerCambio==0)
                {
                    confirmacion=1;
                }
                else
                {
                    confirmacion=confirmarCambios("\nEsta seguro que desea salir sin confirmar cambios? (s/n): ","\nSolo confirme con ('s' o con 'n'): ");
                }
                if(confirmacion==1)
                {
                    printf("\nModificacion finalizada\n");
                    continuarMenu='n';
                }
                break;
            default:
                printf("\nOpcion ingresada no valida\n");
                system("pause");
        }
    }
    while(continuarMenu=='s');
}
void cliente_ordenarDatos(Cliente* arrayCliente,int cantidadElementos)
{
    int i;
    int j;
    Cliente auxDatos;
    for(i=0;i<cantidadElementos-1;i++)
    {
        for(j=i+1;j<cantidadElementos;j++)
        {
            if(strcmp(arrayCliente[i].apellido,arrayCliente[j].apellido)==1)
            {
                auxDatos=arrayCliente[i];
                arrayCliente[i]=arrayCliente[j];
                arrayCliente[j]=auxDatos;
            }
            else if(strcmp(arrayCliente[i].apellido,arrayCliente[j].apellido)==0)
            {
                if(strcmp(arrayCliente[i].nombre,arrayCliente[j].nombre)==1)
                {
                    auxDatos=arrayCliente[i];
                    arrayCliente[i]=arrayCliente[j];
                    arrayCliente[j]=auxDatos;
                }
            }
        }
    }
}
void cliente_mostrarUnoSoloDos(Cliente* unCliente, int indiceCliente)
{
    printf("\n%d\t",unCliente->id);
    printf("%4s",unCliente->nombre);
    printf("%12s",unCliente->apellido);
    printf("%15s",unCliente->sexo);
    printf("%15s\n\t",unCliente->cuit);
}
int Cliente_imprimirPorId(Cliente* arrayClientes, int cantidadElementos, int ID)
{
    int retorno=-1;
    int i;
    if(arrayClientes !=NULL && cantidadElementos>0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayClientes[i].id == ID)
            {
                printf("\nId: %d",arrayClientes[i].id);
                printf("\t Nombre: %s",arrayClientes[i].nombre);
                printf("\t Apellido: %s",arrayClientes[i].apellido);
                printf("\t Cuit: %s\n",arrayClientes[i].cuit);
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
