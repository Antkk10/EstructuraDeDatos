
template <class T>
Posicion<T>& Posicion<T>::operator--(){
	Celda<T> *aux;
	if(primera==punt)
		punt=0;
	else{
		Celda<T> *q=primera;
		while(q->sig!=punt)
			q=q->sig;
		punt=q;
	}

	return *this;
}

template <class T>
void Lista<T>::Copiar(const Lista<T> &L){
	if(L.cab->sig==0){
		cab=new Celda<T>;
		cab->sig=0;
	}
	else{
		cab= new Celda<T>;
		Celda<T> *p=cab;
		Celda<T> *q=L.cab;
		while(q->sig != 0){
			p->sig=new Celda<T>;
			p->sig->elemento;
			p=p->sig;
			q=q->sig;
		}
		p->sig=0;
	}
}


template <class T>
Lista<T>::Lista(){
	cab=new Celda<T>;
	cab->sig=0;
	
}

template <class T>
Lista<T>::Lista(const Lista<T>& L){
	Copiar(L);
}

template <class T>
void Lista<T>::BorrarAll(){
	while(cab->sig!=0){
		Celda<T> *aux = cab->sig;
		cab->sig=cab->sig->sig;
		delete aux;
	}
	delete cab;
}
template <class T>
Lista<T>::~Lista(){
	BorrarAll();
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista<T>& L){
	if(this!=&L){
		BorrarAll();
		Copiar(L);
	}
	return *this;
}

template <class T>
int Lista<T>::size() const{
	int i=0;
	Celda<T> *pCelda;
	pCelda=cab->sig;
	while(pCelda!=0){
		
		pCelda=pCelda->sig;
		i++;

	}
   
	return i;
}

template <class T>
void Lista<T>::Insertar(Posicion<T> pos, const T& v){
	Celda<T> *aux=new Celda<T>;
	aux->sig=pos.punt->sig;
	pos.punt->sig=aux;
	pos.punt->sig->elemento=v;
}

template <class T>
void Lista<T>::Borrar(Posicion<T> p){
	assert(p.punt->sig!=0);
	Celda<T> *aux=p.punt->sig;
	p.punt->sig=aux->sig;
	delete aux;
}

template <class T>
Posicion<T> Lista<T>::begin()const{
	Posicion<T> p;
	p.primera=cab;
	p.punt=cab;
	return p;
}

template <class T>
Posicion<T> Lista<T>::end()const{
	Posicion<T> p;
	Celda<T> *aux=cab;
	while(aux->sig!=0){
		aux=aux->sig;
	}
	p.punt=aux;
	p.primera=cab;
	return p;
}

template <class T>
T Lista<T>::Get(Posicion<T> p)const{
	return p.punt->sig->elemento;
}

template <class T>
void Lista<T>::Set(Posicion<T> p,const T& v){
	p.punt->sig->elemento=v;
}
