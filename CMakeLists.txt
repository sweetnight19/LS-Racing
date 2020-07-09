cmake_minimum_required(VERSION 3.15)
project(grupo-3)

set(CMAKE_C_STANDARD 11)
set(ALLEGRO_DIR "C:\ MinGW")
include_directories(${ALLEGRO_DIR}/include)
link_directories(${ALLEGRO_DIR}/lib)

add_executable(grupo-3 main.c LS_allegro.c LS_allegro.h menu.c menu.h peces.h fitxers.c fitxers.h gp.c gp.h corredores.h base.h grafica.c grafica.h usuario.h usuario.c classificacion.h classificacion.c general.h)

target_link_libraries(grupo-3 -lmingw32 -lallegro-5.0.10-monolith-md-debug)