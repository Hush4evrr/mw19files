sig_offsets::Unlockall = PatternScanEx2(g_data::base + 0x550000, 0x1F0000, xorstr("\x33\xFF\x48\x8D\x15\x00\x00\x00\x00\x48\x89\x05\x00\x00\x00\x00\x48\x8D\x0D"), xorstr("xxxxx????xxx????xxx")) - g_data::base;
	sig_offsets::Unlockallfix = PatternScanEx2(g_data::base + 0x06300000, 0xF00000, xorstr("\x48\x8D\x05\x00\x00\x00\x00\x44\x8B\xCB\x44\x8B\xC7\x48\x89\x44\x24\x00\x41\x8B\xD6\xE8\x00\x00\x00\x00"), xorstr("xxx????xxxxxxxxxx?xxxx????")) - g_data::base;
	sig_offsets::camobase = FindOffset2(g_data::base + 0x2000000, 0x1F00000, xorstr("\x4C\x8B\x00\x00\x00\x00\x00\x4C\x8B\x00\x00\x00\x00\x00\x4D\x85\x00\x74\x00\x49\xB9"), xorstr("xx?????xx?????xx?x?xx"), 3, 7, 0,true);
	sig_offsets::camobase = sig_offsets::camobase + 0x28;
	sig_offsets::FindDvarByName = Scanner::Scanner((xorstr("E8 ? ? ? ? 48 8B F8 48 85 C0 0F 84 ? ? ? ? BA ? ? ? ? 48 8B CB E8 ? ? ? ? 85 C0 0F 84 ? ? ? ? 0F")), xorstr("DvarFindByName")).resolve_call();
	sig_offsets::DvarSetBool = Scanner::Scanner((xorstr("E8 ? ? ? ? 80 3D ? ? ? ? ? 4C 8D 35 ? ? ? ? 74 43 33 D2 F7 05 ? ? ? ? ? ? ? ? 76 2E")), xorstr("DvarSetBool")).resolve_call();
	sig_offsets::DvarSetInt = Scanner::Scanner((xorstr("40 ? 48 81 EC ? ? ? ? 48 8B ? ? ? ? ? 48 33 ? 48 89 ? ? ? ? ? ? 0F B6 ? ? 48 8B")), xorstr("DvarSetInt")).getaddr();
	sig_offsets::DvarSetFloat = Scanner::Scanner((xorstr("E8 ? ? ? ? 45 0F 2E C8")), xorstr("DvarSetFloat")).resolve_call();
	sig_offsets::R_AddObjecToScene = Scanner::Scanner((xorstr("E8 ? ? ? ? F6 43 11 04")), xorstr("R_AddObjecToScene")).resolve_call(); //e8 ? ? ? ? f6 43 ? ? 74 ? 41 8b d5 Vanguard
	sig_offsets::a_parse = utility::PatternScanEx(g_data::hProc, g_data::base + 0x02D00000, 0xF00000, "\x40\x55\x56\x41\x54\x41\x56\x41\x57\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x44\x24\x00\x45\x33\xF6\x4D\x8B\xF9\x45\x89\x31", "xxxxxxxxxxxx????xxx????xxxxxxx?xxxxxxxxx") - g_data::base;
	sig_offsets::R_AddObjecToScene_pointer = Scanner::Scanner((xorstr("83 3d ? ? ? ? ? f3 0f 10 84 24")), xorstr("R_AddObjecToScene_pointer")).resolve_cmp(); //e8 ? ? ? ? f6 43 ? ? 74 ? 41 8b d5 Vanguard
	sig_offsets::ddl_getdllbuffer = utility::PatternScanEx(g_data::hProc, g_data::base + 0x3000000, 0x2F00000, xorstr("\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x48\x8B\xE9\x49\x63\xF8\x41\x8B\xC9\x48\x63\xF2\x41\x8B\xD9\xE8\x00\x00\x00\x00"), xorstr("xxxx?xxxx?xxxx?xxxxxxxxxxxxxxxxxxxxx????")) - g_data::base;
	sig_offsets::R_AddViewmodelDObjToScene = Scanner::Scanner((xorstr("48 83 ec ? 83 3d ? ? ? ? ? 8b 84 24")), xorstr("R_AddViewmodelDObjToScene")).getaddr(); 
	sig_offsets::CgMissile = Scanner::Scanner((xorstr("48 8D 05 ? ? ? ? C7 43 ? ? ? ? ? 48 89 03 48 8B C3 C6 43 0B 01 C6 43 1D 01 C7 43 ? ? ? ? ? 48 83 C4 20 5B C3")), xorstr("CgMissile")).resolve_lea(); // works on vanguard
	sig_offsets::CgTargetAssist = Scanner::Scanner((xorstr("48 8d 05 ? ? ? ? c7 41 ? ? ? ? ? 48 89 01 41")), xorstr("CgTargetAssist")).resolve_lea(); //48 8d 05 ? ? ? ? c7 41 ? ? ? ? ? 48 89 01 41 b8 ? ? ? ? 48 83 c1 ? e8 ? ? ? ? 48 8b c3 48 83 c4 ? 5b c3 90
	sig_offsets::CgAntiLag = Scanner::Scanner((xorstr("48 8D 05 ? ? ? ? 41 B8 ? ? ? ? 48 89 06 48 8D 96")), xorstr("CgAntiLag")).resolve_lea(); // vanguard good
	//sig_offsets::CgHandler =Scanner::Scanner( xorstr("48 8D ? ? ? ? ? 48 89 ? 48 8B ? C3 ? ? B9 01 00 00 00 E9"), xorstr("CgHandler")).resolve_lea();
	/*sig_offsets::CgStaticMp = Scanner::Scanner(xorstr("E8 ? ? ? ? FF C3 48 89 07 49 81 C7 ? ? ? ? 48 8D 7F 08 3B DD 7C E2 8B"), xorstr("CgStaticMp")).resolve_call();
	sig_offsets::CgStaticMp = Scanner::Scanner(sig_offsets::CgStaticMp).resolve_lea();*/
	sig_offsets::ddl_setstring = utility::PatternScanEx(g_data::hProc, g_data::base + 0x6400000, 0x1F00000, "\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30\x49\x8B\xF0\x48\x8B\xFA\x48\x8B\xD9\x48\x85\xD2\x0F\x84\x00\x00\x00\x00\x48\x8B\x42\x10\x48\x85\xC0\x0F\x84\x00\x00\x00\x00", "xxxx?xxxx?xxxxxxxxxxxxxxxxxxx????xxxxxxxxx????") - g_data::base;
	sig_offsets::ddl_movetopath = utility::PatternScanEx(g_data::hProc, g_data::base + 0x6500000, 0xF00000, "\x48\x89\x74\x24\x00\x48\x89\x7C\x24\x00\x41\x56\x48\x83\xEC\x20\x4D\x8B\xF1\x48\x8B\xFA\x48\x85\xC9", "xxxx?xxxx?xxxxxxxxxxxxxxx") - g_data::base;
	sig_offsets::jmp_rbx = memory::find_ida_sig(0, "FF 23");
	//sig_offsets::CG_NextSnapMP = Scanner::Scanner((xorstr("E8 ? ? ? ? 33 FF 48 8B F0 39 78 1C 7E 34 48 89 5C 24 ? 48 8D")), xorstr("CG_NextSnapMP")).resolve_call();
	//game_ret = Scanner::Scanner((xorstr("33 C9 E8 ? ? ? ? 84 C0 0F 85 ? ? ? ? 33 C9 E8 ? ? ? ? 48 8B")), xorstr("game_ret")).getaddr(); //0x54a6541
	//game_ret = FindOpcodeTest((BYTE*)game_ret); // looks good vanguard
	sig_offsets::p_playerstate = Scanner::Scanner((xorstr("48 63 C1 48 69 C8 60 03 00 00 48 8D ? ? ? ? ? 48 03 C8 E9")), xorstr("p_playerstate"), 0xA).resolve_lea() - 0x18; // vanguard
	sig_offsets::Characterinfo = Scanner::Scanner((xorstr("48 8D 05 ? ? ? ? 4C 8B F1 48 89 01 8B F2 C7 81")), xorstr("Characterinfo")).resolve_lea(); //48 8b c4 44 89 40 ? 55 41 56

	sig_offsets::PreMatchCountdown = Scanner::Scanner((xorstr("E8 ? ? ? ? 84 C0 74 09 E8 ? ? ? ? 84 C0 74 2A")), xorstr("PreMatchCountdown")).resolve_call(); // vanguard
	sig_offsets::cg_t = Scanner::Scanner((xorstr("E8 ? ? ? ? 44 8B E5 44 8B C6 8B D5 49 C1 E4 05 41 8B CF 48 8B D8 E8 ? ? ? ?")), xorstr("cg_t")).resolve_call();
	sig_offsets::bounds = Scanner::Scanner((xorstr("48 8d 05 ? ? ? ? 0f 28 c2 48 89 44 24")), xorstr("bounds")).resolve_lea();
	sig_offsets::LegacyTrace = Scanner::Scanner((xorstr("E8 ? ? ? ? F3 0F 10 84 24 ? ? ? ? 0F 2F C7")), xorstr("LegacyTrace")).resolve_call();
	//sig_offsets::ddl_getrootstate = utility::FindOffset(g_data::hProc, g_data::base + 0x2000000, 0x2F00000, xorstr("\xe8\x00\x00\x00\x00\x8b\x0d\x00\x00\x00\x00\x0f\x10\x00"), xorstr("x????xx????xx?"), 1, 5, 0);
	//sig_offsets::NavigateBlueprintDDL = utility::FindOffset(g_data::hProc, g_data::base + 0x2400000, 0x1F00000, xorstr("\xE8\x00\x00\x00\x00\x84\xC0\x0F\x84\x00\x00\x00\x00\x48\x8D\x4C\x24\x00\xE8\x00\x00\x00\x00\x83\xF8\x04\x74\x7E"), "x????xxxx????xxxx?x????xxxxx", 1, 5, 0);
	//sig_offsets::Com_DDL_CreateContext = utility::FindOffset(g_data::hProc, g_data::base + 0x2700000, 0x1F00000, xorstr("\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x41\x56\x41\x57\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\xDA\x48\x8B\xF9\x33\xD2\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x8B\xC8\xE8\x00\x00\x00\x00\x80\x3D\x00\x00\x00\x00\x00"), "xxxx?xxxx?xxxx?xxxxxxxx????xxxxxxxxx????xxx????xxx????xx?????", 1, 5, 0x158);
	//sig_offsets::DDL_GetType = utility::PatternScanEx(g_data::hProc, g_data::base + 0x6500000, 0xF00000, "\x48\x85\xC9\x74\x0D\x48\x8B\x41\x10\x48\x85\xC0\x74\x04\x8B\x40\x14\xC3\xB8\x00\x00\x00\x00\xC3", "xxxxxxxxxxxxxxxxxxx????x") - g_data::base;
	////sig_offsets::DDL_SetEnum = utility::PatternScanEx(g_data::hProc, g_data::base + 0x6400000, 0x1F00000, "\x48\x89\x5C\x24\x0000\x57\x48\x83\xEC\x20\x48\x8B\xFA\x48\x8B\xD9\x33\xD2\x49\x8B\xC8\xE8", "xxxx?xxxxxxxxxxxxxxxxx") - g_data::base;
	//sig_offsets::notsure = utility::FindOffset(g_data::hProc, g_data::base + 0x2200000, 0x2F00000, xorstr("\x4C\x8D\x35\x00\x00\x00\x00\x48\x8B\xE8\x49\x8D\x8E\x00\x00\x00\x00\x48\x03\xCE\xE8\x00\x00\x00\x00\x84\xC0"), xorstr("xxx????xxxxxx????xxxx????xx"), 3, 7, 0);
	//sig_offsets::uploadbps = utility::FindOffset(g_data::hProc, g_data::base + 0x2200000, 0x2F00000, xorstr("\x48\x8D\x05\x00\x00\x00\x00\xC6\x04\x01\x01\x48\x8B\xCB\xE8\x00\x00\x00\x00\x85\xC0\x79\x0F\x48\x8D\x15\x00\x00\x00\x00"), xorstr("xxx????xxxxxxxx????xxxxxxx????"), 3, 7, 0);
	sig_offsets::loot_ptr = Scanner::Scanner((xorstr("48 8D 05 ? ? ? ? 48 03 F8 80 BF ? ? ? ? ? 75 18 48 8B 07")), xorstr("Loot")).resolve_lea();
	sig_offsets::Refdef = Scanner::Scanner((xorstr("33 0D ? ? ? ? 89 8D ? ? ? ? 48 8D 0D ? ? ? ? 33 0D")), xorstr("Refdef")).resolve_cmp();
	sig_offsets::name_array = Scanner::Scanner((xorstr("48 8D 0D ? ? ? ? 48 8B 0C C1 48 8B 01 FF 90 ? ? ? ? 8B 40 78 83 E0 07 48 83 C4 28 C3")), xorstr("name_array")).resolve_lea();
	sig_offsets::camera_base = Scanner::Scanner((xorstr("48 8B 05 ? ? ? ? 48 8B 7C 24 ? 48 05 ? ? ? ? 48 69 CA ? ? ? ? 48 03 C1 C3")), xorstr("camera_base")).resolve_mov();
	sig_offsets::gamemode = Scanner::Scanner((xorstr("3B 1D ? ? ? ? 8B E8 74 17 41 B8 ? ? ? ?")), xorstr("gamemode")).resolve_cmp();
	sig_offsets::distribute = Scanner::Scanner((xorstr("48 8B 1D ? ? ? ? BA FF FF FF FF 48 8B CF E8 ? ? ? ? 48 8B D0 48 85 C0 75 04")), xorstr("distribute")).resolve_mov();
	sig_offsets::visible = Scanner::Scanner((xorstr("48 8D 05 ? ? ? ? 48 89 87 ? ? ? ? F3 0F 11")), xorstr("visible")).resolve_lea();
	sig_offsets::ScreenPlacement = Scanner::Scanner((xorstr("48 8D 3D ? ? ? ? 4C 8B C5")), xorstr("ScreenPlacement")).resolve_lea();
	sig_offsets::WordToScreenPosReal = Scanner::Scanner((xorstr("E8 ? ? ? ? F3 44 0F 10 15 ? ? ? ? 0F 57 F6 44")), xorstr("WorldToScreenPosReal")).resolve_call();
	sig_offsets::weapon_definitions = Scanner::Scanner(xorstr("4C 8D 2D ? ? ? ? 48 8B E8 48 85 DB"), xorstr("weapon_definitions")).resolve_lea();
	sig_offsets::ClientActive = Scanner::Scanner((xorstr("E8 ? ? ? ? 83 7B 24 00 ? ? 83 7B 28 00")), xorstr("ClientActive")).resolve_call();
	//sig_offsets::CG_Entity_patch = Scanner::Scanner((xorstr("0f 85 ? ? ? ? 8b cb 4c 89 74 24")), xorstr("CG_Entity_patch")).getaddr(); // not needed atm
	//sig_offsets::CG_Entity = Scanner::Scanner((xorstr("40 ? 53 57 48 8D ? ? ? 48 81 EC ? ? ? ? 48 63")), xorstr("CG_Entity")).getaddr(); //  not needed atm
	sig_offsets::UI_SafeTranslateString = Scanner::Scanner((xorstr("40 ? 48 83 EC ? 80 39 ? 48 8B ? 75 ? 48 FF")), xorstr("UI_SafeTranslateString")).getaddr(); //vanguard
	//sig_offsets::SL_ConvertToString = Scanner::Scanner((xorstr("E8 ? ? ? ? 4C 8D ? ? ? 48 8B ? B9 ? ? ? ? E8 ? ? ? ? 84 C0 74 ? 48 8B")), xorstr("SL_ConvertToString")).resolve_call();
	sig_offsets::ddl_loadasset = Scanner::Scanner((xorstr("40 53 48 83 EC 20 E8 ? ? ? ? 48 8B D8 48 85 C0 75 15 41 B8 ? ? ? ? 48 8D 15 ? ? ? ? 8D 48 01 E8 ? ? ? ? 48 8B 43 08")), xorstr("ddl_loadasset")).getaddr();
	sig_offsets::DDL_GetRootState = Scanner::Scanner((xorstr("33 C0 C7 41 ?? ?? ?? ?? ?? 48 89 41 10 89 41 04 48 8B C1 48 89 51 18 C6 01 01 C3")), xorstr("DDL_GetRootState")).getaddr();
	sig_offsets::CL_PlayerData_GetDDLBuffer = Scanner::Scanner((xorstr("48 89 ? ? ? 48 89 ? ? ? 48 89 ? ? ? 57 48 83 EC ? 48 8B ? 49 63 ? 41 8B ? 48 63")), xorstr("CL_PlayerData_GetDDLBuffer")).getaddr();
	sig_offsets::DDL_MoveToName = Scanner::Scanner((xorstr("E8 ? ? ? ? 84 C0 74 22 48 8D 54 24 ? 48 8D 4C 24 ? E8 ")), xorstr("DDL_MoveToName")).resolve_call();
	sig_offsets::DDL_SetInt = Scanner::Scanner((xorstr("E8 ? ? ? ? 41 88 B4 2F ? ? ? ? ")), xorstr("DDL_SetInt")).resolve_call();
	sig_offsets::DDL_SetString = Scanner::Scanner((xorstr("e8 ? ? ? ? eb ? 32 c0 4c 8d 9c 24 ? ? ? ? 49 8b 5b ? 49 8b 6b ? 49 8b 73 ? 49 8b 7b ? 49 8b e3 41 5e c3")), xorstr("DDL_SetString")).resolve_call();
	sig_offsets::DDL_MoveToPath = Scanner::Scanner((xorstr("E8 ? ? ? ? 84 C0 0F 95 C0 48 8B 8C")), xorstr("DDL_MoveToPath")).resolve_call();
	sig_offsets::Com_ParseNavStrings = Scanner::Scanner((xorstr("e8 ? ? ? ? 44 8b 44 24 ? 4c 8d 4c 24 ? 48 8b d7")), xorstr("Com_ParseNavStrings")).resolve_call();

	//sig_offsets::Com_ParseNavStrings = PatternScanEx2(g_data::base + 0x02D00000, 0xF00000, "\x40\x55\x56\x41\x54\x41\x56\x41\x57\x48\x81\xEC\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x44\x24\x00\x45\x33\xF6\x4D\x8B\xF9\x45\x89\x31", "xxxxxxxxxxxx????xxx????xxxxxxx?xxxxxxxxx") - g_data::base;
	sig_offsets::runtimeInstanceCount = Scanner::Scanner(xorstr("03 1D ? ? ? ? 3b 1d"), xorstr("runtimeInstanceCount")).resolve_cmp();
	sig_offsets::CG_ScoreboardMP_GetScore = Scanner::Scanner(xorstr("E8 ? ? ? ? 48 85 C0 75 04 33 FF EB 0D"), xorstr("CG_ScoreboardMP_GetScore")).resolve_call();
	sig_offsets::ShowToastNotificationAfterUserJoinedParty = Scanner::Scanner(xorstr("CC 48 89 74 24 ? 57 48 83 EC 20 4C 8B 05 ? ? ? ? "), xorstr("ShowToastNotificationAfterUserJoinedParty"), 1).getaddr();
	//sig_offsets::Lua_VM = Scanner::Scanner(xorstr("4c 8b 05 ? ? ? ? 48 8d 14 5b"), xorstr("Lua_VM")).resolve_mov();
	/**sig_offsets::lui_ToElement = Scanner::Scanner(xorstr("40 53 48 83 ec ? 48 8b 1d ? ? ? ? e8 ? ? ? ? 48 8b d0"), xorstr("lui_ToElement")).getaddr();
	sig_offsets::SL_FindString = Scanner::Scanner(xorstr("E8 ? ? ? ? 85 C0 74 20 4C 8D "), xorstr("SL_FindString")).resolve_call();*/
	//sig_offsets::CG_Entity_GetMutableShaderData = Scanner::Scanner(xorstr("E8 ? ? ? ? 48 8D 8D ? ? ? ? F3"), xorstr("CG_Entity_GetMutableShaderData")).resolve_call();
	//sig_offsets::CG_EntityWorkers_TryAddDObjDrawRequest = Scanner::Scanner(xorstr("48 89 7C 24 ? E8 ? ? ? ? 84 C0 0F"), xorstr("CG_EntityWorkers_TryAddDObjDrawRequest")).getaddr();
	//sig_offsets::CG_Entity_AddDObjToScene = Scanner::Scanner(xorstr("E8 ? ? ? ? 0F 28 BC 24 ? ? ? ? 41 F7"), xorstr("CG_Entity_AddDObjToScene")).resolve_call();
	//sig_offsets::R_EndFrame = Scanner::Scanner(xorstr("48 83 ec ? e8 ? ? ? ? 48 8b 15 ? ? ? ? 45 "), xorstr("R_EndFrame")).getaddr();
	//sig_offsets::CG_PredictMP_PredictPlayerState = Scanner::Scanner(xorstr("e8 ? ? ? ? 8b cb e8 ? ? ? ? 8b cb 48 83 c4 ? 5b e9 ? ? ? ? 00 00"), xorstr("CG_PredictMP_PredictPlayerState")).resolve_call(); // vanguard 	e8 ? ? ? ? 8b cb e8 ? ? ? ? 8b cb 48 83 c4 ? 5b e9 ? ? ? ? 0a 00
	/*sig_offsets::R_AddCmdDrawText = Scanner::Scanner((xorstr("44 89 74 24 ? E8 ? ? ? ? 48 8B 4D")), ("R_AddCmdDrawText2"), 5).resolve_call();
	sig_offsets::R_RegisterFont = Scanner::Scanner((xorstr("E8 ? ? ? ? 48 89 05 ? ? ? ? 8B 05 ? ? ? ? 83")), ("R_RegisterFont")).resolve_call();
	sig_offsets::Material_RegisterHandle = Scanner::Scanner((xorstr("c6 05 ? ? ? ? ? b2 ? 48 8d 0d ? ? ? ? e8 ? ? ? ? b2")), ("Material_RegisterHandle"), 0x10).resolve_call();
	*///sig_offsets::CG_DrawRotatedPicPhysicalW = Scanner::Scanner((xorstr("E8 ? ? ? ? 44 0F 28 8C 24 ? ? ? ? 44 0F 28 84 24 ? ? ? ? 0F 28 BC 24 ? ? ? ? 0F 28 B4 24 ? ? ? ? 4C 8B B4 24 ? ? ? ? 48 8B BC 24")), ("DrawStretchPicPhysicalRotateXY")).resolve_call();
	//sig_offsets::CG_GetCrosshairColorAsInt = Scanner::Scanner((xorstr("48 83 ec ? 48 8b 05 ? ? ? ? 48 33 c4 48 89 44 24 ? f3 0f 10 0d")), ("CG_GetCrosshairColorAsInt")).getaddr();
	//sig_offsets::CGWeaponSystem = Scanner::Scanner((xorstr("48 8d 0d ? ? ? ? 48 89 08 48 83 c4 ? 5b c3 cc 75")), ("CGWeaponSystem")).resolve_lea();
	//std::ptrdiff_t _skip1 = 0x50000;
	//std::ptrdiff_t  searchStart1 = (std::ptrdiff_t)memory::modinfo(memory::info::modbase) + _skip1;
	//std::ptrdiff_t searchEnd1 = searchStart1 + ((std::ptrdiff_t)memory::modinfo(memory::info::imagesize) - _skip1);
	//g__LUI_Get_CrosshairColor = Scanner::Scanner(CG_HUD_ROTATION_SIG, ("g__LUI_DataBinding_Get_CrosshairColor")).resolve_lea();
	//sig_offsets::cbuf_offset = Scanner::Scanner(xorstr("4c 63 c0 48 8d 15 ? ? ? ? e8 ? ? ? ? 01 bb ? ? ? ? b9 ? ? ? ? 48 81 c4 ? ? ? ? 5f 5b 5d e9 ? ? ? ? 66"), xorstr("cbuf_offset")).resolve_lea();
	//sig_offsets::gscr_EndLobby = Scanner::Scanner(xorstr("40 55 53 57 48 8B EC 48 81 EC ? ? ? ? 48 8B 1D ? ? ? ? 90 C6 45 28 79 0F B6 45 28 83 F0 19 65 4C 8B 18 48 85 DB 0F 84 ? ? ? ? "), xorstr("gscr_EndLobby"),0xC).getaddr();
	sig_offsets::DVARBOOL_cl_packetdup = Scanner::Scanner(xorstr("E8 ? ? ? ? 84 C0 0F 84 ? ? ? ? ? ? ? ? ? 04 00 0F 8E"), xorstr("DVARBOOL_cl_packetdup"), 0x1A).resolve_mov();
	//sig_offsets::ClActiveClient_GetClient = Scanner::Scanner(xorstr("e8 ? ? ? ? 8b c8 e8 ? ? ? ? eb ? e8 ? ? ? ? 8b c8"), xorstr("ClActiveClient_GetClient"), 0x2D).resolve_call();


	

	sig_offsets::s_scriptableClLootCount = Scanner::Scanner(xorstr("47 0F B7 BC 65 ? ? ? ?"), xorstr("LootCount"), 0x5).get_offset<int>();

	sig_offsets::ScriptableMapDef = Scanner::Scanner(xorstr("4B 8B ? ? ? ? ? ? 48 85 ? 0F 84 ? ? ? ? 4C 8B"), xorstr("ScriptableMapDef"), 0x14).get_offset<int>();

	sig_offsets::ClientContext = Scanner::Scanner(xorstr("4B 8B ? ? ? ? ? ? 4D 8B ? ? 41 8B"), xorstr("ClientContext"), 0x4).get_offset<int>();

	sig_offsets::s_scriptableClLootTable = Scanner::Scanner(xorstr("4B 8B ? ? ? ? ? ? 48 85 ? 0F 84 ? ? ? ? 4C 8B"), xorstr("LootTable"), 0x4).get_offset<int>();

	sig_offsets::Recoil = Scanner::Scanner((xorstr("49 8D 90 ? ? ? ? 8B 42 10")), xorstr("Recoil"), 0x3).get_offset<int>();

	sig_offsets::local_index = Scanner::Scanner((xorstr("48 83 bb ? ? ? ? ? 0f 84 ? ? ? ? 83 bb ? ? ? ? ? 0f 84")), xorstr("temp_local_index"), 0x3).get_offset<int>();

	sig_offsets::player_team = Scanner::Scanner((xorstr("48 63 8D ? ? ? ? 48 69 C9 ? ? ? ? 48 03 C8 EB 15")), xorstr("player_team"), 0x2A).get_offset<int>();

	//sig_offsets::player_team = Scanner::Scanner((xorstr("8B 87 ? ? ? ? 4C 8B BC 24 ? ? ? ? 4C 8B B4 24 ? ? ? ? 4C 8B AC 24 ? ? ? ? 4C 8B A4 24 ? ? ? ? 85 C0 74 16 3B 81 ? ? ? ? 75 0E B0 01 48 81 C4 ? ? ? ? 5F 5E 5B 5D C3 ")), xorstr("player_team"), 0x2A).get_offset<int>();

	sig_offsets::stance = Scanner::Scanner((xorstr("0F 48 F0 83 BF ? ? ? ? ? 75 0A F3 0F 10 35 ? ? ? ? EB 08")), xorstr("stance"), 0x5).get_offset<int>();

	sig_offsets::position = Scanner::Scanner((xorstr("48 8B EA 75 ? 49 83 ? ? ? ? ? ? 74")), xorstr("position"), 0x8).get_offset<int>();

	sig_offsets::weaponmap = Scanner::Scanner((xorstr("49 8B 84 F0 ? ? ? ? 48 C1 E1 06 48 8B 40 08 0F B7 54 08 ? 66")), xorstr("weaponmapaddr"), 0x4).get_offset<int>();

	

	sig_offsets::vieworigin = Scanner::Scanner((xorstr("89 83 ? ? ? ? 8B 47 04 89 83 ? ? ? ? 8B 47 08 89 83 ? ? ? ? 48 8B 5C 24 ? 48 83 C4 20 5F C3")), xorstr("origin"), 0x2).get_offset<int>();

	

	
	sig_offsets::ddl_getint = FindOffset2(g_data::base + 0x3500000, 0xF00000, "\xE8\x00\x00\x00\x00\x40\x38\x35\x00\x00\x00\x00\x8B\xF8\x74\x58", "x????xxx????xxxx", 3, 7, 0, true) - g_data::base;

	sig_offsets::clanttag = PatternScanEx2(g_data::base + 0x4000000, 0x1F00000, xorstr("\x40\x53\x48\x83\xEC\x30\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x44\x24\x00\x4C\x8B\xCA\x41\xB8\x00\x00\x00\x00\x8B\x15\x00\x00\x00\x00\x8B\xD9"), xorstr("xxxxxxxxx????xxxxxxx?xxxxx????xx????xx")) - g_data::base;
