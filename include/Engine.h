#pragma once

#include "Render.h"
#include "Export.h"

class Engine
{
public:
    Engine() = delete;

    ENGINE_API static void Initialize();
    ENGINE_API static void InputInitialize();
    ENGINE_API static void Tick();
    ENGINE_API static void Clear();

    /*
    static OnlineGameScreen* client;
    */
    static Render render;
    static GUIHandler gui_handler;

    ENGINE_API static Render& GetRender();

};
