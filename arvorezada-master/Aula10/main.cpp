#include <iostream>
#include "ArvBin.h"
using namespace std;

int main()
{
    ArvBin arv;
    arv.montaArvore();
    arv.preOrdem();
    cout<<endl;
    cout<<"n nos:"<<arv.contanos()<<endl;
    cout<<"n folhas:"<<arv.contanosfolha()<<endl;
    cout<<"altura:"<<arv.altura()<<endl;
    cout<<"n imp:"<<arv.contaimp()<<endl;
    cout<<"n folhas imp:"<<arv.contaFolhaImpar()<<endl;
    arv.imprimeNivel(1);
    cout<<"media:"<<arv.mediaNivel(1)<<endl;
    cout<<"maior:"<<arv.max()<<endl;
    cout<<"mais a esquerda:"<<arv.maisaesquerda()<<endl;
    return 0;
}
