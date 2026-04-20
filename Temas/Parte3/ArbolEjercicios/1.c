void MostrarInteresantes(tArbolBB a) {
    tArbolBB izq, der;
    tElemento r;

    if (!EsArbolVacio(a)) {
        HijoIzq(a, &izq);
        MostrarInteresantes(izq);

        Raiz(a, &r);
        if (EsInteresante(r)) {
            Mostrar(r);
        }

        HijoDer(a, &der);
        MostrarInteresantes(der);
    }
}
-------------------------------------------------------------------------------------
