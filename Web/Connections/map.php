<?php
    include("./map8key.php");
?>
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>初始化地圖 - Map8 Platform Documentation</title>
    <link rel="stylesheet" href="https://api.map8.zone/css/gomp.css?key=<?php echo $map8key; ?>" />
    <style>
        #map{
            height: 400px;
            width: 100%;
        }
    </style>
</head>
<body>
    <div id="map"></div>

    <script type="text/javascript" src="https://api.map8.zone/maps/js/gomp.js?key=<?php echo $map8key; ?>"></script>
    <script type="text/javascript">
        gomp.accessToken = '<?php echo $map8key; ?>';
        var map = new gomp.Map({
            container: 'map',
            style: 'https://api.map8.zone/styles/go-life-maps-tw-style-std/style.json', // 地圖樣式檔案位置
            maxBounds: [[105, 15], [138.45858, 33.4]],
            center: [121.54885, 25.03625],
            zoom: 16,
            minZoom: 6,
            maxZoom: 19.99, 
            attributionControl: false
        }).addControl(new gomp.AttributionControl({
            compact: false
        }));
        map.addControl(new gomp.NavigationControl());
    </script>
</body>
</html>