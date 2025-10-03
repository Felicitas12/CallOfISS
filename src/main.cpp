#include <Engine.h>
#include <iostream>
#include <Window.h>
#include <Entity.h>
#include <UUID.h>
#include <Scene.h>

int main() {

    Engine::Initialize();

    /*SceneSerializer ss; // загружает сцену из файла, но ее пока шо нет
     ss.Deserialize("scene.yaml");*/

    Engine::GetRender().init_buffers(Window::GetWindowWidth(), Window::GetWindowHeight());

    Engine::InputInitialize();

    //все что выше не трогать, это инициализация движка


    Entity earth("Earth", "assets/objects/SpaceItems/Earth_1_12756.glb");
    earth.set_scale(glm::vec3(0.3F));
    earth.set_position(glm::vec3(0.0f, -10.0f, 0.0f));
    Scene::createEntity(earth);

    //где то тут можешь делать все что угодно, например создавать энтити и добавлять их в сцену



    while (!Window::ShouldClose())
    {

        // Render::getLightSources().set_directional_light(0, glm::normalize(-earth_pos), glm::vec3{ 6.0f });
        // берем сущевствующий свет и меняем его направленность

       // Render::getLightSources().send_changes(); отправляем все изменения с освещением в шейдеры

        // до тик инпута
        Engine::Tick(); //тут небольшой просак, потом разделю тик
        // после прохода отрисовки



        Window::SwapBuffers();//конец кадра
    }
    Engine::Clear();

    // сотреш потом комменты

    return 0;
}
