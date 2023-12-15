#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include<conio.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <iostream>
#include <sstream>
#include "winmm.h"
extern "C"
{
	int check();
	DWORD getVolume(HANDLE hWaveOut);
	void setVolume(float val);
}

int main()
{
	int checkResult = check();
	if (!checkResult)
	{
		std::cout << "No Sound Card Detected\n";
		system("pause");
		return 0;
	}
	else
	{
			std::cout << "Sound Card Detected\n";
			system("pause");
			system("cls");
			while (1)
			{
			std::cout << "0 - EXIT\n1 - Get Volume\n2 - Change Volume\n";
			int choose;
			std::cin >> choose;
			switch (choose)
			{
			case(0):
				{
					std::cout << "Exit\n";
					return 0;
					break;
				}
			case(1):
			{
				float volume;
				HWAVEOUT hwo;
				WAVEFORMATEX wfx;
				wfx.wFormatTag = WAVE_FORMAT_PCM;
				wfx.nChannels = 2;
				wfx.nSamplesPerSec = 44100;
				wfx.nAvgBytesPerSec = 44100 * 2 * 2;
				wfx.nBlockAlign = 2 * 2;
				wfx.wBitsPerSample = 16;
				wfx.cbSize = 0;
				MMRESULT res = waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE);
				__asm
				{
					mov eax, volume
					mov ebx, hwo
					push ebx
					push eax
					call waveOutGetVolume
					mov volume,eax
				}
				HANDLE hWaveOut;
				volume = GetVolume(hWaveOut);
				std::cout << "Volume percent - " << volume * 100 << "%\n";
				system("pause");
				system("cls");
				break;
			}
			case(2):
			{
			float volume;
			input:
			while (true) {
				try {

					std::cout << "\nInput Volume from 0.0 to 1.0 - ";
					std::string str;
					std::cin >> str;
					volume = std::stof(str);
						if (volume < 0.0 || volume > 1.0)
						{
							system("pause");
							system("cls");
							goto input;
						}
						break;
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << '\n';
				}
			}

				HWAVEOUT hwo;
				    WAVEFORMATEX wfx;
				    wfx.wFormatTag = WAVE_FORMAT_PCM;
				    wfx.nChannels = 2;
				    wfx.nSamplesPerSec = 44100;
				    wfx.nAvgBytesPerSec = 44100 * 2*2;
				    wfx.nBlockAlign = 2*2;
				    wfx.wBitsPerSample = 16;
				    wfx.cbSize = 0;
				    MMRESULT res= waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE);
					__asm
					{
						mov eax, volume
						mov ebx, hwo
						push ebx
						push eax
						call waveOutSetVolume
						mov eax, volume
						mov volume, eax
					}
				SetVolume(volume);
				system("pause");
				system("cls");
				break;
			}
			default:
			{
				std::cout << "Incorrect input!\n";
				system("pause");
				system("cls");
				break;
			}
				break;
			}
		}
	}
	
}
//#include <windows.h>
//#include <mmsystem.h>
//#include <iostream>
//
//int getVolume(UINT deviceID)
//{
//    DWORD volume = 0;
//    __asm
//    {
//        mov eax, volume
//        mov ebx, deviceID
//        push eax
//        push ebx
//        call waveOutGetVolume
//        mov eax, volume
//        mov volume, eax
//    }
//    return static_cast<int>(volume);
//}
//
//int main() {
//    setlocale(0, "");
//    WAVEOUTCAPS waveOutCaps;
//    UINT deviceCount = waveOutGetNumDevs();
//
//    for (UINT i = 0; i <= deviceCount; ++i) {
//        MMRESULT result = waveOutGetDevCaps(i, &waveOutCaps, sizeof(WAVEOUTCAPS));
//
//            std::wcout << "Device " << i  << waveOutCaps.szPname << std::endl;
//
//            // Получаем дескриптор звукового устройства из структуры waveOutCaps
//            //UINT deviceID = waveOutCaps.
//
//            // Передаем дескриптор в функцию getVolume и выводим результат
//            std::cout << "Громкость для устройства " << i << ": " << getVolume(i) << std::endl;
//        
//    }
//    return 0;
//}
//#include <iostream>
//#include <Windows.h>
//#include <mmdeviceapi.h>
//#include <endpointvolume.h>
//#include <iostream>
//#include <sstream>
//void SetVolume(float volume) {
//    // Получаем текущий звуковой устройства
//    HWND hwnd = GetForegroundWindow();
//
//    // Получаем интерфейс управления звуковым устройством
//    IAudioEndpointVolume* pEndpointVolume = NULL;
//    IMMDeviceEnumerator* pEnumerator = NULL;
//    CoInitialize(NULL);
//    CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
//    IMMDevice* pDevice = NULL;
//    pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);
//    pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pEndpointVolume);
//
//    // Устанавливаем громкость
//    pEndpointVolume->SetMasterVolumeLevelScalar(volume, NULL);
//
//    // Освобождаем ресурсы
//    pDevice->Release();
//    pEnumerator->Release();
//    pEndpointVolume->Release();
//    CoUninitialize();
//}
//int main() {
//    float volume = 0.0;
//    SetVolume(volume);
//
//    return 0;
//}

//#include <windows.h>
//#include <mmsystem.h>
//#include <iostream>
//int main() 
//{
//    HWAVEOUT hwo;
//    WAVEFORMATEX wfx;
//    wfx.wFormatTag = WAVE_FORMAT_PCM;
//    wfx.nChannels = 2;
//    wfx.nSamplesPerSec = 44100;
//    wfx.nAvgBytesPerSec = 44100 * 2*2;
//    wfx.nBlockAlign = 2*2;
//    wfx.wBitsPerSample = 16;
//    wfx.cbSize = 0;
//    MMRESULT res= waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
//    if (res == MMSYSERR_NOERROR)
//    {
//        DWORD dwVolume = 0xFFFF;
//        MMRESULT res2 = waveOutSetVolume(hwo, dwVolume);
//        if (res2 == MMSYSERR_NOERROR)
//        {
//            if (waveOutGetVolume(hwo, &dwVolume) == MMSYSERR_NOERROR)
//            {
//                std::cout << "Current volume: " << dwVolume << std::endl;
//            }
//        }
//    }
//    return 0;
//}
