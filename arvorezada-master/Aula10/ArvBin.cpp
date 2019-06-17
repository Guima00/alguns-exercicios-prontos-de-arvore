#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvBin.h"
#include <math.h>

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if (raiz != NULL)
        return raiz->getInfo();
    else
    {
        cout << "Árvore vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int x, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(x);
    p->setEsq(sae->raiz);
    p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

void ArvBin::montaArvore()
{
    if(!vazia())
        cout << "Arvore jah montada. So eh possivel a insercao de nos." << endl;
    else
    {
        cout << "Montagem da arvore em pre-ordem:" << endl;
        raiz = auxMontaArvore();
    }
}

NoArv* ArvBin::auxMontaArvore()
{
    string linha;
    cout << "Valor: ";
    cin >> linha;
    if(linha != "NULL" && linha != "null")
    {
        istringstream ent(linha);
        int valor;
        ent >> valor;
        NoArv *p = new NoArv();
        p->setInfo(valor);
        cout << "Esquerda" << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita" << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }
    else
        return NULL;
}

void ArvBin::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvBin::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));
    }
    return p;
}

bool ArvBin::vazia()
{
    return (raiz == NULL);
}

bool ArvBin::busca(int x)
{
    return auxBusca(raiz, x);
}

bool ArvBin::auxBusca(NoArv *p, int x)
{
    if (p == NULL)
        return false;
    else if (p->getInfo() == x)
        return true;
    else if (auxBusca(p->getEsq(), x))
        return true;
    else
        return auxBusca(p->getDir(), x);
}

ArvBin::~ArvBin()
{
    raiz = libera(raiz);
}

NoArv* ArvBin::libera(NoArv *p)
{
    if (p != NULL)
    {
        p->setEsq(libera(p->getEsq()));
        p->setDir(libera(p->getDir()));
        delete p;
        p = NULL;
    }
    return NULL;
}

void ArvBin::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvBin::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}
int ArvBin::contanos()
{
    return auxcontanos(raiz);
}
int ArvBin::auxcontanos(NoArv*p)
{
    if(p!=NULL)
    {
        return 1 + auxcontanos(p->getEsq()) + auxcontanos(p->getDir());
    }
    else
    {
        return 0;
    }
}
int ArvBin::contanosfolha()
{
    return auxcontanosfolha(raiz);
}
int ArvBin::auxcontanosfolha(NoArv*p)
{
    if(p==NULL)
        return 0;
    if(p->getEsq()==NULL && p->getDir()==NULL)
    {
        return 1+auxcontanosfolha(p->getEsq())+auxcontanosfolha(p->getDir());
    }
    else
        return auxcontanosfolha(p->getEsq())+auxcontanosfolha(p->getDir());
}
int ArvBin::altura()
{
    return auxaltura(raiz);
}
int ArvBin::auxaltura(NoArv*p)
{
    int u, v;
    if (p == NULL)
    {
        return -1;
    }
    u = auxaltura(p->getEsq());
    v = auxaltura(p->getDir());
    if (u > v)
        return u+1;
    else
        return v+1;
}
int ArvBin::contaimp()
{
    return auxcontaimp(raiz);
}
int ArvBin::auxcontaimp(NoArv*p)
{
    if(p==NULL)
        return 0;
    if(p->getInfo()%2!=0)
    {
        return 1+auxcontaimp(p->getEsq())+auxcontaimp(p->getDir());
    }
    else
        return auxcontaimp(p->getEsq())+auxcontaimp(p->getDir());
}
int ArvBin::contaFolhaImpar()
{
    return auxcontaFolhaImpar(raiz);
}
int ArvBin::auxcontaFolhaImpar(NoArv *p)
{
    if(p==NULL)
        return 0;
    if(p->getEsq()==NULL && p->getDir()==NULL && p->getInfo()%2!=0)
    {
        return 1+auxcontaFolhaImpar(p->getEsq())+auxcontaFolhaImpar(p->getDir());
    }
    else
        return auxcontaFolhaImpar(p->getEsq())+auxcontaFolhaImpar(p->getDir());
}
void ArvBin::imprimeNivel(int k)
{
    auximprimeNivel(k,raiz);
}
void ArvBin::auximprimeNivel(int k,NoArv*p)
{
    if(p!=NULL)
    {
        if(k==0)
        {
            cout<<p->getInfo()<<" ";
        }
        auximprimeNivel(k-1,p->getEsq());
        auximprimeNivel(k-1,p->getDir());
    }
}
float ArvBin::mediaNivel(int k)
{
    return auxmedianivel(k,raiz);
}
float ArvBin::auxmedianivel(int k,NoArv*p)
{
    if(p==NULL)
        return 0;
    if(k==0)
    {
        return p->getInfo();
    }
    return (auxmedianivel(k-1,p->getEsq())+auxmedianivel(k-1,p->getDir()))/pow(2,k);
}
int ArvBin::max()
{
    return auxmax(raiz);

}
int ArvBin::auxmax(NoArv*p)
{
    int c=0;
    int d=0;
    if(p==NULL)
    {
        return 0;
    }
    c=auxmax(p->getEsq());
    d=auxmax(p->getDir());
    if(c>=d)
    {
        if(c>=p->getInfo())
        {
            return c;
        }
        else
            return p->getInfo();
    }
    else if(d>=p->getInfo())
    {
        return d;
    }
    else
        return p->getInfo();
}
void ArvBin::inverte()
{
    auxInverte(raiz);
}
void ArvBin::auxInverte(NoArv*p)
{
    int c=0;
    if(p==NULL);
    else if(p->getDir()!=NULL && p->getEsq()!=NULL)
    {
        c=p->getEsq()->getInfo();
        p->getEsq()->setInfo(p->getDir()->getInfo());
        p->getDir()->setInfo(c);
        cout<<p->getEsq()->getInfo()<<" ";
        cout<<p->getDir()->getInfo()<<" ";
        cout<<endl;
        auxInverte(p->getEsq());
        auxInverte(p->getDir());
    }
}
int ArvBin::maisaesquerda()
{
    return auxmaisaesquerda(raiz);
}
int ArvBin::auxmaisaesquerda(NoArv*p)
{
    if(p==NULL) return -1;

    if(p->getEsq()!=NULL)
    {
         return auxmaisaesquerda(p->getEsq());
    }
    else
    {
         return p->getInfo();
    }

}
