DROP DATABASE IF EXISTS AV1;
CREATE DATABASE AV1;
USE AV1;

/*Letra A*/
CREATE TABLE IF NOT EXISTS Alunos(
	matricula INT NOT NULL,
    nome VARCHAR(45),
    idade INT,
	cidade VARCHAR(45)
);

/*Letra B*/
INSERT INTO Alunos (matricula, nome, idade, cidade) VALUES (87123, "Maria", 22, "Rio de Janeiro");
INSERT INTO Alunos (matricula, nome, idade, cidade) VALUES (59234, "Pedro", 20, "São Paulo");
INSERT INTO Alunos (matricula, nome, idade, cidade) VALUES (15256, "Marcos", 25, "Belo Horizonte");
INSERT INTO Alunos (matricula, nome, idade, cidade) VALUES (78952, "Lucas", 19, "Salvador");
INSERT INTO Alunos (matricula, nome, idade, cidade) VALUES (98765, "Mariana", 21, "Brasília");

/*Letra C*/
SELECT * FROM Alunos WHERE idade >= 20;

/*Letra D*/
DELETE FROM Alunos WHERE matricula = '59234';

/*Letra E*/
UPDATE Alunos SET cidade = "Campinas" WHERE matricula = '98765';

/*Letra F*/
SELECT DISTINCT nome FROM Alunos;

/*Letra G*/
SELECT * FROM Alunos WHERE nome LIKE 'Mar%';

/*Letra H*/
INSERT INTO Alunos (matricula, nome, idade, cidade) VALUES (299, "Matheus", 22, "Rio de Janeiro");