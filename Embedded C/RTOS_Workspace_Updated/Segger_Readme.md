To setup SEGGER systemview with the project :

- Download the package from the official website
- It has 3 folders : Config, Sample, SEGGER
- Go to rootFolder/Middlewares/Third_Party
- Create the folder : SEGGER
- Inside that folder, make new folders: Config, OS, Patch, SEGGER
- Copy the content of Config from the downloaded package to the folder Config we created
- In the downloaded package, go to : Sample/FreeRTOSV10.4/Config/Cortex-M and copy the file there to : rootFolder/Middlewares/Third_Party/SEGGER/Config
- From the FreeRTOSV10.4 folder, copy the H and C files there to the OS folder that we created earlier
- From FreeRTOSV10.4/Patch, copy the available patch file there to the Patch folder we created earlier
- From the SEGGER folder in the downloaded package, copy all content to rootFolder/Middlewares/Third_Party/SEGGER/SEGGER
- Inside SEGGER/Syscalls, delete all files except the GCC one which we need
- In the CubeIDE, refresh the project explorer and check to confirm that the SEGGER folder we added is not excluded from the build: Go to its Properties->C/C++ General->Paths and Symbols
- Add the new folders to the build: Go to project properties->C/C++ General->Paths and Symbols and from there click Add and select the new folders Config, OS, Patch, SEGGER.
- In the patch file inside the Patch folder, correct the 1st 3 lines to point correctly to the FreeRTOSConfig.h file, such that the paths are like : Core/Inc/.. or new/Core/Inc to match out project paths.
- Similar paths corrections are needed in the file for generic and CM4F specific lines.
