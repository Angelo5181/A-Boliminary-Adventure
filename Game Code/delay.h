#ifdef _WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

void setTimeout(void func(), unsigned int delay) {
  #ifdef _WIN32
    Sleep(delay);
    func();
  #else
    sleep(delay / 1000);
    func();
  #endif
}