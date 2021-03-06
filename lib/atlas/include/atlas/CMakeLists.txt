set(ATLAS_INCLUDE_ROOT_LIST
    "${ATLAS_INCLUDE_ROOT}/Atlas.hpp")
configure_file("${ATLAS_INCLUDE_ROOT}/Atlas.hpp.in" ${ATLAS_INCLUDE_ROOT_LIST})

# Traverse the lower include directories.
add_subdirectory("${ATLAS_INCLUDE_ROOT}/core")
add_subdirectory("${ATLAS_INCLUDE_ROOT}/gl")
add_subdirectory("${ATLAS_INCLUDE_ROOT}/math")
add_subdirectory("${ATLAS_INCLUDE_ROOT}/utils")
add_subdirectory("${ATLAS_INCLUDE_ROOT}/tools")

# Wrap each of the variables coming from the folders and pass them up.
set(ATLAS_INCLUDE_CORE_LIST_PARENT ${ATLAS_INCLUDE_CORE_LIST} PARENT_SCOPE)
set(ATLAS_INCLUDE_GL_LIST_PARENT ${ATLAS_INCLUDE_GL_LIST} PARENT_SCOPE)
set(ATLAS_INCLUDE_MATH_LIST_PARENT ${ATLAS_INCLUDE_MATH_LIST} PARENT_SCOPE)
set(ATLAS_INCLUDE_UTILS_LIST_PARENT ${ATLAS_INCLUDE_UTILS_LIST} PARENT_SCOPE)
set(ATLAS_INCLUDE_TOOLS_LIST_PARENT ${ATLAS_INCLUDE_TOOLS_LIST} PARENT_SCOPE)
set(ATLAS_INCLUDE_ROOT_LIST_PARENT ${ATLAS_INCLUDE_ROOT_LIST} PARENT_SCOPE)

# Now assemble the final list and pass it up.
set(ATLAS_INCLUDE_LIST
    ${ATLAS_INCLUDE_ROOT_LIST}
    ${ATLAS_INCLUDE_CORE_LIST}
    ${ATLAS_INCLUDE_GL_LIST}
    ${ATLAS_INCLUDE_MATH_LIST}
    ${ATLAS_INCLUDE_UTILS_LIST}
    ${ATLAS_INCLUDE_TOOLS_LIST}
    PARENT_SCOPE)
