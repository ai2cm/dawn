//===--------------------------------------------------------------------------------*- C++ -*-===//
//                         _     _ _              _            _
//                        (_)   | | |            | |          | |
//               __ _ _ __ _  __| | |_ ___   ___ | |___    ___| | __ _ _ __   __ _
//              / _` | '__| |/ _` | __/ _ \ / _ \| / __|  / __| |/ _` | '_ \ / _` |
//             | (_| | |  | | (_| | || (_) | (_) | \__ \ | (__| | (_| | | | | (_| |
//              \__, |_|  |_|\__,_|\__\___/ \___/|_|___/  \___|_|\__,_|_| |_|\__, |
//               __/ |                                                        __/ |
//              |___/                                                        |___/
//
//  This file is distributed under the MIT License (MIT).
//  See LICENSE.txt for details.
//
//===------------------------------------------------------------------------------------------===//

#ifndef GTCLANG_SUPPORT_CONFIG_H
#define GTCLANG_SUPPORT_CONFIG_H

// Major version of GTClang 
#define GTCLANG_VERSION_MAJOR ${GTCLANG_VERSION_MAJOR}

// Minor version of GTClang 
#define GTCLANG_VERSION_MINOR ${GTCLANG_VERSION_MINOR}

// Patch version of GTClang 
#define GTCLANG_VERSION_PATCH ${GTCLANG_VERSION_PATCH}

// GTClang version string 
#define GTCLANG_VERSION_STRING "${GTCLANG_VERSION_STRING}"

// Path to gridtools clang DSL headers
#define GTCLANG_DSL_INCLUDES "${GTCLANG_DSL_INCLUDES}"

// Ressource path of the Clang specific headers needed during invocation of Clang
#define GTCLANG_CLANG_RESSOURCE_INCLUDE_PATH "${GTCLANG_CLANG_RESSOURCE_INCLUDE_PATH}"

#endif

