pushd "C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin" 
STM32_Programmer_CLI.exe -c port=SWD  freq=4000 -el C:\0_dev\h750_feature\stldr\STM32CubePro_FK750M1_V0.stldr -w C:\0_dev\h750_feature\rt-thread.elf -rst
popd 