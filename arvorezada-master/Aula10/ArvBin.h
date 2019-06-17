























































































































#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"

class ArvBin
{
  public:
    ArvBin();
    ~ArvBin();
    int getRaiz();
    void cria(int x, ArvBin *sae, ArvBin *sad);
    void anulaRaiz();
    bool vazia(); // verifica se a árvore está vazia
    bool busca(int x);
    void preOrdem();
    void montaArvore();
    void insere(int x);
    int contanos();
    int contanosfolha();
    int auxcontanosfolha(NoArv *p);
    int altura();
    int auxaltura(NoArv*p);
    int contaimp();
    int auxcontaimp(NoArv*p);
    int contaFolhaImpar();
    int auxcontaFolhaImpar(NoArv *p);
    void imprimeNivel(int k);
    void auximprimeNivel(int k, NoArv*p);
    float mediaNivel(int k);
    float auxmedianivel(int k, NoArv*p);
    int max();
    int auxmax(NoArv*p);
  private:
    NoArv *raiz; // ponteiro para o No raiz da árvore

    NoArv* libera(NoArv *p);
    bool auxBusca(NoArv *p, int x);
    void auxPreOrdem(NoArv *p);
    NoArv* auxMontaArvore();
    void auxImpNivel(NoArv *p, int atual, int k);
    void auxInverte(NoArv * p);
    NoArv* auxInsere(NoArv *p, int x);
    int auxcontanos(NoArv*p);
};

#endif // ARVBIN_H_INCLUDED
