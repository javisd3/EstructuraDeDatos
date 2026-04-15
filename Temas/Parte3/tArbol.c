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

int nivelElemento(tArbol a, tElemento e){
    tElemento r;
    tArbol hi, hd;
    int nivel;
    
    if(EsArbolVacio(a)){
        nivel = 0;
    }else{
        Raiz(a, &r);
        if(igualElemento(e, r)){
            nivel = 1
    }else{
            HijoIzq(a, &hi);
            HijoDer(a, &hd); 
            if (pertenece(hi, e)){
                if (pertenece(hd, e)){
                    nivel = 1 + min(nivelElemento(hi, e), nivelElemento(hd, e));
            }else{
                nivel = 1 + nivelElemento(hi,e);
            }
        }
    }
    return nivel;
}

void simetrico (tArbol a, tArbol *as){
    tElemento r;
    tArbol hi, hd,hsi, hsd;
    if(EsArbolVacio(a)){
        crearArbolVacio(as);
    }else{
        Raiz(a, &r);
        HijoIzq(a, &hi);
        HijoDer(a, &hd);    
        simetrico(hd,&hds);
        simetrico(hi,&his);
        ConstruirArbolBin(&as, hds, r, his);
    }
}

int iguales(tArbol a, tArbol b){
    telemento r;
    tArbol hi, hd;
    int igual;

    if(EsArbolVacio(a)){
        igual = EsArbolVacio(b);
    }else if (!EsArbolVacio(b)){
        Raiz(a, &r);
        Raiz(b, &r2);
        if(igualElemento(r, r2)){   
    
