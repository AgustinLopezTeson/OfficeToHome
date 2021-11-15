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

int main()
{


    eEmpleado* emp2;
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


    emp3 = new_empleadoParam(12340,"Juan",'m',22500.25);


    mostrarEmpleadoD(emp2);
    mostrarEmpleadoD(emp3);


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
            free(nuevoEmpleado);
            nuevoEmpleado=NULL;
        }

    }else{
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
    }else{
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
    }else{
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
    }else{
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
    }else{
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
