#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;


struct Passagem {
    int numAssento;
    string dataHora;
    string cpf;
    string nome;
    int idade;
};

struct Viagem {
    string origem;
    string destino;
    string horario;
    vector<Passagem> passagens;
};

double calcularTotalArrecadado(const Viagem& viagem) {
    return viagem.passagens.size() * 80.0;
}

double calcularTotalArrecadadoNoMes(const vector<Viagem>& viagens, int mes) {
    double total = 0.0;
    for (const Viagem& viagem : viagens) {

        struct tm tm;
        strptime(viagem.horario.c_str(), "%d/%m/%Y %H:%M", &tm);
        if (tm.tm_mon + 1 == mes) {
            total += calcularTotalArrecadado(viagem);
        }
    }
    return total;
}

string obterNomeDoPassageiro(const Viagem& viagem, int numAssento) {
    for (const Passagem& passagem : viagem.passagens) {
        if (passagem.numAssento == numAssento) {
            return passagem.nome;
        }
    }
    return "Poltrona vazia";
}

string encontrarHorarioMaisRentavel(const vector<Viagem>& viagens) {
    double maxArrecadacao = 0.0;
    string horarioMaisRentavel = "";

    for (const Viagem& viagem : viagens) {
        double arrecadacao = calcularTotalArrecadado(viagem);
        if (arrecadacao > maxArrecadacao) {
            maxArrecadacao = arrecadacao;
            horarioMaisRentavel = viagem.horario;
        }
    }
    return horarioMaisRentavel;
}

double calcularMediaIdadeDosPassageiros(const Viagem& viagem) {
    if (viagem.passagens.empty()) {
        return 0.0; 
    }

    int somaIdades = 0;
    for (const Passagem& passagem : viagem.passagens) {
        somaIdades += passagem.idade;
    }
    return static_cast<double>(somaIdades) / viagem.passagens.size();
}

int main() {
    vector<Viagem> viagens;

    Viagem viagem1 = {"Rio de Janeiro", "São Paulo", "10/10/2023 08:00", {}};
    viagem1.passagens.push_back({1, "10/10/2023 08:30", "12345678901", "João", 30});
    viagem1.passagens.push_back({2, "10/10/2023 08:35", "98765432109", "Maria", 25});
    viagens.push_back(viagem1);

    Viagem viagem2 = {"São Paulo", "Rio de Janeiro", "10/10/2023 14:00", {}};
    viagem2.passagens.push_back({10, "10/10/2023 14:30", "56789012345", "Pedro", 40});
    viagem2.passagens.push_back({11, "10/10/2023 14:35", "34567890123", "Ana", 35});
    viagens.push_back(viagem2);

    double totalViagem1 = calcularTotalArrecadado(viagem1);
    cout << "1. Total arrecadado para uma determanda viagem: R$ " << totalViagem1 << endl;

    double totalMes10 = calcularTotalArrecadadoNoMes(viagens, 10);
    cout << "2. Total arrecadado em determdado mês: R$ " << totalMes10 << endl;

    int poltronaDesejada = 2;
    string nomePassageiro = obterNomeDoPassageiro(viagem1, poltronaDesejada);
    cout << "3. Nome do passageiro de uma determanda poltrona P de uma determinada viagem. " << poltronaDesejada << ": " << nomePassageiro << endl;

    string horarioRentavel = encontrarHorarioMaisRentavel(viagens);
    cout << "4. Horário de viagem mais rentável: " << horarioRentavel << endl;

    double mediaIdadeViagem1 = calcularMediaIdadeDosPassageiros(viagem1);
    cout << "5. Média de idade dos passageiros: " << mediaIdadeViagem1 << " anos" << endl;
    
    cout << "" << endl;

    return 0;
}
