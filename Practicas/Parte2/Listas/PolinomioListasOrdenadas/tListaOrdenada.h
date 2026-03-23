// Constructoras generadoras
void crearListaVacia(TLista *l);
void construir(TLista *l, TElemento elem);

// Observadoras selectoras
void obtenerPrimeroLista(TLista l, TElemento* elem);
void restoListaL (TLista *l);

// Observadoras no selectoras
int esListaVacia(TLista l);
int longitudLista (TLista l);
int perteneceLista (TElemento e, TLista l);
void ultimoLista(TElemento *e, TLista l);

// Constructoras no generadoras
void insertarListaFinal(TLista *l, TElemento elem);
int eliminarElementoLista(TLista *l, TElemento elem);
void concatenarLista (TLista *l1, TLista l2);
int igualLista (TLista l1, TLista l2);
void asignarLista (TLista original, TLista *copia);
void destruirLista(TLista *l);
void mostrarLista(TLista l);