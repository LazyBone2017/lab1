set(lab_benchmark_additional_files "" CACHE INTERNAL "")
set(lab_lib_additional_files "" CACHE INTERNAL "")
set(lab_test_additional_files "" CACHE INTERNAL "")

if(WIN32) # Benchmark
	list(APPEND lab_benchmark_additional_files "benchmark.h")
endif()
	
if(WIN32) # Lib
	list(APPEND lab_lib_additional_files "authors.h")
	
	list(APPEND lab_lib_additional_files "encryption/FES.h")
	list(APPEND lab_lib_additional_files "encryption/Key.h")
	
	list(APPEND lab_lib_additional_files "image/bitmap_image.h")
	list(APPEND lab_lib_additional_files "image/pixel.h")
	
	list(APPEND lab_lib_additional_files "io/image_parser.h")
endif()

if(WIN32) # Tests
	list(APPEND lab_test_additional_files "test.h")	
endif()
