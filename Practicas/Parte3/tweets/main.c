#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbolbb.h"

// Función auxiliar para quitar el salto de línea al leer de un fichero
void limpiarSaltoLinea(char *str) {
    int len = strlen(str);
    if (len > 0 && (str[len-1] == '\n' || str[len-1] == '\r')) str[len-1] = '\0';
    if (len > 1 && (str[len-2] == '\n' || str[len-2] == '\r')) str[len-2] = '\0';
}

// Función auxiliar para detectar si un carácter marca el fin del hashtag según el enunciado
int esDelimitador(char c) {
    return (c == ' ' || c == '\n' || c == '\r' || c == '.' || c == ',' || 
            c == '"' || c == '?' || c == '!' || c == ':' || c == ';');
}

int main() {
    tArbolBB arbolTwitter;
    crearArbolVacio(&arbolTwitter);

    // --- 1. CONSTRUIR LA ESTRUCTURA DEL ABB (hashtags.txt) ---
    FILE *fHash = fopen("hashtags.txt", "r");
    if (fHash != NULL) {
        char linea[100];
        // Leemos línea a línea
        while (fgets(linea, sizeof(linea), fHash)) {
            limpiarSaltoLinea(linea);
            if (strlen(linea) > 0) {
                tElemento e;
                inicializarElemento(&e, linea);
                insertarABB(&arbolTwitter, e);
            }
        }
        fclose(fHash);
        printf("[+] Arbol de hashtags construido con exito.\n");
    } else {
        printf("Error: No se pudo abrir hashtags.txt\n");
        return 1;
    }

    // --- 2. ETIQUETADO DE TWEETS (tweets.txt) ---
    FILE *fTweets = fopen("tweets.txt", "r");
    if (fTweets != NULL) {
        char tweet[250]; // Espacio generoso para cada línea
        while (fgets(tweet, sizeof(tweet), fTweets)) {
            limpiarSaltoLinea(tweet);
            
            // Recorremos el texto del tweet buscando la almohadilla '#'
            char *ptr = tweet;
            while (*ptr != '\0') {
                if (*ptr == '#') {
                    char *inicio = ptr;
                    char *fin = inicio + 1; // Avanzamos al menos 1 posición para saltar el '#'
                    
                    // Avanzamos hasta encontrar un delimitador de fin de hashtag o el final de cadena (\0)
                    while (*fin != '\0' && !esDelimitador(*fin)) {
                        fin++;
                    }
                    
                    // Extraemos el hashtag identificado usando strncpy como pide el enunciado
                    int longitud = fin - inicio;
                    char hashEncontrado[100] = {0}; 
                    strncpy(hashEncontrado, inicio, longitud);
                    hashEncontrado[longitud] = '\0'; // Aseguramos el fin de cadena

                    // Buscamos el nodo en nuestro ABB
                    tNodoABB *nodo = buscarNodo(arbolTwitter, hashEncontrado);
                    if (nodo != NULL) {
                        // Si existe, insertamos EL TEXTO DEL TWEET ENTERO en su lista
                        insertarTweet(&(nodo->info.listaTweets), tweet);
                    }
                    
                    ptr = fin; // Continuamos buscando desde donde terminó el hashtag
                } else {
                    ptr++;
                }
            }
        }
        fclose(fTweets);
        printf("[+] Tweets parseados y etiquetados en el arbol.\n\n");
    } else {
        printf("Error: No se pudo abrir tweets.txt\n");
        return 1;
    }

    // --- 3. CONSULTAS INTERACTIVAS ---
    char consulta[100];
    printf("--- SISTEMA DE CONSULTA DE TWITTER ---\n");
    printf("Introduce hashtag a buscar (con el # incluido, o 'FIN' para salir): ");
    scanf("%s", consulta);
    
    while (strcmp(consulta, "FIN") != 0) {
        tNodoABB *resultado = buscarNodo(arbolTwitter, consulta);
        
        if (resultado != NULL) {
            printf("\n=> Tweets encontrados para %s:\n", consulta);
            mostrarListaTweets(resultado->info.listaTweets);
        } else {
            printf("\n=> No se ha encontrado ningun tweet con el hashtag %s.\n", consulta);
        }
        
        printf("\nIntroduce hashtag a buscar (o 'FIN' para salir): ");
        scanf("%s", consulta);
    }

    return 0;
}