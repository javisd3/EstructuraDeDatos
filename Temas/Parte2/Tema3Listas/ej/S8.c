Prefijo(CrearVacia, e)=CrearVacia
Prefijo(Construir(e,lista),e1) = Si e=e1 -> CrearVacia | Construir (e, Prefijo(lista,e1))

