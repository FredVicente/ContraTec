#pragma once

#include <iostream>

namespace Listas {
    template <class TL>
    class Lista {
    private:
        /* template Elemento to use as Elemento of the Lista */
        template <class TE>
        class Elemento {
        private:
            Elemento<TE>* pProximo;
            TE* pInfo;

        public:
            Elemento() {
                pProximo = nullptr;
                pInfo = nullptr;
            }
            ~Elemento() {
                pProximo = nullptr;
                pInfo = nullptr;
            }
            /* Set Proximo template Elemento - internal Lista use */
            void setProximo(Elemento<TE>* pProximo) { this->pProximo = pProximo; }
            /* Get Proximo Elemento of the Lista */
            Elemento<TE>* getProximo() { return pProximo; }
            /* Sets the pointer the template Elemento points to*/
            void setInfo(TE* pInfo) { this->pInfo = pInfo; }
            /* Returns the pointer the template Elemento points to. */
            TE* getInfo() { return pInfo; }
        };

    private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
        int tamanho;

    public:
        Lista();
        ~Lista();

        void clear();
        int getTamanho() { return tamanho; }
        TL* operator[](int x);
        void adicionar(TL* pInfo);
        TL* remover(TL* pInfo);
        TL* remover(int index);

    private:
        void setElemento(Elemento<TL>* pElemento);
        Elemento<TL>* getpPrimeiro() { return pPrimeiro; }
        Elemento<TL>* getpUltimo() { return pUltimo; }
    };

    template <class TL>
    Lista<TL>::Lista() :
        pPrimeiro(nullptr),
        pUltimo(nullptr),
        tamanho(0) { }

    template <class TL>
    Lista<TL>::~Lista() { }

    /* Delete the whole Lista */
    template <class TL>
    void Lista<TL>::clear() {
        Elemento<TL>* paux1;
        Elemento<TL>* paux2;

        paux1 = pPrimeiro;
        paux2 = paux1;
        int i = 0;

        while (paux1 != nullptr && i < tamanho) {
            delete (paux1->getInfo());
            paux2 = paux1->getProximo();
            delete (paux1);
            paux1 = paux2;
            i++;
        }

        pPrimeiro = nullptr;
        pUltimo = nullptr;
        tamanho = 0;
    }

    template <class TL>
    TL* Lista<TL>::operator[](int index) {
        if (index >= tamanho || index < 0) {
            std::cout << "ERROR: Segmentation fault on template list. Exceeded boundaries. Index " << index << " out of " << tamanho << " elements." << std::endl;
            exit(1);
        }

        Elemento<TL>* pAux = pPrimeiro;
        for (int i = 0; i < index; i++) {
            pAux = pAux->getProximo();
        }

        if (pAux == nullptr) {
            std::cout << "ERROR: on template operator[] pAux == nullptr." << std::endl;
            exit(1);
        }
        return pAux->getInfo();
    }

    /* Add new Elemento to Lista - internal use */
    template <class TL>
    void Lista<TL>::setElemento(Elemento<TL>* pElemento) {
        if (pElemento != nullptr) {
            if (pPrimeiro == nullptr) {
                pPrimeiro = pElemento;
                pUltimo = pElemento;
            }
            else {
                pUltimo->setProximo(pElemento);
                pUltimo = pElemento;
            }
            tamanho++;

        }
        else {
            std::cout << "ERROR: on Lista<TL>::setElemento -> Pointer pElemento == nullptr. Insert not succeeded." << std::endl;
        }
    }

    /* adicionar new Elemento to the template Lista */
    template <class TL>
    void Lista<TL>::adicionar(TL* pInfo) {
        if (pInfo != nullptr) {
            Elemento<TL>* pElemento = nullptr;
            pElemento = new Elemento<TL>();
            pElemento->setInfo(pInfo);
            setElemento(pElemento);
        }

        else {
            std::cout << "ERROR: on Lista<TL>::adicionar -> pInfo == nullptr" << std::endl;
        }
    }

    /* Remove a specific element fom Lista given by the information. Returns the element popped from Lista.*/
    template <class TL>
    TL* Lista<TL>::remover(TL* pInfo) {
        Elemento<TL>* pAux = pPrimeiro;
        if (pAux->getInfo() == pInfo) {
             pPrimeiro = pAux->getProximo();
             delete (pAux);
             tamanho--;
             return pInfo;
        }
        
        while (pAux->getProximo() != nullptr){
            if(pAux->getProximo()->getInfo() == pInfo)
            {
                Elemento<TL>* pAux2 = nullptr;
                if (pAux->getProximo() == pUltimo)
                    pUltimo = pAux;
                else
                    pAux2 = pAux->getProximo()->getProximo();

                delete (pAux->getProximo());
                tamanho--;
                if(pAux2)
                    pAux->setProximo(pAux2);
                return pInfo;
            }

            pAux = pAux->getProximo();
        }
        
        return nullptr;
    }

    /* Remove a specific element fom Lista given by its index. Returns the element popped from Lista.*/
    template <class TL>
    TL* Lista<TL>::remover(int index) {
        if (index >= tamanho || index < 0) {
            std::cout << "ERROR: Segmentation fault on Lista<TL>::pop(int index). Exceeded boundaries. Index " << index << " out of " << tamanho << " elements." << std::endl;
            exit(1);
        }

        Elemento<TL>* pAux = pPrimeiro;
        TL* pInfo = pAux->getInfo();

        if (index == 0) {
            pPrimeiro = pAux->getProximo();
            delete (pAux);
            tamanho--;
            
            return pInfo;
        }

        for (int i = 0; i < index-1; i++) {
            pAux = pAux->getProximo();
        }
        
        if (pAux->getProximo() == pUltimo) {
            pUltimo = pAux;
        }

        pInfo = pAux->getProximo()->getInfo();

        delete (pAux->getProximo());
        tamanho--;

        return pInfo;
    }
}