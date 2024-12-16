
/*
 * Copyright (C) Zhu Jiashun
 * Copyright (C) Zaver
 */

#ifndef DBG_H
#define DBG_H

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#ifdef NDEBUG
#define debug(M, ...)
#define debugf(M, ...)
#else
#define debug(M) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__)
#define debugf(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno())
#define log_errf(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno())
#define log_warnf(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__)
#define log_infof(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M) if(!(A)) { log_err(M "\n"); /* exit(1); */ }
#define checkf(A, M, ...) if(!(A)) { log_errf(M "\n", ##__VA_ARGS__); /* exit(1); */ }

#define check_exit(A, M) if(!(A)) { log_err(M "\n"); exit(1);}
#define check_exitf(A, M, ...) if(!(A)) { log_errf(M "\n", ##__VA_ARGS__); exit(1);}

#define check_debug(A, M) if(!(A)) { debug(M "\n"); /* exit(1); */}
#define check_debugf(A, M, ...) if(!(A)) { debugf(M "\n", ##__VA_ARGS__); /* exit(1); */}

#endif
