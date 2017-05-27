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

#ifndef GAME_ANALYTICS_H
#define GAME_ANALYTICS_H

#include <common.h>
#include <cpp/GameAnalytics.h>

#include <Godot.hpp>
#include <Reference.hpp>

NS_GODOT_BEGIN

/**
 * @brief The GameAnalytics works with Linux, Window, Mac OS.
 *
 * Need changes with Android/IOS
 */

class GameAnalytics : public GodotScript<Reference> {
	GODOT_CLASS(GameAnalytics)

	/**
	 * Todo: Bind enums with GDNativie.
	 */

	enum EGAResourceFlowType { Source = 1, Sink };
	enum EGAProgressionStatus { Start = 1, Complete, Fail };
	enum EGAErrorSeverity { Debug = 1, Info, Warning, Error, Critical };
	enum EGAGender { Male =1, Female };

public:
	GameAnalytics();
	~GameAnalytics();

	void init(Variant key, Variant secret);

	void setEnabledInfoLog(bool value);
	void setEnabledVerboseLog (bool value);
	void setCustomDimension01(Variant customDimension);
	void setCustomDimension02(Variant customDimension);
	void setCustomDimension03(Variant customDimension);
	void setFacebookId(Variant facebookId);
	void setGender(int gender);
	void setBirthYear(int birthYear);

	void setEnabledManualSessionHandling(bool flag);

	void startSession();
	void endSession();

	void addBusinessEvent(
	Variant currency, int amount, Variant itemType, Variant itemId, Variant cartType);

	void addResourceEvent(
	int flowType, Variant currency, float amount, Variant itemType, Variant itemId);

	void addProgressionEvent(
	int progressionStatus, Variant progression01, Variant progression02, Variant progression03, int score);

	void addDesignEvent(Variant eventId, float value);
	void addErrorEvent(int severity, Variant message);

	void configureAvailableCustomDimensions01(Variant list);
	void configureAvailableCustomDimensions02(Variant list);
	void configureAvailableCustomDimensions03(Variant list);

	void configureAvailableResourceCurrencies(Variant list);
	void configureAvailableResourceItemTypes(Variant list);

	void configureBuild(Variant buildID);
	void configureUserId(Variant uId);
	void configureSdkGameEngineVersion(Variant sdkGameEngineVersion);
	void configureGameEngineVersion(Variant engineVersion);

	static void _register_methods ();

private:
	String name;
	String key, secret;
};

NS_GODOT_END

#endif // GAME_ANALYTICS_H
