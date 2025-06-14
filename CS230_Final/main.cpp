/*
Copyright (C) 2023 DigiPen Institute of Technology
Reproduction or distribution of this file or its contents without
prior written consent is prohibited
File Name:  main.cpp
Project:    CS230 Engine
Author:     Taekyung Ho
Created:    March 4, 2025
*/

#include <iostream>

#include "Engine/Engine.h"
#include "Game/Splash.h"
#include "Game/MainMenu.h"
#include "Game/Project.h"
#include "Game/GoodSandwich.h"
#include "Game/NormalSandwich.h"
#include "Game/BadSandwich.h"

int main() {
    try {
        Engine& engine = Engine::Instance();
        engine.Start("Assignment 12 - taekyung.ho@digipen.edu");

        engine.AddFont("Assets/Font_Simple.png");
        engine.AddFont("Assets/Font_Outlined.png");

        Splash splash;
        engine.GetGameStateManager().AddGameState(splash);
        MainMenu mainmenu;
        engine.GetGameStateManager().AddGameState(mainmenu);
        Project project;
        engine.GetGameStateManager().AddGameState(project);
        GoodSandwich goodsandwich;
        engine.GetGameStateManager().AddGameState(goodsandwich);
        NormalSandwich normalsandwich;
        engine.GetGameStateManager().AddGameState(normalsandwich);
        BadSandwich badsandwich;
        engine.GetGameStateManager().AddGameState(badsandwich);


        while (engine.HasGameEnded() == false) {
            engine.Update();
        }

        engine.Stop();

        return 0;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << "\n";
        return -1;
    }

}


