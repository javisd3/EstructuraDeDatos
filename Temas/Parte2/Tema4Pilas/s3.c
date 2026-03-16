void Sustituir(tPila *pPila, tElemento e1, tElemento e2){
    tPila aux;
    tElemento elem;

    crearPilaVacia(aux);

    while (!esPilaVacia(*pPila)){
        cima(*pPila, &elem);
        pop(pPila);
        Push(&aux, elem);
    }
    while(cima->info != e1){
        cima(pPila, &elem);
        pop(pPila);
        Push(&aux, elem);
    }
    else{
        cima(pPila, &elem);
        pop(pPila);
        Push(pPila, e2);
    }
}
--------------------------------------
void Sustituir(tPila *pPila, tElemento e1, tElemento e2){
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
        if (igualElemento(elem, e1)){
            Push(pPila, e2);
        }else{
            Push(pPila, elem);
    }
}