# Kokorone's Marlin Stock firmware

This is updated to the latest firmware.
This has UART enabled optionally. For now the boards of the drivers are set to TMC2209. If you do not want UART enabled please just add _STANDALONE to the board, for example:

TMC2209_STANDALONE

Or if you have TMC2208:

TMC2208_STANDALONE.

Or others; you get the picture.

Anything else this is pure stock. I have a friend who still has a vanilla one test this and it is working pure stock (except he has TMC2209 and wanted UART. However just changing the board settings will disable UART).

In this folder is also a simple wiring schematic included to enable UART. Note: SIMPLE. Like MSPaint simple. (also one-wire)

Unzip and open in VSCode with the Platform.io plugin.

