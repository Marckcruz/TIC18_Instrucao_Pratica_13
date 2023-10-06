#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPREGADOS = 50;

struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    double salario;
};

void Reajusta_dez_porcento(Empregado vetor[], int quantidade) {
    for (int i = 0; i < quantidade; ++i) {
        vetor[i].salario *= 1.10; // Aumento de 10%
    }
}

int main() {
    Empregado empregados[MAX_EMPREGADOS];

    empregados[0] = {"João", "Silva", 1980, "1234567", 2010, 3000.0};
    empregados[1] = {"Maria", "Santos", 1990, "9876543", 2015, 3500.0};
    empregados[2] = {"Carlos", "Ferreira", 1985, "5678912", 2005, 2800.0};

    int quantidadeEmpregados = 3;

    Reajusta_dez_porcento(empregados, quantidadeEmpregados);

    cout << "Salários reajustados em 10%:" << endl;
    for (int i = 0; i < quantidadeEmpregados; ++i) {
        cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$ " << empregados[i].salario << endl;
        
    }
    cout << "" << endl;
    return 0;
}
