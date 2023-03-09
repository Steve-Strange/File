macro(Ubpa_InitUCMake)
  include(FetchContent)
  set(UCMake_VERSION 0.6.0)
  message(STATUS "find package: UCMake ${UCMake_VERSION}")
  find_package(UCMake ${UCMake_VERSION} QUIET)
  if(NOT UCMake_FOUND)
    message(STATUS "searching _deps for UCMake ${UCMake_VERSION}")
	if(NOT EXISTS "${CMAKE_SOURCE_DIR}/_deps/UCMake-${UCMake_VERSION}/CMakeLists.txt")
		message(FATAL_ERROR "UCMake ${UCMake_VERSION} not found in ${CMAKE_SOURCE_DIR}/_deps")
	endif()
    FetchContent_Declare(
		UCMake
		SOURCE_DIR "${CMAKE_SOURCE_DIR}/_deps/UCMake-${UCMake_VERSION}"
	)
    FetchContent_MakeAvailable(UCMake)
    message(STATUS "UCMake ${UCMake_VERSION} build done")
  endif()
endmacro()
