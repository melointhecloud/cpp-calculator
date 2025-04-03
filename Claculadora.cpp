#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <locale>

using namespace std;

struct Calculo
{
    double numero1;
    double numero2;
    char operador;
    double resultado;
    string descricao;
};

double calcularPotencia(double base, double expoente)
{
    return pow(base, expoente);
}

double calcularRaizQuadrada(double numero)
{
    if (numero < 0)
    {
        throw "Erro: Não é possível calcular raiz quadrada de número negativo!";
    }
    return sqrt(numero);
}

double calcularPorcentagem(double numero, double percentual)
{
    return (numero * percentual) / 100;
}

void mostrarMenu()
{
    cout << "\n=== Calculadora Avançada ===" << endl;
    cout << "1. Operações básicas (+, -, *, /)" << endl;
    cout << "2. Potenciação" << endl;
    cout << "3. Raiz Quadrada" << endl;
    cout << "4. Porcentagem" << endl;
    cout << "5. Ver histórico" << endl;
    cout << "6. Limpar histórico" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opção: ";
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    vector<Calculo> historico;
    int opcao;

    do
    {
        mostrarMenu();
        cin >> opcao;

        try
        {
            Calculo calc;

            switch (opcao)
            {
            case 1: {
                cout << "Digite o primeiro número: ";
                cin >> calc.numero1;

                cout << "Digite o operador (+, -, *, /): ";
                cin >> calc.operador;

                cout << "Digite o segundo número: ";
                cin >> calc.numero2;

                switch (calc.operador)
                {
                case '+':
                    calc.resultado = calc.numero1 + calc.numero2;
                    calc.descricao = "Adição";
                    break;
                case '-':
                    calc.resultado = calc.numero1 - calc.numero2;
                    calc.descricao = "Subtração";
                    break;
                case '*':
                    calc.resultado = calc.numero1 * calc.numero2;
                    calc.descricao = "Multiplicação";
                    break;
                case '/':
                    if (calc.numero2 == 0) throw "Erro: Divisão por zero não é permitida!";
                    calc.resultado = calc.numero1 / calc.numero2;
                    calc.descricao = "Divisão";
                    break;
                default:
                    throw "Operador inválido!";
                }
                historico.push_back(calc);
                cout << "Resultado: " << fixed << setprecision(2) << calc.resultado << endl;
                break;
            }

            case 2: {
                cout << "Digite a base: ";
                cin >> calc.numero1;
                cout << "Digite o expoente: ";
                cin >> calc.numero2;

                calc.resultado = calcularPotencia(calc.numero1, calc.numero2);
                calc.operador = '^';
                calc.descricao = "Potenciação";
                historico.push_back(calc);
                cout << "Resultado: " << fixed << setprecision(2) << calc.resultado << endl;
                break;
            }

            case 3: {
                cout << "Digite o número: ";
                cin >> calc.numero1;

                calc.resultado = calcularRaizQuadrada(calc.numero1);
                calc.numero2 = 0;
                calc.operador = '√';
                calc.descricao = "Raiz Quadrada";
                historico.push_back(calc);
                cout << "Resultado: " << fixed << setprecision(2) << calc.resultado << endl;
                break;
            }

            case 4: {
                cout << "Digite o número: ";
                cin >> calc.numero1;
                cout << "Digite a porcentagem: ";
                cin >> calc.numero2;

                calc.resultado = calcularPorcentagem(calc.numero1, calc.numero2);
                calc.operador = '%';
                calc.descricao = "Porcentagem";
                historico.push_back(calc);
                cout << calc.numero2 << "% de " << calc.numero1 << " = "
                    << fixed << setprecision(2) << calc.resultado << endl;
                break;
            }

            case 5: {
                if (historico.empty())
                {
                    cout << "Histórico vazio!" << endl;
                }
                else
                {
                    cout << "\n=== Histórico de Operações ===" << endl;
                    for (size_t i = 0; i < historico.size(); i++)
                    {
                        cout << i + 1 << ". " << historico[i].descricao << ": ";
                        if (historico[i].operador == '√')
                        {
                            cout << "√" << historico[i].numero1;
                        }
                        else if (historico[i].operador == '%')
                        {
                            cout << historico[i].numero2 << "% de " << historico[i].numero1;
                        }
                        else
                        {
                            cout << historico[i].numero1 << " " << historico[i].operador
                                << " " << historico[i].numero2;
                        }
                        cout << " = " << fixed << setprecision(2) << historico[i].resultado << endl;
                    }
                }
                break;
            }

            case 6: {
                historico.clear();
                cout << "Histórico limpo com sucesso!" << endl;
                break;
            }

            case 0:
                cout << "Encerrando o programa... Obrigado por usar!" << endl;
                break;

            default:
                cout << "Opção inválida! Por favor, escolha uma opção válida." << endl;
            }
        }
        catch (const char* erro)
        {
            cout << erro << endl;
        }
        catch (...)
        {
            cout << "Ocorreu um erro inesperado! Tente novamente." << endl;
        }

    } while (opcao != 0);

    return 0;
}