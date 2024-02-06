find_path(concurrentqueue_INCLUDE_DIR concurrentqueue.h PATH_SUFFIXES concurrentqueue)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(concurrentqueue
    REQUIRED_VARS concurrentqueue_INCLUDE_DIR)

# Create the imported target
if(concurrentqueue_FOUND)
    set(concurrentqueue_INCLUDE_DIRS ${concurrentqueue_INCLUDE_DIR})

    if(NOT TARGET concurrentqueue)
        add_library(concurrentqueue INTERFACE IMPORTED)
        set_target_properties(concurrentqueue PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${concurrentqueue_INCLUDE_DIRS}")
    endif()
endif()