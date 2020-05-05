#include <ArduinoJson.h>
//https://data.moi.gov.tw/MoiOD/System/Principle.aspx?Sample=2
// use above URL to example
const size_t capacity = JSON_ARRAY_SIZE(23) + 23*JSON_OBJECT_SIZE(7) + 4460;
DynamicJsonDocument doc(capacity);

const char* json = "[{\"unit\":\"單位\",\"telephon\":\"電 話\",\"fax\":\"傳 真\",\"address\":\"地 址\",\"website\":\"網址\",\"TgosTWD_X\":\"TgosTWD_X\",\"TgosTWD_Y\":\"TgosTWD_Y\"},{\"unit\":\"新北市政府民政局\",\"telephon\":\"02-29603456\",\"fax\":\"02-29693894\",\"address\":\"新北市板橋區中山路1段161號11樓\",\"website\":\"http://www.ca.ntpc.gov.tw/\",\"TgosTWD_X\":\"296995.84\",\"TgosTWD_Y\":\"2767196.5\"},{\"unit\":\"臺北市政府兵役局\",\"telephon\":\"02-23654361；02-23654362；02-23654363；02-23654364\",\"fax\":\"02-23673072\",\"address\":\"臺北市中正區羅斯福路四段92號9樓\",\"website\":\"http://www.tcdms.taipei.gov.tw/\",\"TgosTWD_X\":\"303996.47\",\"TgosTWD_Y\":\"2767406.2\"},{\"unit\":\"臺中市政府民政局\",\"telephon\":\"04-22289111\",\"fax\":\"04-22202480\",\"address\":\"臺中市臺中港路2段89號6樓\",\"website\":\"http://www.civil.taichung.gov.tw/\",\"TgosTWD_X\":\"214160.3\",\"TgosTWD_Y\":\"2673009.2\"},{\"unit\":\"臺南市政府民政局\",\"telephon\":\"06-2991111\",\"fax\":\"06-2982560\",\"address\":\"臺南市安平區永華路2段6號\",\"website\":\"http://www.tainan.gov.tw/agr/default.asp\",\"TgosTWD_X\":\"166419.75\",\"TgosTWD_Y\":\"2543371.8\"},{\"unit\":\"高雄市政府兵役局\",\"telephon\":\"07-3373582\",\"fax\":\"07-3312241\",\"address\":\"高雄市苓雅區四維3路2號4樓\",\"website\":\"http://mildp.kcg.gov.tw/index.php\",\"TgosTWD_X\":\"178329.53\",\"TgosTWD_Y\":\"2502050.8\"},{\"unit\":\"宜蘭縣政府民政處\",\"telephon\":\"03-9251000#1680；03-9251000#1690\",\"fax\":\"03-9332434\",\"address\":\"宜蘭縣宜蘭市縣政北路1號3樓\",\"website\":\"http://civil.e-land.gov.tw/releaseRedirect.do?unitID=102&pageID=9297\",\"TgosTWD_X\":\"327162.16\",\"TgosTWD_Y\":\"2736149.2\"},{\"unit\":\"桃園縣政府民政局\",\"telephon\":\"03-3322101\",\"fax\":\"03-3364817\",\"address\":\"桃園縣桃園市縣府路1號\",\"website\":\"http://cab.tycg.gov.tw/site/ex_bureau_index.aspx?site_id=029\",\"TgosTWD_X\":\"280383.2\",\"TgosTWD_Y\":\"2765042.2\"},{\"unit\":\"新竹縣政府民政處\",\"telephon\":\"03-5518101#268\",\"fax\":\"03-5513672\",\"address\":\"新竹縣竹北市光明六路10號\",\"website\":\"http://web.hsinchu.gov.tw/civil/\",\"TgosTWD_X\":\"251305.73\",\"TgosTWD_Y\":\"2746600.8\"},{\"unit\":\"苗栗縣政府民政處\",\"telephon\":\"037-322150\",\"fax\":\"037-354593\",\"address\":\"苗栗縣苗栗市縣府路100號\",\"website\":\"http://www.miaoli.gov.tw/civil_affairs/index.php\",\"TgosTWD_X\":\"231846.64\",\"TgosTWD_Y\":\"2717592.8\"},{\"unit\":\"彰化縣政府民政處\",\"telephon\":\"04-7222151#0122\",\"fax\":\"04-7293510\",\"address\":\"彰化縣彰化市中山路二段416號7樓\",\"website\":\"http://www.chcg.gov.tw/civil/00home/index1.asp\",\"TgosTWD_X\":\"203707.83\",\"TgosTWD_Y\":\"2663465.2\"},{\"unit\":\"南投縣政府民政處\",\"telephon\":\"049-2222106；049-2222107；049-2222108；049-2222109\",\"fax\":\"049-2238404\",\"address\":\"南投縣南投市中興路660號\",\"website\":\"http://www.nantou.gov.tw/big5/index.asp?dptid=376480000AU100000\",\"TgosTWD_X\":\"218455\",\"TgosTWD_Y\":\"2644256\"},{\"unit\":\"雲林縣政府民政處\",\"telephon\":\"05-5322154\",\"fax\":\"05-5352041\",\"address\":\"雲林縣斗六市雲林路二段515號\",\"website\":\"http://www4.yunlin.gov.tw/civil/\",\"TgosTWD_X\":\"201694.66\",\"TgosTWD_Y\":\"2621765\"},{\"unit\":\"嘉義縣政府民政處\",\"telephon\":\"05-3620123#460；05-3620123#461\",\"fax\":\"05-3620399\",\"address\":\"嘉義縣太保市祥和新村祥和一路東段1號\",\"website\":\"http://www1.cyhg.gov.tw/civil/chinese/\",\"TgosTWD_X\":\"\",\"TgosTWD_Y\":\"\"},{\"unit\":\"屏東縣政府民政處\",\"telephon\":\"08-7324147\",\"fax\":\"08-7331538\",\"address\":\"屏東縣屏東市自由路527號\",\"website\":\"http://www.pthg.gov.tw/plancab/Index.aspx\",\"TgosTWD_X\":\"197386.9\",\"TgosTWD_Y\":\"2509263\"},{\"unit\":\"臺東縣政府民政處\",\"telephon\":\"089-326141\",\"fax\":\"089-340560\",\"address\":\"台東縣台東市中山路276號\",\"website\":\"http://www.taitung.gov.tw/Civil/index.aspx\",\"TgosTWD_X\":\"265435.62\",\"TgosTWD_Y\":\"2517223.5\"},{\"unit\":\"花蓮縣政府民政處\",\"telephon\":\"03-8232047；03-8221894#374；03-8221894#375\",\"fax\":\"03-8230576\",\"address\":\"花蓮縣花蓮市府後路6號\",\"website\":\"http://ca.hl.gov.tw/bin/home.php\",\"TgosTWD_X\":\"312974.72\",\"TgosTWD_Y\":\"2654109\"},{\"unit\":\"澎湖縣政府民政處\",\"telephon\":\"06-9274400\",\"fax\":\"06-9274701\",\"address\":\"澎湖縣馬公市治平路32號\",\"website\":\"http://www.penghu.gov.tw/civil/\",\"TgosTWD_X\":\"103661.375\",\"TgosTWD_Y\":\"2608175\"},{\"unit\":\"基隆市政府民政處\",\"telephon\":\"02-24201122#2304；02-24201122#2305；02-24201122#2306；02-24201122#2307；02-24201122#2308；02-24201122#2309；02-24201122#2310；02-24201122#2311\",\"fax\":\"02-24668739\",\"address\":\"基隆市中正區正信路205號2樓\",\"website\":\"http://www.klcg.gov.tw/civil/\",\"TgosTWD_X\":\"326702.88\",\"TgosTWD_Y\":\"2781832.5\"},{\"unit\":\"新竹市政府民政處\",\"telephon\":\"03-5216121#314；03-5216121#315；03-5216121#316；03-5216121#317；03-5216121#318；03-5216121#319\",\"fax\":\"03-5214703\",\"address\":\"新竹市中正路120號\",\"website\":\"http://dep-civil.hccg.gov.tw/web/Home?FP=1064\",\"TgosTWD_X\":\"246852.16\",\"TgosTWD_Y\":\"2744373.2\"},{\"unit\":\"嘉義市政府民政處\",\"telephon\":\"05-2254321\",\"fax\":\"05-2259885\",\"address\":\"嘉義市中山路199號\",\"website\":\"http://www.chiayi.gov.tw/web/civil/index.asp\",\"TgosTWD_X\":\"194178.02\",\"TgosTWD_Y\":\"2597686.8\"},{\"unit\":\"金門縣政府民政局\",\"telephon\":\"082-325753\",\"fax\":\"082-322613\",\"address\":\"金門縣金城鎮民生路60號\",\"website\":\"http://www.kinmen.gov.tw/Layout/sub_A/index.aspx?frame=3\",\"TgosTWD_X\":\"-21896.012\",\"TgosTWD_Y\":\"2706070\"},{\"unit\":\"連江縣政府民政局\",\"telephon\":\"0836-22485\",\"fax\":\"0836-22209\",\"address\":\"連江縣南竿鄉介壽村76號\",\"website\":\"http://www.matsu.gov.tw/2008web/governor_index.php?id=civilaffairbureau\",\"TgosTWD_X\":\"145745.47\",\"TgosTWD_Y\":\"2894431\"}]";


void setup() {
  Serial.begin(9600);
  deserializeJson(doc, json);
  // put your setup code here, to run once:
JsonObject root_0 = doc[0];
const char* root_0_unit = root_0["unit"]; // "單位"
const char* root_0_telephon = root_0["telephon"]; // "電 話"
const char* root_0_fax = root_0["fax"]; // "傳 真"
const char* root_0_address = root_0["address"]; // "地 址"
const char* root_0_website = root_0["website"]; // "網址"
const char* root_0_TgosTWD_X = root_0["TgosTWD_X"]; // "TgosTWD_X"
const char* root_0_TgosTWD_Y = root_0["TgosTWD_Y"]; // "TgosTWD_Y"

JsonObject root_1 = doc[1];
const char* root_1_unit = root_1["unit"]; // "新北市政府民政局"
const char* root_1_telephon = root_1["telephon"]; // "02-29603456"
const char* root_1_fax = root_1["fax"]; // "02-29693894"
const char* root_1_address = root_1["address"]; // "新北市板橋區中山路1段161號11樓"
const char* root_1_website = root_1["website"]; // "http://www.ca.ntpc.gov.tw/"
const char* root_1_TgosTWD_X = root_1["TgosTWD_X"]; // "296995.84"
const char* root_1_TgosTWD_Y = root_1["TgosTWD_Y"]; // "2767196.5"

JsonObject root_2 = doc[2];
const char* root_2_unit = root_2["unit"]; // "臺北市政府兵役局"
const char* root_2_telephon = root_2["telephon"]; // "02-23654361；02-23654362；02-23654363；02-23654364"
const char* root_2_fax = root_2["fax"]; // "02-23673072"
const char* root_2_address = root_2["address"]; // "臺北市中正區羅斯福路四段92號9樓"
const char* root_2_website = root_2["website"]; // "http://www.tcdms.taipei.gov.tw/"
const char* root_2_TgosTWD_X = root_2["TgosTWD_X"]; // "303996.47"
const char* root_2_TgosTWD_Y = root_2["TgosTWD_Y"]; // "2767406.2"

JsonObject root_3 = doc[3];
const char* root_3_unit = root_3["unit"]; // "臺中市政府民政局"
const char* root_3_telephon = root_3["telephon"]; // "04-22289111"
const char* root_3_fax = root_3["fax"]; // "04-22202480"
const char* root_3_address = root_3["address"]; // "臺中市臺中港路2段89號6樓"
const char* root_3_website = root_3["website"]; // "http://www.civil.taichung.gov.tw/"
const char* root_3_TgosTWD_X = root_3["TgosTWD_X"]; // "214160.3"
const char* root_3_TgosTWD_Y = root_3["TgosTWD_Y"]; // "2673009.2"

JsonObject root_4 = doc[4];
const char* root_4_unit = root_4["unit"]; // "臺南市政府民政局"
const char* root_4_telephon = root_4["telephon"]; // "06-2991111"
const char* root_4_fax = root_4["fax"]; // "06-2982560"
const char* root_4_address = root_4["address"]; // "臺南市安平區永華路2段6號"
const char* root_4_website = root_4["website"]; // "http://www.tainan.gov.tw/agr/default.asp"
const char* root_4_TgosTWD_X = root_4["TgosTWD_X"]; // "166419.75"
const char* root_4_TgosTWD_Y = root_4["TgosTWD_Y"]; // "2543371.8"

JsonObject root_5 = doc[5];
const char* root_5_unit = root_5["unit"]; // "高雄市政府兵役局"
const char* root_5_telephon = root_5["telephon"]; // "07-3373582"
const char* root_5_fax = root_5["fax"]; // "07-3312241"
const char* root_5_address = root_5["address"]; // "高雄市苓雅區四維3路2號4樓"
const char* root_5_website = root_5["website"]; // "http://mildp.kcg.gov.tw/index.php"
const char* root_5_TgosTWD_X = root_5["TgosTWD_X"]; // "178329.53"
const char* root_5_TgosTWD_Y = root_5["TgosTWD_Y"]; // "2502050.8"

JsonObject root_6 = doc[6];
const char* root_6_unit = root_6["unit"]; // "宜蘭縣政府民政處"
const char* root_6_telephon = root_6["telephon"]; // "03-9251000#1680；03-9251000#1690"
const char* root_6_fax = root_6["fax"]; // "03-9332434"
const char* root_6_address = root_6["address"]; // "宜蘭縣宜蘭市縣政北路1號3樓"
const char* root_6_website = root_6["website"]; // "http://civil.e-land.gov.tw/releaseRedirect.do?unitID=102&pageID=9297"
const char* root_6_TgosTWD_X = root_6["TgosTWD_X"]; // "327162.16"
const char* root_6_TgosTWD_Y = root_6["TgosTWD_Y"]; // "2736149.2"

JsonObject root_7 = doc[7];
const char* root_7_unit = root_7["unit"]; // "桃園縣政府民政局"
const char* root_7_telephon = root_7["telephon"]; // "03-3322101"
const char* root_7_fax = root_7["fax"]; // "03-3364817"
const char* root_7_address = root_7["address"]; // "桃園縣桃園市縣府路1號"
const char* root_7_website = root_7["website"]; // "http://cab.tycg.gov.tw/site/ex_bureau_index.aspx?site_id=029"
const char* root_7_TgosTWD_X = root_7["TgosTWD_X"]; // "280383.2"
const char* root_7_TgosTWD_Y = root_7["TgosTWD_Y"]; // "2765042.2"

JsonObject root_8 = doc[8];
const char* root_8_unit = root_8["unit"]; // "新竹縣政府民政處"
const char* root_8_telephon = root_8["telephon"]; // "03-5518101#268"
const char* root_8_fax = root_8["fax"]; // "03-5513672"
const char* root_8_address = root_8["address"]; // "新竹縣竹北市光明六路10號"
const char* root_8_website = root_8["website"]; // "http://web.hsinchu.gov.tw/civil/"
const char* root_8_TgosTWD_X = root_8["TgosTWD_X"]; // "251305.73"
const char* root_8_TgosTWD_Y = root_8["TgosTWD_Y"]; // "2746600.8"

JsonObject root_9 = doc[9];
const char* root_9_unit = root_9["unit"]; // "苗栗縣政府民政處"
const char* root_9_telephon = root_9["telephon"]; // "037-322150"
const char* root_9_fax = root_9["fax"]; // "037-354593"
const char* root_9_address = root_9["address"]; // "苗栗縣苗栗市縣府路100號"
const char* root_9_website = root_9["website"]; // "http://www.miaoli.gov.tw/civil_affairs/index.php"
const char* root_9_TgosTWD_X = root_9["TgosTWD_X"]; // "231846.64"
const char* root_9_TgosTWD_Y = root_9["TgosTWD_Y"]; // "2717592.8"

JsonObject root_10 = doc[10];
const char* root_10_unit = root_10["unit"]; // "彰化縣政府民政處"
const char* root_10_telephon = root_10["telephon"]; // "04-7222151#0122"
const char* root_10_fax = root_10["fax"]; // "04-7293510"
const char* root_10_address = root_10["address"]; // "彰化縣彰化市中山路二段416號7樓"
const char* root_10_website = root_10["website"]; // "http://www.chcg.gov.tw/civil/00home/index1.asp"
const char* root_10_TgosTWD_X = root_10["TgosTWD_X"]; // "203707.83"
const char* root_10_TgosTWD_Y = root_10["TgosTWD_Y"]; // "2663465.2"

JsonObject root_11 = doc[11];
const char* root_11_unit = root_11["unit"]; // "南投縣政府民政處"
const char* root_11_telephon = root_11["telephon"]; // "049-2222106；049-2222107；049-2222108；049-2222109"
const char* root_11_fax = root_11["fax"]; // "049-2238404"
const char* root_11_address = root_11["address"]; // "南投縣南投市中興路660號"
const char* root_11_website = root_11["website"]; // "http://www.nantou.gov.tw/big5/index.asp?dptid=376480000AU100000"
const char* root_11_TgosTWD_X = root_11["TgosTWD_X"]; // "218455"
const char* root_11_TgosTWD_Y = root_11["TgosTWD_Y"]; // "2644256"

JsonObject root_12 = doc[12];
const char* root_12_unit = root_12["unit"]; // "雲林縣政府民政處"
const char* root_12_telephon = root_12["telephon"]; // "05-5322154"
const char* root_12_fax = root_12["fax"]; // "05-5352041"
const char* root_12_address = root_12["address"]; // "雲林縣斗六市雲林路二段515號"
const char* root_12_website = root_12["website"]; // "http://www4.yunlin.gov.tw/civil/"
const char* root_12_TgosTWD_X = root_12["TgosTWD_X"]; // "201694.66"
const char* root_12_TgosTWD_Y = root_12["TgosTWD_Y"]; // "2621765"

JsonObject root_13 = doc[13];
const char* root_13_unit = root_13["unit"]; // "嘉義縣政府民政處"
const char* root_13_telephon = root_13["telephon"]; // "05-3620123#460；05-3620123#461"
const char* root_13_fax = root_13["fax"]; // "05-3620399"
const char* root_13_address = root_13["address"]; // "嘉義縣太保市祥和新村祥和一路東段1號"
const char* root_13_website = root_13["website"]; // "http://www1.cyhg.gov.tw/civil/chinese/"
const char* root_13_TgosTWD_X = root_13["TgosTWD_X"]; // ""
const char* root_13_TgosTWD_Y = root_13["TgosTWD_Y"]; // ""

JsonObject root_14 = doc[14];
const char* root_14_unit = root_14["unit"]; // "屏東縣政府民政處"
const char* root_14_telephon = root_14["telephon"]; // "08-7324147"
const char* root_14_fax = root_14["fax"]; // "08-7331538"
const char* root_14_address = root_14["address"]; // "屏東縣屏東市自由路527號"
const char* root_14_website = root_14["website"]; // "http://www.pthg.gov.tw/plancab/Index.aspx"
const char* root_14_TgosTWD_X = root_14["TgosTWD_X"]; // "197386.9"
const char* root_14_TgosTWD_Y = root_14["TgosTWD_Y"]; // "2509263"

JsonObject root_15 = doc[15];
const char* root_15_unit = root_15["unit"]; // "臺東縣政府民政處"
const char* root_15_telephon = root_15["telephon"]; // "089-326141"
const char* root_15_fax = root_15["fax"]; // "089-340560"
const char* root_15_address = root_15["address"]; // "台東縣台東市中山路276號"
const char* root_15_website = root_15["website"]; // "http://www.taitung.gov.tw/Civil/index.aspx"
const char* root_15_TgosTWD_X = root_15["TgosTWD_X"]; // "265435.62"
const char* root_15_TgosTWD_Y = root_15["TgosTWD_Y"]; // "2517223.5"

JsonObject root_16 = doc[16];
const char* root_16_unit = root_16["unit"]; // "花蓮縣政府民政處"
const char* root_16_telephon = root_16["telephon"]; // "03-8232047；03-8221894#374；03-8221894#375"
const char* root_16_fax = root_16["fax"]; // "03-8230576"
const char* root_16_address = root_16["address"]; // "花蓮縣花蓮市府後路6號"
const char* root_16_website = root_16["website"]; // "http://ca.hl.gov.tw/bin/home.php"
const char* root_16_TgosTWD_X = root_16["TgosTWD_X"]; // "312974.72"
const char* root_16_TgosTWD_Y = root_16["TgosTWD_Y"]; // "2654109"

JsonObject root_17 = doc[17];
const char* root_17_unit = root_17["unit"]; // "澎湖縣政府民政處"
const char* root_17_telephon = root_17["telephon"]; // "06-9274400"
const char* root_17_fax = root_17["fax"]; // "06-9274701"
const char* root_17_address = root_17["address"]; // "澎湖縣馬公市治平路32號"
const char* root_17_website = root_17["website"]; // "http://www.penghu.gov.tw/civil/"
const char* root_17_TgosTWD_X = root_17["TgosTWD_X"]; // "103661.375"
const char* root_17_TgosTWD_Y = root_17["TgosTWD_Y"]; // "2608175"

JsonObject root_18 = doc[18];
const char* root_18_unit = root_18["unit"]; // "基隆市政府民政處"
const char* root_18_telephon = root_18["telephon"]; // "02-24201122#2304；02-24201122#2305；02-24201122#2306；02-24201122#2307；02-24201122#2308；02-24201122#2309；02-24201122#2310；02-24201122#2311"
const char* root_18_fax = root_18["fax"]; // "02-24668739"
const char* root_18_address = root_18["address"]; // "基隆市中正區正信路205號2樓"
const char* root_18_website = root_18["website"]; // "http://www.klcg.gov.tw/civil/"
const char* root_18_TgosTWD_X = root_18["TgosTWD_X"]; // "326702.88"
const char* root_18_TgosTWD_Y = root_18["TgosTWD_Y"]; // "2781832.5"

JsonObject root_19 = doc[19];
const char* root_19_unit = root_19["unit"]; // "新竹市政府民政處"
const char* root_19_telephon = root_19["telephon"]; // "03-5216121#314；03-5216121#315；03-5216121#316；03-5216121#317；03-5216121#318；03-5216121#319"
const char* root_19_fax = root_19["fax"]; // "03-5214703"
const char* root_19_address = root_19["address"]; // "新竹市中正路120號"
const char* root_19_website = root_19["website"]; // "http://dep-civil.hccg.gov.tw/web/Home?FP=1064"
const char* root_19_TgosTWD_X = root_19["TgosTWD_X"]; // "246852.16"
const char* root_19_TgosTWD_Y = root_19["TgosTWD_Y"]; // "2744373.2"

JsonObject root_20 = doc[20];
const char* root_20_unit = root_20["unit"]; // "嘉義市政府民政處"
const char* root_20_telephon = root_20["telephon"]; // "05-2254321"
const char* root_20_fax = root_20["fax"]; // "05-2259885"
const char* root_20_address = root_20["address"]; // "嘉義市中山路199號"
const char* root_20_website = root_20["website"]; // "http://www.chiayi.gov.tw/web/civil/index.asp"
const char* root_20_TgosTWD_X = root_20["TgosTWD_X"]; // "194178.02"
const char* root_20_TgosTWD_Y = root_20["TgosTWD_Y"]; // "2597686.8"

JsonObject root_21 = doc[21];
const char* root_21_unit = root_21["unit"]; // "金門縣政府民政局"
const char* root_21_telephon = root_21["telephon"]; // "082-325753"
const char* root_21_fax = root_21["fax"]; // "082-322613"
const char* root_21_address = root_21["address"]; // "金門縣金城鎮民生路60號"
const char* root_21_website = root_21["website"]; // "http://www.kinmen.gov.tw/Layout/sub_A/index.aspx?frame=3"
const char* root_21_TgosTWD_X = root_21["TgosTWD_X"]; // "-21896.012"
const char* root_21_TgosTWD_Y = root_21["TgosTWD_Y"]; // "2706070"

JsonObject root_22 = doc[22];
const char* root_22_unit = root_22["unit"]; // "連江縣政府民政局"
const char* root_22_telephon = root_22["telephon"]; // "0836-22485"
const char* root_22_fax = root_22["fax"]; // "0836-22209"
const char* root_22_address = root_22["address"]; // "連江縣南竿鄉介壽村76號"
const char* root_22_website = root_22["website"]; // "http://www.matsu.gov.tw/2008web/governor_index.php?id=civilaffairbureau"
const char* root_22_TgosTWD_X = root_22["TgosTWD_X"]; // "145745.47"
const char* root_22_TgosTWD_Y = root_22["TgosTWD_Y"]; // "2894431"
}

void loop() {
  // put your main code here, to run repeatedly:

}
