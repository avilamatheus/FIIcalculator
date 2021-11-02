#include "header.cpp"

int main()
{
    cout << endl;
    string fii = "";
    while(fii == "")
    {
        cout << "Insira o nome do FII: ";
        cin >> fii;
    }
    string sdiv;
    float div = 0;
    while(div == 0)
    {
        cout << "Insira a media dos dividentos nos ultimos meses: ";
        cin >> sdiv;
        replace( sdiv.begin(), sdiv.end(), ',', '.');
        div = stof(sdiv);
        if(div < 0)
        {
            cout << "dividendos negativos? pessima escolha de ativo :P, numero invalido" << endl;
            div = 0;
            continue;
        }
        if(div == 0)
        {
            cout << "dividendos zerados? pessima escolha de ativo :P, numero invalido" << endl;
            div = 0;
        }
    }
    float cotacao = 0;
    string scot;
    while(cotacao == 0)
    {
        cout << "Insira a cotacao do FII " << fii << ": ";
        cin >> scot;
        replace( scot.begin(), scot.end(), ',', '.');
        cotacao = stof(scot);
        if(cotacao < 0)
        {
            cout << "cotacao negativa? wtf :P, insira um numero valido" << endl;
            cotacao = 0;
            continue;
        }
        if(cotacao == 0)
        {
            cout << "cotacao zerada? wtf :P, insira um numero valido" << endl;
            cotacao = 0;
        }

    }
    float money = 0;
    string smon;
    while(money == 0)
    {
        cout << "Insira o investimento inicial: ";
        cin >> smon;
        replace( smon.begin(), smon.end(), ',', '.');
        money = stof(smon);
        if(money < cotacao)
        {
            cout << "Seu investimento inicial nao pode ser menor que a cotacao do FII, insira um numero valido" << endl;
            money = 0;
            continue;
        }
        if(money <= 0)
        {
            cout << "ERRO: insira um numero valido" << endl;
            money = 0;
        }
    }
    int cotas = money/cotacao;
    float rendimentos = cotas*div;
    int anos = 0;
    while(anos==0)
    {
        cout << "Quer simular quantos anos a partir do mes 0 (mes do primeiro investimento)? ";
        cin >> anos;
        if(anos<=0)
        {
            cout << "ERRO: insira um numero valido" << endl;
            anos = 0;
        }
    }
    int meses = 12*anos;
    meses++;
    bool ap = false;
    float aporte = 0;
    while(!ap)
    {
        cout << "Qual o valor do aporte mensal? ";
        cin >> aporte;
        if(aporte<0)
        {
            cout << "ERRO: insira um numero valido" << endl;
            ap = false;
        }
        else
        {
            ap = true;
        }
    }
    float porcentagem = 0;
    bool porc = false;
    while (!porc)
    {
        cout << "Quantos % do valor recebido mensalmente pelos dividendos sera reinvistido? ";
        cin >> porcentagem;
        if(porcentagem<0)
        {
            cout << "ERRO: insira um numero valido" << endl;
            porc = false;
        }
        else
        {
            porc = true;
        }
    }
    porcentagem = porcentagem/100;
    bool op = false;
    int c = 0;
    while (c==0)
    {
        cout << "Deseja ver o calculo mes a mes? 0 = NAO, 1 = SIM: ";
        cin >> c;
        if (c == 0)
        {
            break;
        }
        else if (c == 1)
        {
            op = true;
        }
        else
        {
            cout << "ERRO: insira um numero valido" << endl;
            c = 0;
            op = false;
        }
    }
    cout << endl;
    cout << "------------------------------------------ CONFIRMANDO INFORMACOES ------------------------------------------" << endl;
    cout << "O FII da simulacao se chama: " << fii << endl;
    cout << fixed << setprecision(2) << "Sua media de dividendos por cota eh de " << div << " reais" << endl;
    cout << fixed << setprecision(2) << "E sua cotacao eh: " << cotacao << " reais" << endl;
    cout << fixed << setprecision(2) << "Com seu investimento inicial de " << money << " reais voce consegue comprar " << cotas << " cotas" << endl;
    money=money-(cotas*cotacao);
    if(money) cout << fixed << setprecision(2) << "Desse investimento sobram " << money << " reais, que serao guardados para reinvestir" << endl;
    if(!money) cout << fixed << setprecision(2) << "Desse investimento nao sobra dinheiro (todo investimento inicial foi convertido em cotas)" << endl;
    if(aporte) cout << fixed << setprecision(2) << "Seu aporte mensal sera de: " << aporte << " reais" << endl;
    if(!aporte) cout << "Voce optou por nao realizar aportes mensais" << endl;
    if(op) cout << "Voce optou por demonstrar o calculo mes a mes" << endl;
    if(!op) cout << "Voce optou por nao demonstrar o calculo mes a mes" << endl;
    cout << "A porcentagem de reinvestimento dos dividendos informada foi de " << porcentagem*100 << "%" << endl;
    cout << "A simulacao levara em conta " << anos << " ano(s) (" << meses-1 << " meses)" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    Calc(cotas, money, cotacao, div, meses, aporte, op, porcentagem);
    return 0;
}