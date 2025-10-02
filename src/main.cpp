#include <Engine.h>
#include <iostream>
#include <Window.h>
#include <Entity.h>
#include <UUID.h>
#include <Scene.h>


int main() {

    Engine::Initialize();

	/*SceneSerializer ss; // ��������� ����� �� �����, �� �� ���� �� ���
     ss.Deserialize("scene.yaml");*/

    Engine::GetRender().init_buffers(Window::GetWindowWidth(), Window::GetWindowHeight());

    Engine::InputInitialize();

	//��� ��� ���� �� �������, ��� ������������� ������

    Entity map("map", "assets/objects/sponzaAtrium/Sponza.gltf");
    map.set_scale(glm::vec3(5.15F));
    auto mapUUID = UUID();
    //map.make_collision(mapUUID, "assets/objects/sponzaAtrium/Sponza.gltf",  true); <-- �������� ��������� ��������, �� ������� ����� �������� ������
    Scene::createEntityWithUUID(mapUUID, map); 

	//��� �� ��� ������ ������ ��� ��� ������, �������� ��������� ������ � ��������� �� � �����
    

    while (!Window::ShouldClose())
    {
        Engine::Tick();

        


        Window::SwapBuffers();
    }
    Engine::Clear();


    return 0;
}
