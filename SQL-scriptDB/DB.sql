-- MySQL dump 10.13  Distrib 5.5.27, for Win32 (x86)
--
-- Host: localhost    Database: mysysadmin
-- ------------------------------------------------------
-- Server version	5.5.27

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `characteristic`
--

DROP TABLE IF EXISTS `characteristic`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `characteristic` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `value` varchar(255) NOT NULL,
  `id_device` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=175 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `characteristic`
--

LOCK TABLES `characteristic` WRITE;
/*!40000 ALTER TABLE `characteristic` DISABLE KEYS */;
INSERT INTO `characteristic` VALUES (1,'Материнская плата','AsusTek Computer P4S800-MX SE',7),(3,'Оперативная память','735 Мб',7),(5,'Сетевой адаптер','Sis 900-Based',7),(6,'Операционная система','Windows XP',7),(7,'Материнская плата','',1),(8,'Процессор','',1),(9,'Оперативная память','',1),(10,'Видеоадаптер','',1),(11,'Сетевой адаптер','',1),(12,'Операционная система','',1),(13,'Материнская плата','',2),(14,'Процессор','',2),(15,'Оперативная память','',2),(16,'Видеоадаптер','',2),(17,'Сетевой адаптер','',2),(18,'Операционная система','',2),(19,'Материнская плата','Gigabyte Technology H61M-DS2V',3),(20,'Процессор','Intel Pentium 3 Xeon',3),(21,'Оперативная память','1936 Мб',3),(22,'Видеоадаптер','Intel(R) HD Graphic, 1024 Мб',3),(23,'Сетевой адаптер','Realtek PCIe GBE',3),(24,'Операционная система','Windows XP',3),(25,'Материнская плата','',4),(26,'Процессор','',4),(27,'Оперативная память','',4),(28,'Видеоадаптер','',4),(29,'Сетевой адаптер','',4),(30,'Операционная система','',4),(31,'Материнская плата','AsusTek Computer P5GC-MX/1333',5),(32,'Процессор','Intel(R) Pentium(R) Dual E2160 CPU 1.8 GHz',5),(33,'Оперативная память','1015 Мб',5),(34,'Видеоадаптер','Intel(R) 92945G Express, 128 Мб',5),(35,'Сетевой адаптер','Atheros L2 Fast 10/100 Base-T',5),(36,'Операционная система','Windows XP',5),(37,'Материнская плата','AsusTek Computer P5G41T-M LX2/GB/LPT',6),(38,'Процессор','Intel Pentium 3 Xeon',6),(39,'Оперативная память','2013 Мб',6),(40,'Видеоадаптер','Intel(R) G41 Express, 256 Мб',6),(41,'Сетевой адаптер','Realtek PCIe Family',6),(42,'Операционная система','Windows XP',6),(44,'Процессор','Intel(R) Celeron(R) CPU 2.4 GHz',7),(46,'Видеоадаптер','Sis 661FX, 32 Мб',7),(49,'Материнская плата','Intel Corporation D865PERL',9),(50,'Процессор','Intel(R) Pentium(R) 4 CPU 2.8 GHz',9),(51,'Оперативная память','511 Мб',9),(52,'Видеоадаптер','Radeon 9200 PRO, 128 Мб',9),(53,'Сетевой адаптер','Intel(R) PRO/100 VE',9),(54,'Операционная система','Windows XP',9),(55,'Материнская плата','',10),(56,'Процессор','',10),(57,'Оперативная память','',10),(58,'Видеоадаптер','',10),(59,'Сетевой адаптер','',10),(60,'Операционная система','',10),(61,'Материнская плата','AsusTek Computer P8H61-M LX2',11),(62,'Процессор','Intel(R) Pentium(R) CPU G620 2.6 GHz',11),(63,'Оперативная память','1954 Мб',11),(64,'Видеоадаптер','Intel(R) HD Graphic, 785 Мб',11),(65,'Сетевой адаптер','Realtek PCIe GBE',11),(66,'Операционная система','Windows 7',11),(67,'Материнская плата','ASRock H16M-VG3',12),(68,'Процессор','Intel(R) Celeron(R) CPU G1610 2.6 GHz',12),(69,'Оперативная память','1749 Мб',12),(70,'Видеоадаптер','Intel(R) HD Graphics, 874 Мб',12),(71,'Сетевой адаптер','Realtek PCIe GBE',12),(72,'Операционная система','Windows 7',12),(73,'Материнская плата','Hewlett-Packard 3618',13),(74,'Процессор','Intel(R) Core(TM) Duo CPU 1.8 GHz',13),(75,'Оперативная память','2039 Мб',13),(76,'Видеоадаптер','Mobile Intel(R) 965, 384 Мб',13),(77,'Сетевой адаптер','Intel(R) 82562GT 10/100',13),(78,'Операционная система','Windows XP',13),(79,'Материнская плата','Gigabyte Technology G31M-ES2L',14),(80,'Процессор','Intel(R) Core(TM) Duo E4700 CPU 2.6 GHz',14),(81,'Оперативная память','2037 Мб',14),(82,'Видеоадаптер','Intel(R) G33/G31, 384 Мб',14),(83,'Сетевой адаптер','Atheros AR8131 PCI-E',14),(84,'Операционная система','Windows XP',14),(85,'Материнская плата','P4i65G',15),(86,'Процессор','Intel(R) Celeron(R) CPU 2.0 GHz',15),(87,'Оперативная память','503 Мб',15),(88,'Видеоадаптер','Intel(R) 82865G Graphic, 96 Мб',15),(89,'Сетевой адаптер','Realtek RTL8139/810x Fast',15),(90,'Операционная система','Windows XP',15),(91,'Материнская плата','',16),(92,'Процессор','',16),(93,'Оперативная память','',16),(94,'Видеоадаптер','',16),(95,'Сетевой адаптер','',16),(96,'Операционная система','',16),(97,'Материнская плата','',17),(98,'Процессор','',17),(99,'Оперативная память','',17),(100,'Видеоадаптер','',17),(101,'Сетевой адаптер','',17),(102,'Операционная система','',17),(103,'Материнская плата','MSI H61M-P20 (G3) (MS-7788)',18),(104,'Процессор','Intel Pentium 3 Xeon',18),(105,'Оперативная память','1936 Мб',18),(106,'Видеоадаптер','Intel(R) HD Graphic, 256 Мб',18),(107,'Сетевой адаптер','Realtek PCIe FE',18),(108,'Операционная система','Windows XP',18),(109,'Материнская плата','AsusTek Computer P5GC-MX/1333',20),(110,'Процессор','Intel(R) Core(Tm) Duo CPU E4600 2.4 GHz',20),(111,'Оперативная память','1015 Мб',20),(112,'Видеоадаптер','Intel(R) 82945G, 128 Мб',20),(113,'Сетевой адаптер','Atheros L2 10/100 Base-T',20),(114,'Операционная система','Windows XP',20),(115,'Материнская плата','AsusTek Computer P8H61-M LX3',21),(116,'Процессор','Intel Pentium 3 Xeon',21),(117,'Оперативная память','2986 Мб',21),(118,'Видеоадаптер','Intel(R) HD Graphic, 1024 Мб',21),(119,'Сетевой адаптер','Realtek PCIe GBE',21),(120,'Операционная система','Windows XP',21),(121,'Материнская плата','AsusTek Computer P5GC-MX/1333',22),(122,'Процессор','Intel(R) Pentium(R) Dual CPU E2160 1.8 GHz',22),(123,'Оперативная память','1015 Мб',22),(124,'Видеоадаптер','Intel(R) 82945G, 128 Мб',22),(125,'Сетевой адаптер','Atheros WDC WD2500AAKS-00VSA0',22),(126,'Операционная система','Windows XP',22),(127,'Материнская плата','',23),(128,'Процессор','',23),(129,'Оперативная память','',23),(130,'Видеоадаптер','',23),(131,'Сетевой адаптер','',23),(132,'Операционная система','',23),(133,'Материнская плата','',24),(134,'Процессор','',24),(135,'Оперативная память','',24),(136,'Видеоадаптер','',24),(137,'Сетевой адаптер','',24),(138,'Операционная система','',24),(139,'Материнская плата','',25),(140,'Процессор','',25),(141,'Оперативная память','',25),(142,'Видеоадаптер','',25),(143,'Сетевой адаптер','',25),(144,'Операционная система','',25),(145,'Материнская плата','',26),(146,'Процессор','',26),(147,'Оперативная память','',26),(148,'Видеоадаптер','',26),(149,'Сетевой адаптер','',26),(150,'Операционная система','',26),(151,'Материнская плата','',27),(152,'Процессор','',27),(153,'Оперативная память','',27),(154,'Видеоадаптер','',27),(155,'Сетевой адаптер','',27),(156,'Операционная система','',27),(157,'Материнская плата','AsusTek Computer P5G41T-M LX2/GB/LPT',28),(158,'Процессор','Intel Pentium 2 Xeon',28),(159,'Оперативная память','2013 Мб',28),(160,'Видеоадаптер','Intel(R) G41 Express, 256 Мб',28),(161,'Сетевой адаптер','Realtek PCIe GBE',28),(162,'Операционная система','Windows XP',28),(163,'Материнская плата','Intel Corporation D865PERL',29),(164,'Процессор','Intel(R) Pentium(R) 4 CPU 2.8 GHz',29),(165,'Оперативная память','1023 Мб',29),(166,'Видеоадаптер','Radeon 9200 SE, 64 Мб',29),(167,'Сетевой адаптер','Intel(R) PRO/100 VE',29),(168,'Операционная система','Windows XP',29),(169,'Материнская плата','Lenovo Base Board',30),(170,'Процессор','Intel Pentium 2',30),(171,'Оперативная память','2999 Мб',30),(172,'Видеоадаптер','NVidio GeForce 310M, 512 Мб',30),(173,'Сетевой адаптер','Realtek PCie FE',30),(174,'Операционная система','Windows XP',30);
/*!40000 ALTER TABLE `characteristic` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `device`
--

DROP TABLE IF EXISTS `device`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `device` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_type_device` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `inn` varchar(255) NOT NULL,
  `srn` varchar(255) NOT NULL,
  `id_persona` int(11) NOT NULL,
  `host` varchar(255) NOT NULL,
  `ip` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=31 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `device`
--

LOCK TABLES `device` WRITE;
/*!40000 ALTER TABLE `device` DISABLE KEYS */;
INSERT INTO `device` VALUES (1,1,'','1004','N12345682',1,'buh1_1',''),(2,1,'','1007','N12345685',17,'buh1_4','192.168.1.21'),(3,1,'Intel Pentium 3 Xeon','1010','N12345688',21,'buh2_1','192.168.1.27'),(4,1,'','1013','N12345691',39,'buh2_2','192.168.1.26'),(5,1,'Intel(R) Pentium(R) Dual E2160 CPU 1.8 GHz','1016','N12345694',27,'buh3-1','192.168.1.34'),(6,1,'Intel Pentium 3 Xeon','1019','N12345697',28,'buh3_2','192.168.1.37'),(7,1,'Intel(R) Celeron(R) CPU 2.4 GHz','1022','N12345700',19,'buhg2_2','192.168.1.25'),(9,1,'Intel(R) Pentium(R) 4 CPU 2.8 GHz','1025','N12345703',16,'glbuh','192.168.1.20'),(10,1,'','1000','N12345678',37,'market-92','192.168.1.106'),(11,1,'Intel(R) Pentium(R) CPU G620 2.6 GHz','1003','N12345681',34,'market-93','192.168.1.104'),(12,1,'Intel(R) Celeron(R) CPU G1610 2.6 GHz','1006','N12345684',31,'market-98','192.168.1.98'),(13,1,'Intel(R) Core(TM) Duo CPU 1.8 GHz','1009','N12345687',29,'noutorim','192.168.1.72'),(14,1,'Intel(R) Core(TM) Duo E4700 CPU 2.6 GHz','1012','N12345690',9,'ok1_1','192.168.1.105'),(15,1,'Intel(R) Celeron(R) CPU 2.0 GHz','1015','N12345693',4,'ok1_2','192.168.1.30'),(16,1,'','1018','N12345696',22,'oper1','192.168.1.44'),(17,1,'','1021','N12345699',26,'buh3-3','192.168.1.33'),(18,1,'Intel Pentium 3 Xeon','1024','N12345702',20,'buh2_3','192.168.1.28'),(20,1,'Intel(R) Core(Tm) Duo CPU E4600 2.4 GHz','1027','N12345705',13,'plan1','192.168.1.35'),(21,1,'Intel Pentium 3 Xeon','1002','N12345680',15,'plan2','192.168.1.31'),(22,1,'Intel(R) Pentium(R) Dual CPU E2160 1.8 GHz','1005','N12345683',14,'plan4','192.168.1.36'),(23,1,'','1008','N12345686',35,'snab','192.168.1.47'),(24,1,'','1011','N12345689',48,'ves1','192.168.1.81'),(25,1,'','1014','N12345692',46,'ves2','192.168.1.77'),(26,1,'','1017','N12345695',47,'vesy2','192.168.1.78'),(27,1,'','1020','N12345698',3,'yurist2','192.168.1.51'),(28,1,'Intel Pentium 2 Xeon','1023','N12345701',2,'yurist3','192.168.1.53'),(29,1,'Intel(R) Pentium(R) 4 CPU 2.8 GHz','1026','N12345704',24,'zarpl1','192.168.1.40'),(30,1,'Intel Pentium 2','1001','N12345679',49,'programmer','192.168.1.198');
/*!40000 ALTER TABLE `device` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `persona`
--

DROP TABLE IF EXISTS `persona`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `persona` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `fio` varchar(255) NOT NULL,
  `id_subdivision` int(11) NOT NULL,
  `id_specialty` int(11) NOT NULL,
  `phone` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=50 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `persona`
--

LOCK TABLES `persona` WRITE;
/*!40000 ALTER TABLE `persona` DISABLE KEYS */;
INSERT INTO `persona` VALUES (1,'boguckya','l1e2n3a4_b','БОГУЦКАЯ ЕЛЕНА ВИКТОРОВНА',10,16,'2-72',''),(2,'ola','o1l2a3_e','ЕРЕМЕЕВА ОЛЬГА АНАТОЛЬЕВНА',11,7,'2-26',''),(3,'ira','i1r2a3_n','НИКИТИНА ИРИНА НИКОЛАЕВНА',11,7,'2-26',''),(4,'ok','a1l2i3n4a5_s','СЫСЕНКО АЛИНА ОЛЕГОВНА',11,5,'2-18',''),(7,'sekretar','','РАЙКЕВИЧ ЛЮДМИЛА СТЕПАНОВНА',11,14,'2-16',''),(8,'admin','','РЯЗАНЦЕВА ЛЮБОВЬ МИХАЙЛОВНА',11,10,'2-20',''),(9,'ok1','l1u2d3a4_n','НОВИКОВА ЛЮДМИЛА ИВАНОВНА',11,5,'2-18',''),(10,'admin','','ДУРНЕВА ТАТЬЯНА ЕВГЕНЬЕВНА',11,3,'2-75',''),(11,'shevcov1','i1g2o3r4_s','ШЕВЦОВ ИГОРЬ ВАСИЛЬЕВИЧ',11,12,'2-97',''),(12,'admin','','РОМАНОВИЧ ОЛЬГА НИКОЛАЕВНА',11,15,'2-80',''),(13,'garkusha','l1e2n3a4_g','ГАРКУША ЕЛЕНА ВЛАДИМИРОВНА',9,18,'2-36',''),(14,'koleda','a1n2n3a4_k','КОЛЕДА АННА ВЛАДИМИРОВНА',9,6,'2-36',''),(15,'admin','','ХАРИТОНЧИК ЛЮДМИЛА ВАЛЕРЬЕВНА',9,6,'2-82',''),(16,'leichenko','l1v2v3_gb','ЛЕЙЧЕНКО ВАЛЕНТИНА ВИКТОРОВНА',10,18,'2-73',''),(17,'kalchevskay','s1v2e3t4a5_k','КОЛЬЧЕВСКАЯ СВЕТЛАНА МИХАЙЛОВНА',10,1,'2-38',''),(18,'kyleshova','n1i2n3a4_k','КУЛЕШОВА НИНА ИОСИФОВНА',10,1,'2-38',''),(19,'buhg2_2','t1a2n3a4_h','ХАТКЕВИЧ ТАТЬЯНА НИКОЛАЕВНА',10,1,'2-78',''),(20,'symareva','n1i2n3a4_s','СУМАРЕВА НИНА ДМИТРИЕВНА',10,1,'2-78',''),(21,'gyrko','e1l2e3n4a5_j','ЖУРКО ЕЛЕНА ГРИГОРЬЕВНА',10,1,'2-78',''),(22,'gribova','s1v2e3t4a5_g','ГРИБОВА СВЕТЛАНА ПЕТРОВНА',10,1,'2-37',''),(23,'opr2','s1v2e3t4a5_z','ЗАБОРОВСКАЯ СВЕТЛАНА ВЛАДИМИРОВНА',10,1,'2-37',''),(24,'rudneva','z1i2n3a4_r','РУДНЕВА ЗИНАИДА ИВАНОВНА',10,1,'2-35',''),(25,'lavrenova','i1r2a3_l','ЛАВРЕНОВА ИРИНА АЛЕКСАНДРОВНА',10,1,'2-35',''),(26,'buh12','buh_12','ФИАЛКО ЕЛЕНА ВАСИЛЬЕВНА',10,1,'2-13',''),(27,'admin','','СИЗОВА ЕВГЕНИЯ ГЕННАДЬЕВНА',10,1,'2-13',''),(28,'burdukova','s1v2e3t4a5_b','БУРДУКОВА СВЕТЛАНА НИКОЛАЕВНА',10,1,'2-13',''),(29,'noutorim','','ДУБНИЦКАЯ ЕЛЕНА МИХАЙЛОВНА',8,18,'3-93',''),(30,'admin','','КОРОЛЕВА ЛЮДМИЛА СЕМЕНОВНА',8,17,'2-94',''),(31,'jukova','l1e2n3a4_j','ЖУКОВА ЕЛЕНА ВАСИЛЬЕВНА',8,17,'3-93',''),(32,'market98','market_98','КАРАЛЕНОК ВАДИМ АНАТОЛЬЕВИЧ',8,17,'2-23',''),(33,'market102','market_102','СМЕХОВА ОЛЬГА СЕРГЕЕВНА',8,17,'3-93',''),(34,'market93','market_93','ДОРОШКЕВИЧ ПАВЕЛ ПЕТРОВИЧ',8,17,'3-93',''),(35,'fialko','v1a2s3a4_f','ТИТОВЕЦ ВИКТОР МИХАЙЛОВИЧ',8,19,'3-93',''),(36,'admin','','ЧАЧУРА ЕКАТЕРИНА ВИКТОРОВНА',8,13,'2-23',''),(37,'market101','market_101','ЖУКОВА ЛАРИСА ВАСИЛЬЕВНА',8,13,'2-23',''),(38,'simonovich','t1a2n3a4_s','СИМОНОВИЧ ТАТЬЯНА ВАЛЕРЬЕВНА',4,1,'2-38',''),(39,'admin','','СОЛОВЬЁВА ОЛЬГА ВИКТОРОВНА',4,20,'2-78',''),(40,'zam_lab','e1l2e3n4a5_b','БОРОДИНА ЕЛЕНА ОЛИМПИЕВНА',5,18,'2-34',''),(41,'admin','','КАРДАШ ЕВГЕНИЯ ЮРЬЕВНА',5,2,'3-10',''),(42,'gavrilovich','t1a2n3a4_g','ГАВРИЛОВИЧ ТАТЬЯНА ЭДУАРДОВНА',5,2,'3-10',''),(43,'admin','','МАЙОРОВА НИНА ИОСИФОВНА',5,4,'2-95',''),(44,'admin','','СКОРОДЕНОК ВАЛЕНТИНА ВЛАДИМИРОВНА',5,13,'3-10',''),(45,'admin','','КОРЖУЕВА ТАТЬЯНА АЛЕКСАНДРОВНА',2,20,'2-37',''),(46,'ves1','ves_1','МИХАЙЛОВА АНЖЕЛИКА АЛЕКСАНДРОВНА',7,13,'2-49',''),(47,'ves2','ves_2','МЯГКАЯ ГАЛИНА МИХАЙЛОВНА',7,13,'2-49',''),(48,'ves3','ves_3','ПРОШКОВИЧ ИРИНА ЛЕОНИДОВНА',7,13,'2-49',''),(49,'maxim','m1a2x3i4m5_1','ТИХОНОВ МАКСИМ ВАСИЛЬЕВИЧ',11,21,'2-69','');
/*!40000 ALTER TABLE `persona` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `repair`
--

DROP TABLE IF EXISTS `repair`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `repair` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `name` varchar(255) NOT NULL,
  `comment` varchar(255) NOT NULL,
  `id_device` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=30 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `repair`
--

LOCK TABLES `repair` WRITE;
/*!40000 ALTER TABLE `repair` DISABLE KEYS */;
INSERT INTO `repair` VALUES (1,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',1),(2,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',2),(3,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',3),(4,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',4),(5,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',5),(6,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',6),(7,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',7),(9,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',9),(10,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',10),(11,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',11),(12,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',12),(13,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',13),(14,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',14),(15,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',15),(16,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',16),(17,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',17),(18,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',18),(19,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',20),(20,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',21),(21,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',22),(22,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',23),(23,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',24),(24,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',25),(25,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',26),(26,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',27),(27,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',28),(28,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',29),(29,'2014-06-01','Техническое обслуживание','Очистка системных блоков от пыли',30);
/*!40000 ALTER TABLE `repair` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `specialty`
--

DROP TABLE IF EXISTS `specialty`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `specialty` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `specialty`
--

LOCK TABLES `specialty` WRITE;
/*!40000 ALTER TABLE `specialty` DISABLE KEYS */;
INSERT INTO `specialty` VALUES (1,'Бухгалтер'),(2,'Инженер по качеству'),(3,'Инженер по охране труда'),(4,'Инженер по управлению качеством'),(5,'Специалист по кадрам'),(6,'Экономист'),(7,'Юрисконсульт'),(9,'Директор'),(10,'Заместитель директора'),(11,'Инженер-лаборант'),(12,'Инженер-программист'),(13,'Оператор ПЭВМ'),(14,'Секретарь'),(15,'Инженер по вентиляции'),(16,'Кассир'),(17,'Специалист по маркетингу'),(18,'Начальник отдела'),(19,'Специалист по закупкам'),(20,'Кладовщик'),(21,'Техник-программист');
/*!40000 ALTER TABLE `specialty` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `subdivision`
--

DROP TABLE IF EXISTS `subdivision`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `subdivision` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `subdivision`
--

LOCK TABLES `subdivision` WRITE;
/*!40000 ALTER TABLE `subdivision` DISABLE KEYS */;
INSERT INTO `subdivision` VALUES (1,'Мукомольное производство'),(2,'Комбикормовое производство'),(3,'Элеватор'),(4,'Производство и реализация с/х продукции'),(5,'Производственно-технологическая лаборатория'),(6,'Участок готовой продукции и материалов'),(7,'Транспортный участок'),(8,'Отдел реализации и маркетинга'),(9,'Планово-экономический отдел'),(10,'Бухгалтерия'),(11,'Общее руководство'),(12,'Ремонтно-механический участок'),(13,'Ремонтно-энергетический участок'),(14,'Ремонтно-строительный участок'),(15,'Тепло-энергетический участок');
/*!40000 ALTER TABLE `subdivision` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `type_device`
--

DROP TABLE IF EXISTS `type_device`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `type_device` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=cp1251;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `type_device`
--

LOCK TABLES `type_device` WRITE;
/*!40000 ALTER TABLE `type_device` DISABLE KEYS */;
INSERT INTO `type_device` VALUES (1,'Персональный компьютер'),(2,'Принтер');
/*!40000 ALTER TABLE `type_device` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-06-04 13:21:16
