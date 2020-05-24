-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 24, 2020 at 03:03 PM
-- Server version: 10.4.11-MariaDB
-- PHP Version: 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `pvradm`
--

-- --------------------------------------------------------

--
-- Table structure for table `bedriftbehandlnger`
--

CREATE TABLE `bedriftbehandlnger` (
  `BedriftID` int(11) NOT NULL,
  `BehandlingID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `bedrifter`
--

CREATE TABLE `bedrifter` (
  `BedriftID` int(11) NOT NULL,
  `BedriftNavn` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `behandlinger`
--

CREATE TABLE `behandlinger` (
  `behandlingsID` int(11) NOT NULL,
  `Behandlingsnavn` varchar(75) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `bruker`
--

CREATE TABLE `bruker` (
  `BrukeID` int(11) NOT NULL,
  `BrukerNavn` char(25) NOT NULL,
  `Passord` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `objekt`
--

CREATE TABLE `objekt` (
  `ObjektID` int(11) NOT NULL,
  `Artikkelnummer` varchar(255) NOT NULL,
  `bildelink` int(11) NOT NULL,
  `strekkodebilde` blob NOT NULL,
  `Behandlingtype` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `objektbilder`
--

CREATE TABLE `objektbilder` (
  `bildeID` int(11) NOT NULL,
  `Objektbilde` blob NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `objektliste`
--

CREATE TABLE `objektliste` (
  `ListID` int(11) NOT NULL,
  `objekter` int(11) NOT NULL,
  `Dato` date NOT NULL,
  `Plukker` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `bedriftbehandlnger`
--
ALTER TABLE `bedriftbehandlnger`
  ADD KEY `BedriftID` (`BedriftID`),
  ADD KEY `BehandlingID` (`BehandlingID`);

--
-- Indexes for table `bedrifter`
--
ALTER TABLE `bedrifter`
  ADD PRIMARY KEY (`BedriftID`);

--
-- Indexes for table `behandlinger`
--
ALTER TABLE `behandlinger`
  ADD PRIMARY KEY (`behandlingsID`);

--
-- Indexes for table `bruker`
--
ALTER TABLE `bruker`
  ADD PRIMARY KEY (`BrukeID`);

--
-- Indexes for table `objekt`
--
ALTER TABLE `objekt`
  ADD PRIMARY KEY (`ObjektID`),
  ADD KEY `bildelink` (`bildelink`),
  ADD KEY `Behandlingtype` (`Behandlingtype`);

--
-- Indexes for table `objektbilder`
--
ALTER TABLE `objektbilder`
  ADD PRIMARY KEY (`bildeID`);

--
-- Indexes for table `objektliste`
--
ALTER TABLE `objektliste`
  ADD PRIMARY KEY (`ListID`),
  ADD KEY `objekter` (`objekter`),
  ADD KEY `Plukker` (`Plukker`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `bedrifter`
--
ALTER TABLE `bedrifter`
  MODIFY `BedriftID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `behandlinger`
--
ALTER TABLE `behandlinger`
  MODIFY `behandlingsID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `bruker`
--
ALTER TABLE `bruker`
  MODIFY `BrukeID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `objekt`
--
ALTER TABLE `objekt`
  MODIFY `ObjektID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `objektbilder`
--
ALTER TABLE `objektbilder`
  MODIFY `bildeID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `objektliste`
--
ALTER TABLE `objektliste`
  MODIFY `ListID` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `bedriftbehandlnger`
--
ALTER TABLE `bedriftbehandlnger`
  ADD CONSTRAINT `bedriftbehandlnger_ibfk_1` FOREIGN KEY (`BedriftID`) REFERENCES `bedrifter` (`BedriftID`),
  ADD CONSTRAINT `bedriftbehandlnger_ibfk_2` FOREIGN KEY (`BehandlingID`) REFERENCES `behandlinger` (`behandlingsID`);

--
-- Constraints for table `objekt`
--
ALTER TABLE `objekt`
  ADD CONSTRAINT `objekt_ibfk_1` FOREIGN KEY (`bildelink`) REFERENCES `objektbilder` (`bildeID`),
  ADD CONSTRAINT `objekt_ibfk_2` FOREIGN KEY (`Behandlingtype`) REFERENCES `behandlinger` (`behandlingsID`);

--
-- Constraints for table `objektliste`
--
ALTER TABLE `objektliste`
  ADD CONSTRAINT `objektliste_ibfk_1` FOREIGN KEY (`objekter`) REFERENCES `objekt` (`ObjektID`),
  ADD CONSTRAINT `objektliste_ibfk_2` FOREIGN KEY (`Plukker`) REFERENCES `bruker` (`BrukeID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
