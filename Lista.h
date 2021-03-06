//Autor: Thiago Riquelmo Marques Nascimento

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED


#include <iostream>

using namespace std;

#define MAX_VALORES 100

class Lista{
public:
    int valores[MAX_VALORES];
    unsigned tamanho;
    bool trocou;


    Lista() {         
        tamanho=0;
    }
    ~Lista() {}

    void insere(int valor){
        //erro: nao tem mais espaco
        if (tamanho == MAX_VALORES){
            cout << "Sem espaço"<< endl;
            return;
        }

        else{
            valores[tamanho]=valor;
            tamanho++;
        }
        
    }

    void InsertionSort(bool imprimir, bool interacoes){
        int j, valor;
        int acessos = 0;

        for(int i = 1; i <= tamanho-1; i++){
            j = i-1;
            valor = valores[i];

            while((j >= 0) && (valor < valores[j])){
                valores[j+1] = valores[j];
                j--;
                acessos++;
            }
            valores[j+1] = valor;
            if(imprimir){
                imprime();
            } 
        }
        if(interacoes){
            cout<< "O numero de acessos foi de "<< acessos <<" vezes!"<<endl;
        }
    }

    void imprime(){
        cout << endl << "Do inicio ao fim" << endl;
        for(unsigned i = 0; i < tamanho; i++){
            cout<< "<" << valores[i] << "> ";
        } 
        cout<<"\n";
    }

};

#endif
