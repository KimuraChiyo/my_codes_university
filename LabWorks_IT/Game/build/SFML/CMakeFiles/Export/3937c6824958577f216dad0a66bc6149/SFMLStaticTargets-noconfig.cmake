#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SFML::System" for configuration ""
set_property(TARGET SFML::System APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SFML::System PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-system.a"
  )

list(APPEND _cmake_import_check_targets SFML::System )
list(APPEND _cmake_import_check_files_for_SFML::System "${_IMPORT_PREFIX}/lib/libsfml-system.a" )

# Import target "SFML::Main" for configuration ""
set_property(TARGET SFML::Main APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SFML::Main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-main.a"
  )

list(APPEND _cmake_import_check_targets SFML::Main )
list(APPEND _cmake_import_check_files_for_SFML::Main "${_IMPORT_PREFIX}/lib/libsfml-main.a" )

# Import target "SFML::Window" for configuration ""
set_property(TARGET SFML::Window APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SFML::Window PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-window.a"
  )

list(APPEND _cmake_import_check_targets SFML::Window )
list(APPEND _cmake_import_check_files_for_SFML::Window "${_IMPORT_PREFIX}/lib/libsfml-window.a" )

# Import target "SFML::Network" for configuration ""
set_property(TARGET SFML::Network APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SFML::Network PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-network.a"
  )

list(APPEND _cmake_import_check_targets SFML::Network )
list(APPEND _cmake_import_check_files_for_SFML::Network "${_IMPORT_PREFIX}/lib/libsfml-network.a" )

# Import target "SFML::Graphics" for configuration ""
set_property(TARGET SFML::Graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SFML::Graphics PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-graphics.a"
  )

list(APPEND _cmake_import_check_targets SFML::Graphics )
list(APPEND _cmake_import_check_files_for_SFML::Graphics "${_IMPORT_PREFIX}/lib/libsfml-graphics.a" )

# Import target "SFML::Audio" for configuration ""
set_property(TARGET SFML::Audio APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SFML::Audio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libsfml-audio.a"
  )

list(APPEND _cmake_import_check_targets SFML::Audio )
list(APPEND _cmake_import_check_files_for_SFML::Audio "${_IMPORT_PREFIX}/lib/libsfml-audio.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
