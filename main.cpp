#include <bits/stdc++.h>
using namespace std;
struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};
Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}
void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
    if(arbol == NULL){//si el arbol esta vacio
        Nodo *nuevo_nodo = crearNodo(n, padre);//se crera un nuevo nodo
        arbol = nuevo_nodo;//almacenarlo en la raiz del arbol
    }else if(n == 0){//si el numero a insertar es igual a cero
        //se genera el arbol con puros ceros de acuerdo al nivel
        insertarNodo(arbol->izq, n, arbol);
        insertarNodo(arbol->der, n, arbol);
    }else{//si el arbol tiene un nodo o mas de un nodo
        int valorRaiz = arbol->dato;//obtenemos el valor de la raiz
        if(n < valorRaiz){//se manda al lado izquierdo
            insertarNodo(arbol->izq, n, arbol);
        }else{//si es mayor se inserta en el lado derecho
            insertarNodo(arbol->der, n, arbol);
        }
    }
}

//prootipos
Nodo *crearNodo(int, Nodo*);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *&, int);
bool busqueda(Nodo *, int);
void sumarNodo(Nodo *&, int);

//recorridos
void preOrden(Nodo *&);
void enOrden(Nodo *&);
void postOrden(Nodo *&);

Nodo *arbol = NULL;
int main(){
    /*  1 -> AGUILA
        0 -> SOL
    */
   int dato, opcion, contador=0;
    int niveles = 3; //niveles del arbol
    int tiros[niveles];
    srand(time(NULL));
    int c;
    int num;

    do{
        cout << "MENU" << endl;
        cout << "1.- generar arbol" << endl;
        cout << "2.- mostrar arbol" << endl;
        cout << "3.- generrar e insertar tiros en el arbol" << endl;
        cout << "4.- " << endl;
        cout << "5.- Recorridos" << endl;
        cout << "6.- Salir" << endl;
        cout << "inserte opcion:  ";
        cin >> opcion;
        switch(opcion){
            case 1:
                int num, c;
                cout << "inserte el total de niveles (tiros): ";
                cin >> niveles;
                //se genera el arbol con ceros, se llama la funcion el numero de veces
                // al que se eligio el tiro
                for(c = 0; c <= niveles; c++){
                    insertarNodo(arbol, 0, NULL);//insertamo como dato cero
                }
                cout << endl;
                system("cls");
                break;
            case 2:
                mostrarArbol(arbol, contador);
                system("pause");
                break;
            case 3:
                cout << "gerando tiros e insertando ene l arbol" << endl;
                for(int i=0; i<100; i++){
                    for(int j=0; j<niveles; j++){
                    num=( 0 + rand() % (2 - 0));
                        cout << " " << num ;//<< tiros[j];
                        sumarNodo(arbol, num);
                    }

                    cout << endl;
                }
                cout << "\n";
                system("pause");
                break;
            case 4:

                system("pause");
                break;
            case 5:
                cout << "Recorridos " << endl;
                cout << "\n\n En orden   :  ";   enOrden(arbol);
                cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
                cout << "\n\n Post Orden :  ";   postOrden(arbol);
                cout << endl << endl;
                system("pause");
                break;
            case 6:
                break;
            default:
                continue;
        }//fin de switch
        system("cls");
    }while(opcion != 6);
    //generar el arbol

    cin.get();
	return 0;
}//funcion pra crear un nuevo nodo


void mostrarArbol(Nodo *&arbol, int cont){
    if(arbol==NULL){
        return;
    }else{
        mostrarArbol(arbol->der, cont+1);
        for(int i=0; i<cont; i++){
            cout << "   ";
        }
        cout<< arbol->dato <<endl;
            mostrarArbol(arbol->izq, cont+1);
    }
}

bool busqueda(Nodo *arbol, int n){
    if(arbol == NULL){
        return false;
    }else if(arbol->dato == n){
        return true;
    }else if(n < arbol->dato){
        return busqueda(arbol->izq, n);
    }else{
        return busqueda(arbol->der, n);
    }
}

void preOrden(Nodo *&arbol){
  if(arbol!=NULL){
    cout << arbol->dato <<" ";
    preOrden(arbol->izq);
    preOrden(arbol->der);
  }
}
void enOrden(Nodo *&arbol){
  if(arbol!=NULL){
    enOrden(arbol->izq);
    cout << arbol->dato << " ";
    enOrden(arbol->der);
  }
}
void postOrden(Nodo *&arbol){
  if(arbol!=NULL){
    postOrden(arbol->izq);
    postOrden(arbol->der);
    cout << arbol->dato << " ";
  }
}



void sumarNodo(Nodo *&arbol, int n){
    if(arbol == NULL || arbol->izq == NULL || arbol->der == NULL){//si el arbol esta vacio
        return;
    }else{//si el arbol tiene un nodo o mas de un nodo
        int valorRaiz = arbol->dato;//obtenemos el valor de la raiz
        if(n < valorRaiz){//se manda al lado izquierdo
            sumarNodo(arbol->izq, n);
            valorRaiz = valorRaiz + n;
        arbol->dato = valorRaiz;
        }else if (n > valorRaiz){//si es mayor se inserta en el lado derecho
            sumarNodo(arbol->der, n);
            valorRaiz = valorRaiz + n;
        arbol->dato = valorRaiz;
        }
        valorRaiz = valorRaiz + n;
        arbol->dato = valorRaiz;
    }
}
