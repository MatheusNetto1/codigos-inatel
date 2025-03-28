CREATE SCHEMA IF NOT EXISTS `SenhorDosAneis`;
USE `SenhorDosAneis` ;

CREATE TABLE IF NOT EXISTS `SenhorDosAneis`.`Item Mágico` (
  `Nome` VARCHAR(45) NOT NULL,
  `Tipo` VARCHAR(45) NOT NULL,
  `Durabilidade` INT NULL,
  `Material` VARCHAR(45) NULL,
  `Natureza` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Nome`))
  ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `SenhorDosAneis`.`Localização` (
  `Cidade` VARCHAR(45) NOT NULL,
  `Reino` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Cidade`))
  ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `SenhorDosAneis`.`Habitante` (
  `Nome` VARCHAR(45) NOT NULL,
  `Raça` VARCHAR(45) NOT NULL,
  `Idade` INT NOT NULL,
  `Altura` DECIMAL(2) NOT NULL,
  `Item Mágico_Nome` VARCHAR(45) NOT NULL,
  `Localização_Cidade` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Nome`),
  CONSTRAINT `fk_Habitante_Item Mágico1`
    FOREIGN KEY (`Item Mágico_Nome`)
    REFERENCES `SenhorDosAneis`.`Item Mágico` (`Nome`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Habitante_Localização1`
    FOREIGN KEY (`Localização_Cidade`)
    REFERENCES `SenhorDosAneis`.`Localização` (`Cidade`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
    ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `SenhorDosAneis`.`Arma` (
  `Nome` VARCHAR(45) NOT NULL,
  `Tipo` VARCHAR(45) NOT NULL,
  `Durabilidade` INT NULL,
  `Material` VARCHAR(45) NULL,
  `Propriedade` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Nome`))
  ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `SenhorDosAneis`.`Armadura` (
  `Nome` VARCHAR(45) NOT NULL,
  `Tipo` VARCHAR(45) NOT NULL,
  `Durabilidade` INT NULL,
  `Peso` DECIMAL(2) NULL,
  `Material` VARCHAR(45) NULL,
  `Propriedade` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Nome`))
  ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `SenhorDosAneis`.`Habitante_has_Arma` (
  `Habitante_Nome` VARCHAR(45) NOT NULL,
  `Arma_Nome` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Habitante_Nome`, `Arma_Nome`),
  CONSTRAINT `fk_Habitante_has_Arma_Habitante`
    FOREIGN KEY (`Habitante_Nome`)
    REFERENCES `SenhorDosAneis`.`Habitante` (`Nome`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Habitante_has_Arma_Arma1`
    FOREIGN KEY (`Arma_Nome`)
    REFERENCES `SenhorDosAneis`.`Arma` (`Nome`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
    ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `SenhorDosAneis`.`Habitante_has_Armadura` (
  `Habitante_Nome` VARCHAR(45) NOT NULL,
  `Armadura_Nome` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Habitante_Nome`, `Armadura_Nome`),
  CONSTRAINT `fk_Habitante_has_Armadura_Habitante1`
    FOREIGN KEY (`Habitante_Nome`)
    REFERENCES `SenhorDosAneis`.`Habitante` (`Nome`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Habitante_has_Armadura_Armadura1`
    FOREIGN KEY (`Armadura_Nome`)
    REFERENCES `SenhorDosAneis`.`Armadura` (`Nome`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
    ENGINE = InnoDB;