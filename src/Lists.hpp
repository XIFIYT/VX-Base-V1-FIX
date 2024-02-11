#pragma once
#include "UI/UIManager.hpp"

namespace VX::Lists
{
	inline const char* HeaderTypesFrontend[]
	{
		"Static",
		"Gradient"
	};

	inline UserInterface::HeaderType HeaderTypesBackend[]
	{
		UserInterface::HeaderType::Static,
		UserInterface::HeaderType::Gradient
	};

	inline std::size_t HeaderTypesPosition = 1;

	inline const char* DemoList[10]
	{
		"One",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten"
	};

	inline std::size_t DemoListPos = 0;

	inline const char* Scenarios[] = 
	{
		"WORLD_HUMAN_AA_COFFEE",
		"WORLD_HUMAN_AA_SMOKE",
		"WORLD_HUMAN_BINOCULARS",
		"WORLD_HUMAN_BUM_FREEWAY",
		"WORLD_HUMAN_BUM_SLUMPED",
		"WORLD_HUMAN_BUM_STANDING",
		"WORLD_HUMAN_BUM_WASH",
		"WORLD_HUMAN_CAR_PARK_ATTENDANT",
		"WORLD_HUMAN_CHEERING",
		"WORLD_HUMAN_CLIPBOARD",
		"WORLD_HUMAN_CONST_DRILL",
		"WORLD_HUMAN_COP_IDLES",
		"WORLD_HUMAN_DRINKING",
		"WORLD_HUMAN_DRUG_DEALER",
		"WORLD_HUMAN_DRUG_DEALER_HARD",
		"WORLD_HUMAN_MOBILE_FILM_SHOCKING",
		"WORLD_HUMAN_GARDENER_LEAF_BLOWER",
		"WORLD_HUMAN_GARDENER_PLANT",
		"WORLD_HUMAN_GOLF_PLAYER",
		"WORLD_HUMAN_GUARD_PATROL",
		"WORLD_HUMAN_GUARD_STAND",
		"WORLD_HUMAN_GUARD_STAND_ARMY",
		"WORLD_HUMAN_HAMMERING",
		"WORLD_HUMAN_HANG_OUT_STREET",
		"WORLD_HUMAN_HIKER_STANDING",
		"WORLD_HUMAN_HUMAN_STATUE",
		"WORLD_HUMAN_JANITOR",
		"WORLD_HUMAN_JOG_STANDING",
		"WORLD_HUMAN_LEANING",
		"WORLD_HUMAN_MAID_CLEAN",
		"WORLD_HUMAN_MUSCLE_FLEX",
		"WORLD_HUMAN_MUSCLE_FREE_WEIGHTS",
		"WORLD_HUMAN_MUSICIAN",
		"WORLD_HUMAN_PAPARAZZI",
		"WORLD_HUMAN_PARTYING",
		"WORLD_HUMAN_PICNIC",
		"WORLD_HUMAN_PROSTITUTE_HIGH_CLASS",
		"WORLD_HUMAN_PROSTITUTE_LOW_CLASS",
		"WORLD_HUMAN_PUSH_UPS",
		"WORLD_HUMAN_SEAT_LEDGE",
		"WORLD_HUMAN_SEAT_LEDGE_EATING",
		"WORLD_HUMAN_SEAT_STEPS",
		"WORLD_HUMAN_SEAT_WALL",
		"WORLD_HUMAN_SEAT_WALL_EATING",
		"WORLD_HUMAN_SEAT_WALL_TABLET",
		"WORLD_HUMAN_SECURITY_SHINE_TORCH",
		"WORLD_HUMAN_SIT_UPS",
		"WORLD_HUMAN_SMOKING",
		"WORLD_HUMAN_SMOKING_POT",
		"WORLD_HUMAN_STAND_FIRE",
		"WORLD_HUMAN_STAND_FISHING",
		"WORLD_HUMAN_STAND_IMPATIENT",
		"WORLD_HUMAN_STAND_IMPATIENT_UPRIGHT",
		"WORLD_HUMAN_STAND_MOBILE",
		"WORLD_HUMAN_STAND_MOBILE_UPRIGHT",
		"WORLD_HUMAN_STRIP_WATCH_STAND",
		"WORLD_HUMAN_STUPOR",
		"WORLD_HUMAN_SUNBATHE",
		"WORLD_HUMAN_SUNBATHE_BACK",
		"WORLD_HUMAN_SUPERHERO",
		"WORLD_HUMAN_SWIMMING",
		"WORLD_HUMAN_TENNIS_PLAYER",
		"WORLD_HUMAN_TOURIST_MAP",
		"WORLD_HUMAN_TOURIST_MOBILE",
		"WORLD_HUMAN_VEHICLE_MECHANIC",
		"WORLD_HUMAN_WELDING",
		"WORLD_HUMAN_WINDOW_SHOP_BROWSE",
		"WORLD_HUMAN_YOGA",
		"PROP_HUMAN_ATM",
		"PROP_HUMAN_BBQ",
		"PROP_HUMAN_BUM_BIN",
		"PROP_HUMAN_BUM_SHOPPING_CART",
		"PROP_HUMAN_BUM_SHOPPING_CART",
		"PROP_HUMAN_MUSCLE_CHIN_UPS",
		"PROP_HUMAN_MUSCLE_CHIN_UPS_ARMY",
		"PROP_HUMAN_MUSCLE_CHIN_UPS_PRISON",
		"PROP_HUMAN_PARKING_METER",
		"PROP_HUMAN_SEAT_ARMCHAIR",
		"PROP_HUMAN_SEAT_BAR",
		"PROP_HUMAN_SEAT_BENCH",
		"PROP_HUMAN_SEAT_BENCH_DRINK",
		"PROP_HUMAN_SEAT_BENCH_DRINK_BEER",
		"PROP_HUMAN_SEAT_BENCH_FOOD",
		"PROP_HUMAN_SEAT_BUS_STOP_WAIT",
		"PROP_HUMAN_SEAT_CHAIR",
		"PROP_HUMAN_SEAT_CHAIR_DRINK",
		"PROP_HUMAN_SEAT_CHAIR_DRINK_BEER",
		"PROP_HUMAN_SEAT_CHAIR_FOOD",
		"PROP_HUMAN_SEAT_CHAIR_UPRIGHT",
		"PROP_HUMAN_SEAT_CHAIR_MP_PLAYER",
		"PROP_HUMAN_SEAT_COMPUTER",
		"PROP_HUMAN_SEAT_DECKCHAIR",
		"PROP_HUMAN_SEAT_DECKCHAIR_DRINK",
		"PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS",
		"PROP_HUMAN_SEAT_MUSCLE_BENCH_PRESS_PRISON",
		"PROP_HUMAN_SEAT_SEWING",
		"PROP_HUMAN_SEAT_STRIP_WATCH",
		"PROP_HUMAN_SEAT_SUNLOUNGER",
		"PROP_HUMAN_STAND_IMPATIENT",
		"CODE_HUMAN_COWER",
		"CODE_HUMAN_CROSS_ROAD_WAIT",
		"CODE_HUMAN_PARK_CAR",
		"PROP_HUMAN_MOVIE_BULB",
		"PROP_HUMAN_MOVIE_STUDIO_LIGHT",
		"CODE_HUMAN_MEDIC_KNEEL",
		"CODE_HUMAN_MEDIC_TEND_TO_DEAD",
		"CODE_HUMAN_MEDIC_TIME_OF_DEATH",
		"CODE_HUMAN_POLICE_CROWD_CONTROL",
		"CODE_HUMAN_POLICE_INVESTIGATE",
		"CODE_HUMAN_STAND_COWER",
		"EAR_TO_TEXT",
		"EAR_TO_TEXT_FAT"
	};
}

class CVehicleList
{
public:

	inline static std::size_t VehicleListPos = 0;
	constexpr static inline std::array<const char*, 24> VehicleLists{ "Super", "Sports", "Sports Classic", "Sedans", "Motorcycles", "Cycles", "Helicopters", "Planes", "Boats", "Military", "Emergency", "Commercials", "Muscle", "OffRoad", "SUVs", "Open Wheel", "Trailer", "Trains", "Service", "Utlity", "Vans", "Industrial", "Coupes", "Compacts" };

	constexpr static inline std::array<const char*, 52> Super = { "adder", "autarch", "banshee2", "bullet", "champion", "cheetah", "cyclone", "deveste", "entity2", "entityxf", "emerus", "fmj", "furia", "gp1", "ignus", "infernus", "italigtb", "italigtb2", "krieger", "le7b", "nero", "nero2", "osiris", "penetrator", "pfister811", "prototipo", "prototipo", "reaper", "s80", "sc1", "scramjet", "sheava", "sultanrs", "t20", "taipan", "tempesta", "tezeract", "thrax", "tigon", "turismor", "tyrant", "tyrus", "vacca", "vagner", "vigilante", "visione", "voltic", "voltic2", "xa21", "zeno", "zentorno", "zorrusso" };
	constexpr static inline std::array<const char*, 95> Sports = { "alpha", "banshee", "bestiagts", "blista2", "blista3", "buffalo", "buffalo2", "buffalo3", "calico", "carbonizzare", "comet2", "comet3", "comet4", "comet5", "comet7", "coquette", "coquette4", "cypher", "drafter", "deveste", "euros", "elegy", "elegy2", "feltzer2", "flashgt", "furoregt", "fusilade", "futo", "futo2", "gb200", "growler", "hotring", "komoda", "imorgon", "issi7", "italigto", "jugular", "jester", "jester2", "jester3", "jester4", "khamelion", "kuruma", "kuruma2", "locust", "lynx", "massacro", "massacro2", "neo", "neon", "ninef", "ninef2", "omnis", "paragon", "paragon2", "pariah", "penumbra", "penumbra2", "raiden", "rapidgt", "rapidgt2", "raptor", "remus", "revolter", "rt3000", "ruston", "schafter2", "schafter3", "schafter4", "schafter5", "schafter6", "schlagen", "schwarzer", "sentinel3", "seven70", "specter", "specter2", "streiter", "sugoi", "sultan", "sultan2", "sultan3", "surano", "tampa2", "tropos", "vectre", "verlierer2", "vstr", "zr380", "zr3802", "zr3803", "italirsx", "veto", "veto2", "vstr" };
	constexpr static inline std::array<const char*, 46> SportsClassic = { "ardent", "btype", "btype2", "btype3", "casco", "cheetah2", "coquette2", "deluxo", "dynasty", "fagaloa", "feltzer3", "gt500", "infernus2", "jb700", "jb7002", "mamba", "manana", "manana2", "michelli", "monroe", "nebula", "peyote", "peyote3", "pigalle", "rapidgt3", "retinue", "retinue2", "savestra", "stinger", "stingergt", "stromberg", "swinger", "torero", "tornado", "tornado2", "tornado3", "tornado4" ,"tornado5", "tornado6", "turismo2", "viseris", "z190", "ztype", "zion3","cheburek", "toreador" };
	constexpr static inline std::array<const char*, 34> Sedans = { "asea", "asea2", "asterope", "cinquemila", "cog55", "cog552", "cognoscenti", "cognoscenti2", "deity", "emperor", "emperor2", "emperor3", "fugitive", "glendale", "glendale2", "ingot", "intruder", "limo2", "premier", "primo", "primo2", "regina", "romero", "stafford", "stanier", "stratum", "stretch", "superd", "surge", "tailgater", "tailgater2", "warrener", "warrener2", "washington" };
	constexpr static inline std::array<const char*, 54> Motorcycles = { "akuma", "avarus", "bagger", "bati", "bati2", "bf400", "carbonrs", "chimera", "cliffhanger", "daemon", "daemon2", "defiler", "deathbike", "deathbike2", "deathbike3", "diablous", "diablous2", "double", "enduro", "esskey", "faggio", "faggio2", "faggio3", "fcr", "fcr2", "gargoyle", "hakuchou", "hakuchou2", "hexer", "innovation", "lectro", "manchez", "nemesis", "nightblade", "oppressor", "oppressor2", "pcj", "ratbike", "ruffian", "rrocket", "sanchez", "sanchez2", "sanctus", "shotaro", "sovereign", "stryder", "thrust", "vader", "vindicator", "vortex", "wolfsbane", "zombiea", "zombieb", "manchez2" };
	constexpr static inline std::array<const char*, 7>  Cycles = { "bmx", "cruiser", "fixter", "scorcher", "tribike", "tribike2", "tribike3" };
	constexpr static inline std::array<const char*, 26> Helicopters = { "akula", "annihilator", "buzzard", "buzzard2", "cargobob", "cargobob2", "cargobob3", "cargobob4", "frogger", "frogger2", "havok", "hunter", "maverick", "savage", "seasparrow", "skylift", "supervolito", "supervolito2", "swift", "swift2", "valkyrie", "valkyrie2", "volatus", "annihilator2", "seasparrow2", "seasparrow3" };
	constexpr static inline std::array<const char*, 39> Planes = { "alphaz1", "avenger", "avenger2", "besra", "blimp", "blimp2", "blimp3", "bombushka",	"cargoplane", "cuban800", "dodo", "duster", "howard", "hydra", "jet", "lazer","luxor", "luxor2", "mammatus", "microlight", "miljet", "mogul", "molotok", "nimbus", "nokota", "pyro", "rogue", "seabreeze", "shamal", "starling", "strikeforce", "stunt", "titan", "tula", "velum", "velum2", "vestra", "volatol", "alkonost" };
	constexpr static inline std::array<const char*, 23> Boats = { "avisa", "dinghy", "jetmax", "marquis", "seashark", "seashark2", "seashark3", "speeder", "speeder2", "squalo", "submersible", "submersible2", "suntrap", "toro", "toro2", "tropic", "tropic2", "tug", "avisa", "dinghy5", "kosatka", "longfin", "patrolboat" };
	constexpr static inline std::array<const char*, 17> Military = { "apc", "barracks", "barracks2", "barracks3", "barrage", "chernobog", "crusader", "halftrack", "khanjali", "minitank", "rhino", "scarab", "scarab2", "scarab3", "thruster", "trailersmall2", "vetir" };
	constexpr static inline std::array<const char*, 21> Emergency = { "ambulance", "fbi", "fbi2", "firetruck", "lguard", "pbus", "police", "police2", "police3", "police4", "policeb", "polmav", "policeold1", "policeold2", "policet", "pranger", "predator", "riot", "riot2", "sheriff", "sheriff2" };
	constexpr static inline std::array<const char*, 20> Commercials = { "benson", "biff", "cerberus", "cerberus2", "cerberus3", "hauler", "hauler2", "mule", "mule2", "mule3", "mule4", "packer", "phantom", "phantom2", "phantom3", "pounder", "pounder2", "stockade", "stockade3", "terbyte" };
	constexpr static inline std::array<const char*, 71> Muscle = { "blade", "buccaneer", "buccaneer2", "chino", "chino2", "clique", "coquette3", "deviant", "dominator", "dominator2", "dominator3", "dominator4", "dominator5", "dominator6", "dukes", "dukes2", "dukes3", "faction", "faction2", "faction3", "ellie", "gauntlet","gauntlet2", "gauntlet3", "gauntlet4", "gauntlet5", "hermes", "hotknife", "hustler", "impaler", "impaler2", "impaler3","impaler4", "imperator", "imperator2", "imperator3", "lurcher", "moonbeam", "moonbeam2", "nightshade", "peyote2", "phoenix", "picador", "ratloader", "ratloader2", "ruiner", "ruiner2", "ruiner3", "sabregt", "sabregt2", "slamvan", "slamvan2", "slamvan3", "slamvan4", "slamvan5", "slamvan6", "stalion", "stalion2", "tampa", "tampa3", "tulip", "vamos", "vigero", "virgo", "virgo2", "virgo3", "voodoo", "voodoo2", "yosemite", "yosemite2","yosemite3" };
	constexpr static inline std::array<const char*, 58> OffRoad = { "bfinjection", "bifta", "blazer", "blazer2", "blazer3", "blazer4", "blazer5", "bodhi2", "brawler", "bruiser", "bruiser2", "bruiser3", "brutus", "brutus2", "brutus3", "caracara", "caracara2", "dloader", "dubsta3", "dune", "dune2", "dune3", "dune4", "dune5", "everon", "freecrawler", "hellion", "insurgent", "insurgent2", "insurgent3", "kalahari", "kamacho", "marshall", "mesa3", "monster", "monster3", "monster4", "monster5", "menacer", "outlaw", "nightshark", "rancherxl", "rancherxl2", "rebel", "rebel2", "rcbandito", "riata", "sandking", "sandking2", "technical", "technical2", "technical3", "trophytruck", "trophytruck2", "vagrant", "zhaba", "verus", "winky" };
	constexpr static inline std::array<const char*, 34> SUVs = { "baller", "baller2", "baller3", "baller4", "baller5", "baller6", "bjxl", "cavalcade", "cavalcade2", "contender", "dubsta", "dubsta2", "fq2", "granger", "gresley", "habanero", "huntley", "landstalker", "landstalker2", "mesa", "mesa2", "movak", "patriot", "patriot2", "radi", "rebla", "rocoto", "seminole", "seminole2", "serrano", "toros", "xls", "xls2", "squaddie" };
	constexpr static inline std::array<const char*, 4>  OpenWheel = { "formula", "formula2", "openwheel1", "openwheel2" };
	constexpr static inline std::array<const char*, 25> Trailer = { "armytanker", "armytrailer", "armytrailer2", "baletrailer", "boattrailer", "cablecar", "docktrailer", "freighttrailer", "graintrailer", "proptrailer", "raketrailer", "tr2", "tr3", "tr4", "trflat", "tvtrailer", "tanker", "tanker2", "trailerlarge", "trailerlogs", "trailersmall", "trailers", "trailers2", "trailers3", "trailers4" };
	constexpr static inline std::array<const char*, 7>  Trains = { "freight", "freightcar", "freightcont1", "freightcont2", "freightgrain", "metrotrain", "tankercar" };
	constexpr static inline std::array<const char*, 12> Service = { "airbus", "brickade", "bus", "coach", "pbus2", "rallytruck", "rentalbus", "taxi", "tourbus", "trash", "trash2", "wastelander" };
	constexpr static inline std::array<const char*, 20> Utility = { "airtug", "caddy", "caddy2", "caddy3", "docktug", "forklift", "mower", "ripley", "sadler", "sadler2", "scrap", "towtruck", "towtruck2", "tractor", "tractor2", "tractor3", "utillitruck", "utillitruck2", "utillitruck3", "slamtruck" };
	constexpr static inline std::array<const char*, 35> Vans = { "bison", "bison2", "bison3", "bobcatxl", "boxville", "boxville2", "boxville3", "boxville4", "boxville5", "burrito", "burrito2", "burrito3", "burrito4", "burrito5", "camper", "gburrito", "gburrito2", "journey", "minivan", "minivan2", "paradise", "pony", "pony2", "rumpo", "rumpo2", "rumpo3", "speedo", "speedo2", "speedo4", "surfer", "surfer2", "taco", "youga", "youga2", "youga3" };
	constexpr static inline std::array<const char*, 11> Industrial = { "bulldozer", "cutter", "dump", "flatbed", "guardian", "handler", "mixer", "mixer2", "rubble", "tiptruck", "tiptruck2", };
	constexpr static inline std::array<const char*, 14> Coupes = { "cogcabrio", "exemplar", "f620", "felon", "felon2", "jackal", "oracle", "oracle2", "sentinel", "sentinel2", "windsor", "windsor2", "zion", "zion2" };
	constexpr static inline std::array<const char*, 17> Compacts = { "asbo", "blista", "brioso", "club", "dilettante", "dilettante2", "kanjo", "issi2", "issi3", "issi4", "issi5", "issi6", "panto", "prairie", "rhapsody", "brioso2", "weevil" };

}; inline std::unique_ptr<CVehicleList> g_VehicleList;