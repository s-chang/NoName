#pragma once

#include <string>
#include <map>
#include <vector>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include "Drawable.h"

typedef IDirect3DTexture9* pDirectTexture;
typedef D3DXIMAGE_INFO iInfo;

//TODO:  Create a function to load only assets that are needed for the screen/area

namespace Engine
{
	class Graphics
	{
	private:
		void loadTextures();
		Graphics();

		pDirectTexture error;
		iInfo errorinfo;

		struct TextureValue
		{
			pDirectTexture texture;
			iInfo info;
		};

		std::map<std::string, TextureValue> textureStorage;

	public:
		static Graphics* instance();
		~Graphics();

		void init();
		void shutdown();

		void render(Drawable object);
		
		pDirectTexture getTexture(const std::string handle);
		iInfo getInfo(const std::string handle);
	};
};