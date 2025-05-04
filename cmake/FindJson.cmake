set(name json)

include(FetchContent)
# Check if it's already fetched
FetchContent_GetProperties(${name})
if (NOT ${name}_POPULATED)
  # If not, fetch it
  FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
  )
  FetchContent_MakeAvailable(${name})
endif()
