#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mostrarNumeros(int* vec ,int tam );

typedef struct
{
    int numero;
    char caracter;
    char cadena[50];
    float flotante;
}eDato;

eDato* funcion();
/*int main()
{


    printf("Hello world!\n");

    int* casa=NULL;
    int tam=2;
    casa = (int*)malloc(sizeof(int)*5);

    if(casa == NULL){
    printf("No se pudo conseguir espacion en memoria");
    exit(1);
    }

    for(int i = 0; i<tam; i++)
    {
        printf("Ingrese un numero ");
        scanf("%d",casa + i);
    }

    for(int i = 0 ; i<tam; i++){

        printf("%d\n\n", *(casa+i));
    }


    int* auxPileta=NULL;
    auxPileta=(int*)realloc(casa,sizeof(int)*tam*4);

    if(auxPileta==NULL){

        printf("No se encontro memoria para agrandar");
        exit(1);

    }

    casa=auxPileta;

    auxPileta=NULL;

    tam=tam*2;

    for(int i = 0; i<tam; i++)
    {
        printf("Ingrese un numero ");
        scanf("%d",casa + i);
    }

    for(int i = 0 ; i<tam; i++){

        printf("%d\n\n", *(casa+i));
    }




        casa = (int*)realloc(casa,sizeof(int)*(tam/2));

        tam =tam/2;

        mostrarNumeros(casa,tam);


        eDato* miDato;


        miDato= funcion();

        printf("%d----%c----%s----%.2f\n",miDato->numero,miDato->caracter,miDato->cadena,miDato->flotante);
        printf("%d----%c----%s----%.2f\n",miDato->numero,miDato->caracter,miDato->cadena,miDato->flotante);
        printf("%d----%c----%s----%.2f\n",miDato->numero,miDato->caracter,miDato->cadena,miDato->flotante);
        printf("%d----%c----%s----%.2f\n",miDato->numero,miDato->caracter,miDato->cadena,miDato->flotante);
        printf("%d----%c----%s----%.2f\n",miDato->numero,miDato->caracter,miDato->cadena,miDato->flotante);








    return 0;
}

eDato* funcion() //Constructor por defecto
{
    eDato* p;

    if (p!=NULL){

    p = (eDato*) malloc(sizeof(eDato));

    p->numero=1000;
    p->caracter='a';
    strcpy(p->cadena,"holis");
    p->flotante=5.5;


         }

return p;
}















int mostrarNumeros(int* vec ,int tam ){
    int todoOk=0;
        for(int i = 0; i<tam; i++)
        {
            printf("Ingrese un numero ");
            scanf("%d",vec + i);
        }

        for(int i = 0 ; i<tam; i++){

            printf("%d\n\n", *(vec+i));
        }
return todoOk;
}
*/
