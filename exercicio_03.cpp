#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int MAX_PRODUTOS = 300;

struct Produto {
    string codigo;
    string nome;
    double preco;
};

vector<Produto> produtos;

bool InserirProduto(const string& codigo, const string& nome, double preco) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo || produto.nome == nome) {
            cout << "Produto com o mesmo código ou nome já cadastrado." << endl;
            return false;
        }
    }

    if (produtos.size() >= MAX_PRODUTOS) {
        cout << "Limite máximo de produtos cadastrados atingido." << endl;
        return false;
    }

    produtos.push_back({codigo, nome, preco});
    cout << "Produto cadastrado com sucesso." << endl;
    return true;
}

bool ExcluirProduto(const string& codigo) {
    for (auto it = produtos.begin(); it != produtos.end(); ++it) {
        if (it->codigo == codigo) {
            produtos.erase(it);
            cout << "Produto excluído com sucesso." << endl;
            return true;
        }
    }

    cout << "Produto com código " << codigo << " não encontrado." << endl;
    return false;
}

void ListarProdutos() {
    cout << "Lista de produtos:" << endl;
    for (const Produto& produto : produtos) {
        cout << "Código: " << produto.codigo << ", Nome: " << produto.nome << ", Preço: R$ " << fixed << setprecision(2) << produto.preco << endl;
    }
}

void ConsultarPreco(const string& codigo) {
    for (const Produto& produto : produtos) {
        if (produto.codigo == codigo) {
            cout << "Preço de " << produto.nome << ": R$ " << fixed << setprecision(2) << produto.preco << endl;
            return;
        }
    }

    cout << "Produto com código " << codigo << " não encontrado." << endl;
}

int main() {
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Inserir um novo produto" << endl;
        cout << "2. Excluir um produto cadastrado" << endl;
        cout << "3. Listar todos os produtos" << endl;
        cout << "4. Consultar o preço de um produto por código" << endl;
        cout << "0. Sair" << endl;

        int escolha;
        cin >> escolha;

        switch (escolha) {
            case 1: {
                string codigo, nome;
                double preco;
                cout << "Informe o código do produto: ";
                cin >> codigo;
                cout << "Informe o nome do produto: ";
                cin >> nome;
                cout << "Informe o preço do produto: ";
                cin >> preco;
                InserirProduto(codigo, nome, preco);
                break;
            }
            case 2: {
                string codigo;
                cout << "Informe o código do produto a ser excluído: ";
                cin >> codigo;
                ExcluirProduto(codigo);
                break;
            }
            case 3: {
                ListarProdutos();
                break;
            }
            case 4: {
                string codigo;
                cout << "Informe o código do produto para consultar o preço: ";
                cin >> codigo;
                ConsultarPreco(codigo);
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "Escolha inválida. Tente novamente." << endl;
            }
        }
    }

    return 0;
}
