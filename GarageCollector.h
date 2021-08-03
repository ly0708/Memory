#pragma once

#define malloc(size) custom_malloc(size, __FILE__, __LINE__)
