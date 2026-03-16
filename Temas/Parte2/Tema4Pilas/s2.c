void duplicar(tPila *pPila){
    tPila aux;
    tElemento elem;

    crearPilaVacia(dPila);

    while !(EsPilaVacia(pPila)){
        cima(pPila, &e);
        Push(e, dPila);
        Push(e, dPila);
        Pop(pPila);
    }
}

-------------------------------
void duplicar(tPila *pPila){
    tPila aux;
    tElemento elem;

    crearPilaVacia(aux);

    while (!esPilaVacia(*pPila)){
        cima(*pPila, &elem);
        pop(pPila);
        Push(&aux, elem);
    }
    while (!esPilaVacia(aux)){
        cima(aux, &elem);
        pop(&aux);
        Push(pPila, elem);
        Push(pPila, elem);
    }
}
//que hace,*&,comparacion