-- MySQL dump 10.13  Distrib 8.0.13, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: amusement_park
-- ------------------------------------------------------
-- Server version	5.5.5-10.1.37-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `child`
--

DROP TABLE IF EXISTS `child`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `child` (
  `childId` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  PRIMARY KEY (`childId`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `child`
--

LOCK TABLES `child` WRITE;
/*!40000 ALTER TABLE `child` DISABLE KEYS */;
INSERT INTO `child` VALUES (1,'Child1',12),(2,'Child2',14),(3,'Child3',6),(4,'Child4',4),(5,'Child5',14),(6,'Child6',15);
/*!40000 ALTER TABLE `child` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `installation`
--

DROP TABLE IF EXISTS `installation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `installation` (
  `installationId` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  `minAge` int(11) DEFAULT NULL,
  PRIMARY KEY (`installationId`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `installation`
--

LOCK TABLES `installation` WRITE;
/*!40000 ALTER TABLE `installation` DISABLE KEYS */;
INSERT INTO `installation` VALUES (1,'Ferris wheel',6),(2,'Speed Train',14),(3,'Crazy jungle',4),(4,'Rocket tower',12),(5,'Cosmo swing',6),(6,'Coffee cups',4),(7,'Boat ride',7),(8,'Kite run',9),(9,'Lulka',5);
/*!40000 ALTER TABLE `installation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `manager`
--

DROP TABLE IF EXISTS `manager`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `manager` (
  `managerId` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  `salary` double DEFAULT NULL,
  `salaryIncreased` int(11) DEFAULT '0',
  PRIMARY KEY (`managerId`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `manager`
--

LOCK TABLES `manager` WRITE;
/*!40000 ALTER TABLE `manager` DISABLE KEYS */;
INSERT INTO `manager` VALUES (1,'Martin Simeonov',3000,0),(2,'Ivan Petrov',1500,0),(3,'Zlatan Zlatanov',1000,0),(4,'Georgi Georgev',1200,0),(5,'Georgi Dimitrov',800,0),(6,'Nikola Petkov',1680,1),(7,'Zlatko Zlatev',1728,1),(8,'Kalin Stoyanov',1234,0),(9,'Ivan Gorchev',1872,1),(10,'Martin',1200,1),(11,'Pesho',800,0);
/*!40000 ALTER TABLE `manager` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `park`
--

DROP TABLE IF EXISTS `park`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `park` (
  `parkId` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) DEFAULT NULL,
  `manager` int(11) DEFAULT NULL,
  `saleThreshold` double DEFAULT NULL,
  `salaryIncrease` int(11) DEFAULT NULL,
  `ticketPrice` double DEFAULT NULL,
  PRIMARY KEY (`parkId`),
  UNIQUE KEY `manager_uq` (`manager`),
  CONSTRAINT `manager_fk` FOREIGN KEY (`manager`) REFERENCES `manager` (`managerId`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `park`
--

LOCK TABLES `park` WRITE;
/*!40000 ALTER TABLE `park` DISABLE KEYS */;
INSERT INTO `park` VALUES (1,'Park1',1,20000,5,12),(2,'park2',2,123,123,5),(3,'park3',3,1234,1212,8),(4,'Sofia Land',4,15000,5,25),(5,'PlovdivWorld',5,12500,5,17),(7,'STZOtbora',6,100,20,30),(8,'VarnaPark',7,100,20,35),(9,'Burgas',8,1123,23,14),(10,'Sozopolis',9,100,20,35),(11,'ParkNBU',10,100,20,35);
/*!40000 ALTER TABLE `park` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `park_child`
--

DROP TABLE IF EXISTS `park_child`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `park_child` (
  `parkId` int(11) DEFAULT NULL,
  `childId` int(11) DEFAULT NULL,
  KEY `child_pc_fk` (`childId`),
  KEY `park_pc_fk` (`parkId`),
  CONSTRAINT `child_pc_fk` FOREIGN KEY (`childId`) REFERENCES `child` (`childId`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `park_pc_fk` FOREIGN KEY (`parkId`) REFERENCES `park` (`parkId`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `park_child`
--

LOCK TABLES `park_child` WRITE;
/*!40000 ALTER TABLE `park_child` DISABLE KEYS */;
INSERT INTO `park_child` VALUES (5,3),(9,4),(8,1),(10,5),(10,5),(10,5),(1,1),(1,5),(11,6),(11,5),(11,5);
/*!40000 ALTER TABLE `park_child` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `park_installation`
--

DROP TABLE IF EXISTS `park_installation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `park_installation` (
  `parkId` int(11) DEFAULT NULL,
  `installationId` int(11) DEFAULT NULL,
  KEY `installation_fk` (`installationId`),
  KEY `park_fk` (`parkId`),
  CONSTRAINT `installation_fk` FOREIGN KEY (`installationId`) REFERENCES `installation` (`installationId`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `park_fk` FOREIGN KEY (`parkId`) REFERENCES `park` (`parkId`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `park_installation`
--

LOCK TABLES `park_installation` WRITE;
/*!40000 ALTER TABLE `park_installation` DISABLE KEYS */;
INSERT INTO `park_installation` VALUES (1,1),(2,2),(3,3),(4,3),(4,4),(4,5),(3,2),(5,4),(5,1),(5,5),(7,2),(7,1),(8,3),(8,6),(9,1),(9,3),(9,2),(10,3),(10,8),(10,1),(11,6),(11,1),(11,4),(11,3);
/*!40000 ALTER TABLE `park_installation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'amusement_park'
--
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-01-18  9:53:24
