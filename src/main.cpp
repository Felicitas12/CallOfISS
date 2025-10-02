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

    Entity map("map", "assets/objects/sponzaAtrium/Sponza.gltf");
    map.set_scale(glm::vec3(5.15F));
    auto mapUUID = UUID();
    //map.make_collision(mapUUID, "assets/objects/sponzaAtrium/Sponza.gltf",  true); <-- созадает детальную коллизию, по которой можно например ходить
    Scene::createEntityWithUUID(mapUUID, map); 

	//где то тут можешь делать все что угодно, например создавать энтити и добавлять их в сцену
    

    while (!Window::ShouldClose())
    {
        Engine::Tick();

        


        Window::SwapBuffers();
    }
    Engine::Clear();


    return 0;
}
