set(name finder)

include(FetchContent)
# Check if it's already fetched
FetchContent_GetProperties(${name})
if (NOT ${name}_POPULATED)
  # If not, fetch it
  FetchContent_Declare(
    ${name}
    GIT_REPOSITORY https://github.com/P-E-R-R-Y/${name}.git
    GIT_TAG main #v0.1.0
  )
  FetchContent_MakeAvailable(${name})
endif()