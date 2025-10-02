#pragma once

#include "Entity.h"
#include "UUID.h"

class OnlineGameScreen;
class PlayerController;
class Terrain;
class AnimEntity;
class SoundEffectsPlayer;

class Scene
{

public:
	Scene() = delete;

	static void Initialize();
	static void Tick();
	static void Clear();

	ENGINE_API inline static PlayerController& GetCamera();
	ENGINE_API inline static std::unordered_map<UUID, Entity>& getEntities();
	ENGINE_API inline static Entity& getEntity(const UUID id);

	ENGINE_API inline static std::unordered_map<UUID, std::unique_ptr<AnimEntity>>& getAnimEntities();
	ENGINE_API inline static std::unordered_map<UUID, Terrain>& getTerrain();
	ENGINE_API inline static std::unordered_map<UUID, std::unique_ptr<SoundEffectsPlayer>>& getSoundPlayer();

	ENGINE_API static void createEntity(const Entity& gameObject);
	ENGINE_API static void createAnimEntity(std::unique_ptr<AnimEntity> anim_entity);
	ENGINE_API static void createSoundPlayer(std::unique_ptr<SoundEffectsPlayer> soundPlayer);
	ENGINE_API static void createSoundPlayerWithUUID(const UUID& id, std::unique_ptr<SoundEffectsPlayer> soundPlayer);
	ENGINE_API static void createTerrainWithUUID(const UUID& id, const Terrain& terrain);
	ENGINE_API static void createEntityWithUUID(const UUID& id, const Entity& gameObject);

	ENGINE_API static bool destroyEntity(const UUID& id);
	ENGINE_API static bool destroy_sound_player(const UUID& id);
	ENGINE_API static bool destroyTerrain(const UUID& id);



private:
	static PlayerController camera;
	static std::unordered_map<UUID, Entity> entity_map;
	static std::unordered_map<UUID, std::unique_ptr<AnimEntity>> anim_entity_map;
	static std::unordered_map<UUID, Terrain> terrain_map;
	static std::unordered_map<UUID, std::unique_ptr<SoundEffectsPlayer>> sound_players_map;

};

