#include "Graphics.h"
#include <fstream>
#include "DX.h"

//helper function
std::wstring string2wstring(const std::string word)
{
	int length;
	int slength = (int)word.length() + 1;
	length = MultiByteToWideChar(CP_ACP, 0, word.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[length];
	MultiByteToWideChar(CP_ACP, 0, word.c_str(), slength, buf, length);
	std::wstring wWord(buf);
	delete[] buf;
	return wWord;
}

Engine::Graphics::Graphics()
{}

Engine::Graphics::~Graphics()
{}

Engine::Graphics* Engine::Graphics::instance()
{
	static Graphics instance;
	return &instance;
}

void Engine::Graphics::init()
{
	loadTextures();

	//TODO: create and load shader/shader manager
}

void Engine::Graphics::render(Drawable object)
{
	D3DXMATRIX transMat, scaleMat, rotMat, worldMat;

	D3DXMatrixIdentity(&transMat);
	D3DXMatrixIdentity(&scaleMat);
	D3DXMatrixIdentity(&rotMat);
	D3DXMatrixIdentity(&worldMat);

	D3DXMatrixScaling(&scaleMat, object.getScale().x, object.getScale().y, object.getScale().z);
	D3DXMatrixTranslation(&transMat, object.getTranslate().x, object.getTranslate().y, object.getTranslate().z);
	D3DXMatrixRotationYawPitchRoll(&rotMat, D3DXToRadian(object.getRotate().y),D3DXToRadian(object.getRotate().x), D3DXToRadian(object.getRotate().z));
	D3DXMatrixMultiply(&scaleMat, &scaleMat, &rotMat);
	D3DXMatrixMultiply(&worldMat, &scaleMat, &transMat);

	Engine::DX::instance()->getSprite()->SetTransform(&worldMat);

	Engine::DX::instance()->getSprite()->Draw(
		getTexture(object.getHandle()),
		object.getIsSpriteSheet() ? &object.getRect() : 0,
		object.getIsSpriteSheet() ? &dVec3(object.getWidth() * 0.5f, object.getHeight() * 0.5f, 0.0f) : &dVec3(getInfo(object.getHandle()).Width *0.5f, getInfo(object.getHandle()).Height *0.5f, 0.0f),
		0,
		object.getColor());
}

void Engine::Graphics::shutdown()
{
	for(auto& texture: textureStorage)
	{
		SAFE_RELEASE(texture.second.texture);
	}
	textureStorage.clear();

	SAFE_RELEASE(error);
}

void Engine::Graphics::loadTextures()
{
	TextureValue temp_storage;

	std::string temp_file_name;
	std::string temp_handle;

	struct temp_Data
	{
		std::string temp_handle;
		std::wstring temp_file_name;
	};

	std::vector<temp_Data> tempStorageData;

	std::ifstream file("Textures.txt");

	//read til end of file
	while(!file.eof())
	{
		//store file name and handle to the file in temp variables
		file >> temp_file_name >> temp_handle;

		//create a temporary struct to hold data
		temp_Data some_data;
		some_data.temp_file_name = L"";
		some_data.temp_handle = temp_handle;

		//convert string to LPCWSTR
		some_data.temp_file_name = std::wstring(temp_file_name.begin(), temp_file_name.end());

		//push back the data
		tempStorageData.push_back(some_data);

	}

	file.close();

	//Iterate through temp data storage to create textures
	for(unsigned int i = 0; i < tempStorageData.size(); i++)
	{
		D3DXCreateTextureFromFileEx(Engine::DX::instance()->getDevice(),
			tempStorageData[i].temp_file_name.c_str(), 0, 0, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT,
			D3DCOLOR_XRGB(255,255,255), &temp_storage.info, 0, &temp_storage.texture);

		textureStorage[tempStorageData[i].temp_handle] = temp_storage;
		//set pointer to null before resuing
		temp_storage.texture = nullptr;
	}

	//Create Error texture to show errors
	D3DXCreateTextureFromFileEx(Engine::DX::instance()->getDevice(),
		L"error.png", 0, 0,0, 0,
		D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT,
		D3DCOLOR_XRGB(255,255,255), &errorinfo, 0, &error);
}

pDirectTexture Engine::Graphics::getTexture(const std::string handle)
{
	if(textureStorage.find(handle) != textureStorage.end())
		return textureStorage[handle].texture;
	else
		return error;
}

iInfo Engine::Graphics::getInfo(const std::string handle)
{
	if( textureStorage.find(handle) != textureStorage.end())
		return textureStorage[handle].info;
	else
		return errorinfo;
}

