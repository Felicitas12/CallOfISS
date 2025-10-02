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

    Entity map("map", "assets/objects/Sun_1_1391000.usdz");
    map.set_scale(glm::vec3(5.15F));
    auto mapUUID = UUID();
    //map.make_collision(mapUUID, "assets/objects/sponzaAtrium/Sponza.gltf",  true);
    Scene::createEntityWithUUID(mapUUID, map);


	//где то тут можешь делать все что угодно, например создавать энтити и добавлять их в сцену
    
    while (!Window::ShouldClose())
    {
        // до тик инпута
        Engine::Tick(); //тут небольшой просак, потом разделю тик
        // после прохода отрисовки

        

		Window::SwapBuffers();//конец кадра
    }
    Engine::Clear();

    // сотреш потом комменты

    return 0;
}
