#include <Engine.h>
#include <iostream>
#include <Window.h>
#include <Entity.h>
#include <UUID.h>
#include <Scene.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>


int main() {

    Engine::Initialize();

	/*SceneSerializer ss; // загружает сцену из файла, но ее пока шо нет
     ss.Deserialize("scene.yaml");*/

    Engine::GetRender().init_buffers(Window::GetWindowWidth(), Window::GetWindowHeight());

    Engine::InputInitialize();

	//все что выше не трогать, это инициализация движка

    Entity earth("Earth", "assets/objects/SpaceItem/Planets/Earth_1_12756.glb");
    earth.set_scale(glm::vec3(1.0F));
    Scene::createEntity(earth);

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
