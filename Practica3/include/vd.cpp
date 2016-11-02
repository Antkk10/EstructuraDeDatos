
template <class T>
void VD<T>::Resize(int nuevo_tam){
	T* aux = new T[nuevo_tam];
	int minimo=(this->n < nuevo_tam)?n:nuevo_tam;
	for(int i=0;i<minimo;i++)
		aux[i]=datos[i];
	this->reservados=nuevo_tam;
	delete[] this->datos;
	this->datos=aux;
	this->n=minimo;
}

template <class T>
VD<T>::VD(int n){
	if(n==0){
		this->reservados=0;
		this->n=0;
		this->datos = new T[this->reservados];
	}
	else{
		this->reservados=n;
		this->n=0;
		this->datos = new T[reservados];
	}
}

template <class T>
VD<T>::VD(const VD<T>& original){
	this->reservados = original.reservados;
	this->n=original.n;
	if(this->reservados==0)
		this->datos=0;
	else{
		this->datos = new T[this->reservados];
		for(int i=0;i < this->n;i++)
			this->datos[i]=original.datos[i];
	}
}

template <class T>
VD<T>& VD<T>::operator=(const VD<T>&original){
	if(this!=&original){
		if(datos!=0)
			delete[] datos;
		this->reservados=original.reservados;
		this->n=original.n;
		if(this->reservados==0)
			this->datos=0;
		else{
			this->datos= new T[this->reservados];
			for(int i=0;i < this->n;i++)
				this->datos[i]=original.datos[i];
		}
	}
	return *this;
}

template <class T>
VD<T>::~VD(){
	if(this->datos!=0)
		delete[] this->datos;
}

template <class T>
void VD<T>::Insertar(const T& dato, int pos){
	if(this->n >= (this->reservados/2))
		Resize(this->reservados * 2);
	for(int i= this->n;i > pos;i--)
		datos[i]=datos[i-1];
	this->datos[pos]=dato;
	this->n++;
}

template <class T>
void VD<T>::Borrar(int pos){
	for(int i=pos;i < this->n - 1;i++)
		this->datos[i]=this->datos[i+1];
	this->n--;
	if(this->n < this->reservados/4)
		Resize(this->reservados/2);
}