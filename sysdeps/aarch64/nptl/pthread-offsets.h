#ifdef __LP64__
# define __PTHREAD_MUTEX_KIND_OFFSET		16

# define __PTHREAD_RWLOCK_FLAGS_OFFSET		48
#else
/* ILP32: the generic 32-bit struct of bits/struct_mutex.h, and the
   aarch64 bits/struct_rwlock.h with 32-bit long.  */
# define __PTHREAD_MUTEX_KIND_OFFSET		12

# define __PTHREAD_RWLOCK_FLAGS_OFFSET		40
#endif
