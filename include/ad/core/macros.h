#ifndef AD_MACROS_H
#define AD_MACROS_H

/**
 * Allow including our library from C++ code
 */
#ifdef __cplusplus
#define AD_BEGIN_DECLS extern "C"{
#define AT_END_DECLS }
#else
#define AD_BEGIN_DECLS
#define AT_END_DECLS
#endif


#endif
