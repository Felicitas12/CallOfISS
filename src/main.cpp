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


    Entity earth("Earth", "assets/objects/SpaceItems/Earth_1_12756.glb");
    earth.set_scale(glm::vec3(0.3F));
    earth.set_position(glm::vec3(0.0f, -10.0f, 0.0f));
    Scene::createEntity(earth);

    //��� �� ��� ������ ������ ��� ��� ������, �������� ��������� ������ � ��������� �� � �����



    while (!Window::ShouldClose())
    {

        // Render::getLightSources().set_directional_light(0, glm::normalize(-earth_pos), glm::vec3{ 6.0f });
        // ����� ������������� ���� � ������ ��� ��������������

       // Render::getLightSources().send_changes(); ���������� ��� ��������� � ���������� � �������

        // �� ��� ������
        Engine::Tick(); //��� ��������� ������, ����� ������� ���
        // ����� ������� ���������



        Window::SwapBuffers();//����� �����
    }
    Engine::Clear();

    // ������ ����� ��������

    return 0;
}
