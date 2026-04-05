Prefijo : TipoLista x TipoElemento -> TipoLista

Prefijo(CrearVacia, elem) = CrearVacia

Prefijo(Construir(e, lista), elem) = 
    SI Igual(e, elem) ENTONCES
        CrearVacia
    SINO
        Construir(e, Prefijo(lista, elem))