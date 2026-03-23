#include <stdio.h>
#include <string.h>
#include "Lista.h"
#include "Noticias.h"
#include "Elemento.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    tLista miLista;
    crearListaVacia(&miLista); // Inicializamos la lista circular

    int opcion;
    do {
        printf("\n--- FAKE NEWS DAILY --- \n");
        printf("1. Registrar una nueva noticia\n");
        printf("2. Mostrar todas las noticias\n");
        printf("3. Eliminar una noticia\n");
        printf("4. Calcular numero total de lectores\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1: {
                // Registrar noticia 
                char titulo[MAX_TITULO];
                char medio[MAX_MEDIO];
                int visitas, d, m, a;
                tFecha fecha;
                tElemento nuevaNoticia;

                printf("Introduce el titulo de la noticia: ");
                fgets(titulo, MAX_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Eliminar salto de linea

                printf("Introduce la fecha (DD MM AAAA): ");
                scanf("%d %d %d", &d, &m, &a);
                limpiarBuffer();
                // Asumiendo que tu struct tFecha tiene estos campos accesibles
                fecha.dia = d; fecha.mes = m; fecha.anio = a;

                printf("Introduce el medio o fuente: ");
                fgets(medio, MAX_MEDIO, stdin);
                medio[strcspn(medio, "\n")] = 0;

                printf("Introduce el numero de visionados: ");
                scanf("%d", &visitas);
                limpiarBuffer();

                // Usamos la función exacta de tu profesora
                crearNoticia(&nuevaNoticia, titulo, fecha, medio, visitas);
                
                // Insertamos al final con coste computacional minimo
                insertarFinal(&miLista, nuevaNoticia); 
                printf("Noticia registrada con exito.\n");
                break;
            }
            case 2:
                // Mostrar noticias en orden de almacenamiento [cite: 17, 18]
                printf("\n--- LISTA DE NOTICIAS ---\n");
                mostrarLista(miLista);
                break;
            case 3: {
                // Eliminar noticia 
                char tituloBorrar[MAX_TITULO];
                tElemento noticiaBorrar;

                printf("Introduce el titulo de la noticia a eliminar: ");
                fgets(tituloBorrar, MAX_TITULO, stdin);
                tituloBorrar[strcspn(tituloBorrar, "\n")] = 0;

                // Creamos un elemento temporal solo con el titulo para que 'igualElemento' lo encuentre
                strcpy(noticiaBorrar.titulo, tituloBorrar);

                if (eliminarElemento(&miLista, noticiaBorrar)) {
                    printf("La noticia fue eliminada del sistema.\n");
                } else {
                    printf("No se encontro ninguna noticia con ese titulo.\n");
                }
                break;
            }
            case 4:
                // Calcular lectores 
                printf("\nEl numero total de lectores afectados por desinformacion es: %d\n", contarVisitas(miLista));
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion no valida. Intentalo de nuevo.\n");
        }
    } while (opcion != 5);

    return 0;
}