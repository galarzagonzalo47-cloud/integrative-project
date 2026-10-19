# Copilot Instructions

## Project
- This is a small C++ console project for managing activities at a club.
- Source files currently include `Fecha` (`Fecha.h`, `Fecha.cpp`), `Socios` (`Socios.h`, `Socios.cpp`), and `main.cpp`.
- User-facing prompts and domain terminology are in Spanish. Preserve that language and existing naming conventions unless asked otherwise.
- The comments in `main.cpp` describe planned `.dat` record schemas; preserve field names and types when implementing those records.

## C++ Changes
- Keep declarations in headers and matching implementations in their corresponding `.cpp` files.
- Include the standard headers required by each public type directly in its header.
- Follow the existing class-based style and keep changes focused; avoid introducing frameworks or unrelated abstractions.
- Be careful with fixed-size character arrays when handling input, and avoid buffer overflows.

## Build and Validation
- No build system or project configuration is currently present, and `main.cpp` does not yet contain an application entry point.
- Before claiming a build or test passed, confirm a usable target exists. For source changes, use an available compiler or focused checks and report any pre-existing blockers separately.