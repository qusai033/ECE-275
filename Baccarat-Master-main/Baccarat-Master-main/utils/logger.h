#ifndef LOGGER_UTILS_H_
#define LOGGER_UTILS_H_

#if defined ENABLE_DEBUG_MSG

#include <stdio.h>
// Define macro to print a log message with the function name and line number
#define log_msg(fmt, ...)						\
  fprintf(stdout, "[%s:%d] " fmt,  __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define check(cond, msg, ...)					       \
  do {								       \
    if (!(cond)) log_msg(msg, ##__VA_ARGS__);			       \
  } while(0)

#else

#define log_msg(fmt, ...) do{}while(0)
#define check(cond, msg, ...) do{}while(0) 

#endif
#endif
