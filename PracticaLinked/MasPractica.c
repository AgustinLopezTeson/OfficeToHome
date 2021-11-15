#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct
{
    int id;
    char nombre[50];
    char sexo;
    float sueldo;
} eEmpleado;
//View
void mostrarEmpleadoD(eEmpleado* e);
void mostrarEmpleadosD(eEmpleado* e, int tam);
int mostrarEmpleados2(eEmpleado** e, int tam);
//Contructores
eEmpleado* new_empleado();
eEmpleado* new_empleadoParam(int id, char* nombre,char sexo,float sueldo);
//Destructor
void empleadoDestroy(eEmpleado* pEmp);
//Setters
int empleadoSetId(eEmpleado* pEmp, int id);
int empleadoSetNombre(eEmpleado* pEmp, char* nombre);
int empleadoSetSexo(eEmpleado* pEmp, char sexo);
int empleadoSetSueldo (eEmpleado* pEmp, float sueldo);
//Getters
int empleadoGetId(eEmpleado* pEmp, int* pId);
int empleadoGetNombre(eEmpleado* pEmp, char* nombre);
int empleadoGetSexo(eEmpleado* pEmp, char* sexo);
int empleadoGetSueldo (eEmpleado* pEmp, float* sueldo);
//isEmpty
int inicializarEmpleados(eEmpleado** pEmps, int tam);
//BuscarLibre
int buscarLibre(eEmpleado** PEmps, int tam, int* pIndice);
//Agrandar
int agrandarArray(eEmpleado*** pEmps, int* tam);
int main()
{
    int pIndice;
    int tam=3;
    /*eEmpleado* listaEmp = (eEmpleado*)malloc(sizeof(eEmpleado)*TAM);


    (listaEmp+0)->id = 10003;
    strcpy((listaEmp+0)->nombre,"Lucio");
    (listaEmp+0)->sexo = 'm';
    (listaEmp+0)->sueldo= 97000;

    (listaEmp+1)->id = 10004;
    strcpy((listaEmp+1)->nombre,"Tamara");
    (listaEmp+1)->sexo = 'f';
    (listaEmp+1)->sueldo= 47500;

    (listaEmp+2)->id = 10005;
    strcpy((listaEmp+2)->nombre,"Franscisco");
    (listaEmp+2)->sexo = 'm';
    (listaEmp+2)->sueldo= 97000;*/


    eEmpleado** plista = (eEmpleado**)malloc(sizeof(eEmpleado*)*tam);

    if(!inicializarEmpleados(plista,tam)){

        printf("No se pudo inicializar");
        exit(1);

    }else{

        printf("Empleados inicializados\n");
    }

    buscarLibre(plista,tam,&pIndice);

    if(pIndice!= -1){
    *(plista+pIndice) = new_empleadoParam(10006,"Luis",'m',24000);

    printf("Alta exitosa Luis\n");

    }else{
        printf("No se encontro lugar\n");
        }

    buscarLibre(plista,tam,&pIndice);

    if(pIndice!= -1){

    *(plista+pIndice) = new_empleadoParam(10007,"Cristian",'m',27000);
    printf("Alta exitosa Cristian\n");

    }else{
        printf("No se encontro lugar\n");
        }

    buscarLibre(plista,tam,&pIndice);

      if(pIndice!= -1){
        *(plista+pIndice) = new_empleadoParam(10008,"Ariel",'m',127000);

    printf("Alta exitosa Ariel\n");

    }else{
        printf("No se encontro lugar\n");
        }

    buscarLibre(plista,tam,&pIndice);
      if(pIndice!= -1){
            *(plista+pIndice) = new_empleadoParam(10008,"Lucio",'m',127000);

            printf("Alta exitosa Lucio\n");

    }else{
        printf("No consegui lugar para lucio\n\n ");
       if(agrandarArray(&plista,&tam)){

            buscarLibre(plista,tam,&pIndice);
                if(pIndice!= -1){

                *(plista+pIndice) = new_empleadoParam(10008,"Lucio",'m',127000);
                printf("Alta exitosa Lucio\n");

               }
            }
        }

 /*   eEmpleado* emp2;
    emp2 = new_empleado();

    eEmpleado* emp3;
    emp3 = new_empleado();


    printf("Ingrese el id: \n");
    scanf("%d", &emp2->id);

    printf("Ingrese el nombre: \n");
    fflush(stdin);
    gets(emp2->nombre);

    printf("Ingrese el sexo: \n");
    fflush(stdin);
    scanf("%c", &emp2->sexo);

    printf("Ingrese el sueldo : \n");
    scanf("%f", &emp2->sueldo);
*/

   // emp3 = new_empleadoParam(10002,"Ernesto",'m',22500.25);


   // mostrarEmpleadoD(emp2);
   // mostrarEmpleadoD(emp3);
   // mostrarEmpleadosD(listaEmp,tam);
        mostrarEmpleados2(plista,tam);












    //empleadoDestroy(emp2);
    //empleadoDestroy(emp3);



    return 0;
}



void mostrarEmpleadoD(eEmpleado* e)
{

    printf("%d   %s   %c   %.2f\n\n",e->id,e->nombre,e->sexo,e->sueldo);

}

eEmpleado* new_empleado()
{

    eEmpleado* nuevoEmpleado;


    nuevoEmpleado = (eEmpleado*) malloc ( sizeof(eEmpleado));

    if(nuevoEmpleado!=NULL)
    {
        nuevoEmpleado->id= 0;
        strcpy(nuevoEmpleado->nombre," ");
        nuevoEmpleado->sexo='x';
        nuevoEmpleado->sueldo= 0000;
    }

    return nuevoEmpleado;
}

eEmpleado* new_empleadoParam(int id, char* nombre,char sexo,float sueldo)
{

    eEmpleado* nuevoEmpleado;


    nuevoEmpleado = new_empleado();

    if(nuevoEmpleado!=NULL)
    {
        if(!(    empleadoSetId(nuevoEmpleado,id)&&
                 empleadoSetNombre(nuevoEmpleado,nombre)&&
                 empleadoSetSexo(nuevoEmpleado,sexo)&&
                 empleadoSetSueldo(nuevoEmpleado,sueldo)))
        {
            printf("Hubo un problema");
            empleadoDestroy(nuevoEmpleado);
            nuevoEmpleado=NULL;
        }

    }
    else
    {
        printf("No se pudo conseguir memoria");
    }
    return nuevoEmpleado;
}

int empleadoSetId(eEmpleado* pEmp, int id)
{
    int todoOk=0;

    if(pEmp !=NULL && id>=10000 && id<= 50000)
    {
        pEmp->id=id;
        todoOk =1;
    }
    else
    {
        printf("Problema con el Id");
    }


    return todoOk;
}

int empleadoSetSexo(eEmpleado* pEmp, char sexo)
{
    int todoOk=0;
    sexo= tolower(sexo);
    if(pEmp !=NULL && (sexo=='m' || sexo== 'f'))
    {
        pEmp->sexo=sexo;
        todoOk =1;
    }
    else
    {
        printf("Problema con el sexo");
    }


    return todoOk;
}

int empleadoSetSueldo (eEmpleado* pEmp, float sueldo)
{

    int todoOk=0;

    if(pEmp !=NULL && sueldo>0)
    {
        pEmp->sueldo=sueldo;
        todoOk =1;
    }
    else
    {
        printf("Problema con el Sueldo");
    }


    return todoOk;

}

int empleadoSetNombre(eEmpleado* pEmp, char* nombre)
{
    int todoOk=0;

    if(pEmp != NULL && nombre!=NULL && strlen(nombre)<20)
    {
        //strlwr(nombre);
        //nombre[0]= toupper(nombre[0]);
        strcpy(pEmp->nombre,nombre);
        todoOk =1;
    }
    else
    {
        printf("Problema con el Nombre");
    }


    return todoOk;
}

int empleadoGetId(eEmpleado* pEmp, int* pId)
{
    int todoOk=0;

    if(pEmp != NULL && pId!=NULL)
    {

        *pId= pEmp->id;
        todoOk=1;
    }

    return todoOk;
}

int empleadoGetNombre(eEmpleado* pEmp, char* nombre)
{
    int todoOk=0;

    if(pEmp != NULL && nombre!=NULL)
    {

        strcpy(nombre,pEmp->nombre);
        todoOk=1;
    }

    return todoOk;
}

int empleadoGetSexo(eEmpleado* pEmp,char* sexo)
{
    int todoOk=0;

    if(pEmp != NULL && sexo!=NULL)
    {

        *sexo= pEmp->sexo;
        todoOk=1;
    }

    return todoOk;
}

int empleadoGetSueldo(eEmpleado* pEmp, float* sueldo)
{
    int todoOk=0;

    if(pEmp != NULL && sueldo!=NULL)
    {

        *sueldo= pEmp->sueldo;
        todoOk=1;
    }

    return todoOk;
}

void empleadoDestroy(eEmpleado* pEmp)
{
    free(pEmp);
}

void mostrarEmpleadosD(eEmpleado* e, int tam)
{

    if(e!=NULL && tam> 0)
    {

        for(int i = 0 ; i<tam; i++)
        {
            printf("ID      NOMBRE     SEXO      SUELDO");
            mostrarEmpleadoD(e+i);

        }

    }

}

int mostrarEmpleados2(eEmpleado** e, int tam)
{


    int todoOk=0;
    if(e!=NULL && tam> 0)
    {
        printf("ID      NOMBRE     SEXO      SUELDO\n\n");
        for(int i = 0 ; i<tam; i++)
        {

            mostrarEmpleadoD(*(e+i));

        }

    }

    return todoOk;
}

int inicializarEmpleados(eEmpleado ** pEmps, int tam)
{
    int todoOk=0;

    if(pEmps != NULL && tam>0)
    {

        for(int i =0; i<tam ; i++)
        {

            *(pEmps+i)=NULL;


        }
        todoOk=1;
    }


    return todoOk;
}

int buscarLibre(eEmpleado** pEmps, int tam, int* pIndice)
{

    int todoOk=0;
    *pIndice = -1;
    if(pEmps != NULL && tam>0)
    {

        for(int i =0; i<tam ; i++)
        {

            if(*(pEmps+i)== NULL)
            {
               *pIndice=i;
                break;
            }

        }
        todoOk=1;
    }


    return todoOk;


}

int agrandarArray(eEmpleado*** pEmps, int* tam)
{

int todoOk=0;
eEmpleado** aux;

            aux=(eEmpleado**)realloc(*pEmps,sizeof(eEmpleado*)*(*tam+1));
            if(aux!=NULL){
                printf("Se agrando el array")
                *pEmps=aux;
                *tam++;
                todoOk=1;
            }

    return todoOk;
}
