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

	/*SceneSerializer ss; // ��������� ����� �� �����, �� �� ���� �� ���
     ss.Deserialize("scene.yaml");*/

    Engine::GetRender().init_buffers(Window::GetWindowWidth(), Window::GetWindowHeight());

    Engine::InputInitialize();

	//��� ��� ���� �� �������, ��� ������������� ������

    Entity earth("Earth", "assets/objects/SpaceItem/Planets/Earth_1_12756.glb");
    earth.set_scale(glm::vec3(1.0F));
    Scene::createEntity(earth);

	//��� �� ��� ������ ������ ��� ��� ������, �������� ��������� ������ � ��������� �� � �����
    
    while (!Window::ShouldClose())
    {
        // �� ��� ������
        Engine::Tick(); //��� ��������� ������, ����� ������� ���
        // ����� ������� ���������

        

		Window::SwapBuffers();//����� �����
    }
    Engine::Clear();

    // ������ ����� ��������

    return 0;
}
