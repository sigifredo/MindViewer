# Supongamos que 'third_party/qwt' está en la raíz del proyecto
set(QWT_ROOT_DIR "${CMAKE_SOURCE_DIR}/third_party/qwt")

# Establecer paths del include y la biblioteca
set(QWT_INCLUDE_DIR "${QWT_ROOT_DIR}/src")
set(QWT_LIBRARY_DIR "${QWT_ROOT_DIR}/build/lib")

# Determina la librería según el sistema
if(WIN32)
    set(QWT_LIBRARY "${QWT_LIBRARY_DIR}/qwt.lib")
elseif(APPLE)
    set(QWT_LIBRARY "${QWT_LIBRARY_DIR}/libqwt.dylib")
else()
    set(QWT_LIBRARY "${QWT_LIBRARY_DIR}/libqwt.so")
endif()

# Crear un target IMPORTED para qwt::qwt
add_library(qwt::qwt UNKNOWN IMPORTED)
set_target_properties(qwt::qwt PROPERTIES
    IMPORTED_LOCATION "${QWT_LIBRARY}"
    INTERFACE_INCLUDE_DIRECTORIES "${QWT_INCLUDE_DIR}"
)

# Opcional: mensajes de depuración
message(STATUS "Qwt include: ${QWT_INCLUDE_DIR}")
message(STATUS "Qwt library: ${QWT_LIBRARY}")