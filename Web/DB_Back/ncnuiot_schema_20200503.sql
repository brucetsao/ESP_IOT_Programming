-- phpMyAdmin SQL Dump
-- version 4.8.2
-- https://www.phpmyadmin.net/
--
-- 主機: localhost
-- 產生時間： 2020 年 05 月 03 日 17:26
-- 伺服器版本: 5.5.57-MariaDB
-- PHP 版本： 5.6.31

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- 資料庫： `ncnuiot`
--

-- --------------------------------------------------------

--
-- 資料表結構 `area`
--

CREATE TABLE `area` (
  `mid` int(11) NOT NULL COMMENT '主鍵',
  `sysdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `areaid` varchar(16) CHARACTER SET ascii NOT NULL COMMENT '區域代碼',
  `areaname` varchar(50) NOT NULL COMMENT '區域名稱'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `coutytbl`
--

CREATE TABLE `coutytbl` (
  `cid` varchar(14) CHARACTER SET ascii NOT NULL COMMENT '縣市ID',
  `cname` varchar(40) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '	縣市名稱'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `cwbsite`
--

CREATE TABLE `cwbsite` (
  `id` int(11) NOT NULL DEFAULT '0' COMMENT '主鍵',
  `dataorder` varchar(14) NOT NULL COMMENT '時間維度',
  `sysdatetime` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00' COMMENT '資料更新時間',
  `sid` varchar(20) NOT NULL COMMENT '站台ID',
  `sname` varchar(60) DEFAULT NULL COMMENT '站台名稱',
  `sdatetime` datetime NOT NULL COMMENT '資料時間',
  `lat` double NOT NULL COMMENT '緯度',
  `lon` double NOT NULL COMMENT '經度',
  `hight` int(11) NOT NULL COMMENT '海拔',
  `wdir` int(11) NOT NULL COMMENT '風向',
  `wspeed` int(11) NOT NULL COMMENT '風速',
  `temp` double NOT NULL COMMENT '溫度',
  `humid` double NOT NULL COMMENT '濕度',
  `bar` double NOT NULL COMMENT '氣壓',
  `rain` double NOT NULL COMMENT '雨量',
  `cid` varchar(14) NOT NULL COMMENT '縣市ID',
  `cname` varchar(40) DEFAULT NULL COMMENT '縣市名稱',
  `tid` varchar(14) NOT NULL COMMENT '鄉鎮ID',
  `tname` varchar(60) DEFAULT NULL COMMENT '鄉鎮名稱'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `data`
--

CREATE TABLE `data` (
  `ID` int(11) NOT NULL,
  `MAC` varchar(12) NOT NULL,
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `utime` varchar(14) NOT NULL,
  `temp` float DEFAULT NULL COMMENT '温度',
  `humid` float DEFAULT NULL COMMENT '湿度',
  `lat` double NOT NULL,
  `long` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `device`
--

CREATE TABLE `device` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `deviceid` varchar(16) CHARACTER SET ascii NOT NULL,
  `devicename` varchar(40) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `address` varchar(200) NOT NULL,
  `longitude` double NOT NULL COMMENT '經度',
  `latitude` double NOT NULL COMMENT '緯度',
  `mac` varchar(12) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `dht`
--

CREATE TABLE `dht` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置MAC值',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `temperature` float NOT NULL COMMENT '使用者更新',
  `humidity` float NOT NULL COMMENT '濕度',
  `systime` varchar(14) CHARACTER SET ascii NOT NULL COMMENT '使用者更新時間'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `dhtData`
--

CREATE TABLE `dhtData` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `MAC` varchar(12) NOT NULL COMMENT '裝置MAC值',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `temperature` float NOT NULL COMMENT '溫度',
  `humidity` float NOT NULL COMMENT '濕度',
  `systime` varchar(14) NOT NULL COMMENT '使用者更新時間'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `environment`
--

CREATE TABLE `environment` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `dataorder` varchar(14) NOT NULL COMMENT '時間維度',
  `sysdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料更新時間',
  `sid` varchar(20) NOT NULL COMMENT '站台ID',
  `sname` varchar(60) DEFAULT NULL COMMENT '站台名稱',
  `sdatetime` datetime NOT NULL COMMENT '資料時間',
  `lat` double NOT NULL COMMENT '緯度',
  `lon` double NOT NULL COMMENT '經度',
  `hight` int(11) NOT NULL COMMENT '海拔',
  `wdir` int(11) NOT NULL COMMENT '風向',
  `wspeed` int(11) NOT NULL COMMENT '風速',
  `temp` double NOT NULL COMMENT '溫度',
  `humid` double NOT NULL COMMENT '濕度',
  `bar` double NOT NULL COMMENT '氣壓',
  `rain` double NOT NULL COMMENT '雨量',
  `cid` varchar(14) NOT NULL COMMENT '縣市ID',
  `cname` varchar(40) DEFAULT NULL COMMENT '縣市名稱',
  `tid` varchar(14) NOT NULL COMMENT '鄉鎮ID',
  `tname` varchar(60) DEFAULT NULL COMMENT '鄉鎮名稱'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `particle`
--

CREATE TABLE `particle` (
  `id` int(11) NOT NULL,
  `mac` varchar(12) NOT NULL COMMENT '網路卡號',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料時間',
  `pm1` double NOT NULL COMMENT 'pm1.0',
  `pm25` double NOT NULL COMMENT 'pm2.5',
  `pm10` double NOT NULL COMMENT 'pm10',
  `temperature` double NOT NULL COMMENT '溫度',
  `humidity` double NOT NULL COMMENT '濕度',
  `updatetime` varchar(12) NOT NULL COMMENT '每分鐘統計'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `pmdevice`
--

CREATE TABLE `pmdevice` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `status` varchar(1) NOT NULL COMMENT '狀態',
  `sysdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料更新時間',
  `mac` varchar(12) CHARACTER SET ascii NOT NULL COMMENT '裝置mac',
  `deviceid` varchar(12) CHARACTER SET ascii NOT NULL COMMENT '裝置號碼',
  `devicename` varchar(25) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '裝置名稱',
  `deviceaddr` varchar(250) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '裝置所在地住址',
  `longitude` double NOT NULL COMMENT '經度',
  `latitude` double NOT NULL COMMENT '緯度',
  `areaid` varchar(16) CHARACTER SET ascii DEFAULT NULL COMMENT '偵測區域'
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='蚊子機裝機所在地';

-- --------------------------------------------------------

--
-- 資料表結構 `rfidreader`
--

CREATE TABLE `rfidreader` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '系統時間',
  `mac` varchar(12) NOT NULL COMMENT '網路卡編號',
  `cardnumber` varchar(10) NOT NULL COMMENT 'RFID卡號',
  `inputdatetime` datetime NOT NULL COMMENT '資料輸入時間'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `rfidreader03`
--

CREATE TABLE `rfidreader03` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '系統時間',
  `mac` varchar(12) NOT NULL COMMENT '網路卡編號',
  `cardnumber` varchar(10) NOT NULL COMMENT 'RFID卡號',
  `inputdatetime` datetime NOT NULL COMMENT '資料輸入時間'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `rfidreader04`
--

CREATE TABLE `rfidreader04` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '系統時間',
  `mac` varchar(12) NOT NULL COMMENT '網路卡編號',
  `cardnumber` varchar(10) NOT NULL COMMENT 'RFID卡號',
  `inputdatetime` datetime NOT NULL COMMENT '資料輸入時間'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `rfidreader05`
--

CREATE TABLE `rfidreader05` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '系統時間',
  `mac` varchar(12) NOT NULL COMMENT '網路卡編號',
  `cardnumber` varchar(10) NOT NULL COMMENT 'RFID卡號',
  `inputdatetime` datetime NOT NULL COMMENT '資料輸入時間'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `rfidreader06`
--

CREATE TABLE `rfidreader06` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '系統時間',
  `mac` varchar(12) NOT NULL COMMENT '網路卡編號',
  `cardnumber` varchar(10) NOT NULL COMMENT 'RFID卡號',
  `inputdatetime` datetime NOT NULL COMMENT '資料輸入時間'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `rfidreader07`
--

CREATE TABLE `rfidreader07` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `crtdatetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '系統時間',
  `mac` varchar(12) NOT NULL COMMENT '網路卡編號',
  `cardnumber` varchar(10) NOT NULL COMMENT 'RFID卡號',
  `inputdatetime` datetime NOT NULL COMMENT '資料輸入時間'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 資料表結構 `t0_dhtdata`
--

CREATE TABLE `t0_dhtdata` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置MAC值',
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `utime` varchar(14) NOT NULL COMMENT '使用者輸入時間',
  `temp` float NOT NULL COMMENT '溫度',
  `humid` float NOT NULL COMMENT '濕度',
  `lat` double NOT NULL COMMENT ' latitude(緯度)',
  `longi` double NOT NULL COMMENT ' longitude(經度)'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t1_dhtdata`
--

CREATE TABLE `t1_dhtdata` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置MAC值',
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `utime` varchar(14) NOT NULL COMMENT '使用者輸入時間',
  `temp` float NOT NULL COMMENT '溫度',
  `humid` float NOT NULL COMMENT '濕度',
  `lat` double NOT NULL COMMENT 'latitude(緯度)',
  `longi` double NOT NULL COMMENT 'longitude(經度)'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t2_dhtdata`
--

CREATE TABLE `t2_dhtdata` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置MAC',
  `systime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `utime` varchar(14) NOT NULL COMMENT '使用者輸入時間',
  `temp` float NOT NULL COMMENT '溫度',
  `humid` float NOT NULL COMMENT '濕度',
  `lat` float NOT NULL COMMENT 'latitude(緯度)',
  `longi` float NOT NULL COMMENT 'longitude(經度)'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t3_dhtdata`
--

CREATE TABLE `t3_dhtdata` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置mac值',
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `utime` varchar(14) NOT NULL COMMENT '使用者輸入時間',
  `temp` float NOT NULL COMMENT '溫度',
  `humid` float NOT NULL COMMENT '濕度',
  `lat` double NOT NULL COMMENT 'latitude(緯度)',
  `longi` double NOT NULL COMMENT 'longtitude(經度)'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t4_dhtdata`
--

CREATE TABLE `t4_dhtdata` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置mac值',
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `utime` varchar(14) NOT NULL COMMENT '使用者輸入時間',
  `temp` float NOT NULL COMMENT '溫度',
  `humid` float NOT NULL COMMENT '濕度',
  `lat` double NOT NULL COMMENT 'latitude(緯度)',
  `longi` double NOT NULL COMMENT 'longitude(經度)'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t5_dhtdata`
--

CREATE TABLE `t5_dhtdata` (
  `id` int(11) NOT NULL,
  `mac` varchar(12) NOT NULL,
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `utime` varchar(14) NOT NULL,
  `temp` float NOT NULL,
  `humid` float NOT NULL,
  `lat` double DEFAULT NULL,
  `longi` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t6_dhtdata`
--

CREATE TABLE `t6_dhtdata` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置mac值',
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `utime` varchar(14) NOT NULL COMMENT '使用者資料輸入時間',
  `temp` float NOT NULL COMMENT '溫度',
  `humid` float NOT NULL COMMENT '濕度',
  `lat` double NOT NULL COMMENT 'latitude(緯度',
  `longi` double NOT NULL COMMENT 'longitude(經度'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t7_dhtdata`
--

CREATE TABLE `t7_dhtdata` (
  `id` int(11) NOT NULL,
  `mac` varchar(12) NOT NULL,
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `utime` varchar(14) NOT NULL,
  `temp` float NOT NULL,
  `humid` float NOT NULL,
  `lat` double NOT NULL,
  `longi` double NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `t8_dhtdata`
--

CREATE TABLE `t8_dhtdata` (
  `id` int(11) NOT NULL COMMENT '主鍵',
  `mac` varchar(12) NOT NULL COMMENT '裝置MAC值',
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '資料輸入時間',
  `utime` varchar(14) NOT NULL COMMENT '使用者輸入時間',
  `temp` float NOT NULL COMMENT 'temp',
  `humid` float NOT NULL COMMENT 'humid',
  `lat` double NOT NULL COMMENT 'latitude',
  `longi` double NOT NULL COMMENT 'longitude'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `test`
--

CREATE TABLE `test` (
  `id` int(11) NOT NULL,
  `mac` varchar(12) NOT NULL,
  `systemtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `utime` varchar(14) NOT NULL,
  `temp` float NOT NULL,
  `humid` float NOT NULL,
  `lat` int(11) NOT NULL COMMENT 'latitude(緯度)',
  `longi` double NOT NULL COMMENT 'longitude(經度)'
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- 資料表結構 `towntbl`
--

CREATE TABLE `towntbl` (
  `tid` varchar(14) CHARACTER SET ascii NOT NULL COMMENT '鄉鎮ID',
  `tname` varchar(60) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '鄉鎮名稱',
  `cid` varchar(14) CHARACTER SET ascii NOT NULL COMMENT '縣市ID',
  `cname` varchar(40) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '縣市名稱'
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- 已匯出資料表的索引
--

--
-- 資料表索引 `area`
--
ALTER TABLE `area`
  ADD PRIMARY KEY (`mid`),
  ADD UNIQUE KEY `areaid` (`areaid`);

--
-- 資料表索引 `coutytbl`
--
ALTER TABLE `coutytbl`
  ADD PRIMARY KEY (`cid`);

--
-- 資料表索引 `cwbsite`
--
ALTER TABLE `cwbsite`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `sid` (`sid`);

--
-- 資料表索引 `data`
--
ALTER TABLE `data`
  ADD PRIMARY KEY (`ID`);

--
-- 資料表索引 `device`
--
ALTER TABLE `device`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `mac` (`mac`);

--
-- 資料表索引 `dht`
--
ALTER TABLE `dht`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `dhtData`
--
ALTER TABLE `dhtData`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `environment`
--
ALTER TABLE `environment`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `checkduplicate` (`sid`,`sdatetime`);

--
-- 資料表索引 `particle`
--
ALTER TABLE `particle`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `pmdevice`
--
ALTER TABLE `pmdevice`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `checkid` (`deviceid`,`status`),
  ADD KEY `deviceid` (`deviceid`) USING BTREE,
  ADD KEY `mac` (`mac`) USING BTREE;

--
-- 資料表索引 `rfidreader`
--
ALTER TABLE `rfidreader`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `rfidreader03`
--
ALTER TABLE `rfidreader03`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `rfidreader04`
--
ALTER TABLE `rfidreader04`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `rfidreader05`
--
ALTER TABLE `rfidreader05`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `rfidreader06`
--
ALTER TABLE `rfidreader06`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `rfidreader07`
--
ALTER TABLE `rfidreader07`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `t0_dhtdata`
--
ALTER TABLE `t0_dhtdata`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `t1_dhtdata`
--
ALTER TABLE `t1_dhtdata`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `t3_dhtdata`
--
ALTER TABLE `t3_dhtdata`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `t4_dhtdata`
--
ALTER TABLE `t4_dhtdata`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `t6_dhtdata`
--
ALTER TABLE `t6_dhtdata`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `t7_dhtdata`
--
ALTER TABLE `t7_dhtdata`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `t8_dhtdata`
--
ALTER TABLE `t8_dhtdata`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `test`
--
ALTER TABLE `test`
  ADD PRIMARY KEY (`id`);

--
-- 資料表索引 `towntbl`
--
ALTER TABLE `towntbl`
  ADD PRIMARY KEY (`tid`);

--
-- 在匯出的資料表使用 AUTO_INCREMENT
--

--
-- 使用資料表 AUTO_INCREMENT `data`
--
ALTER TABLE `data`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- 使用資料表 AUTO_INCREMENT `device`
--
ALTER TABLE `device`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `dht`
--
ALTER TABLE `dht`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `dhtData`
--
ALTER TABLE `dhtData`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `environment`
--
ALTER TABLE `environment`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `particle`
--
ALTER TABLE `particle`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- 使用資料表 AUTO_INCREMENT `rfidreader`
--
ALTER TABLE `rfidreader`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `rfidreader03`
--
ALTER TABLE `rfidreader03`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `rfidreader04`
--
ALTER TABLE `rfidreader04`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `rfidreader05`
--
ALTER TABLE `rfidreader05`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `rfidreader06`
--
ALTER TABLE `rfidreader06`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `rfidreader07`
--
ALTER TABLE `rfidreader07`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `t0_dhtdata`
--
ALTER TABLE `t0_dhtdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `t1_dhtdata`
--
ALTER TABLE `t1_dhtdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `t3_dhtdata`
--
ALTER TABLE `t3_dhtdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `t4_dhtdata`
--
ALTER TABLE `t4_dhtdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `t6_dhtdata`
--
ALTER TABLE `t6_dhtdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';

--
-- 使用資料表 AUTO_INCREMENT `t7_dhtdata`
--
ALTER TABLE `t7_dhtdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- 使用資料表 AUTO_INCREMENT `t8_dhtdata`
--
ALTER TABLE `t8_dhtdata`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '主鍵';
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
