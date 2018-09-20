// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#if !defined MICRORTPS_HELLOWORLD_DEMO__VISIBILITY_H_
#define MICRORTPS_HELLOWORLD_DEMO__VISIBILITY_H_

#if __cplusplus
extern "C" {
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define MICRORTPS_HELLOWORLD_DEMO_EXPORT __attribute__ ((dllexport))
    #define MICRORTPS_HELLOWORLD_DEMO_IMPORT __attribute__ ((dllimport))
  #else
    #define MICRORTPS_HELLOWORLD_DEMO_EXPORT __declspec(dllexport)
    #define MICRORTPS_HELLOWORLD_DEMO_IMPORT __declspec(dllimport)
  #endif
  #ifdef MICRORTPS_HELLOWORLD_DEMO_BUILDING_DLL
    #define MICRORTPS_HELLOWORLD_DEMO_PUBLIC MICRORTPS_HELLOWORLD_DEMO_EXPORT
  #else
    #define MICRORTPS_HELLOWORLD_DEMO_PUBLIC MICRORTPS_HELLOWORLD_DEMO_IMPORT
  #endif
  #define MICRORTPS_HELLOWORLD_DEMO_PUBLIC_TYPE MICRORTPS_HELLOWORLD_DEMO_PUBLIC
  #define MICRORTPS_HELLOWORLD_DEMO_LOCAL
#else
  #define MICRORTPS_HELLOWORLD_DEMO_EXPORT __attribute__ ((visibility("default")))
  #define MICRORTPS_HELLOWORLD_DEMO_IMPORT
  #if __GNUC__ >= 4
    #define MICRORTPS_HELLOWORLD_DEMO_PUBLIC __attribute__ ((visibility("default")))
    #define MICRORTPS_HELLOWORLD_DEMO_OCAL  __attribute__ ((visibility("hidden")))
  #else
    #define MICRORTPS_HELLOWORLD_DEMO_PUBLIC
    #define MICRORTPS_HELLOWORLD_DEMO_LOCAL
  #endif
  #define MICRORTPS_HELLOWORLD_DEMO_PUBLIC_TYPE
#endif

#if __cplusplus
} // extern "C"
#endif

#endif  // MICRORTPS_HELLOWORLD_DEMO__VISIBILITY_H_
