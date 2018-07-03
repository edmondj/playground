set(HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/event.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/property.hpp
)

#add_custom_target(simple_model_files SOURCES ${HEADERS}) #Trick to show it up in IDE

add_library(simple_model INTERFACE)
target_sources(simple_model INTERFACE ${HEADERS})

target_include_directories(simple_model INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)
