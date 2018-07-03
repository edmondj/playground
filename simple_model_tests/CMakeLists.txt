set(SRC
	main.cpp
  event.cpp
  property.cpp
)

add_executable(simple_model_tests ${SRC})
target_compile_features(simple_model_tests PUBLIC cxx_std_17)
target_link_libraries(simple_model_tests simple_model catch)