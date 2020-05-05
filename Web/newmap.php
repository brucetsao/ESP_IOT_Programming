
    <script type="text/javascript" src="https://api.map8.zone/maps/js/gomp.js?key=<?php echo $map8key; ?>"></script>
    <script type="text/javascript">
        gomp.accessToken = "<?php echo $map8key; ?>";
        var map = new gomp.Map({
            container: 'map', // 地圖容器 ID
            style: 'https://api.map8.zone/styles/go-life-maps-tw-style-std/style.json', // 地圖樣式檔案位置
            maxBounds: [[105, 15], [138.45858, 33.4]], // 台灣地圖區域
            center: [120.854326,23.791066], // 初始中心座標，格式為 [lng, lat]
            zoom: 7 , // 初始 ZOOM LEVEL; [0-20, 0 為最小 (遠), 20 ;最大 (近)]
            minZoom: 6, // 限制地圖可縮放之最小等級, 可省略, [0-19.99]
            maxZoom: 19.99, // 限制地圖可縮放之最大等級, 可省略 [0-19.99]
            speedLoad: false,
            attributionControl: false
        }).addControl(new gomp.AttributionControl({
            compact: false
        }));
        map.addControl(new gomp.NavigationControl());

        // 引入資料 (可用 PHP 生成)
        // 其中仍有幾筆是重複座標，這樣仍會造成重疊問題，以致於點擊圓圈後出現的數值不一致
        var cwbdata = <?php include('./gencwball.php'); ?>	;
 //       var data = <?php include('./genparticle.php'); ?>	;
			
            var popup = new gomp.Popup({
                anchor: 'bottom',
                closeButton: true,
                closeOnClick: false,
                offset: [0, -20]
            });

                // 新增類別為 circle 之圖層


                //-------------------------------------
                map.addLayer(
                    {
                        'id': 'bar',
                        'type': 'circle',
                        'source': 'cwbvalue',
                        'paint': {
                            // 依據地圖 zoom 值動態改變 circle-blur (模糊程度) 之值
                            'circle-blur': [
                                'interpolate',
                                ['linear'],
                                ['zoom'],
                                6, 2, // zoom 為 6 時，circle-blur 為 2
                                20, 1 // zoom 為 20 時，circle-blur 為 1
                            ],
                            // 依據各點 property 內容改變 circle-color (各點顏色) 之值；此處以溫度為例
                            'circle-color': [
                                'interpolate',
                                ['linear'],
                                ['get', 'bar'],
                                // 由溫度 (temperature) 為 0 開始，設定每個區段的顏色
                                1000, 'rgb(0, 234, 255)',
                                1010, 'rgb(10, 255, 0)',
                                1020, 'rgb(160, 255, 0)',
                                1030, 'rgb(255, 190, 0)',
                                1040, 'rgb(255, 120, 0)',
                                1050, 'rgb(255, 81, 0)'
                            ],
                            // 依據地圖 zoom 值改變 circle-radius (圓點尺寸) 之值
                            'circle-radius': [
                                'interpolate',
                                ['linear'],
                                ['zoom'],
                                6, 20, // zoom 為 6 時，circle-radius 為 20
                                7, 25, // zoom 為 7 時，circle-radius 為 25
                                18, 250 // zoom 大於等於 19 時，circle-radius 固定為 250
                            ]
                        }
                    });




                //-------------------------------------

                map.addLayer(
                    {
                        'id': 'humid',
                        'type': 'circle',
                        'source': 'cwbvalue',
                        'paint': {
                            // 依據地圖 zoom 值動態改變 circle-blur (模糊程度) 之值
                            'circle-blur': [
                                'interpolate',
                                ['linear'],
                                ['zoom'],
                                6, 2, // zoom 為 6 時，circle-blur 為 2
                                20, 1 // zoom 為 20 時，circle-blur 為 1
                            ],
                            // 依據各點 property 內容改變 circle-color (各點顏色) 之值；此處以溫度為例
                            'circle-color': [
                                'interpolate',
                                ['linear'],
                                ['get', 'humid'],
                                // 由溫度 (temperature) 為 0 開始，設定每個區段的顏色
                                40, 'rgb(0, 234, 255)',
                                50, 'rgb(10, 255, 0)',
                                60, 'rgb(160, 255, 0)',
                                70, 'rgb(255, 190, 0)',
                                80, 'rgb(255, 120, 0)',
                                90, 'rgb(255, 81, 0)'
                            ],
                            // 依據地圖 zoom 值改變 circle-radius (圓點尺寸) 之值
                            'circle-radius': [
                                'interpolate',
                                ['linear'],
                                ['zoom'],
                                6, 20, // zoom 為 6 時，circle-radius 為 20
                                7, 25, // zoom 為 7 時，circle-radius 為 25
                                18, 250 // zoom 大於等於 19 時，circle-radius 固定為 250
                            ]
                        }
                    });
                //---------------------------------------------
                map.addLayer(
                    {
                        'id': 'temp',
                        'type': 'circle',
                        'source': 'cwbvalue',
                        'paint': {
                            // 依據地圖 zoom 值動態改變 circle-blur (模糊程度) 之值
                            'circle-blur': [
                                'interpolate',
                                ['linear'],
                                ['zoom'],
                                6, 2, // zoom 為 6 時，circle-blur 為 2
                                20, 1 // zoom 為 20 時，circle-blur 為 1
                            ],
                            // 依據各點 property 內容改變 circle-color (各點顏色) 之值；此處以溫度為例
                            'circle-color': [
                                'interpolate',
                                ['linear'],
                                ['get', 'temp'],
                                // 由溫度 (temperature) 為 0 開始，設定每個區段的顏色
                                -1, 'rgb(16, 115, 136)',
                                1, 'rgb(31, 126, 148)',
                                5, 'rgb(93, 168, 189)',
                                11, 'rgb(180, 233, 247)',
                                15, 'rgb(63, 169, 94)',
                                21, 'rgb(164, 218, 132)',
                                25, 'rgb(244, 243, 197)',
                                27, 'rgb(243, 213, 117)',
                                29, 'rgb(239, 117, 76)',
                                31, 'rgb(223, 124, 7)',
                                33, 'rgb(241, 21, 93)',
                                35, 'rgb(118, 2, 2)',
                                37, 'rgb(155, 104, 173)',
                                38, 'rgb(113, 79, 154)',
                                39, 'rgb(125, 41, 155)'
                            ],
                            // 依據地圖 zoom 值改變 circle-radius (圓點尺寸) 之值
                            'circle-radius': [
                                'interpolate',
                                ['linear'],
                                ['zoom'],
                                6, 20, // zoom 為 6 時，circle-radius 為 20
                                7, 25, // zoom 為 7 時，circle-radius 為 25
                                18, 250 // zoom 大於等於 19 時，circle-radius 固定為 250
                            ]
                        }
                    }
                );
                //-------------------------------------
                map.addLayer({
                    'id': 'rain',
                    'type': 'circle',
                    'source': 'cwbvalue',
                    'paint': {
                        // 依據地圖 zoom 值動態改變 circle-blur (模糊程度) 之值
                        'circle-blur': [
                            'interpolate',
                            ['linear'],
                            ['zoom'],
                            6, 2, // zoom 為 6 時，circle-blur 為 2
                            20, 1 // zoom 為 20 時，circle-blur 為 1
                        ],
                        // 依據各點 property 內容改變 circle-color (各點顏色) 之值；此處以溫度為例
                        'circle-color': [
                            'interpolate',
                            ['linear'],
                            ['get', 'rain'],
                            // 由溫度 (temperature) 為 0 開始，設定每個區段的顏色
                            0, 'rgb(202, 202, 202)',
                            1, 'rgb(158, 253,255 )',
                            6, 'rgb(1, 210, 202)',
                            10, 'rgb(0, 165, 254)',
                            20, 'rgb(38, 163, 27)',
                            40, 'rgb(254, 253, 21)',
                            70, 'rgb(255, 167, 31)',
                            110, 'rgb(218, 35, 4)',
                            150, 'rgb(172, 32, 163)',
                            200, 'rgb(220, 45, 210)',
                            300, 'rgb(255, 56, 251)'
                        ],
                        // 依據地圖 zoom 值改變 circle-radius (圓點尺寸) 之值
                        'circle-radius': [
                            'interpolate',
                            ['linear'],
                            ['zoom'],
                            6, 20, // zoom 為 6 時，circle-radius 為 20
                            7, 25, // zoom 為 7 時，circle-radius 為 25
                            18, 250 // zoom 大於等於 19 時，circle-radius 固定為 250
                        ]
                    }
                })


                //-----------------
                map.addLayer(
                    {
                        "id": "circles",
                        "type": "circle",
                        "source": 'mosvalue',
                        "paint":
                        {
                            "circle-radius": 20,
                            "circle-color": "#fff",
                            "circle-stroke-width": 3,
                            "circle-stroke-color": [
                                'match',
                                ['get', 'species'],
                                'AEDES', '#c00', // 埃及斑蚊
                                '#1dc400' // 其他類型
                            ]
                        }
                    });

                //-----------------
                map.addLayer({
                    "id": "numbers",
                    "type": "symbol",
                    "source": 'mosvalue',
                    "layout":
                    {
                        "text-field": "{amount}",
                        "text-size": 16,
                        "text-font": ["Noto Sans Regular"] // 此行不可變動
                    }
                });

                map.on('click', 'circles', function (e) {
                    // 設定滑鼠游標樣式
                    map.getCanvas().style.cursor = 'pointer';

                    var coordinates = e.features[0].geometry.coordinates.slice();
                    var description = e.features[0].properties.title;

                    // 確保訊息視窗不會被遮擋
                    while (Math.abs(e.lngLat.lng - coordinates[0]) > 180) {
                        coordinates[0] += e.lngLat.lng > coordinates[0] ? 360 : -360;
                    }

                    // 設定訊息視窗內容並在地圖上顯示
                    popup.setLngLat(coordinates)
                        .setHTML(description)
                        .addTo(map);
                });
            });

            map.once('idle', function () {
                map.moveLayer('circles');
                map.moveLayer('numbers');
                // 新增 Filter，先設定只顯示「AEDES」
                map.setFilter('circles', ['==', 'species', 'AEDES']);
                map.setFilter('numbers', ['==', 'species', 'AEDES']);
                // 切換選項按鈕
                document.getElementsByName('switch').forEach((input) => {
                    input.addEventListener("change", function (event) {
                        let val = event.target.value;
                        map.setFilter('circles', ['==', 'species', val]);
                        map.setFilter('numbers', ['==', 'species', val]);
                        // 加上底下這一行
                        popup.remove();
                    })
                });
                var toggleableLayerIds = ['rain', 'temp', 'humid'];
                var cwbRadioInputs = document.getElementsByName('cwb')
                for (var i = 0; i < cwbRadioInputs.length; ++i) {
                    cwbRadioInputs[i].addEventListener('change', function(event) {
                        var inputValue = event.target.value
                        for(var j = 0; j < toggleableLayerIds.length; ++j) {
                            if (toggleableLayerIds[j] == inputValue) {
                                map.setLayoutProperty(toggleableLayerIds[j], 'visibility', 'visible')
                            }
                            else {
                                map.setLayoutProperty(toggleableLayerIds[j], 'visibility', 'none')
                            }
                        }
                    })
                }

            });
        </script>