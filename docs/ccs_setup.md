# CCS Setup Guide for MSP432E401Y

This guide explains how to create a CCS bare-metal project for the MSP432E401Y and run the LED blink example.

## 1. Open Code Composer Studio
Launch CCS and choose a workspace folder. The workspace can be any location, but use the repository folder if you want to keep the project with your notes.

## 2. Create a new CCS project
1. File → New → CCS Project
2. Enter a project name, for example `MSP432_LED_Blink`
3. Device: search for `MSP432E401Y`
4. Connection: choose your debug probe (e.g. XDS110, XDS200, etc.)
5. Project templates: choose `Empty Project` or `Empty Project with main.c` if available
6. Runtime support: choose `No RTOS` or `None`
7. Finish the wizard

## 3. Add source files
In the new CCS project, add these files from this repository:
- `src/main.c`
- `src/startup.c`
- `ld/linker.ld`

If CCS created its own `main.c`, replace that content with the code in `src/main.c`.

## 4. Configure the linker file
1. Right-click the project → Properties
2. Go to `Build → MSP432 Linker` or `ARM Linker` settings
3. Set the linker command file to `ld/linker.ld`
4. Ensure the target device is MSP432E401Y and the toolchain is TI ARM

## 5. Build the project
1. Right-click the project → Build Project
2. Fix any compiler or linker errors that appear

## 6. Connect the board and debugger
1. Connect the MSP432E401Y board by USB
2. Ensure the debug probe is detected in CCS
3. If needed, use `Tools → Debug` or the Debug button

## 7. Run on hardware
1. In CCS, click `Debug` or `Run`
2. The firmware will flash to the board and start executing
3. Observe the onboard LED on P1.0 blinking

## 8. Notes
- The code in `src/main.c` is written for the MSP432E401Y P1.0 LED pin.
- CCS manages the `.project` and debug settings automatically.
- If CCS asks for a linker command file, point it to `ld/linker.ld`.

## 9. What to do if the board does not blink
- Check that the device selected is `MSP432E401Y`
- Verify the debug probe connection
- Confirm the LED pin is actually P1.0 on your board
- Make sure the project is built as a Cortex-M4F target

## 10. Optional: use CCS project settings
If the project is already created, you can also add the files by:
- Right-click project → Add Files...
- Select `src/main.c`, `src/startup.c`, and `ld/linker.ld`

That is the full CCS-style workflow for this repository.
