
# GameAnalytics Godot 3.0 (GDNative)

Still in development state.

```
init(String key, String secret);
set_gender(int flag) Male = 1, Female = 2;
set_birth_year(int year)

enable_info_log(bool flag);
enabled_verbose_log(bool flag);
enable_manual_session_handling(bool flag);

set_custom_dimension1(String customDimension);
set_custom_dimension2(String customDimension);
set_custom_dimension3(String customDimension);

set_facebook_id(String facebookId);

add_bussiness_event(String currency, int amount, String itemType, String itemId, String cartType);
add_resource_event(int flowType, String currency, float amount, String itemType, String itemId);
add_progression_event(int progStatus, String prog01, String prog02, String prog03, int score);
add_design_event(String eventId, float value);

add_error_event(int severity, String message); // severity: Debug = 1, Info = 2, Warning = 3, Error = 4, Critical = 5

conf_build(String buildID);
conf_user_id(String UID);
conf_available_resource_item_type(Array list);
conf_available_resource_currency(Array list);
conf_available_custom_dimension1(Array list);
conf_available_custom_dimension2(Array list);
conf_available_custom_dimension3(Array list);

conf_game_engine_version(String sdkGEVerison);
conf_sqk_game_engine_version(String GEVersion);
```

# Initializing GameAnalytics

```
	var ga = load("gameanalytics.gdn");
	gamea = ga.new();
	gamea.enable_info_log(true);
	gamea.conf_build("0.1.0");

	var curList = ["gold", "gem"];
	gamea.conf_available_resource_currency(curList);

	gamea.init("[Game Key]", "[Game Secret]");
```
