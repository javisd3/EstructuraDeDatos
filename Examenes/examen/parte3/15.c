float SumarHojas(tArbol a){
    tArbol izq, der;
    tElemento elem;
    float miNumero;
    float loQueYoAporto;

    if(esArbolVacio(a) == 1){
        return 0;
    }

    Raiz(a, &elem);
    miNumero = valor(elem);
    
    HijoIzq(a, &izq);
    HijoDer(a, &der);

    if (EsArbolVacio(izq) == 1 && EsArbolVacio(der) == 1) {
        loQueYoAporto = miNumero; 
    } else {
        loQueYoAporto = 0.0;     
    }
    return loQueYoAporto + SumarHojas(izq) + SumarHojas(der);
}

