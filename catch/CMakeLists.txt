set(HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/catch.hpp
)

add_library(catch INTERFACE)
target_sources(catch INTERFACE ${HEADERS})

target_include_directories(catch INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)
