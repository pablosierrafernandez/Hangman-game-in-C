/** JUEGO DEL AHORCADO
 *  PABLO SIERRA FERNÁNDEZ
 *  27/11/2019*/
/**Hacemos declaración de librerias y constantes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define MAX 100   /**Numero maximo de caracteres de la palabra*/
#define MAXP 9     /** Numero máximo de palabras dentro del fichero*/
#define INTENTOS 10  /**Numero másimo de INTENTOS*/

int main()
{


    /**Hacemos declaración de las variables*/

    FILE *fichero;
    char palabra[MAX]=""; /**Cadena para guardar la palabra*/
    char secreto[MAX]=""; /**Cadena para guardar la palabra en formato secreto "_ _ _"*/
    char creencia[MAX]="";
    char c;
    int a=1, numletras=0;
    char nombre[MAX];  /**Cadena para guardar el nombre de usuario.*/
    bool encontrado=false;

    fichero = fopen ("paraules.txt", "r"); /** Abrimos el fichero en modo lectura (r).*/
    srand (time(NULL));
    int numero = rand ()% (MAXP - 1 + 1); /**Generamos numero aleatorio entre MAXP y 1*/
    int inte=0;
    char letras[INTENTOS]=""; /**    Cadena donde guardaremos las letras que el usuario va diciendo.*/
    bool completo=false;
    bool esta=false;
    bool repetida=false;
    int cont;


    /**Si fichero NULL acaba el juego sino comenzamos el juego*/
if(feof(fichero)){printf("ERROR"); return 0;}
    if ((fichero!=NULL)&& (!feof(fichero)))
    {
        printf("\n\n\n\n\t\t<<<<<<<<<>>>>>>>>><<<<<<<< JUEGO DEL AHORCADO >>>>>>>>><<<<<<<<>>>>>>>>>\n");
        printf("\nBienvenid@ al juego del ahoracado. Como te llamas?\n");
        scanf("%s", nombre) ; /**  ---->  gets coge todo hasta marcar el enter, ----->   y el scanf("%s", nombre) solo hasta el primer espacio(' ')*/

        printf("\nHola %s , que empiece el juego!\n", nombre);


        /**Buscamos la el salto de linea correspondiente al numero aleatorio para entonces encontrar
        la palabra aleatoria*/


        while (!feof(fichero) && (encontrado==false))  /**Mientras no lleguemos al final del archivo y no encontremos la palabra seguiremos avanzando en el fichero*/
        {
            if(c=='\n')
            {
                a++;  /**'a' corresponde al numero de palabras que hemos leido en el fichero*/
            }
            if(a==numero) /**Si encontramos la palabra entonces la guardamos en un vector*/
            {
                encontrado=true;
                fscanf (fichero, "%c", &c);
                while((c!='\n')&&(!feof(fichero)))
                {
                    palabra[numletras]=c;
                    secreto[numletras]='_'; /**Creamos el vector secreto aprovechando la creacion del vector con la palabra secreta.*/
                    fscanf (fichero, "%c", &c);
                    numletras++; /**Calculamos el numero de letras de la palabra ya que luego nos servirá como dimensión.*/

                }
            }
            fscanf (fichero, "%c", &c);
        }


        /**Una vez leída la palabra y guardada en un vector ya podemos cerrar el fichero.*/

        fclose(fichero);
        printf("\nTe quedan %i intentos. %s, por que letra apuestas? Pulsa 0 si crees que la sabes.\n", INTENTOS, nombre);


        /**Mientras no hayamos completado el vector secreto con las letras introducidas por el usuario seguiremos
        en el while. Nos devolverá un return 0 si el numnero de intentos se agota.*/

        while(completo==false)
        {
            for(int s=0; s<=numletras; s++)  /**Imprimimos el vector secreto*/

            {
                printf("%c ",secreto[s]);
            }



            scanf(" %c",&letras[inte]);  /**Leemos la letra introducida por el usuario y la guardamos en el vector 'letras'*/
            printf("\nLa palabra es: %s\n", palabra);  /** **** A EFECTOS PRÁCTICOS MANTENDREMOS ESTA LINEA DE CÓDIGO PARA FACILITAR SU JUEGO DE PRUEBAS *****/
            /**implementacion EXTRA*/
            if (letras[inte]=='0')
            {
                printf("Cual crees que es la palabra secreta?");
                scanf("%s", creencia);

                int ret = strcmp(creencia,palabra);
                if(ret==0)
                {
                    printf("Muy bien has acertado");
                    return 0;
                }
                else
                {
                    printf("No es la palabra\n Escriba otra letra\n");
                }
            }
            else
            {
                /**Recorremos el vector 'letras' junto con el vector de la palabra buscando equivalencias, si las hay guardaremos la equivalencia
                en el mismo sitio en el vector 'secreto', así lo vamos rellenando*/

                for(int j=0; palabra[j]!='\0'; j++)
                {
                    if(letras[inte]==palabra[j])
                    {
                        secreto[j]=letras[inte];
                        esta=true;
                    }


                }
                /**     ***** APORTE EXTRA *****
                    Si la letra introducida por el usuario coincide con alguna del vector 'letras', es decir, que ya haya sido dicha anteriormente, ha repetido la letra
                    En ese caso NO contará como turno y le pediremos nuevamente que inserte una letra.*/
                for(int indice=0; indice<inte; indice++)
                {
                    if(letras[indice]==letras[inte])
                    {
                        repetida=true;
                    }
                }
                if(repetida==false)
                {
                    inte++; /**Variable correspondiente a los intentos del usuario, además tendremos tantas*/
                    /**letras introducidas por el usuario como intentos realice asique nos vale de índice*/

                    /**Si el vector 'secreto' y el vector 'palabra' coinciden completamente podremos decir que el usuario ha encontrado la palabra secreta.
                    Por lo que vamos a comparar ambos vectores*/

                    for(int com=0; com<=numletras; com++)
                    {
                        if(palabra[com]==secreto[com])
                        {
                            completo=true;  /**Booleano para avisar de que se ha encontrado coincidencia.*/
                        }
                        else
                        {
                            completo=false;  /**Booleano para avisar de que no hay coincidencia*/
                            com=numletras+1; /**Si se produce una sola vez que NO haya coincidencia 'com' que es el indice del for pasará a ser <numLetras y saldrá del mismo.*/
                        }


                        /**Vía de escape si el usuario gasta sus INTENTOS y NO existen coincidencia completa entre el vector 'secreto' y el vector 'palabra'*/

                        if ((inte==INTENTOS) &&(completo==false))
                        {
                            printf("\nLastima, %s! La palabra era %s.",nombre,palabra);
                            return 0; /**FIN DEL PROGRAMA*/
                        }

                    }


                    /**En base a si la letra que ha dicho el usuario se encontraba en la palabra  o no mostraremos un mensaje*/

                    if(completo==false)
                    {
                        if(esta==false)
                        {
                            printf("Oh, la letra %c no esta en la palabra.\n", letras[inte-1]);

                            cont=INTENTOS-inte;
                            printf("\nTe quedan %i intentos. %s, por que letra apuestas?\n", cont, nombre);
                        }
                        else
                        {

                            cont=INTENTOS-inte;
                            printf("\nMuy bien! Te quedan %i intentos. %s, por que letra apuestas?\n", cont, nombre);
                        }
                    }

                    esta=false; /**Siempre volvemos a poner 'esta' en falso ya que si el vector 'secreto' cambia cambiará*/
                    /** a verdadero puesto que se ha añadido una nueva letra al vector*/
                }
                else
                {
                    printf("\nHas repetido la letra!!! Vuelve a insertar otra letra\n"); /**Como hemos dicho anteriormente volveremos a pedir una nueva letra ya que esta repetida.*/
                    repetida=false;

                }

            }
        }
        printf("\nFelicidades, %s! La palabra es: %s.", nombre, palabra); /**Si no ha acabado el programa por final de INTENTOS entonces sí o sí habrá acertado.*/
    }



    else
    {
        printf("\n\t\tERROR\t\t <<<Archivo no encontrado o vacio>>>\n"); /**MENSAJE QUE NOS MUESTRA ERROR DE BUSQUEDA DEL ARCHIVO DE LECTURA*/
    }



}
