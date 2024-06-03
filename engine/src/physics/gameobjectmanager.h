#pragma once

#include <memory>
#include <map>
#include <string>

#include "gameobject.h"

using namespace std;


namespace Richard::Physics {
	class GameObjectManager {
	public:
		/* Methods*/

		/*
		* Submit() adds the game object to the map.
		*/
		void Submit(string id, shared_ptr<GameObject> gameObject);

		/*
		* Update() updates all the gameobjects.
		*/
		void Update();

		/*
		* Render() renders all the gameobjects.
		*/
		void Render();

		/*
		* Clear() empties the map.
		*/
		void Clear();

		/*
		* DeleteGameObject() deletes the game object identified with the id provided.
		*/
		void DeleteGameObject(string id);


	private:
		/*Member variables*/

		/*
		* Map with all the commands that will be executed in the rendering pipeline.
		*/
		map<string, shared_ptr<GameObject>> mGameObjects;
	};
}