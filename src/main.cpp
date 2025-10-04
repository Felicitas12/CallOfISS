// Engine imports
#include <Engine.h>
#include <iostream>
#include <Window.h>
#include <Entity.h>
#include <UUID.h>
#include <Scene.h>

// Other stuff
#include <string>
#include <glm/ext/quaternion_trigonometric.hpp>
#include "constants.h"

int main() {
    // Constants and variables zone
    constexpr float fullPi = glm::pi<float>();

    float earthAxis = glm::radians(earthDefaultAxis);
    glm::vec3 axisFull(0.0f, 0.0f, 1.0f);
    glm::vec3 earthAxisTilted = glm::normalize(glm::vec3(0.0f, glm::sin(glm::radians(earthDefaultAxis)), glm::cos(glm::radians(earthDefaultAxis))));
    glm::quat earthAngle = glm::angleAxis(earthAxis, earthAxisTilted);

    Engine::Initialize();

    /*SceneSerializer ss; // çàãðóæàåò ñöåíó èç ôàéëà, íî åå ïîêà øî íåò
     ss.Deserialize("scene.yaml");*/

    Engine::GetRender().init_buffers(Window::GetWindowWidth(), Window::GetWindowHeight());

    Engine::InputInitialize();

	Entity sun("Sun", "assets/objects/SpaceItems/sun.glb");
    sun.set_scale(glm::vec3(20.0F));
    auto sunUUID = UUID();
    sun.set_rotation(axisFull, sunDefaultAxis);
    Scene::createEntityWithUUID(sunUUID, sun);

    Entity iss("ISS", "assets/objects/SpaceItems/ISS_stationary.glb");
    iss.set_scale(glm::vec3(10.0F));
    iss.set_position(glm::vec3(-700.0F, 0.0F, -700.0F));
    auto issUUID = UUID();

    Scene::createEntityWithUUID(issUUID, iss);

    Entity earth("Earth", "assets/objects/SpaceItems/Earth_1_12756.glb");
    auto earthUUID = UUID();
    earth.set_scale(glm::vec3(0.3F));
	earth.set_position(glm::vec3(500.0F, 0.0F, 500.0F));
    //earth.set_rotation(earthAxisTilted, glm::radians(360.0f));
    auto earth_uuid = UUID();

	Scene::createEntityWithUUID(earth_uuid, earth);
   
    while (!Window::ShouldClose())
    {
        auto& eartsh = Scene::getEntity(earth_uuid);
        eartsh.set_rotation(earthAxisTilted, earthAxis);

        /*eartsh.set_rotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(1.0f));*/
        // Render::getLightSources().set_directional_light(0, glm::normalize(-earth_pos), glm::vec3{ 6.0f });
        // áåðåì ñóùåâñòâóþùèé ñâåò è ìåíÿåì åãî íàïðàâëåííîñòü

        // Render::getLightSources().send_changes(); îòïðàâëÿåì âñå èçìåíåíèÿ ñ îñâåùåíèåì â øåéäåðû
        Engine::Tick();
		Window::SwapBuffers();
    }
    Engine::Clear();

    return 0;
}
