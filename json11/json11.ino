#include <ArduinoJson.h>
//https://data.moi.gov.tw/MoiOD/System/Principle.aspx?Sample=2
// use above URL to example

const size_t capacity = JSON_ARRAY_SIZE(23) + 23*JSON_OBJECT_SIZE(7);
DynamicJsonDocument doc(capacity);


void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
JsonObject doc_0 = doc.createNestedObject();
doc_0["unit"] = "單位";
doc_0["telephon"] = "電 話";
doc_0["fax"] = "傳 真";
doc_0["address"] = "地 址";
doc_0["website"] = "網址";
doc_0["TgosTWD_X"] = "TgosTWD_X";
doc_0["TgosTWD_Y"] = "TgosTWD_Y";

JsonObject doc_1 = doc.createNestedObject();
doc_1["unit"] = "新北市政府民政局";
doc_1["telephon"] = "02-29603456";
doc_1["fax"] = "02-29693894";
doc_1["address"] = "新北市板橋區中山路1段161號11樓";
doc_1["website"] = "http://www.ca.ntpc.gov.tw/";
doc_1["TgosTWD_X"] = "296995.84";
doc_1["TgosTWD_Y"] = "2767196.5";

JsonObject doc_2 = doc.createNestedObject();
doc_2["unit"] = "臺北市政府兵役局";
doc_2["telephon"] = "02-23654361；02-23654362；02-23654363；02-23654364";
doc_2["fax"] = "02-23673072";
doc_2["address"] = "臺北市中正區羅斯福路四段92號9樓";
doc_2["website"] = "http://www.tcdms.taipei.gov.tw/";
doc_2["TgosTWD_X"] = "303996.47";
doc_2["TgosTWD_Y"] = "2767406.2";

JsonObject doc_3 = doc.createNestedObject();
doc_3["unit"] = "臺中市政府民政局";
doc_3["telephon"] = "04-22289111";
doc_3["fax"] = "04-22202480";
doc_3["address"] = "臺中市臺中港路2段89號6樓";
doc_3["website"] = "http://www.civil.taichung.gov.tw/";
doc_3["TgosTWD_X"] = "214160.3";
doc_3["TgosTWD_Y"] = "2673009.2";

JsonObject doc_4 = doc.createNestedObject();
doc_4["unit"] = "臺南市政府民政局";
doc_4["telephon"] = "06-2991111";
doc_4["fax"] = "06-2982560";
doc_4["address"] = "臺南市安平區永華路2段6號";
doc_4["website"] = "http://www.tainan.gov.tw/agr/default.asp";
doc_4["TgosTWD_X"] = "166419.75";
doc_4["TgosTWD_Y"] = "2543371.8";

JsonObject doc_5 = doc.createNestedObject();
doc_5["unit"] = "高雄市政府兵役局";
doc_5["telephon"] = "07-3373582";
doc_5["fax"] = "07-3312241";
doc_5["address"] = "高雄市苓雅區四維3路2號4樓";
doc_5["website"] = "http://mildp.kcg.gov.tw/index.php";
doc_5["TgosTWD_X"] = "178329.53";
doc_5["TgosTWD_Y"] = "2502050.8";

JsonObject doc_6 = doc.createNestedObject();
doc_6["unit"] = "宜蘭縣政府民政處";
doc_6["telephon"] = "03-9251000#1680；03-9251000#1690";
doc_6["fax"] = "03-9332434";
doc_6["address"] = "宜蘭縣宜蘭市縣政北路1號3樓";
doc_6["website"] = "http://civil.e-land.gov.tw/releaseRedirect.do?unitID=102&pageID=9297";
doc_6["TgosTWD_X"] = "327162.16";
doc_6["TgosTWD_Y"] = "2736149.2";

JsonObject doc_7 = doc.createNestedObject();
doc_7["unit"] = "桃園縣政府民政局";
doc_7["telephon"] = "03-3322101";
doc_7["fax"] = "03-3364817";
doc_7["address"] = "桃園縣桃園市縣府路1號";
doc_7["website"] = "http://cab.tycg.gov.tw/site/ex_bureau_index.aspx?site_id=029";
doc_7["TgosTWD_X"] = "280383.2";
doc_7["TgosTWD_Y"] = "2765042.2";

JsonObject doc_8 = doc.createNestedObject();
doc_8["unit"] = "新竹縣政府民政處";
doc_8["telephon"] = "03-5518101#268";
doc_8["fax"] = "03-5513672";
doc_8["address"] = "新竹縣竹北市光明六路10號";
doc_8["website"] = "http://web.hsinchu.gov.tw/civil/";
doc_8["TgosTWD_X"] = "251305.73";
doc_8["TgosTWD_Y"] = "2746600.8";

JsonObject doc_9 = doc.createNestedObject();
doc_9["unit"] = "苗栗縣政府民政處";
doc_9["telephon"] = "037-322150";
doc_9["fax"] = "037-354593";
doc_9["address"] = "苗栗縣苗栗市縣府路100號";
doc_9["website"] = "http://www.miaoli.gov.tw/civil_affairs/index.php";
doc_9["TgosTWD_X"] = "231846.64";
doc_9["TgosTWD_Y"] = "2717592.8";

JsonObject doc_10 = doc.createNestedObject();
doc_10["unit"] = "彰化縣政府民政處";
doc_10["telephon"] = "04-7222151#0122";
doc_10["fax"] = "04-7293510";
doc_10["address"] = "彰化縣彰化市中山路二段416號7樓";
doc_10["website"] = "http://www.chcg.gov.tw/civil/00home/index1.asp";
doc_10["TgosTWD_X"] = "203707.83";
doc_10["TgosTWD_Y"] = "2663465.2";

JsonObject doc_11 = doc.createNestedObject();
doc_11["unit"] = "南投縣政府民政處";
doc_11["telephon"] = "049-2222106；049-2222107；049-2222108；049-2222109";
doc_11["fax"] = "049-2238404";
doc_11["address"] = "南投縣南投市中興路660號";
doc_11["website"] = "http://www.nantou.gov.tw/big5/index.asp?dptid=376480000AU100000";
doc_11["TgosTWD_X"] = "218455";
doc_11["TgosTWD_Y"] = "2644256";

JsonObject doc_12 = doc.createNestedObject();
doc_12["unit"] = "雲林縣政府民政處";
doc_12["telephon"] = "05-5322154";
doc_12["fax"] = "05-5352041";
doc_12["address"] = "雲林縣斗六市雲林路二段515號";
doc_12["website"] = "http://www4.yunlin.gov.tw/civil/";
doc_12["TgosTWD_X"] = "201694.66";
doc_12["TgosTWD_Y"] = "2621765";

JsonObject doc_13 = doc.createNestedObject();
doc_13["unit"] = "嘉義縣政府民政處";
doc_13["telephon"] = "05-3620123#460；05-3620123#461";
doc_13["fax"] = "05-3620399";
doc_13["address"] = "嘉義縣太保市祥和新村祥和一路東段1號";
doc_13["website"] = "http://www1.cyhg.gov.tw/civil/chinese/";
doc_13["TgosTWD_X"] = "";
doc_13["TgosTWD_Y"] = "";

JsonObject doc_14 = doc.createNestedObject();
doc_14["unit"] = "屏東縣政府民政處";
doc_14["telephon"] = "08-7324147";
doc_14["fax"] = "08-7331538";
doc_14["address"] = "屏東縣屏東市自由路527號";
doc_14["website"] = "http://www.pthg.gov.tw/plancab/Index.aspx";
doc_14["TgosTWD_X"] = "197386.9";
doc_14["TgosTWD_Y"] = "2509263";

JsonObject doc_15 = doc.createNestedObject();
doc_15["unit"] = "臺東縣政府民政處";
doc_15["telephon"] = "089-326141";
doc_15["fax"] = "089-340560";
doc_15["address"] = "台東縣台東市中山路276號";
doc_15["website"] = "http://www.taitung.gov.tw/Civil/index.aspx";
doc_15["TgosTWD_X"] = "265435.62";
doc_15["TgosTWD_Y"] = "2517223.5";

JsonObject doc_16 = doc.createNestedObject();
doc_16["unit"] = "花蓮縣政府民政處";
doc_16["telephon"] = "03-8232047；03-8221894#374；03-8221894#375";
doc_16["fax"] = "03-8230576";
doc_16["address"] = "花蓮縣花蓮市府後路6號";
doc_16["website"] = "http://ca.hl.gov.tw/bin/home.php";
doc_16["TgosTWD_X"] = "312974.72";
doc_16["TgosTWD_Y"] = "2654109";

JsonObject doc_17 = doc.createNestedObject();
doc_17["unit"] = "澎湖縣政府民政處";
doc_17["telephon"] = "06-9274400";
doc_17["fax"] = "06-9274701";
doc_17["address"] = "澎湖縣馬公市治平路32號";
doc_17["website"] = "http://www.penghu.gov.tw/civil/";
doc_17["TgosTWD_X"] = "103661.375";
doc_17["TgosTWD_Y"] = "2608175";

JsonObject doc_18 = doc.createNestedObject();
doc_18["unit"] = "基隆市政府民政處";
doc_18["telephon"] = "02-24201122#2304；02-24201122#2305；02-24201122#2306；02-24201122#2307；02-24201122#2308；02-24201122#2309；02-24201122#2310；02-24201122#2311";
doc_18["fax"] = "02-24668739";
doc_18["address"] = "基隆市中正區正信路205號2樓";
doc_18["website"] = "http://www.klcg.gov.tw/civil/";
doc_18["TgosTWD_X"] = "326702.88";
doc_18["TgosTWD_Y"] = "2781832.5";

JsonObject doc_19 = doc.createNestedObject();
doc_19["unit"] = "新竹市政府民政處";
doc_19["telephon"] = "03-5216121#314；03-5216121#315；03-5216121#316；03-5216121#317；03-5216121#318；03-5216121#319";
doc_19["fax"] = "03-5214703";
doc_19["address"] = "新竹市中正路120號";
doc_19["website"] = "http://dep-civil.hccg.gov.tw/web/Home?FP=1064";
doc_19["TgosTWD_X"] = "246852.16";
doc_19["TgosTWD_Y"] = "2744373.2";

JsonObject doc_20 = doc.createNestedObject();
doc_20["unit"] = "嘉義市政府民政處";
doc_20["telephon"] = "05-2254321";
doc_20["fax"] = "05-2259885";
doc_20["address"] = "嘉義市中山路199號";
doc_20["website"] = "http://www.chiayi.gov.tw/web/civil/index.asp";
doc_20["TgosTWD_X"] = "194178.02";
doc_20["TgosTWD_Y"] = "2597686.8";

JsonObject doc_21 = doc.createNestedObject();
doc_21["unit"] = "金門縣政府民政局";
doc_21["telephon"] = "082-325753";
doc_21["fax"] = "082-322613";
doc_21["address"] = "金門縣金城鎮民生路60號";
doc_21["website"] = "http://www.kinmen.gov.tw/Layout/sub_A/index.aspx?frame=3";
doc_21["TgosTWD_X"] = "-21896.012";
doc_21["TgosTWD_Y"] = "2706070";

JsonObject doc_22 = doc.createNestedObject();
doc_22["unit"] = "連江縣政府民政局";
doc_22["telephon"] = "0836-22485";
doc_22["fax"] = "0836-22209";
doc_22["address"] = "連江縣南竿鄉介壽村76號";
doc_22["website"] = "http://www.matsu.gov.tw/2008web/governor_index.php?id=civilaffairbureau";
doc_22["TgosTWD_X"] = "145745.47";
doc_22["TgosTWD_Y"] = "2894431";

serializeJson(doc, Serial);

}

void loop() {
  // put your main code here, to run repeatedly:

}
