import os
import sys
import rtconfig

RTT_ROOT = os.path.normpath(os.getcwd() + '/rt-thread')
# if os.getenv('RTT_ROOT'):
#     RTT_ROOT = os.getenv('RTT_ROOT')
# else:
#     RTT_ROOT = os.path.normpath(os.getcwd() + '/../../..')

sys.path = sys.path + [os.path.join(RTT_ROOT, 'tools')]
try:
    from building import *
except Exception as e:
    print("Error message:", e.message)
    print('Cannot found RT-Thread root directory, please check RTT_ROOT')
    print(RTT_ROOT)
    sys.exit(-1)

TARGET = 'rt-thread.elf'

DefaultEnvironment(tools=[])
env = Environment(tools = ['mingw'],
    AS = rtconfig.AS, ASFLAGS = rtconfig.AFLAGS,
    CC = rtconfig.CC, CCFLAGS = rtconfig.CFLAGS,
    AR = rtconfig.AR, ARFLAGS = '-rc',
    CXX = rtconfig.CXX, CXXFLAGS = rtconfig.CXXFLAGS,
    LINK = rtconfig.LINK, LINKFLAGS = rtconfig.LFLAGS)
env.PrependENVPath('PATH', rtconfig.EXEC_PATH)

env.AppendUnique(CPPDEFINES =  ['STM32H750xx', 'USE_HAL_DRIVER'])

Export('RTT_ROOT')
Export('rtconfig')

SDK_ROOT = os.path.abspath('./')

# if os.path.exists(SDK_ROOT + '/libraries'):
#     libraries_path_prefix = SDK_ROOT + '/libraries'
# else:
#     libraries_path_prefix = os.path.dirname(SDK_ROOT) + '/libraries'
libraries_path_prefix = SDK_ROOT
SDK_LIB = libraries_path_prefix
Export('SDK_LIB')
# prepare building environment
objs = PrepareBuilding(env, RTT_ROOT, has_libcpu=False)

stm32_library = 'STM32H7xx_HAL_Driver'
rtconfig.BSP_LIBRARY_TYPE = stm32_library
# include cubemx
# objs.extend(SConscript(os.path.join('cubemx', 'SConscript'),variant_dir='build/cubemx', duplicate=0))
# # include libraries
# objs.extend(SConscript(os.path.join('libraries', 'SConscript'), variant_dir='build/libraries', duplicate=0))
# # include drivers
# objs.extend(SConscript(os.path.join('drivers', 'SConscript'),variant_dir='build/drivers', duplicate=0))

# make a building
DoBuilding(TARGET, objs)
