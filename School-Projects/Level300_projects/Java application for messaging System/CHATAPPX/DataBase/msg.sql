-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 14, 2022 at 11:41 PM
-- Server version: 10.4.19-MariaDB
-- PHP Version: 8.0.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `msg`
--

-- --------------------------------------------------------

--
-- Table structure for table `group2`
--

CREATE TABLE `group2` (
  `ID` int(11) NOT NULL,
  `Group_Name` varchar(30) NOT NULL,
  `Group_CName` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `group2`
--

INSERT INTO `group2` (`ID`, `Group_Name`, `Group_CName`) VALUES
(1, 'We_all', 'alka');

-- --------------------------------------------------------

--
-- Table structure for table `log1`
--

CREATE TABLE `log1` (
  `LOID` int(11) NOT NULL,
  `username` varchar(30) NOT NULL,
  `password` varchar(30) NOT NULL,
  `Email` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `log1`
--

INSERT INTO `log1` (`LOID`, `username`, `password`, `Email`) VALUES
(1, 'mark', '123', ''),
(2, 'alka', '123', 'alka1'),
(3, 'ben', '321', 'bb'),
(4, 'adina', '123', 'ff'),
(5, 'suzy', '12345', 'sysy'),
(6, 'vanella', 'denise', 'uhsdufhd');

-- --------------------------------------------------------

--
-- Table structure for table `message`
--

CREATE TABLE `message` (
  `id` int(11) NOT NULL,
  `subject` varchar(100) NOT NULL,
  `creator_id` varchar(30) NOT NULL,
  `message_body` text NOT NULL,
  `parent_message_id` varchar(30) NOT NULL,
  `flag` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `message`
--

INSERT INTO `message` (`id`, `subject`, `creator_id`, `message_body`, `parent_message_id`, `flag`) VALUES
(23, '123', 'alka', 'hello', 'suzy', 0),
(24, 'hello', 'alka', 'firts message', 'Wall_alka', 1);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE `user` (
  `id` int(11) NOT NULL,
  `Full_Name` varchar(50) NOT NULL,
  `User_Name` varchar(50) NOT NULL,
  `Email` varchar(50) NOT NULL,
  `Contact` int(11) NOT NULL,
  `Location` varchar(30) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`id`, `Full_Name`, `User_Name`, `Email`, `Contact`, `Location`) VALUES
(2, 'Enembe Alkaoid', 'alka', 'alkalio111', 67524343, 'Buea');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `group2`
--
ALTER TABLE `group2`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `log1`
--
ALTER TABLE `log1`
  ADD PRIMARY KEY (`LOID`);

--
-- Indexes for table `message`
--
ALTER TABLE `message`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `user`
--
ALTER TABLE `user`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `group2`
--
ALTER TABLE `group2`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `log1`
--
ALTER TABLE `log1`
  MODIFY `LOID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `message`
--
ALTER TABLE `message`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- AUTO_INCREMENT for table `user`
--
ALTER TABLE `user`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
