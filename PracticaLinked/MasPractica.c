#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    char nombre[50];
    char sexo;
    float sueldo;
} eEmpleado;

void mostrarEmpleadoD(eEmpleado* e);
//Contructores
eEmpleado* new_empleado();
eEmpleado* new_empleadoParam(int id, char* nombre,char sexo,float sueldo);
//Setters
int empleadoSetId(eEmpleado* pEmp, int id);
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

    emp3 = new_empleadoParam(1234,"Juan",'m',22500);


    mostrarEmpleadoD(emp2);
    mostrarEmpleadoD(emp3);


    free(emp2);
    free(emp3);

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
        nuevoEmpleado->id= id;
        strcpy(nuevoEmpleado->nombre,nombre);
        nuevoEmpleado->sexo=sexo;
        nuevoEmpleado->sueldo= sueldo;
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


    return todoOk;
}
