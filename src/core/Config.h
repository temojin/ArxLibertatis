/*
 ===========================================================================
 ARX FATALIS GPL Source Code
 Copyright (C) 1999-2010 Arkane Studios SA, a ZeniMax Media company.

 This file is part of the Arx Fatalis GPL Source Code ('Arx Fatalis Source Code').

 Arx Fatalis Source Code is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
 License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

 Arx Fatalis Source Code is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with Arx Fatalis Source Code.  If not, see
 <http://www.gnu.org/licenses/>.

 In addition, the Arx Fatalis Source Code is also subject to certain additional terms. You should have received a copy of these
 additional terms immediately following the terms and conditions of the GNU General Public License which accompanied the Arx
 Fatalis Source Code. If not, please request a copy in writing from Arkane Studios at the address below.

 If you have questions concerning this license or the applicable additional terms, you may contact in writing Arkane Studios, c/o
 ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
 ===========================================================================
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <string>

#include "core/ConfigHashMap.h"
#include "gui/MenuWidgets.h"

enum
{
	MAX_ACTION_KEY = 40
};

struct SACTION_KEY
{
	int	iKey[2];
	int iPage;
};

class Config
{
	public:
		//LANGUAGE
		std::string pcName;
		//VIDEO
		int			iWidth;
		int			iHeight;
		int			iNewWidth;
		int			iNewHeight;
		int bpp;
		int			iNewBpp;
		bool		bFullScreen;
		bool		bBumpMapping;
		bool		bNewBumpMapping;
		bool		bMouseSmoothing;
		int			iTextureResol;
		int			iNewTextureResol;
		int			iMeshReduction;
		int			iLevelOfDetails;
		int			iFogDistance;
		int			iGamma;
		int			iLuminosite;
		int			iContrast;
		bool		bShowCrossHair;
		bool		bAntiAliasing;
		bool		bChangeResolution;
		bool		bChangeTextures;
		bool		bDebugSetting;
		//AUDIO
		int			iMasterVolume;
		int			iSFXVolume;
		int			iSpeechVolume;
		int			iAmbianceVolume;
		bool		bEAX;
		//INPUT
		bool		bInvertMouse;
		bool		bAutoReadyWeapon;
		bool		bMouseLookToggle;
		bool		bAutoDescription;
		int			iMouseSensitivity;
		SACTION_KEY sakActionKey[MAX_ACTION_KEY];
		SACTION_KEY sakActionDefaultKey[MAX_ACTION_KEY];
		bool		bLinkMouseLookToUse;
		//MISC
		bool		bATI;
		bool		bForceZBias;
		bool		bOneHanded;
		unsigned int uiGoreMode;

		bool first_launch;

		bool		bNoReturnToWindows;
	private:
		ConfigHashMap config_map; // Map containing the config file contents

		int GetDIKWithASCII( const std::string& _pcTouch);
		std::string ReadConfig( const std::string& _pcSection, const std::string& _pcKey) const;
		bool WriteConfig( const std::string& _pcSection, const std::string& _pcKey, const std::string& _pcDatas);

	public:
		Config();
		Config( const std::string& );
		virtual ~Config();

		int ReadConfigInt( const std::string& _pcSection, const std::string& _pcKey, bool & _bOk);

		std::string ReadConfig( const std::string& section, const std::string& key, const std::string& default_value ) const;
		int ReadConfig( const std::string& section, const std::string& key, int default_value ) const;
		bool ReadConfig( const std::string& section, const std::string& key, bool default_value ) const;

		void WriteConfig( const std::string& section, const std::string& key, bool data );
		void WriteConfig( const std::string& section, const std::string& key, int data );
		//void WriteConfig( const std::string& section, const std::string& key, const std::string& data );
		bool WriteConfigInt( const std::string& _pcSection, const std::string& _pcKey, int _iDatas);
		bool WriteConfigString( const std::string& _pcSection, const std::string& _pcKey, const std::string& _pcDatas);

		bool SetActionKey(int _iAction, int _iActionNum, int _iVirtualKey);
		void ResetActionKey();
		bool WriteConfigKey( const std::string& _pcKey, int _iAction);
		bool ReadConfigKey( const std::string& _pcKey, int _iAction);
		void ReInitActionKey(CWindowMenuConsole * _pwmcWindowMenuConsole);
		void SetDefaultKey();
		void DefaultValue();
		void First();

		bool SaveAll();
		bool ReadAll();
};

extern Config* pMenuConfig;

#endif // CONFIG_H