import os
EnsureSConsVersion(3,0)

sdl2_include_path = 'C:/visualStudioCppLibraries/SDL2-2.0.18/include'
sdl2_lib_path = 'C:/visualStudioCppLibraries/SDL2-2.0.18/lib/x64'

env = Environment()

cxxflags = ['/W4', '/WX', '/std:c++17', '/EHsc']

env.Append(CXXFLAGS=cxxflags, 
           CPPPATH=['#src', sdl2_include_path], 
           LIBPATH=[sdl2_lib_path],
           LIBS=['SDL2', 'SDL2main'])

#specify build directory
VariantDir('build', 'src', duplicate=0)

SConscript('build/SConscript', exports='env')


