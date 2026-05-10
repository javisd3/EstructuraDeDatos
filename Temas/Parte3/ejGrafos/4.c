void PadresNoAbuelos(tArbol a, tLista *l){
    tArbol hi, hd;
    tElemento r;

    if (!esArbolVacio(a)) {
        hijoIzq(a, &hi);
        hijoDer(a, &hd);

        if(esHoja(hi) && esHoja(hd) || 
        esHoja(hi) && esArbolVacio(hd) || 
        esArbolVacio(hi) && esHoja(hd){
            raiz(a, &r);
            insertar(&l, r);
        } else {
            padresNoAbuelos(hi, &l);
            padresNoAbuelos(hd, &l);
        }
    }
}
------------------------------------------------
Observadora no selectora
RecInverso: TipoArbolBin -> TipoLista

RecInverso (CrearArbolBinVacio) = CrearListaVacia

RecInverso (ConstruirArbolBin(i,r,d)) = Concatenar(InsertarFinal(r,RecInverso(d)) r, RecInverso(i))


