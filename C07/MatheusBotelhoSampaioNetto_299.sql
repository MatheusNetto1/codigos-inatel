DROP DATABASE IF EXISTS av3;
CREATE DATABASE av3;
USE av3;

CREATE TABLE IF NOT EXISTS Cliente(
    id INT NOT NULL,
    nome VARCHAR(50) NOT NULL,
    saldo FLOAT NOT NULL,
    cidade VARCHAR(50) NOT NULL,
    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS Compra(
    id INT NOT NULL AUTO_INCREMENT,
    nomeProduto VARCHAR(50) NOT NULL,
    precoKG FLOAT NOT NULL,
    peso FLOAT NOT NULL,
    precoTotal FLOAT,
    idCliente INT,
    validade VARCHAR(15),
    PRIMARY KEY(id),
    CONSTRAINT fk1
        FOREIGN KEY(idCliente)
        REFERENCES Cliente(id)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

INSERT INTO Cliente(id, nome, saldo, cidade) VALUES
    (1, 'João', 1700, 'Santa Rita do Sapucai'),
    (2, 'Maria', 3500, 'Santa Rita do Sapucai'),
    (3, 'Marcos', 2600, 'Itajuba'),
    (4, 'Marilia', 1800, 'Pouso Alegre');

DELIMITER $$
DROP PROCEDURE IF EXISTS insere_e_calcula_preco $$
CREATE PROCEDURE insere_e_calcula_preco (
    IN p_nomeProduto VARCHAR(50),
    IN p_validade VARCHAR(15),
    IN p_precoKG FLOAT,
    IN p_peso FLOAT,
    INOUT p_precoTotal FLOAT,
    IN p_idCliente INT
)
BEGIN
    IF p_peso <= 2 
		THEN SET p_precoTotal = (p_precoKG * p_peso) + 5;
    ELSE
        SET p_precoTotal = (p_precoKG * p_peso) + 15;
    END IF;

    INSERT INTO Compra (nomeProduto, precoKG, peso, precoTotal, idCliente, validade)
    VALUES (p_nomeProduto, p_precoKG, p_peso, p_precoTotal, p_idCliente, p_validade);
END $$
DELIMITER ;
-- CALL insere_e_calcula_preco('Produto1', 'xx-xx-xxxx', 20, 1.5, 1);
-- CALL insere_e_calcula_preco('Produto2', 'xx-xx-xxxx', 15, 3, 2);

DELIMITER $$
DROP FUNCTION IF EXISTS preco_com_desconto $$
CREATE FUNCTION preco_com_desconto(p_preco FLOAT) RETURNS FLOAT
DETERMINISTIC
BEGIN
    DECLARE p_preco_final FLOAT;

    IF p_preco > 100 
		THEN SET p_preco_final = p_preco * 0.85;
    ELSE
        SET p_preco_final = p_preco * 0.90;
    END IF;

    RETURN p_preco_final;
END $$

DELIMITER ;

SELECT preco_com_desconto(120) AS NovoPreco1;
SELECT preco_com_desconto(80) AS NovoPreco2;

DELIMITER $$
DROP TRIGGER IF EXISTS before_insert_compra $$
CREATE TRIGGER before_insert_compra BEFORE INSERT
ON Compra
FOR EACH ROW
BEGIN
    DECLARE v_saldo_atual FLOAT;

    SELECT saldo INTO v_saldo_atual
    FROM Cliente
    WHERE id = NEW.idCliente;
    
    UPDATE Cliente
	SET saldo = saldo - NEW.precoTotal
	WHERE id = NEW.idCliente;
    
END $$

DELIMITER ;

CALL insere_e_calcula_preco('Produto1', 'xx-xx-xxxx', 10, 10, @precoTotal, 4);
CALL insere_e_calcula_preco('Produto2', 'xx-xx-xxxx', 15, 15, @precoTotal, 2);
CALL insere_e_calcula_preco('Produto3', 'xx-xx-xxxx', 20, 20, @precoTotal, 3);
CALL insere_e_calcula_preco('Produto4', 'xx-xx-xxxx', 25, 25, @precoTotal, 1);
SELECT * FROM Compra;
SELECT * FROM Cliente;

CREATE VIEW Compra_Cliente_Info AS
SELECT 
    c.nomeProduto, 
    c.validade, 
    c.precoTotal, 
    cli.nome, 
    cli.cidade, 
    cli.saldo
FROM 
    Compra c
JOIN 
    Cliente cli ON c.idCliente = cli.id
WHERE 
    c.precoTotal > 300 
    AND cli.cidade = 'Santa Rita do Sapucai';

SELECT * FROM Compra_Cliente_Info