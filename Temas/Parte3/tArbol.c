int numNodos(tArbol a){
    int num;
    tArbol hi, hd;
    if(EsArbolVacio(a)){
        num=0;
    }
    else{
        HijoIzq(a, &hi);
        HijoDer(a, &hd);
        num=1+numNodos(a->hi)+numNodos(a->hd);
    }
    return num;
}

int numHojas(tArbol a){
    int num;
    tArbol hi, hd;
    if(EsArbolVacio(a)){ 
        num=0;
    }
    else{
        HijoIzq(a, &hi);
        HijoDer(a, &hd);
        if(EsHoja(a)){
            num=1;
        }           
        else{
            num=numHojas(a->hi)+numHojas(a->hd);
        }
    }
    return num;
}


int altura(tArbol a){
    int alt; 
    tArbol hi, hd;
    if(EsArbolVacio(a)){
        alt=0;
    }else{
        HijoIzq(a, &hi);
        HijoDer(a, &hd);
        alt=1+max(altura(hi), altura(hd));
    }
    return alt;
}

int pertenece(tArbol a, tElemento){
    int esta;
    tArbol hi, hd;
    tElemento r;
    if(EsArbolVacio(a)){
        esta = 0;
    }else{
        Raiz(a, &r);
        if (igualElemento(r, e)){
            esta = 1;
        }else{
            HijoIzq(a, &hi);
            HijoDer(a, &hd); 
            esta = pertenece(hi) || pertenece(hd);
        }
    }
    return esta;
}