
create database chicken_management;
go

use chicken_management
go

CREATE TABLE Rooster (
    Rooster_ID INT PRIMARY KEY,
    Rooster_Name NVARCHAR(50),
    Rooster_Breed NVARCHAR(50),
    Rooster_HatchingDate DATE,
    Rooster_TrunkSize INT,
    Rooster_FeatherColor NVARCHAR(50),
    Rooster_CombColor NVARCHAR(50),
    Rooster_Weight DECIMAL(10,2),
    Rooster_Compatibility NVARCHAR(50),
    Rooster_FertilizationRate DECIMAL(5,2)
);
go

CREATE TABLE Hen (
    Hen_ID INT PRIMARY KEY,
    Hen_Name NVARCHAR(50),
    Hen_Breed NVARCHAR(50),
    Hen_HatchingDate DATE,
    Hen_EggColor NVARCHAR(50),
    Hen_AverageEggWeight DECIMAL(10,2),
    Hen_TrunkSize INT,
    Hen_FeatherColor NVARCHAR(50),
    Hen_CombColor NVARCHAR(50),
    Hen_Weight DECIMAL(10,2),
    Hen_Compatibility NVARCHAR(50)
);
go

CREATE TABLE Egg (
    Egg_ID INT PRIMARY KEY,
    Egg_HenID INT,
    Egg_RoosterID INT,
    Egg_DateLaid DATE,
    Egg_Weight DECIMAL(10,2),
    Egg_CoopNumber INT
);
go

ALTER TABLE Egg
ADD Egg_Fertilized BIT;
go

ALTER TABLE Egg
DROP COLUMN Fertilized;
