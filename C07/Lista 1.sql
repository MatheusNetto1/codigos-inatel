DROP DATABASE IF EXISTS aula3;
CREATE DATABASE aula3;
USE aula3;

#QUESTAO 1
/*

Uma chave primitiva é responsável por identificar exclusivamenmte cada registro em uma tabela de BD 

*/


#QUESTAO 2
CREATE TABLE IF NOT EXISTS pessoa(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45),
    endereco VARCHAR(45),
    cargo VARCHAR(45)
);

#RESPOSNDA A QUESTÂO 2 AQUI
INSERT INTO pessoa (nome, endereço, cargo) VALUES ("Matheus", "MG", "Estudante");
INSERT INTO pessoa (nome, endereço, cargo) VALUES ("Fulano", "SP", "Desempregado");
UPDATE pessoa SET nome = "Ciclano" WHERE id = '1';

SELECT nome FROM pessoa;

DELETE FROM pessoa WHERE id = '2';

INSERT INTO pessoa (nome, endereço, cargo) VALUES ("Beltrano", "RJ", "Pizzaiolo");
INSERT INTO pessoa (nome, endereço, cargo) VALUES ("Beltraninho", "RJ", "Garçom");
INSERT INTO pessoa (nome, endereço, cargo) VALUES ("Beltranão", "RJ", "Caixa");

#QUESTAO 3
CREATE TABLE IF NOT EXISTS empresa(
	matricula INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(45),
    cpf VARCHAR(45),
    cargo VARCHAR(45),
    nProjetos INT
);

#RESPOSNDA A QUESTÂO 3 AQUI

INSERT INTO pessoa (nome, cpf, cargo, nProjetos) VALUES ("Junior", "000.000.000-00", "GP", "2");
INSERT INTO pessoa (nome, cpf, cargo, nProjetos) VALUES ("Maria", "111.111.111-11", "Desenvolvedor", "3");
INSERT INTO pessoa (nome, cpf, cargo, nProjetos) VALUES ("Junior", "222.222.222-22", "Tester", "4");
INSERT INTO pessoa (nome, cpf, cargo, nProjetos) VALUES ("Junior", "333.333.333-33", "Desenvolvedor", "5");

SELECT count(*) FROM empresa WHERE nProjetos >= 4;

SELECT AVG(nProjetos) FROM empresa WHERE cargo != "GP";

SELECT DISTINCT cargo FROM empresa;

SELECT nome, cpf, nProjetos FROM empresa WHERE cargo = "Desenvolvedor";

#QUESTAO 4
CREATE TABLE IF NOT EXISTS aluno(
	matricula INT NOT NULL PRIMARY KEY,
    nome VARCHAR(45),
    endereco VARCHAR(45),
    ano_nasc INT,
    curso VARCHAR(45)
);

#RESPOSNDA A QUESTÂO 4 AQUI
/*
A - correta
B - matrícula não pode ser declarada como default
C - matrícula não foi declarada
D - chave primária não pode estar como valor de dois registros diferentes
E - não tem o curso
*/

INSERT INTO aluno (nome, matricula, endereco, ano_nasc, curso) VALUES ("Janaina", 123, "Rua 1", 1998, "GEB");
INSERT INTO aluno (nome, matricula, endereco, ano_nasc, curso) VALUES ("Pedro", 100 , "Rua 2", 2000, "GES");
INSERT INTO aluno (nome, matricula, endereco, ano_nasc, curso) VALUES ("Jander", 200, "Rua 3", 1999, "GEC");
INSERT INTO aluno (nome, matricula, endereco, ano_nasc, curso) VALUES ("Lucca", 300, "Rua 4", 1998, "GEB");
INSERT INTO aluno (nome, matricula, endereco, ano_nasc, curso) VALUES ("Laura", 456, "Rua 5", 1998, "GEA");

#QUESTÂO 5
SELECT nome, matricula, curso FROM aluno WHERE nome LIKE "Jan____%";

SELECT nome, curso FROM aluno WHERE nome LIKE "L%A";

SELECT DISTINCT ano_nasc, curso FROM aluno;

SELECT nome, ano_nasc, curso FROM aluno WHERE ano_nasc <= 1998;

SELECT * FROM aluno LIMIT 3;

UPDATE aluno SET endereco = 'República GEB' WHERE curso = 'GEB';

DELETE FROM aluno WHERE curso = "GEB";
