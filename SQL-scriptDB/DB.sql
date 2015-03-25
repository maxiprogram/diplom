-- phpMyAdmin SQL Dump
-- version 3.5.2.2
-- http://www.phpmyadmin.net
--
-- Хост: 127.0.0.1
-- Время создания: Мар 25 2015 г., 12:01
-- Версия сервера: 5.5.27
-- Версия PHP: 5.4.7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- База данных: `pkhp`
--

-- --------------------------------------------------------

--
-- Структура таблицы `characteristic`
--

CREATE TABLE IF NOT EXISTS `characteristic` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `value` varchar(255) NOT NULL,
  `id_device` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=cp1251 AUTO_INCREMENT=175 ;

-- --------------------------------------------------------

--
-- Структура таблицы `device`
--

CREATE TABLE IF NOT EXISTS `device` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_type_device` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `inn` varchar(255) NOT NULL,
  `srn` varchar(255) NOT NULL,
  `id_persona` int(11) NOT NULL,
  `host` varchar(255) NOT NULL,
  `ip` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=cp1251 AUTO_INCREMENT=32 ;

-- --------------------------------------------------------

--
-- Структура таблицы `passport`
--

CREATE TABLE IF NOT EXISTS `passport` (
  `tn` int(11) NOT NULL,
  `sex` tinyint(1) NOT NULL,
  `date_birth` date NOT NULL,
  `birth_place` varchar(255) NOT NULL,
  `nationality` varchar(255) NOT NULL,
  `serial_passport` varchar(255) NOT NULL,
  `number_passport` varchar(255) NOT NULL,
  `who_passport` varchar(255) NOT NULL,
  `date_passport` date NOT NULL,
  `city` varchar(255) NOT NULL,
  `street` varchar(255) NOT NULL,
  `number_house` int(11) NOT NULL,
  `number_apartment` int(11) NOT NULL,
  `phone` varchar(255) NOT NULL,
  `mobile_phone` varchar(255) NOT NULL,
  `date` date NOT NULL,
  `number_personal` varchar(255) NOT NULL,
  `number_insurance` varchar(255) NOT NULL,
  PRIMARY KEY (`tn`)
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;

-- --------------------------------------------------------

--
-- Структура таблицы `persona`
--

CREATE TABLE IF NOT EXISTS `persona` (
  `tn` int(11) NOT NULL,
  `login` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `surname` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `patronymic` varchar(255) NOT NULL,
  `id_subdivision` int(11) NOT NULL,
  `id_specialty` int(11) NOT NULL,
  `phone` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  PRIMARY KEY (`tn`)
) ENGINE=InnoDB DEFAULT CHARSET=cp1251;

-- --------------------------------------------------------

--
-- Структура таблицы `repair`
--

CREATE TABLE IF NOT EXISTS `repair` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL,
  `name` varchar(255) NOT NULL,
  `comment` varchar(255) NOT NULL,
  `id_device` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=cp1251 AUTO_INCREMENT=30 ;

-- --------------------------------------------------------

--
-- Структура таблицы `specialty`
--

CREATE TABLE IF NOT EXISTS `specialty` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=cp1251 AUTO_INCREMENT=23 ;

-- --------------------------------------------------------

--
-- Структура таблицы `subdivision`
--

CREATE TABLE IF NOT EXISTS `subdivision` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=cp1251 AUTO_INCREMENT=20 ;

-- --------------------------------------------------------

--
-- Структура таблицы `type_device`
--

CREATE TABLE IF NOT EXISTS `type_device` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=cp1251 AUTO_INCREMENT=3 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
