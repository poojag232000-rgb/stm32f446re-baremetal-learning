# CCS-style project layout for MSP432E401Y

This folder is organized so you can import it into Code Composer Studio as a bare-metal embedded project.

## Suggested CCS project structure
- src/         -> C source files
- include/     -> headers
- ld/          -> linker script
- docs/        -> study notes

## Main files
- src/main.c
- src/startup.c
- ld/linker.ld

## Build target
Use a Cortex-M4F target such as MSP432E401Y or a compatible Cortex-M4F configuration.

## Notes
In CCS, the program is not run like a desktop app. It is built, flashed to the board, then debugged/run on the target MCU.
