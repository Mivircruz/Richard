#include "gameobjectmanager.h"

#include "tools/logger.h"
#include "core/engine.h"

namespace Richard::Physics {
	/*Public methods*/

	void GameObjectManager::Submit(string id, shared_ptr<GameObject> gameObject) {
		mGameObjects[id] = (move(gameObject));
	}

	void GameObjectManager::Update() {
		map<string, shared_ptr<GameObject>>::iterator it = mGameObjects.begin();

		// Iterate through the map and print the elements
		while (it != mGameObjects.end()) {
			it->second->Update();

			++it;
		}
	}

	void GameObjectManager::Render() {
		map<string, shared_ptr<GameObject>>::iterator it = mGameObjects.begin();

		// Iterate through the map and print the elements
		while (it != mGameObjects.end()) {
			it->second->Render();

			++it;
		}

		Engine::GetInstance()->GetRenderer()->Execute();
	}

	void GameObjectManager::Clear() {
		mGameObjects.clear();
	}

	void GameObjectManager::DeleteGameObject(string id) {
		mGameObjects.erase(id);
	}
}