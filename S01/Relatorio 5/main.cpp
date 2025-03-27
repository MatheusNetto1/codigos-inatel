#include <iostream>
#include <string>

using namespace std;

class Pessoa {
public:
  Pessoa(int idade, string nome) {
    this->idade = idade;
    this->nome = nome;
  }

  int getIdade() {
    return this->idade;
  }

  string getNome() {
    return this->nome;
  }

  void imprimeNome() {
    cout << "O nome é: " << getNome() << endl;
  }

  virtual void imprimeIdade() {
    cout << "A pessoa tem " << getIdade() << " anos." << endl;
  }

private:
  int idade;
  string nome;
};

class Professor : public Pessoa {
public:
  Professor(int idade, string nome) : Pessoa(idade, nome) {}

  void imprimeIdade() override {
    cout << "O professor tem " << getIdade() << " anos." << endl;
  }
};

class Aluno : public Pessoa {
public:
  Aluno(int idade, string nome, int matricula) : Pessoa(idade, nome) {
    this->matricula = matricula;
  }

  int getMatricula() {
    return this->matricula;
  }

  void imprimeIdade() override {
    cout << "O aluno tem " << getIdade() << " anos." << endl;
  }

  void imprimeMatricula() {
    cout << "A matricula do aluno é: " << getMatricula() << endl;
  }

private:
  int matricula;
};

int main() {
  Pessoa pessoa(25, "pessoa1");
  Professor professor(35, "professor1");
  Aluno aluno(20, "aluno1", 299);

  cout << "---- Pessoa ----" << endl;
  pessoa.imprimeNome();
  pessoa.imprimeIdade();

  cout << "---- Professor ----" << endl;
  professor.imprimeNome();
  professor.imprimeIdade();

  cout << "---- Aluno ----" << endl;
  aluno.imprimeNome();
  aluno.imprimeIdade();
  aluno.imprimeMatricula();

  return 0;
}