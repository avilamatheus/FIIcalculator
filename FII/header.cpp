#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

float PorcAumento(int cotas, int icotas)
{
    float dif = cotas-icotas;
    float divisao = dif/icotas;
    float aumento = divisao*100;
    return aumento;
}
void Calc(int cotas, float money, float cotacao, float div, int meses, float aporte, bool op, float porcentagem)
{
    float rendtot = 0, bank = 0;
    int icotas = cotas;
    for(int i = 1; i < meses; i++)
        {
            if(op) cout << "Saldo no inicio do mes " << i << " (pre rendimentos): " << money << " reais " << endl;
            float rendimentos = cotas*div;
            rendtot = rendtot + rendimentos;
            if(op) cout << "no mes " << i << " voce recebera em rendimentos " << cotas << "*" << div << " = " << rendimentos << " reais do mes " << i-1 << endl;
            if(porcentagem < 1)
            {
                if(op) cout << "Saldo no dia 15 do mes (no recebimento de rendimentos), levando em conta a % de reinvestimento escolhida (" << porcentagem*100 << "% de "<< rendimentos << " reais) : ";
                if(op) cout << money << " + " << rendimentos*porcentagem << " = " << money+(rendimentos*porcentagem) << " reais " << endl;
                bank = bank + ((1-porcentagem)*rendimentos);
            }
            else
            {
                if(op) cout << "Saldo no dia 15 do mes (no recebimento de rendimentos): " << money << " + " << rendimentos << " = " << money+rendimentos << " reais " << endl;
            }
            money=money+(rendimentos*porcentagem);
            if(aporte > 0)
            {
                if(op) cout << "Somando este saldo ao seu aporte, teremos: " << money << " + " << aporte << " = " << money+aporte << " reais" << endl;
                money=money+aporte;
            }
            int newcotas = ((money)/cotacao);
            if(newcotas>=1)
            {
                money = money-(newcotas*cotacao);
                if(op) cout << "com isso voce compra " << newcotas << " cotas e sobram " << money << " reais, que serao guardados para reinvistir" << endl;
            }
            else
            {
                if(op) cout << "com esses " << money << " reais nao da para comprar cotas, porem esse dinheiro sera guardado para reinvistir" << endl;
            }
            cotas = cotas + newcotas;
            if(op) cout << "assim, seu numero total de cotas esta em " << cotas << endl;
            if(op) cout << endl;
        }
        cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "ao fim dos " << meses-1 << " meses (" << (meses-1)/12 << " ano(s)), voce tera " << cotas << " cotas, ";
        cout << "isso representa um aumento de " << PorcAumento(cotas, icotas) << "% em relacao ao numero inicial" << endl;
        cout << "esse numero de cotas rendera " << cotas*div << " reais por mes, considerando o dividendo de " << div << " reais informado inicialmente " << endl; 
        if(aporte > 0)
        {
            float accaporte = aporte*(meses-1);
            cout << "O total aportado foi: " << accaporte << " reais" << endl;
        }
        cout << "o valor total de dividendos recebidos nesse periodo foi de " << rendtot << " reais" << endl;
        if(bank) cout << "O valor nao reinvestido (devido a porcentagem informada) foi de " << bank << " reais" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl; 
        cout << endl;

}
