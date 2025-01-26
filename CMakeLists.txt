cmake_minimum_required(VERSION 3.28)
project(SolucionSumaArreglosParalela_Carlos_Parra)

set(CMAKE_CXX_STANDARD 17)

# Configura el compilador
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# Configura rutas de OpenMP
set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/Cellar/libomp/19.1.7/include")
set(OpenMP_CXX_LIB_NAMES "omp")
set(OpenMP_omp_LIBRARY "/opt/homebrew/Cellar/libomp/19.1.7/lib/libomp.dylib")

# Agrega banderas de compilación y enlace
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/opt/homebrew/Cellar/libomp/19.1.7/lib -lomp")

# Crea ejecutable
add_executable(SolucionSumaArreglosParalela_Carlos_Parra main.cpp)



