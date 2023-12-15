#pragma once
#include <iostream>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <iostream>
#include <sstream>
void SetVolume(float volume) {

	HWND hwnd = GetForegroundWindow();

	//    Получаем интерфейс управления звуковым устройством
	IAudioEndpointVolume* pEndpointVolume = NULL;
	IMMDeviceEnumerator* pEnumerator = NULL;
	CoInitialize(NULL);
	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
	IMMDevice* pDevice = NULL;
	pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
	pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pEndpointVolume);

	//  Устанавливаем громкость
	pEndpointVolume->SetMasterVolumeLevelScalar(volume, NULL);

	//Освобождаем ресурсы
	pDevice->Release();
	pEnumerator->Release();
	pEndpointVolume->Release();
	CoUninitialize();
}
float GetVolume(HANDLE hWaveOut) {
	float volume = 0.0f;

	//Инициализация COM (Component Object Model)
	CoInitialize(NULL);

	//Получаем интерфейс управления звуковым устройством
	IAudioEndpointVolume* pEndpointVolume = NULL;
	IMMDeviceEnumerator* pEnumerator = NULL;

	//Создаем экземпляр объекта для работы с устройствами воспроизведения
	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);

	//Получаем устройство воспроизведения по умолчанию
	IMMDevice* pDevice = NULL;
	pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);

	//Активируем интерфейс управления громкостью
	pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pEndpointVolume);

	//Получаем текущий уровень громкости
	pEndpointVolume->GetMasterVolumeLevelScalar(&volume);

	//Освобождаем ресурсы
	pDevice->Release();
	pEnumerator->Release();
	pEndpointVolume->Release();

	//Завершаем работу с COM
	CoUninitialize();

	return volume;
}