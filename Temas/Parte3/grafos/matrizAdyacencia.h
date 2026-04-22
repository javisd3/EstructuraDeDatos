eduroam
Error: falló la activación de la conexión: Se necesitan secretos, pero no se han proporcionado
Pista: use «journalctl -xe NM_CONNECTION=f7a45558-5134-4b34-a594-01861605895e + NM_DEVICE=wlan0» para obtener más detalles.


#define N 5

typedef struct{
    int matriz[N][N];
    tConjunto vertices;
}tGrafo;

typedef int tVertice;

void crearGrafo(tGrafo *g);
void insertarVertice(tGrafo *g, tVertice v);
void insertarAristas((tGrafo *g, tVertice v1, tVertice v2);
int esGrafoVacio(tGrafo g);
void adyacentes(tGrafo g, tVertice v, tConjunto *ady);
int sonAdyacentes(tGrafo g, tVertice v1, tVertice v2);
