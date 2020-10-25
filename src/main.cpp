#include "mbed.h"
#include "shell.h"

DigitalOut led(LED_RED);

SHELL_PARAMETER_FLOAT(a, "A", 0.)
SHELL_PARAMETER_FLOAT(b, "B", 0.)

SHELL_COMMAND(sum, "Sum")
{
    shell_print("Sum: ");
    shell_print(a+b);
    shell_println();
}

int main()
{
    shell_init_usb();

    while(1) {
        ThisThread::sleep_for(500);
        led = 0;
        ThisThread::sleep_for(500);
        led = 1;
    }
}