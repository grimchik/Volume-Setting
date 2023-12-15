#pragma once
#include <iostream>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <iostream>
#include <sstream>
void SetVolume(float volume) {

	HWND hwnd = GetForegroundWindow();

	//    �������� ��������� ���������� �������� �����������
	IAudioEndpointVolume* pEndpointVolume = NULL;
	IMMDeviceEnumerator* pEnumerator = NULL;
	CoInitialize(NULL);
	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
	IMMDevice* pDevice = NULL;
	pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
	pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pEndpointVolume);

	//  ������������� ���������
	pEndpointVolume->SetMasterVolumeLevelScalar(volume, NULL);

	//����������� �������
	pDevice->Release();
	pEnumerator->Release();
	pEndpointVolume->Release();
	CoUninitialize();
}
float GetVolume(HANDLE hWaveOut) {
	float volume = 0.0f;

	//������������� COM (Component Object Model)
	CoInitialize(NULL);

	//�������� ��������� ���������� �������� �����������
	IAudioEndpointVolume* pEndpointVolume = NULL;
	IMMDeviceEnumerator* pEnumerator = NULL;

	//������� ��������� ������� ��� ������ � ������������ ���������������
	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);

	//�������� ���������� ��������������� �� ���������
	IMMDevice* pDevice = NULL;
	pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);

	//���������� ��������� ���������� ����������
	pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pEndpointVolume);

	//�������� ������� ������� ���������
	pEndpointVolume->GetMasterVolumeLevelScalar(&volume);

	//����������� �������
	pDevice->Release();
	pEnumerator->Release();
	pEndpointVolume->Release();

	//��������� ������ � COM
	CoUninitialize();

	return volume;
}