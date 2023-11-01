add_library(lab_lib STATIC)
target_sources(
  lab_lib
  PRIVATE 
		  encryption/FES.cpp
		  encryption/Key.cpp
	
		  image/bitmap_image.cpp
		  image/pixel.cpp
		  
		  io/image_parser.cpp
	
		  # for visual studio
		  ${lab_lib_additional_files})

target_include_directories(lab_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(lab_lib PROPERTIES ENABLE_EXPORTS 1)
target_link_libraries(lab_lib PUBLIC project_options project_libraries)

FetchContent_Declare(
  cli11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
  GIT_TAG 815553211b644b2a64b5dc671c602233c49c065f)
FetchContent_MakeAvailable(cli11)

# lab executable
add_executable(lab)
target_sources(lab PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(lab PRIVATE lab_lib)

target_link_libraries(lab PRIVATE CLI11::CLI11)
set_target_properties(lab PROPERTIES ENABLE_EXPORTS 1)

target_link_libraries(lab_lib PUBLIC project_options project_libraries)

get_target_property(lab_lib_sources lab_lib SOURCES)
source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${lab_lib_sources})
