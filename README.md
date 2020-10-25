# BlackPill Project Template

This template is used to build/upload Mbed project on BlackPill boards.
Currently supported board :

- [BlackPill F411CE](https://docs.platformio.org/en/latest/boards/ststm32/blackpill_f411ce.html)
- [BlackPill F401CE](https://docs.platformio.org/en/latest/boards/ststm32/blackpill_f401ce.html)



## PlatformIO Installation

This project require PlatformIO to be installed on your computer. Using python :

```
pip install -U platformio
```

If you are using Linux, you have to register BlackPill USB DFU rule, in /etc/udev/rules.d/dfu.rules:

    ATTRS{idVendor}=="0483", ATTRS{idProduct}=="df11", MODE="664", GROUP="plugdev"

And then reload the rule:

    sudo udevadm control --reload-rules

(Alternatively, you can install the complete PlatformIO.rules file [from here](https://docs.platformio.org/en/latest/faq.html#platformio-udev-rules))



## Initialization

Download the repository and go to the root folder where the `platformio.ini` is located , then init the project:

```
pio init
```

This will download all necessary libraries required for the project to build.

> Optional:
>
> You can init the project for the IDE you want, like this :
>
> ```
> pio init --ide YOUR_IDE
> ```
>
> For a list of supported IDE, type `pio project init --help`



## Build/Upload

To build the project for BlackPill F411CE , open a terminal :

    pio run -e blackpill_f411ce

To build the project for another board, open `platformio.ini `, get the environment code you want (after `env:...`), and replace the name in the upper command.



To upload the project to the board, just add `-t upload`:

    pio run -e blackpill_f411ce -t upload



By default, DFU is used to upload program. If you want to change, you have edit the corresponding line on `platformio.ini`, for example using stlink :

```
upload_protocol = stlink
```

Be aware that every edit done in `platformio.ini` will triggered a clean of the project building.



### Sources :

- https://github.com/JojoS62/custom_targets for BlackPill customs targets files.
- https://docs.platformio.org/en/latest/core/installation.html for PIO installation.
- https://github.com/platformio/platform-ststm32/tree/master/examples/mbed-rtos-custom-target for custom mbed board setup on PIO.
- https://github.com/KKoovalsky/PlatformIO-Helpers for custom mbedignore script.