
# 命令行测试指令

``` shell

STM32_Programmer_CLI.exe -c port=SWD  freq=4000 -rdu -r32 0x1FF0F442 12

STM32_Programmer_CLI.exe -c port=SWD  freq=4000 -el C:\0_dev\h750_feature\stldr\STM32CubePro_FK750M1_V0.stldr -w C:\0_dev\h750_feature\rt-thread.elf -rst
```

**执行结果**

```shell
C:\Program Files\STMicroelectronics\STM32Cube\STM32CubeProgrammer\bin>STM32_Programmer_CLI.exe -c port=SWD  freq=4000 -el C:\0_dev\h750_feature\stldr\STM32CubePro_FK750M1_V0.stldr -w C:\0_dev\h750_feature\rt-thread.elf -rst
      -------------------------------------------------------------------
                       STM32CubeProgrammer v2.19.0
      -------------------------------------------------------------------

ST-LINK SN  : 066FFF485252835087121926
ST-LINK FW  : V2J45M30
Board       : --
Voltage     : 3.25V
SWD freq    : 4000 KHz
Connect mode: Normal
Reset mode  : Software reset
Device ID   : 0x450
Revision ID : Rev V
Device name : STM32H7xx
Flash size  : 128 KBytes
Device type : MCU
Device CPU  : Cortex-M7
BL Version  : 0x91

Opening and parsing file: rt-thread.elf


Memory Programming ...
  File          : rt-thread.elf
  Size          : 286.48 KB
  Address       : 0x90000000



Erasing memory corresponding to sector 0:
Erasing external memory sectors [0 4]
Download in Progress:
圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹圹 100%

File download complete
Time elapsed during download operation: 00:00:03.573

MCU Reset

Software reset is performed
```



**直接运行flash.bat**

# 转换下载算法


```shell

target-gen elf -u .\FANKE_FK750M1_V0.FLM   .\STM32H7_Series.yaml
```

# probe-rs下载

```shell

probe-rs download --chip=stm32h750vbtx --protocol swd --chip-description-path stldr\STM32H7_Series.yaml --speed=46000 rt-thread.elf
probe-rs reset --chip=stm32h750vbtx --protocol swd --chip-description-path  stldr\STM32H7_Series.yaml

```
**直接运行probe-rs-flash.bat**
