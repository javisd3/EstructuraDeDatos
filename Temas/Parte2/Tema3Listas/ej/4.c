entremezclar : TipoLista x TipoLista -> TipoLista

entremezclar(CrearVacia, lista2) = lista2

entremezclar(Construir(e, lista1), lista2) = Construir(e, entremezclar(lista2, lista1))