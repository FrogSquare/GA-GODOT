/**
 * Copyright 2017 RameshRavone. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include <game_analytics.h>
#include <OS.hpp>

NS_GODOT_BEGIN

GameAnalytics::GameAnalytics () {

}

GameAnalytics::~GameAnalytics () {

}

void GameAnalytics::init (Variant p_key, Variant p_secret) {
	key = p_key.operator String();
	secret = p_secret.operator String();

	gameanalytics::GameAnalytics::configureWritablePath (OS::get_data_dir ().c_string ());
	gameanalytics::GameAnalytics::initialize (key.c_string (), secret.c_string ());

	Godot::print ("GameAnalytics:Initialized");
}

void GameAnalytics::setEnabledInfoLog(bool value) {
	gameanalytics::GameAnalytics::setEnabledInfoLog (value);
}

void GameAnalytics::setEnabledVerboseLog (bool value) {
	gameanalytics::GameAnalytics::setEnabledVerboseLog (value);
}

void GameAnalytics::setCustomDimension01(Variant customDimension) {
	gameanalytics::GameAnalytics::setCustomDimension01 (customDimension.operator String().c_string ());
}

void GameAnalytics::setCustomDimension02(Variant customDimension) {
	gameanalytics::GameAnalytics::setCustomDimension02 (customDimension.operator String().c_string ());
}

void GameAnalytics::setCustomDimension03(Variant customDimension) {
	gameanalytics::GameAnalytics::setCustomDimension03 (customDimension.operator String().c_string ());
}

void GameAnalytics::setEnabledManualSessionHandling (bool flag) {
	gameanalytics::GameAnalytics::setEnabledManualSessionHandling (flag);
}

void GameAnalytics::setFacebookId(Variant facebookId) {
	gameanalytics::GameAnalytics::setFacebookId (facebookId.operator String().c_string ());
}

void GameAnalytics::setGender(int gender) {
	switch (gender) {
	case EGAGender::Male:
		gameanalytics::GameAnalytics::setGender ((gameanalytics::EGAGender) gender);
		break;
	case EGAGender::Female:
		gameanalytics::GameAnalytics::setGender ((gameanalytics::EGAGender) gender);
		break;
	default:
		break;
	}
}

void GameAnalytics::setBirthYear(int birthYear) {
	gameanalytics::GameAnalytics::setBirthYear (birthYear);
}

void GameAnalytics::addBusinessEvent(
			Variant currency,
			int amount,
			Variant itemType,
			Variant itemId,
			Variant cartType) {

	gameanalytics::GameAnalytics::addBusinessEvent (
	currency.operator String().c_string (),
	amount,
	itemType.operator String().c_string (),
	itemId.operator String().c_string (),
	cartType.operator String().c_string ());
}

void GameAnalytics::addResourceEvent(
			int flowType,
			Variant currency,
			float amount,
			Variant itemType,
			Variant itemId) {

	gameanalytics::GameAnalytics::addResourceEvent (
	(gameanalytics::EGAResourceFlowType) flowType,
	currency.operator String().c_string (),
	amount,
	itemType.operator String().c_string (),
	itemId.operator String().c_string ());
}

void GameAnalytics::addProgressionEvent(
			int progressionStatus,
			Variant progression01,
			Variant progression02,
			Variant progression03,
			int score) {

	if (!score) {
		gameanalytics::GameAnalytics::addProgressionEvent (
		(gameanalytics::EGAProgressionStatus) progressionStatus,
		progression01.operator String().c_string (),
		progression02.operator String().c_string (),
		progression03.operator String().c_string ());
	} else {
		gameanalytics::GameAnalytics::addProgressionEvent (
		(gameanalytics::EGAProgressionStatus) progressionStatus,
		progression01.operator String().c_string (),
		progression02.operator String().c_string (),
		progression03.operator String().c_string (),
		score);
	}
}

void GameAnalytics::addDesignEvent(Variant eventId, float value) {

	if (!value) {
		gameanalytics::GameAnalytics::addDesignEvent (eventId.operator String().c_string ());
	} else {
		gameanalytics::GameAnalytics::addDesignEvent (eventId.operator String().c_string (), value);
	}
}

void GameAnalytics::addErrorEvent(int severity, Variant message) {
	gameanalytics::GameAnalytics::addErrorEvent (
	(gameanalytics::EGAErrorSeverity) severity, message.operator String().c_string ());
}

void GameAnalytics::configureAvailableCustomDimensions01(Variant p_list) {
	Array list = p_list.operator Array();
	std::vector<std::string> l;
	l.clear ();

	for (int i = 0; i < list.size (); i++) {
		l.push_back (list.pop_back ().operator String().c_string ());
	}

	gameanalytics::GameAnalytics::configureAvailableCustomDimensions01 (l);
}

void GameAnalytics::configureAvailableCustomDimensions02(Variant p_list) {
	Array list = p_list.operator Array();
	std::vector<std::string> l;
	l.clear ();

	for (int i = 0; i < list.size (); i++) {
		l.push_back (list.pop_back ().operator String().c_string ());
	}

	gameanalytics::GameAnalytics::configureAvailableCustomDimensions02 (l);
}

void GameAnalytics::configureAvailableCustomDimensions03(Variant p_list) {
	Array list = p_list.operator Array();
	std::vector<std::string> l;
	l.clear ();

	for (int i = 0; i < list.size (); i++) {
		l.push_back (list.pop_back ().operator String().c_string ());
	}

	gameanalytics::GameAnalytics::configureAvailableCustomDimensions03 (l);
}

void GameAnalytics::configureAvailableResourceCurrencies(Variant p_list) {
	Array list = p_list.operator Array();
	std::vector<std::string> l;
	l.clear ();

	for (int i = 0; i < list.size (); i++) {
		l.push_back (list.pop_back ().operator String().c_string ());
	}

	gameanalytics::GameAnalytics::configureAvailableResourceCurrencies (l);
}

void GameAnalytics::configureAvailableResourceItemTypes(Variant p_list) {
	Array list = p_list.operator Array();
	std::vector<std::string> l;
	l.clear ();

	for (int i = 0; i < list.size (); i++) {
		l.push_back (list.pop_back ().operator String().c_string ());
	}

	gameanalytics::GameAnalytics::configureAvailableResourceItemTypes (l);
}

void GameAnalytics::configureBuild(Variant buildID) {
	gameanalytics::GameAnalytics::configureBuild (buildID.operator String().c_string ());
}

void GameAnalytics::configureUserId(Variant uId) {
	gameanalytics::GameAnalytics::configureUserId (uId.operator String().c_string ());
}

void GameAnalytics::configureSdkGameEngineVersion(Variant sdkGameEngineVersion) {
	gameanalytics::GameAnalytics::configureSdkGameEngineVersion (sdkGameEngineVersion.operator String().c_string ());
}

void GameAnalytics::configureGameEngineVersion(Variant engineVersion) {
	gameanalytics::GameAnalytics::configureGameEngineVersion (engineVersion.operator String().c_string ());
}

void GameAnalytics::startSession() {
	//gameanalytics::GameAnalytics::startSession ();
}

void GameAnalytics::endSession() {
	//gameanalytics::GameAnalytics::endSession ();
}

void GameAnalytics::_register_methods () {
//	register_method((char*)"", &GameAnalytics::);

	register_method((char*)"init", &GameAnalytics::init);

	register_method((char*)"set_gender", &GameAnalytics::setGender);
	register_method((char*)"set_birth_year", &GameAnalytics::setBirthYear);

	register_method((char*)"enable_info_log", &GameAnalytics::setEnabledInfoLog);
	register_method((char*)"enabled_verbose_log", &GameAnalytics::setEnabledVerboseLog);
	register_method((char*)"enable_manual_session_handling", &GameAnalytics::setEnabledManualSessionHandling);

	register_method((char*)"set_custom_dimension1", &GameAnalytics::setCustomDimension01);
	register_method((char*)"set_custom_dimension2", &GameAnalytics::setCustomDimension02);
	register_method((char*)"set_custom_dimension3", &GameAnalytics::setCustomDimension03);
	register_method((char*)"set_facebook_id", &GameAnalytics::setFacebookId);

	register_method((char*)"start_session", &GameAnalytics::startSession);
	register_method((char*)"end_session", &GameAnalytics::endSession);

	register_method((char*)"add_bussiness_event", &GameAnalytics::addBusinessEvent);
	register_method((char*)"add_resource_event", &GameAnalytics::addResourceEvent);
	register_method((char*)"add_progression_event", &GameAnalytics::addProgressionEvent);
	register_method((char*)"add_design_event", &GameAnalytics::addDesignEvent);
	register_method((char*)"add_error_event", &GameAnalytics::addErrorEvent);

	register_method((char*)"conf_build", &GameAnalytics::configureBuild);
	register_method((char*)"conf_user_id", &GameAnalytics::configureUserId);
	register_method((char*)"conf_available_resource_item_type", &GameAnalytics::configureAvailableResourceItemTypes);
	register_method((char*)"conf_available_resource_currency", &GameAnalytics::configureAvailableResourceCurrencies);
	register_method((char*)"conf_available_custom_dimension1", &GameAnalytics::configureAvailableCustomDimensions01);
	register_method((char*)"conf_available_custom_dimension2", &GameAnalytics::configureAvailableCustomDimensions02);
	register_method((char*)"conf_available_custom_dimension3", &GameAnalytics::configureAvailableCustomDimensions03);
	register_method((char*)"conf_game_engine_version", &GameAnalytics::configureGameEngineVersion);
	register_method((char*)"conf_sqk_game_engine_version", &GameAnalytics::configureSdkGameEngineVersion);
}

GODOT_NATIVE_INIT(godot_native_init_options *options) {
	register_class<GameAnalytics>();
}

GODOT_NATIVE_TERMINATE(godot_native_init_options *options) {

}

NS_GODOT_END

